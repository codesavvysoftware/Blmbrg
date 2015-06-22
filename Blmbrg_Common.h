/*
 * Blmbrg_Common.h
 *
 *  Created on: Jun 22, 2015
 *      Author: tomh
 */

#ifndef BLMBRG_COMMON_H_
#define BLMBRG_COMMON_H_
#include <stdlib.h>
#include <array>
#include <memory>
#include <algorithm>
#include <iostream>
namespace Blmbrg_Common {

	typedef struct _CommonNode CommonNode;

	typedef struct _CommonNode {
		int         iNodeData;
		CommonNode  *cnNext;
		CommonNode  *cnPrev;
	};

	bool CreateArrayOfRandomIntegers( std::unique_ptr<int> & randNumAry, unsigned int uiNumberOfArrayElements);
	bool CreateLoopingLinkedList( unsigned int uiTotalNumberOfNodes,
			                      unsigned int uiLinkBackFromNode,
			                      unsigned int uiLinkBackToNode,
			                      CommonNode ** pHead );
	bool CreateSinglyLinkedList( unsigned int uiTotalNumberOfNodes, CommonNode ** pHead );
	void DestroyLinkedList( CommonNode * pHead );
	void DisplayNode( CommonNode * pNode );
};
#endif /* BLMBRG_COMMON_H_ */
