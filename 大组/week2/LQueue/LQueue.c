#define LQUEUE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

// ��ʽ���нṹ
typedef struct node
{
    void *data;        // ������ָ��
    struct node *next; // ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node *front;   // ��ͷ
    Node *rear;    // ��β
    size_t length; // ���г���
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
    Node *p; // ������ʱָ��
    while (Q->front != NULL)
    {
        p = Q->front->next; // pָ���ͷ�ĺ�һ��Ԫ��
        free(Q->front);     // �ͷ�ԭ��ͷռ�õĿռ�
        Q->front = p;       // ���¶�ͷ��λ��
    }
}

Status IsEmptyLQueue(LQueue *Q)
{
    if (Q->length == 0) // ��ͷ�Ͷ�βָ����ͬ�����Ϊ��
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
        return FALSE;   // ����Ϊ�գ��޷�����
    Node *p = Q->front; // �µĽ�㱣���ͷ��㣬�Ա�����ͷ��ڴ�
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
    p = Q->front->next; // ָ���һ����Ч���
    while (p != NULL)   // ѭ�������һ��������
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
    // ��ʼ������
    LQueue *Q;
    int keydown;
    int num;

//    do
//    {
//        printf("==========�����в���===========\n");
//        printf("1.��ʼ��\n");
//        printf("2.����\n");
//        printf("3.�ж��Ƿ�Ϊ��\n");
//        printf("4.�õ���ͷԪ��\n");
//        printf("5.����г���\n");
//        printf("6.���\n");
//        printf("7.����\n");
//        printf("8.���\n");
//        printf("9.����\n");
//        printf("0.�˳�\n");
//        printf("=====================\n");
//        printf("����������ѡ��");
//        scanf("%d", &keydown);
//        int i;
//        switch (keydown)
//		{
//	
//		}
//	}while();
}
