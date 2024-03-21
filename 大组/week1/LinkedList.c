/***************************************************************************************
 *	File Name				:	linkedList.h
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
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

/**************************************************************
 *	Macro Define Section
 **************************************************************/

#define OVERFLOW -1

/**************************************************************
 *	Struct Define Section
 **************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkedList;

// define Status
typedef enum Status
{
    ERROR,
    SUCCESS
} Status;

#include <stdio.h>
#include <stdlib.h>

/**************************************************************
 *	Prototype Declare Section
 **************************************************************/

/**
 *  @name        : Status InitList(LinkedList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LNode *L);
Status InitList(LNode *L)
{
    L = (LNode *)malloc(sizeof(LNode));
    L->data = '\0'; // 头节点数据域为空
    L->next = NULL;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LNode *L);
void DestroyList(LNode *L)
{
    LNode *temp = L;
    while (temp != NULL)
    {
        temp = L;    // 指向表头
        L = L->next; // 头指针指向首元结点的后一个结点
        free(temp);  // 释放原来的首元结点
    }
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q);
Status InsertList(LNode *p, LNode *q)
{
    q = (LNode *)malloc(sizeof(LNode));
    q->next = p->next; // q的指针域指向原来p所指
    p->next = q;       // p的指针域指向q
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e);
Status DeleteList(LNode *p, ElemType *e)
{
    p->next->data = *e;      // 给目标节点的数据域赋值
    p->next = p->next->next; // p的指针域越过下一个结点直接指向再后一个结点
    return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e));
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
    LinkedList temp, p;
    p = L->next = NULL;
    L->next = NULL;
    temp = NULL;

    while (p != NULL)
    {
        temp = p->next;
        p->next = L->next;
        L->next = p;
        p = temp;
        (*visit)(p->data);
    }
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LNode *L, ElemType e);
Status SearchList(LNode *L, ElemType e)
{
    LNode *temp = L;
    while (temp != NULL)
    {
        if (temp->data == e)
        {
            L = temp;
            return SUCCESS;
        }
        temp = temp->next;
    }
    return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LNode *L);
Status ReverseList(LNode *L)
{
    LNode *temp, *head;
    temp->next = NULL;
    head->next = NULL;

    /*
        类似头插法建立新链表进而反转链表
        每次都断开链表头，再以头插法的方式将其用头插法插入
    */

    while (head != NULL)
    {
        temp = L;
        L = L->next;
        temp->next = head;
        head = temp;
    }
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L); // 检测中文乱码
Status IsLoopList(LinkedList L)
{
    LinkedList fast = L, last = L; // ????????????????
    if (L == NULL)
        return ERROR; // ?????????????
    while (1)
    {
        fast = fast->next; // ????????????
        if (fast == NULL)
            return ERROR; // ???п??????????
        else if (fast == last)
            return SUCCESS; // ????????????????????????
        fast = fast->next;  // ????????????
        last = last->next;  // ??????????
    }
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */

// 目前还不是很有头绪
LNode *ReverseEvenList(LinkedList *L);
LNode *ReverseEvenList(LinkedList *L)
{
    LinkedList *p = L;
    while (p != NULL)
    {
    }
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode *FindMidNode(LinkedList L);
LNode *FindMidNode(LinkedList L)
{
    // 一个快指针，一个慢指针
    // 两个指针起始位置都在原点
    // 同时出发，快指针一次两步，慢指针一次一步
    // 当快指针走到链表尾部时，慢指针也到了中间节点位置
    LinkedList fast = L, slow = L;
    // 奇数个结点，fast到最后一个节点时，slow到正中间
    // 偶数个结点，slow到中间俩结点的前一个
    while (fast->next != NULL || fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
}

/**************************************************************
 *	End-Multi-Include-Prevent Section
 **************************************************************/
#endif
