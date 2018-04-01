#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef struct LNode
{
    int data;
    struct LNode *Next;
} * LinkList;

volatile int randomNum();
Status printLNode(LinkList &L);
Status initList(LinkList &L, int n);
Status outList(LinkList &L, int m);

int main()
{
    int n = 0, m = 0;
    LinkList L;
    printf("请输入n的值：");
    scanf("%d", &n);
    initList(L, n);
    printLNode(L);
    printf("请输入m的值：");
    scanf("%d", &m);
    outList(L, m);
}

Status initList(LinkList &L, int n)
{
    LinkList p = L;
    p->data = randomNum();
    // p->Next = (LinkList)malloc(sizeof(LinkList));
    for (size_t i = 0; i < n-1; i++)
    {
        p->Next = (LinkList)malloc(sizeof(LNode));
        p = p->Next;
        p->data = randomNum();
    }
    p->Next = L;
    return OK;
}

Status printLNode(LinkList &L)
{
    LinkList p = L;

    for (int i = 0;; i++)
    {
        printf("这是第%d个元素，它的值为%d.\n", i, p->data);
        p = p->Next;
        if (p->Next == L)
            break;
    }
    return OK;
}

volatile int randomNum()
{
    int number;

    srand(time(0)); //用时间做种，每次产生随机数不一样
    number = rand() % 10 + 1; //产生0-10的随机数
    printf("%d ", number);

    return number;
}

Status outList(LinkList &L, int m)
{
    LinkList p = L,q=L;
    for (size_t i = 0; i < m; i++)
    {
        p = p->Next;
    }

    if (p == p->Next)
    {
        return OK;
    }
    outList(p, p->data);
}