#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

typedef int ElemType;

typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;
// struct StackNode =StackNode
// LinkStackPtr = struct StackNode* = StackNode*

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
} LinkStack;
// Struct LinkStack = LinkStack

// ��ʼ��ջ
Status initLStack(LinkStack *s)
{
    LinkStackPtr L;
    L = (LinkStackPtr)malloc(sizeof(StackNode));
    L->data = NULL;
    L->next = NULL;
    s->top = L;   // ջ��ָ���ͷ
    s->count = 0; // ջ��Ԫ�س�ʼ��Ϊ��
    return SUCCESS;
}

// �ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s)
{
    if (s->count == 0)
        return SUCCESS; // ����ջΪ��
    return ERROR;
}

// �õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s, ElemType *e)
{
    if (s->count == 0) // ��ջ��Ԫ��Ϊ�㣬˵��Ϊ��ջ����ջ��Ԫ��
        return ERROR;

    // e��һ��int��ָ�룬��e������ֵ����ȡ��ջ��Ԫ��ֵ
    *e = s->top->data;
    return SUCCESS;
}

// ���ջ
Status clearLStack(LinkStack *s)
{
    // ��ջ����Ϊ�գ��������
    if (s->count == 0)
        return ERROR;

    int i;
    for (i = s->count; i > 0; i--) // ��ջ�����α���
        popLStack(s, &(s->data));  // ���γ�ջ
    return SUCCESS;
}

// ����ջ
Status destroyLStack(LinkStack *s)
{
    if (s->count == 0)
        return ERROR; // ��ջ����ERRORֵ

    LinkStackPtr p = s->top;
    while (p != NULL)
    {
        free(p);               // �ͷ��ڴ�ռ�
        s->top = s->top->next; // ����ջ��λ��
        p = s->top;
        s->count--; // ����ջ�ĳ���
    }
    return SUCCESS;
}

// ���ջ����
Status LStackLength(LinkStack *s, int *length)
{
    *length = s->count; // ջ�ĳ��ȼ�Ϊs->count
    return SUCCESS;
}

// ��ջ
Status pushLStack(LinkStack *s, ElemType data)
{
    LinkStackPtr p;
    p = (LinkStackPtr)malloc(sizeof(StackNode)); // ����һ���µ��ڴ�ռ�

    if (p == NULL)
        return ERROR; // ����ʧ�ܣ�����ERROR

    p->next = s->top;
    p->data = data;
    s->top = p; // ����ջ��
    s->count++; // ����ջ�ĳ���
}

// ��ջ
Status popLStack(LinkStack *s, ElemType *data)
{
    if (s->count == 0) // ��ջ������ERROR
        return ERROR;

    *data = s->top->data; // ȡ��ջ��Ԫ�ص�ֵ
    LinkStackPtr p;
    p = s->top;
    free(p);               // �ͷ��ڴ�ռ䣬�����ڴ�й©
    s->top = s->top->next; // ����ԭջ��ָ����һԪ��
    s->count--;            // ����ջ�ĳ���
    return SUCCESS;
}