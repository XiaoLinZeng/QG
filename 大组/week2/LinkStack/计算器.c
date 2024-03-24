#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //isdigit����

typedef struct
{
    double *data; // ����ָ��
    int top;      // ջ��ָ��
    int length;   // ջ��
} Stack;

// ��ʼ��ջ
void initStack(Stack *s, int length)
{
    s->data = (double *)malloc(sizeof(double) * length); // ���������ڴ�
    s->top = -1;                                         // ��ʼ��ջ��λ��
    s->length = length;                                  // ��ʼ��ջ��
}

// �ж�ջ�Ƿ�Ϊ��
int IsEmpty(Stack *s)
{
    if (s->top == -1) // ջ����Ϊ��ʼ����״̬,Ϊ��
        return 1;
    return 0;
}

// �ж�ջ�Ƿ�Ϊ��
int IsFull(Stack *s)
{
    if (s->top == s->length - 1) // ����
        return 1;
    return 0;
}

// ��ջ
void push(Stack *s, double data)
{
    if (IsFull(s)) // ���ջ�Ƿ�Ϊ��
    {
        printf("Stack is full\n");
        exit(1); // ջ�������˳�
    }
    s->length++; // ջ����1
    s->top++;    // ջ��ָ���1
    s->data[s->top] = data;
}

// ��ջ
double pop(Stack *s) // ���س�ջԪ�ص�ֵ
{
    if (IsEmpty(s))
    {
        printf("Stack is empty\n");
        exit(1);
    }
    s->length--;
    double data = s->data[s->top]; // �ȴ����ջԪ�ص�ֵ
    s->top--;                      // ����ջ��λ��
    return data;
}

// �õ�ջ��Ԫ��
double GetTop(Stack *s)
{
    if (IsEmpty(s))
    {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->data[s->top];
}

// �ж��Ƿ�Ϊ�����
int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

// �Ƚ���������ȼ�
int ComparePriority(char c)
{
    switch (c)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2; // ����Խ�����ȼ�Խ��
    case '/':
        return 2;
    default:
        return 0;
    }
}

// �����������
double DefineRule(char c, double x, double y)
{
    switch (c)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    default:
        printf("the operator is invalid\n");
        exit(1);
    }
}

// �����׺���ʽ
double calculate(char *suffix)
{
    Stack s;
    initStack(&s, 100); // ��ʼ��ջ
    char *p = suffix;   // ָ�������׺���ʽ
    while (*p != 0)
    {
        if (isdigit(*p))
        {
            double n = *p - '0'; // ���ַ�ת��Ϊ����
            p++;     // ָ�����
            while (isdigit(*p) || *p == '.')
            {
                if (*p == '.')
                {
                    p++;
                    double frac = 0.1;
                    while (isdigit(*p))
                    {
                        n += (*p - '0') * frac;
                        p++;
                        frac /= 10;
                    }
                    break;
                }
                else
                {
                    n = n * 10 + (*p - '0');
                    p++;
                }
            }
            push(&s, n); // ������ջ
        }
        else if (isOperator(*p)) // �������
        {
            // ���ε�������ջ�ڵ������ڶ��ε�������Ϊ��һ��������
            double y = pop(&s); // ��һ�ε����ڶ���������
            double x = pop(&s); // �ڶ��ε�����һ��������
            // ������������������Ӧ���㣬�ó����ѹ��ջ��
            double result = DefineRule(*p, x, y);
            push(&s, result);
            p++;
        }
        else
            p++;
    }
    double data=pop(&s);
    return data;
}

// ����׺���ʽת��Ϊ��׺���ʽ
void convert(char *infix, char *suffix)
{
    Stack s;
    initStack(&s, 100); // ��ʼ��ջ
    // ��������ָ��ֱ������׺�ͺ�׺���ʽ
    char *p = infix, *q = suffix;
    while (*p != 0)
    {
        if (isdigit(*p)) // ������
        {
            while (isdigit(*p) || *p == '.')
            {
                *q = *p; // ��ǰλ����������ֱ���������׺���ʽ��
                p++;
                q++;
            }
            *q = ' '; // ��׺���ʽ������ÿո����
            q++;      // ����ָ��λ��
        }
        else if (isOperator(*p))
        {
            int rank = ComparePriority(*p); // ��ȡ��ǰ��������ȼ�
            // ջΪ�ǿ�          ��ջ��Ϊ�����                �Ƚ� ջ����������ȼ����ڵ��ڵ�ǰ�����
            while (!IsEmpty(&s) && isOperator(GetTop(&s)) && ComparePriority(GetTop(&s) >= rank))
            {
                // ����ջ����������ñ������н���
                char c = pop(&s);
                // ��������������������׺���ʽ
                *q = c;
                q++; // ����qָ��
                *q = ' ';
                q++;
            }
            // ջ����������� �� ջ����������ȼ����ڵ�ǰ�����ʱ,ֱ�ӽ���ǰ�����ѹ��ջ
            push(&s, *p);
            p++;
        }
        else if (*p == '(') // ��ǰΪ������ʱ��ջ
        {
            push(&s, *p);
            p++;
        }
        else if (*p == ')')
        {
            // ��ջ��Ԫ�ز��ϵ�����ֱ������������
            do
            {
                char c = pop(&s); // ��������Ԫ�������׺���ʽ
                *q=c;
				q++;
                *q = ' ';
                q++;
            } while (!IsEmpty(&s) && *p != '(');
            // ������Ϻ�ջ��Ϊ�����ţ��������䵯��������
            if (GetTop(&s) == '(')
                pop(&s);
        }
        else // �������ֱ������
            p++;
    }
    while (!IsEmpty(&s))
    {
        char c = pop(&s);
        *q=c;
        q++;
        *q = ' ';
        q++;
    }
    *(q - 1) = '\0'; // �Ժ�׺���ʽ��ӽ�����
}

int main()
{
    char infix[100], suffix[100];
    printf("������һ����ȷ�ı��ʽ��\n");
    scanf("%s, infix");
    convert(infix, suffix); // ����׺���ʽת��Ϊ��׺���ʽ
    printf("������Ϊ��%lf\n", calculate(suffix));
}
