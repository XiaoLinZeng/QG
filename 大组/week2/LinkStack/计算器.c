#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //isdigit函数

typedef struct
{
    double *data; // 数组指针
    int top;      // 栈顶指针
    int length;   // 栈长
} Stack;

// 初始化栈
void initStack(Stack *s, int length)
{
    s->data = (double *)malloc(sizeof(double) * length); // 分配数组内存
    s->top = -1;                                         // 初始化栈顶位置
    s->length = length;                                  // 初始化栈长
}

// 判断栈是否为空
int IsEmpty(Stack *s)
{
    if (s->top == -1) // 栈顶仍为初始化后状态,为空
        return 1;
    return 0;
}

// 判断栈是否为满
int IsFull(Stack *s)
{
    if (s->top == s->length - 1) // 已满
        return 1;
    return 0;
}

// 入栈
void push(Stack *s, double data)
{
    if (IsFull(s)) // 检查栈是否为满
    {
        printf("Stack is full\n");
        exit(1); // 栈已满则退出
    }
    s->length++; // 栈长加1
    s->top++;    // 栈顶指针加1
    s->data[s->top] = data;
}

// 出栈
double pop(Stack *s) // 返回出栈元素的值
{
    if (IsEmpty(s))
    {
        printf("Stack is empty\n");
        exit(1);
    }
    s->length--;
    double data = s->data[s->top]; // 先储存出栈元素的值
    s->top--;                      // 更新栈顶位置
    return data;
}

// 得到栈顶元素
double GetTop(Stack *s)
{
    if (IsEmpty(s))
    {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->data[s->top];
}

// 判断是否为运算符
int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

// 比较运算符优先级
int ComparePriority(char c)
{
    switch (c)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2; // 数字越大优先级越高
    case '/':
        return 2;
    default:
        return 0;
    }
}

// 定义运算规则
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

// 计算后缀表达式
double calculate(char *suffix)
{
    Stack s;
    initStack(&s, 100); // 初始化栈
    char *p = suffix;   // 指针遍历后缀表达式
    while (*p != 0)
    {
        if (isdigit(*p))
        {
            double n = *p - '0'; // 将字符转换为数字
            p++;     // 指针后移
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
            push(&s, n); // 数字入栈
        }
        else if (isOperator(*p)) // 是运算符
        {
            // 依次弹出两个栈内的数，第二次弹出的数为第一个操作数
            double y = pop(&s); // 第一次弹出第二个操作数
            double x = pop(&s); // 第二次弹出第一个操作数
            // 将弹出的两个数作相应运算，得出结果压入栈中
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

// 将中缀表达式转换为后缀表达式
void convert(char *infix, char *suffix)
{
    Stack s;
    initStack(&s, 100); // 初始化栈
    // 定义两个指针分别遍历中缀和后缀表达式
    char *p = infix, *q = suffix;
    while (*p != 0)
    {
        if (isdigit(*p)) // 是数字
        {
            while (isdigit(*p) || *p == '.')
            {
                *q = *p; // 当前位置是数字则直接输出到后缀表达式中
                p++;
                q++;
            }
            *q = ' '; // 后缀表达式各项间用空格隔开
            q++;      // 更新指针位置
        }
        else if (isOperator(*p))
        {
            int rank = ComparePriority(*p); // 获取当前运算符优先级
            // 栈为非空          且栈顶为运算符                比较 栈顶运算符优先级大于等于当前运算符
            while (!IsEmpty(&s) && isOperator(GetTop(&s)) && ComparePriority(GetTop(&s) >= rank))
            {
                // 弹出栈顶运算符，用变量进行接收
                char c = pop(&s);
                // 将弹出的运算符输出到后缀表达式
                *q = c;
                q++; // 更新q指针
                *q = ' ';
                q++;
            }
            // 栈顶不是运算符 或 栈顶运算符优先级低于当前运算符时,直接将当前运算符压入栈
            push(&s, *p);
            p++;
        }
        else if (*p == '(') // 当前为左括号时入栈
        {
            push(&s, *p);
            p++;
        }
        else if (*p == ')')
        {
            // 将栈内元素不断弹出，直至遇到左括号
            do
            {
                char c = pop(&s); // 将弹出的元素输入后缀表达式
                *q=c;
				q++;
                *q = ' ';
                q++;
            } while (!IsEmpty(&s) && *p != '(');
            // 弹出完毕后，栈顶为左括号，继续将其弹出并丢弃
            if (GetTop(&s) == '(')
                pop(&s);
        }
        else // 其他情况直接跳过
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
    *(q - 1) = '\0'; // 对后缀表达式添加结束符
}

int main()
{
    char infix[100], suffix[100];
    printf("请输入一个正确的表达式：\n");
    scanf("%s, infix");
    convert(infix, suffix); // 将中缀表达式转换为后缀表达式
    printf("计算结果为：%lf\n", calculate(suffix));
}
