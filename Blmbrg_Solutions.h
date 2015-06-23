/*
 * Ben_Solutions.h
 *
 *  Created on: Jun 22, 2015
 *      Author: tomh
 */
#ifndef BEN_SOLUTIONS_H_
#define BEN_SOLUTIONS_H_
#include "Blmbrg_Common.h"
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <array>
#include <memory>



namespace ProblemSolutions {
	/*
	 ***** Solution ******
		2.  Given the root node to a singly linked list, reverse the last 5
			nodes in the list.  For a list with 5 or less nodes, reverse the whole list.
	*/
	void ReverseLastFiveItemsInList();

	/*
	***** Solution ******
		3.  Given the root node to a singly linked list, write an algorithm to
			detect if there is a loop in the list.
	*/
	void DetectLoopInListSolution();

	/*
	***** Solution ******
		4.  Write an algorithm to calculate the square root of a number.
	*/

	void FindSquareRootSolution();

	/*
	***** Solution ******
		5. Give an array of random integers.  Write an algorithm to find the
			the closest 2 integers (closest by position) in the array that add up to 100.
	*/
	void FindTwoClosestRandomIntsInArray();


	/*
	***** Solution ******
		6. Given an array of integers, write a method that returns an array of the same size where each
			index is the product of all integers except itself, ie given array {1,2,3,4} return {24,12,8,6}
			explicitly {2*3*4,1*3*4,1*2*4,1*2*3}.
	*/
	void ProduceArrayOfProductsOfElementsSolution();



	bool CalculateProductArray( int * pVals, unsigned int uiArySize );

	void DisplayProductArray( int * pAry, unsigned int uiArySize );

	void DisplaySquareRootResult( bool         bExactSqrRtFound,
			                      unsigned int uiSquareRootTgt,
			                      unsigned int uiLowerBound,
			                      unsigned int uiUpperBound );

	bool bDoesLinkListLoopOnItself( Blmbrg_Common::CommonNode *  pHead,
		                            Blmbrg_Common::CommonNode ** pLinkBackFromNode,
			                        Blmbrg_Common::CommonNode ** pLinkBackToNode );

	bool FindClosestInArrayThatSum( int *        RandomNumAry,
			                        int          iSummationVal,
			                        unsigned int uiNumAryElmnts,
			                        int &        iFirstValue,
			                        int &        iFirstValueIdx,
			                        int &        iSecondValue,
			                        int &        iSecondValueIdx );
	bool FindSquareRoot( unsigned int uiSquareRootTgt,
			             unsigned int & uiSquareRootRangeBottom,
			             unsigned int & uiSquareRootRangeTop );

	void ReverseLastNodesOfSinglyLinkedList(Blmbrg_Common::CommonNode ** pHead,
			                                unsigned int uiNumberOnEndToReverse);

	void ReverseSinglyLinkedList(Blmbrg_Common::CommonNode ** pHead);

};




#endif /* BEN_SOLUTIONS_H_ */
