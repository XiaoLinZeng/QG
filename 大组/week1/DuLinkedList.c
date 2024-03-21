/***************************************************************************************
 *	File Name				:	duLinkedList.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2020.3.28
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

/**************************************************************
 *	Multi-Include-Prevent Section
 **************************************************************/

#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

/**************************************************************
 *	Macro Define Section
 **************************************************************/

#define OVERFLOW -1

/**************************************************************
 *	Struct Define Section
 **************************************************************/

#include <stdio.h>
#include <stdlib.h>

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct DuLNode
{
	ElemType data;
	struct DuLNode *prior, *next;
} DuLNode, *DuLinkedList;

// define status
typedef enum Status
{
	ERROR,
	SUCCESS
} Status;

/**************************************************************
 *	Prototype Declare Section
 **************************************************************/

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLNode *L);
Status InitList_DuL(DuLNode *L)
{
	L = (DuLNode *)malloc(sizeof(DuLNode));
	L->data = '\0';
	L->next = NULL;
	L->prior = NULL;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLNode *L);
void DestroyList_DuL(DuLNode *L)
{
	DuLNode *p, *q;
	p = L;
	if (p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q);
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{
	q = (DuLNode *)malloc(sizeof(DuLNode));
	q->prior = p->prior->next;
	p->prior->next = q->prior;
	p->prior = q->next;
	q->next = p->prior;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q);
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
	q = (DuLNode *)malloc(sizeof(DuLNode));
	q->next = p->next->prior;
	p->next = q->prior;
	q->prior = p->next;
	p->next->prior = q->next;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e, DuLNode *L);
Status DeleteList_DuL(DuLNode *p, ElemType *e, DuLNode *L)
{
	p->next->data = *e;
	p->next->next->prior = p->next;
	p->next = p->next->next;
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e));
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	DuLinkedList temp = L;
	while (temp != NULL)
		temp = temp->next;
}

/**************************************************************
 *	End-Multi-Include-Prevent Section
 **************************************************************/
#endif
