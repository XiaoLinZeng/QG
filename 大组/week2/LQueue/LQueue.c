#define LQUEUE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

// 链式队列结构
typedef struct node
{
    void *data;        // 数据域指针
    struct node *next; // 指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node *front;   // 队头
    Node *rear;    // 队尾
    size_t length; // 队列长度
} LQueue;

typedef enum
{
    FALSE = 0,
    TRUE = 1
} Status;

char type;
char datatype[30];

void InitLQueue(LQueue *Q)
{
    Q = (LQueue *)malloc(sizeof(LQueue));
    Q->front = Q->rear = NULL;
    Q->length = 0;
}

void DestoryLQueue(LQueue *Q)
{
    Node *p; // 定义临时指针
    while (Q->front != NULL)
    {
        p = Q->front->next; // p指向队头的后一个元素
        free(Q->front);     // 释放原队头占用的空间
        Q->front = p;       // 更新队头的位置
    }
}

Status IsEmptyLQueue(LQueue *Q)
{
    if (Q->length == 0) // 队头和队尾指向相同则队列为空
        return TRUE;
    return FALSE;
}

Status GetHeadLQueue(LQueue *Q, void *e)
{
    if (Q->front == Q->rear)
        return FALSE;
    e = Q->front->data;
    return TRUE;
}

int LengthLQueue(LQueue *Q)
{
    Node *p = NULL;
    p = Q->front;
    int len = 0;
    if (Q->front == Q->rear)
        return 1;
    while (p->next != NULL)
    {
        p = Q->front->next;
        len++;
    }
    return ++len;
}

Status EnLQueue(LQueue *Q, void *data)
{
    Node *NewNode = (Node *)malloc(sizeof(Node));
    if (NewNode == NULL)
        return FALSE;
    NewNode->data = data;
    NewNode->next = NULL;

    if (Q->length == 0)
        Q->front = Q->rear = NewNode;
    else
    {
        Q->rear->next = NewNode;
        Q->rear = NewNode;
        Q->length++;
    }
    return TRUE;
}

Status DeLQueue(LQueue *Q)
{
    if (Q->length == 0)
        return FALSE;   // 队列为空，无法出队
    Node *p = Q->front; // 新的结点保存队头结点，以便后续释放内存
    Q->front = Q->front->next;
    Q->length--;
    free(p);
    return TRUE;
}

void ClearLQueue(LQueue *Q)
{
    Q->front = Q->rear = NULL;
}

Status TraverseLQueue(LQueue *Q, void (*foo)(void *q)) //??
{
    if (LengthLQueue(Q) == 0)
        return FALSE;
    Node *p;
    p = Q->front->next; // 指向第一个有效结点
    while (p != NULL)   // 循环至最后一个结点结束
    {
        p = p->next;
    }
}

// void LPrint(void *q)
//{
//     Node *p =
// }

int main()
{
    // 初始化队列
    LQueue *Q;
    int keydown;
    int num;

//    do
//    {
//        printf("==========链队列操作===========\n");
//        printf("1.初始化\n");
//        printf("2.销毁\n");
//        printf("3.判断是否为空\n");
//        printf("4.得到队头元素\n");
//        printf("5.求队列长度\n");
//        printf("6.入队\n");
//        printf("7.出队\n");
//        printf("8.清空\n");
//        printf("9.遍历\n");
//        printf("0.退出\n");
//        printf("=====================\n");
//        printf("请输入您的选择：");
//        scanf("%d", &keydown);
//        int i;
//        switch (keydown)
//		{
//	
//		}
//	}while();
}
