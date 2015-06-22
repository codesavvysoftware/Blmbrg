//============================================================================
// Name        : Blmbrg_Main
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Main for calling the solutions.
//============================================================================

#include "Blmbrg_Solutions.h"

int main() {
	/*
	***** Solution ******
		2.  Given the root node to a singly linked list, reverse the last 5
			nodes in the list.  For a list with 5 or less nodes, reverse the whole list.
	*/
    ProblemSolutions::ReverseLastFiveItemsInList();

	/*
	***** Solution ******
		3.  Given the root node to a singly linked list, write an algorithm to
			detect if there is a loop in the list.
	*/
    ProblemSolutions::DetectLoopInListSolution();


	/*
	***** Solution ******
	5. Give an array of random integers.  Write an algorithm to find the
	the closest 2 integers (closest by position) in the array that add up to 100.
	*/
	ProblemSolutions::FindTwoClosestRandomIntsInArray();

	return 0;
}
