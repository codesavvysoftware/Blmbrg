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
		4.  Write an algorithm to calculate the square root of a number.
	*/

    ProblemSolutions::FindSquareRootSolution();

	/*
	***** Solution ******
	5. Give an array of random integers.  Write an algorithm to find the
	the closest 2 integers (closest by position) in the array that add up to 100.
	*/
	ProblemSolutions::FindTwoClosestRandomIntsInArray();

	/*
	***** Solution ******
		6. Given an array of integers, write a method that returns an array of the same size where each
			index is the product of all integers except itself, ie given array {1,2,3,4} return {24,12,8,6}
			explicitly {2*3*4,1*3*4,1*2*4,1*2*3}.
	*/
	ProblemSolutions::ProduceArrayOfProductsOfElementsSolution();

	return 0;
}
