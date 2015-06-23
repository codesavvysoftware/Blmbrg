/*
 * Blmbrg_Solutions.cpp
 *
 *  Created on: Jun 22, 2015
 *      Author: tomh
 */
#include "Blmbrg_Solutions.h"


namespace ProblemSolutions {

/*
***** Solution ******
	2.  Given the root node to a singly linked list, reverse the last 5
		nodes in the list.  For a list with 5 or less nodes, reverse the whole list.
*/
void ReverseLastFiveItemsInList() {
	Blmbrg_Common::CommonNode * pHead;

	Blmbrg_Common::CreateSinglyLinkedList( 10, &pHead );

	Blmbrg_Common::CommonNode * p = pHead;

	int i;

	for ( i = 0; i < 10; i++ ) {
		Blmbrg_Common::DisplayNode(p);

		p = p->cnNext;
	}

	ReverseLastNodesOfSinglyLinkedList(&pHead, 5);
	//ReverseSinglyLinkedList(&pHead);

	p = pHead;


	for ( i = 0; i < 10; i++ ) {
		Blmbrg_Common::DisplayNode(p);

		p = p->cnNext;
	}

	Blmbrg_Common::DestroyLinkedList(pHead);

}

/*
***** Solution ******
	3.  Given the root node to a singly linked list, write an algorithm to
		detect if there is a loop in the list.
*/
void DetectLoopInListSolution() {
	Blmbrg_Common::CommonNode * pHead;

	Blmbrg_Common::CreateLoopingLinkedList(10,7,3,&pHead);

	int i;

	Blmbrg_Common::CommonNode * pLinkBackFromNode;
	Blmbrg_Common::CommonNode * pLinkBackToNode;

	bool bListLoopsBackOnItself = bDoesLinkListLoopOnItself( pHead, &pLinkBackFromNode, &pLinkBackToNode );

	if (bListLoopsBackOnItself) {
		std::cout << "Loops Back On Itself  " << "Loop Back Node: ";
		std::cout << pLinkBackFromNode->iNodeData << " Points to: " << pLinkBackToNode->iNodeData << std::endl;

		pLinkBackFromNode->cnNext = pLinkBackFromNode->cnPrev;
	}
	else {
		std::cout << "Loop Does Not Loop Back On Itself" << std::endl;
	}

	Blmbrg_Common::DestroyLinkedList(pHead);

}
/*
***** Solution ******
	4.  Write an algorithm to calculate the square root of a number.
*/
void FindSquareRootSolution() {
	unsigned int uiSquareRootTgt = 289;

	unsigned int uiLowerBound;

	unsigned int uiUpperBound;

	bool bExactSqrRtFound = FindSquareRoot(uiSquareRootTgt, uiLowerBound, uiUpperBound);

	DisplaySquareRootResult( bExactSqrRtFound, uiSquareRootTgt, uiLowerBound, uiUpperBound );

	uiSquareRootTgt = 1050;

	bExactSqrRtFound = FindSquareRoot(uiSquareRootTgt, uiLowerBound, uiUpperBound);

	DisplaySquareRootResult( bExactSqrRtFound, uiSquareRootTgt, uiLowerBound, uiUpperBound );


    uiSquareRootTgt = 4;
}

/*
***** Solution ******
	5. Give an array of random integers.  Write an algorithm to find the
		the closest 2 integers (closest by position) in the array that add up to 100.
*/
void FindTwoClosestRandomIntsInArray() {
	std::unique_ptr<int> pRandNumAry;

	unsigned int uiNumberOfElements = 100;


	bool bArrayCreated = Blmbrg_Common::CreateArrayOfRandomIntegers( pRandNumAry, uiNumberOfElements);

    if ( bArrayCreated ) {
    	int * RandNumAry = pRandNumAry.get();

    	unsigned int uiSumVal = 100;

    	int iAryVal0 = 0;

    	int iAryVal1 = 0;

    	int iAryVal0Idx = 0;

    	int iAryVal1Idx = 0;

    	bool bArrayValsThatSumFound = FindClosestInArrayThatSum( RandNumAry,
    			                   	   	   	   	   	   	   	   	 uiSumVal,
    			                   	   	   	   	   	   	   	   	 uiNumberOfElements,
    			                   	   	   	   	   	   	   	   	 iAryVal0,
    			                   	   	   	   	   	   	   	   	 iAryVal0Idx,
    			                   	   	   	   	   	   	   	   	 iAryVal1,
    			                   	   	   	   	   	   	   	   	 iAryVal1Idx );
    }

}

/*
***** Solution ******
	6. Given an array of integers, write a method that returns an array of the same size where each
		index is the product of all integers except itself, ie given array {1,2,3,4} return {24,12,8,6}
		explicitly {2*3*4,1*3*4,1*2*4,1*2*3}.
*/
void ProduceArrayOfProductsOfElementsSolution(){
	int TestAry0[] = { 1,2,3,4,5,6,7,9 };

	unsigned int uiTestAry0Sz = sizeof(TestAry0)/sizeof(int);

	bool bArrayProduced = CalculateProductArray( TestAry0, uiTestAry0Sz );

	if (bArrayProduced){
		DisplayProductArray( TestAry0, uiTestAry0Sz );
	}

	int TestAry1[] = { 88, 4, 2, 1, 0 };

	unsigned int uiTestAry1Sz = sizeof(TestAry1)/sizeof(int);

	bArrayProduced = CalculateProductArray( TestAry1, uiTestAry1Sz );

	if (bArrayProduced){
		DisplayProductArray( TestAry1, uiTestAry1Sz );
	}
}

void DisplayProductArray( int * pAry, unsigned int uiArySize ) {
	std::cout << "Products are: ";

	unsigned int ui;

	for (ui = 0; ui < uiArySize; ui++) {
		std::cout << "Mmbr " << ui << ": " << pAry[ui] << " ";
	}

	std::cout << std::endl;
}
/* The algorithm:
 * 		Find most significant bit that is set.
 * 		Since bit positions start at 0, if the most significant bit set is an odd bit number
 * 		  use 2**(most significant bit position - 1 ) as the power of two value.
 * 		  the range of values to check is 2**(power of two value/2) to 3 * (2** power of two value/2)
 * 		else if the most significant bit position is even that is the power of two value
 * 		  the range of values to check is 2**(power of two value/2) to 2*(power of two value/2)
 *
 * 		Find either the exact square root or the bounding integer values using the range of values doing a
 * 		binary search
 *
 * 		One assumption I'm making is that we're only working with positive ints only.
 */
bool FindSquareRoot( unsigned int uiSquareRootTgt,
		             unsigned int & uiSquareRootRangeBottom,
		             unsigned int & uiSquareRootRangeTop ) {
	if (uiSquareRootTgt == 0) return false;

	if (uiSquareRootTgt == 1) {
		uiSquareRootRangeBottom = 1;
		uiSquareRootRangeTop = 1;
		return true;
	}

	unsigned int uiMSBPos = 0;

	unsigned int uiPowerOfTwoVal;

	unsigned int uiRangeUpperMltplr;

	unsigned int uiNumberOfIntBits = sizeof(unsigned int) * 8;

	unsigned int uiLastSigBit = 1 << (uiNumberOfIntBits-1);

	unsigned int ui;

	unsigned int ui0 = uiSquareRootTgt;

	for ( ui = uiNumberOfIntBits; ui != 0; ui--) {
		if ( ui0 & uiLastSigBit ) {
			uiMSBPos = ui - 1;

			break;
		}

		ui0 <<= 1;
	}

	if (uiMSBPos & 1) {
		uiPowerOfTwoVal = (uiMSBPos - 1) >> 1;

		uiRangeUpperMltplr = 3;

	}
	else {
		uiPowerOfTwoVal = uiMSBPos >> 1;

		uiRangeUpperMltplr = 2;
	}

	//
	// Lower Bound for search.
	//
	unsigned int uiLowerBoundVal = 1 << uiPowerOfTwoVal;

	unsigned int uiUpperBoundVal = uiRangeUpperMltplr << uiPowerOfTwoVal;

	unsigned int uiTempBound;

	unsigned int uiValToTry;

	unsigned int uiSquaredResult;

	while((uiUpperBoundVal -uiLowerBoundVal) != 1 ) {
		uiValToTry = (uiLowerBoundVal) + ((uiUpperBoundVal - uiLowerBoundVal) >> 1);

		uiSquaredResult = uiValToTry * uiValToTry;

		if ( uiSquaredResult == uiSquareRootTgt) {
			uiSquareRootRangeBottom = uiValToTry;
			uiSquareRootRangeTop = uiValToTry;
			return true;
		}
		else if (uiSquaredResult < uiSquareRootTgt) {
			uiLowerBoundVal = uiValToTry;
		}
		else if (uiSquaredResult > uiSquareRootTgt) {
			uiUpperBoundVal = uiValToTry;
		}
	}
	uiSquareRootRangeBottom = uiLowerBoundVal;
	uiSquareRootRangeTop = uiUpperBoundVal;

	return false;
}



bool CalculateProductArray( int * pVals, unsigned int uiArySize ) {
	if ((!pVals) || (!uiArySize)) {
		return false;
	}

	int * pProductVals = new int[uiArySize];

	if (!pProductVals) return false;

	unsigned int uiIdxOuter, uiIdxInner;

	int iCurrentProductVal = 0;

	for (uiIdxOuter = 0; uiIdxOuter < uiArySize; uiIdxOuter++) {
		iCurrentProductVal = 1;
		for ( uiIdxInner = 0; uiIdxInner < uiArySize; uiIdxInner++ ) {
			if ( uiIdxOuter != uiIdxInner ) {
				iCurrentProductVal *= pVals[uiIdxInner];
			}
		}
		pProductVals[uiIdxOuter] = iCurrentProductVal;
	}

	for ( uiIdxOuter = 0; uiIdxOuter < uiArySize; uiIdxOuter++) {
		pVals[uiIdxOuter] = pProductVals[uiIdxOuter];
	}

	delete pProductVals;

	return true;
}
bool bDoesLinkListLoopOnItself( Blmbrg_Common::CommonNode *  pHead,
								Blmbrg_Common::CommonNode ** pLinkBackFromNode,
								Blmbrg_Common::CommonNode ** pLinkBackToNode ) {
	if ( !pHead ) return false;

	Blmbrg_Common::CommonNode * pOneNodeAtATime = pHead;

	Blmbrg_Common::CommonNode * pTwoNodesAtATime = pHead->cnNext;

	Blmbrg_Common::CommonNode * NodeLoopedOn = nullptr;

	while( pTwoNodesAtATime != nullptr ) {
		if (pOneNodeAtATime == pTwoNodesAtATime ) {

			while(pOneNodeAtATime->cnNext != NodeLoopedOn) {
				pOneNodeAtATime = pOneNodeAtATime->cnNext;
			}

			if ( pLinkBackFromNode ) *pLinkBackFromNode = pOneNodeAtATime;

			if ( pLinkBackToNode ) *pLinkBackToNode = NodeLoopedOn;

			return true;
		}

		NodeLoopedOn = pOneNodeAtATime;

		pOneNodeAtATime = pOneNodeAtATime->cnNext;

		pTwoNodesAtATime = pTwoNodesAtATime->cnNext->cnNext;
	}

	return false;
}

void ReverseSinglyLinkedList( Blmbrg_Common::CommonNode ** pHead) {
	if (!pHead || !(*pHead)) {
		return;
	}

	Blmbrg_Common::CommonNode * pPrevNode = nullptr;

	Blmbrg_Common::CommonNode * pCurrentNode = *pHead;

	Blmbrg_Common::CommonNode * pTempNode = nullptr;

	while(pCurrentNode) {
		pTempNode = pCurrentNode->cnNext;

		pCurrentNode->cnNext = pPrevNode;

		pPrevNode = pCurrentNode;

		pCurrentNode = pTempNode;
	}

	*pHead = pPrevNode;
}

/*
***** Solution ******
2.  Given the root node to a singly linked list, reverse the last 5
	nodes in the list.  For a list with 5 or less nodes, reverse the whole list.
*/
void ReverseLastNodesOfSinglyLinkedList( Blmbrg_Common::CommonNode ** pHead, unsigned int uiNumberOnEndToReverse) {
	Blmbrg_Common::CommonNode * pReverseHead = *pHead;

	unsigned int uiNodeNumber = 0;

	Blmbrg_Common::CommonNode * pCurrent = pReverseHead;

	Blmbrg_Common::CommonNode * pLastNodeBeforeReverse = nullptr;

	while(pCurrent) {
		uiNodeNumber++;

		if (uiNodeNumber > uiNumberOnEndToReverse) {
			pLastNodeBeforeReverse = pReverseHead;

			pReverseHead = pReverseHead->cnNext;
		}

		pCurrent = pCurrent->cnNext;
	}

	ReverseSinglyLinkedList(&pReverseHead);

	if (uiNodeNumber <= uiNumberOnEndToReverse) {
		*pHead = pReverseHead;
	}
	else {
		pLastNodeBeforeReverse->cnNext = pReverseHead;
	}
}

bool FindClosestInArrayThatSum( int *        RandomNumAry,
		                        int          iSummationVal,
		                        unsigned int uiNumAryElmnts,
		                        int &        iFirstValue,
		                        int &        iFirstValueIdx,
		                        int &        iSecondValue,
		                        int &        iSecondValueIdx ) {
    if (!RandomNumAry) return false;

    typedef struct _RandAryElement {
		int        iValue;

		int        iArrayPos;
	    } RandAryElement;

	    RandAryElement ElementAry[uiNumAryElmnts];

	    for (unsigned int ui = 0; ui < uiNumAryElmnts; ui++) {
	    	ElementAry[ui].iValue = RandomNumAry[ui];

	    	ElementAry[ui].iArrayPos = ui;
	    }

	    std::sort( ElementAry,
	               (ElementAry+uiNumAryElmnts),
	               [](RandAryElement const& lhs, RandAryElement const & rhs)->bool{
		           return (lhs.iValue < rhs.iValue);}
             );
	    for ( unsigned int ui = 0; ui < uiNumAryElmnts; ui++ ) {
		    std::cout << ElementAry[ui].iValue << " " << ElementAry[ui].iArrayPos << std::endl;
	    }

	    unsigned int uiFromLastElmntIdx = uiNumAryElmnts - 1;

	    unsigned int uiLeastDistBetweenAryElements = uiNumAryElmnts + 1;

	    unsigned int uiIdx;

	    int iFirstVal;

	    int iSecondVal;

	    int iFirstValIdx;

	    int iSecondValIdx;

	    int iSum;

	    bool bSummationValPairFound = false;

	    for (uiFromLastElmntIdx = uiNumAryElmnts - 1; uiFromLastElmntIdx > 0; uiFromLastElmntIdx--) {
	    	uiIdx = 0;
	    	while( uiIdx < uiFromLastElmntIdx ) {
	    		iSum = ElementAry[uiFromLastElmntIdx].iValue + ElementAry[uiIdx].iValue;

	    		if (    ( iSum == iSummationVal )
	    			 && (abs(ElementAry[uiFromLastElmntIdx].iArrayPos -ElementAry[uiIdx].iArrayPos)
	    			      < uiLeastDistBetweenAryElements ) ) {
	    			iFirstVal     = ElementAry[uiIdx].iValue;
	    			iFirstValIdx  = ElementAry[uiIdx].iArrayPos;
	    			iSecondVal    = ElementAry[uiFromLastElmntIdx].iValue;
	    			iSecondValIdx = ElementAry[uiFromLastElmntIdx].iArrayPos;
	    			uiLeastDistBetweenAryElements
	    			    = abs(ElementAry[uiFromLastElmntIdx].iArrayPos -ElementAry[uiIdx].iArrayPos);

	    			bSummationValPairFound = true;

	    			break;
	    		}
	    		else if ( iSum > iSummationVal ) {
	    			break;
	    		}
	    		else {
	    			uiIdx++;
	    		}
	    	}
	    }

	    if (bSummationValPairFound) {
	    	iFirstValue     = iFirstVal;
	    	iFirstValueIdx  = iFirstValIdx;
	    	iSecondValue    = iSecondVal;
        iSecondValueIdx = iSecondValIdx;
	    }

	    return bSummationValPairFound;
}
void DisplaySquareRootResult( bool bExactSqrRtFound, unsigned int uiSquareRootTgt, unsigned int uiLowerBound, unsigned int uiUpperBound ) {
	if (bExactSqrRtFound) {
		std::cout << "Exact Square Root Found for " << uiSquareRootTgt << " Square Root == " << uiUpperBound << std::endl;
	}
	else {
		std::cout << "Exact Square Root Not Found for " << uiSquareRootTgt << " Square Root between {" << uiUpperBound << "," << uiLowerBound << "}" << std::endl;
	}
}

};



