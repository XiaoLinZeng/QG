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

// 初始化栈
Status initLStack(LinkStack *s)
{
    LinkStackPtr L;
    L = (LinkStackPtr)malloc(sizeof(StackNode));
    L->data = NULL;
    L->next = NULL;
    s->top = L;   // 栈顶指向表头
    s->count = 0; // 栈内元素初始化为零
    return SUCCESS;
}

// 判断栈是否为空
Status isEmptyLStack(LinkStack *s)
{
    if (s->count == 0)
        return SUCCESS; // 表明栈为空
    return ERROR;
}

// 得到栈顶元素
Status getTopLStack(LinkStack *s, ElemType *e)
{
    if (s->count == 0) // 该栈内元素为零，说明为空栈，无栈顶元素
        return ERROR;

    // e是一个int型指针，对e数据域赋值，即取得栈顶元素值
    *e = s->top->data;
    return SUCCESS;
}

// 清空栈
Status clearLStack(LinkStack *s)
{
    // 该栈本身即为空，无需清空
    if (s->count == 0)
        return ERROR;

    int i;
    for (i = s->count; i > 0; i--) // 从栈顶依次遍历
        popLStack(s, &(s->data));  // 依次出栈
    return SUCCESS;
}

// 销毁栈
Status destroyLStack(LinkStack *s)
{
    if (s->count == 0)
        return ERROR; // 空栈返回ERROR值

    LinkStackPtr p = s->top;
    while (p != NULL)
    {
        free(p);               // 释放内存空间
        s->top = s->top->next; // 更新栈顶位置
        p = s->top;
        s->count--; // 更新栈的长度
    }
    return SUCCESS;
}

// 检测栈长度
Status LStackLength(LinkStack *s, int *length)
{
    *length = s->count; // 栈的长度即为s->count
    return SUCCESS;
}

// 入栈
Status pushLStack(LinkStack *s, ElemType data)
{
    LinkStackPtr p;
    p = (LinkStackPtr)malloc(sizeof(StackNode)); // 申请一块新的内存空间

    if (p == NULL)
        return ERROR; // 申请失败，返回ERROR

    p->next = s->top;
    p->data = data;
    s->top = p; // 更新栈顶
    s->count++; // 更新栈的长度
}

// 出栈
Status popLStack(LinkStack *s, ElemType *data)
{
    if (s->count == 0) // 空栈，返回ERROR
        return ERROR;

    *data = s->top->data; // 取出栈顶元素的值
    LinkStackPtr p;
    p = s->top;
    free(p);               // 释放内存空间，避免内存泄漏
    s->top = s->top->next; // 跳过原栈顶指向下一元素
    s->count--;            // 更新栈的长度
    return SUCCESS;
}