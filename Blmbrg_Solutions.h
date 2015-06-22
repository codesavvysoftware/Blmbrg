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
		5. Give an array of random integers.  Write an algorithm to find the
			the closest 2 integers (closest by position) in the array that add up to 100.
	*/
	void FindTwoClosestRandomIntsInArray();

	void ReverseLastNodesOfSinglyLinkedList(Blmbrg_Common::CommonNode ** pHead,
			                                unsigned int uiNumberOnEndToReverse);

	void ReverseSinglyLinkedList(Blmbrg_Common::CommonNode ** pHead);

	bool FindClosestInArrayThatSum( int *        RandomNumAry,
			                        int          iSummationVal,
			                        unsigned int uiNumAryElmnts,
			                        int &        iFirstValue,
			                        int &        iFirstValueIdx,
			                        int &        iSecondValue,
			                        int &        iSecondValueIdx );
	bool bDoesLinkListLoopOnItself( Blmbrg_Common::CommonNode *  pHead,
			                        Blmbrg_Common::CommonNode ** pLinkBackFromNode,
			                        Blmbrg_Common::CommonNode ** pLinkBackToNode );
};




#endif /* BEN_SOLUTIONS_H_ */
