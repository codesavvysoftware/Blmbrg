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

};



