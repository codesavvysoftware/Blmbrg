/*
 * Blmbrg_Common.cpp
 *
 *  Created on: Jun 22, 2015
 *      Author: tomh
 */
#include "Blmbrg_Common.h"

namespace Blmbrg_Common {
bool CreateArrayOfRandomIntegers( std::unique_ptr<int> & randNumAry, unsigned int uiNumberOfArrayElements) {
	if ( ( uiNumberOfArrayElements < 10 ) || ( uiNumberOfArrayElements > 10000) ) return false;

	int * pNewArray = new int[uiNumberOfArrayElements];

	for ( int i = 0; i < uiNumberOfArrayElements; i++ ) {
		pNewArray[i] = rand() % 100;
	}

    std::unique_ptr<int> temp(pNewArray);

    randNumAry.swap(temp);

    return true;
}

bool CreateLoopingLinkedList( unsigned int uiTotalNumberOfNodes,
		                      unsigned int uiLinkBackFromNode,
		                      unsigned int uiLinkBackToNode,
		                      CommonNode ** pHead ) {
	if (    ( !pHead )
		 || ( uiTotalNumberOfNodes < uiLinkBackFromNode )
		 || ( uiTotalNumberOfNodes > 10000)
		 || ( uiLinkBackToNode > uiLinkBackFromNode )
	   )
	{
		return false;
	}

	CommonNode * pNewHead = nullptr;

	unsigned int ui;

	CommonNode * pNewNode = nullptr;

	CommonNode * pLastNode = nullptr;

	CommonNode * pLinkBackToNode = nullptr;

	CommonNode * pLinkBackFromNode = nullptr;

	for (ui=0; ui< uiTotalNumberOfNodes; ui++) {
		pNewNode = new CommonNode;

		if (!pNewNode) {
			DestroyLinkedList(pNewHead);

			return false;
		}

		pNewNode->iNodeData = ui;

		if (!pNewHead) {
			pNewHead = pNewNode;
		}
		else if ( pLastNode != pLinkBackFromNode ) {
			pLastNode->cnNext = pNewNode;
		}
		else {
			// Just so it can be deallocated (Destroyed)
			pLastNode->cnPrev = pNewNode;
		}

		pNewNode->cnNext = nullptr;

		pLastNode = pNewNode;

		if ( ui == uiLinkBackToNode )
		{
			pLinkBackToNode = pNewNode;
		}
		if ( ui == uiLinkBackFromNode )
		{
			pLinkBackFromNode = pNewNode;

			pLinkBackFromNode->cnNext = pLinkBackToNode;
		}
	}

	*pHead = pNewHead;

	return true;
}
bool CreateSinglyLinkedList( unsigned int uiTotalNumberOfNodes,
		                     CommonNode ** pHead ) {
	if (    ( !pHead )
		 || ( uiTotalNumberOfNodes > 10000)
	   )
	{
		return false;
	}

	CommonNode * pNewHead = nullptr;

	unsigned int ui;

	CommonNode * pNewNode = nullptr;

	CommonNode * pLastNode = nullptr;

	for (ui=0; ui< uiTotalNumberOfNodes; ui++) {
		pNewNode = new CommonNode;

		if (!pNewNode) {
			DestroyLinkedList(pNewHead);

			return false;
		}

		pNewNode->iNodeData = ui;

		if (!pNewHead) {
			pNewHead = pNewNode;
		}
		else {
			pLastNode->cnNext = pNewNode;
		}

		pNewNode->cnNext = nullptr;

		pLastNode = pNewNode;
	}

	*pHead = pNewHead;

	return true;
}

void DestroyLinkedList( CommonNode * pHead ) {
	CommonNode * pNewNode;

	while(pHead) {
		pNewNode = pHead;

		pHead = pNewNode->cnNext;

		delete pNewNode;
	}
}

void DisplayNode( CommonNode * pNode ) {
	if ( pNode ) {
		std::cout << "Node Data: " << pNode->iNodeData << "   Next Node:  " << pNode->cnNext << std::endl;
	}
	else {
		std::cout << "Input Node is a null_ptr" << std::endl;
	}
}

};



