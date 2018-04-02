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

int randomNum();
Status printLNode(LinkList &L);
Status initList(LinkList &L, int n, char ch);
Status outList(LinkList &L, int m);

int main()
{
    int n = 0, m = 0;
    char ch;
    LinkList L;

    printf("请输入n的值：");
    scanf("%d", &n);
    fflush(stdin);
    printf("是否要手动输入密码？(Y/N)");
    scanf("%c", &ch);
    fflush(stdin);
    if (!initList(L, n, ch))
    {
        printf("初始化错误！");
        getchar();
        exit(0);
    }
    printLNode(L);
    printf("请输入m的值：");
    scanf("%d", &m);
    if (!outList(L, m))
    {
        printf("出队错误！");
        getchar();
        exit(0);
    }
    getchar();
    getchar();
    getchar();
    return OK;
}

Status initList(LinkList &L, int n, char ch)
{
    int data;
    L = (LinkList)malloc(sizeof(LNode));
    if (L == NULL)
    {
        printf("错误");
        return ERROR;
    }
    LinkList p = L;
    if (ch == 'Y' || ch == 'y')
    {
        printf("请输入密码：");
        for (size_t i = 0; i < n; i++)
        {
            scanf("%d", &data);
            p->data = data;
            printf("你输入的是%d\n", p->data);
            p->Next = (LinkList)malloc(sizeof(LNode));
            if (i == n - 1)
            {
                p->Next = L;
                break;
            }
            p = p->Next;
        }
    }
    else
    {
        srand(time(NULL));
        for (size_t i = 0; i < n; i++)
        {
            p->data = randomNum();
            printf("随机生成的数字是%d\n", p->data);
            p->Next = (LinkList)malloc(sizeof(LNode));
            if (i == n - 1)
            {
                p->Next = L;
                break;
            }
            p = p->Next;
        }
    }
    return OK;
}

Status printLNode(LinkList &L)
{
    LinkList p = L;

    for (int i = 0;; i++)
    {
        printf("这是第%d个元素，它的值为%d.\n", i + 1, p->data);

        if (p->Next == L)
            break;
        p = p->Next;
    }
    return OK;
}

int randomNum()
{
    int number;
    number = rand() % 10 + 1; //产生0-10的随机数
    // printf("%d ", number);
    return number;
}

Status outList(LinkList &L, int m)
{
    LinkList _out = L, _pre = L;
    int data;
    if (_out == _out->Next)
    {
        printf("最后一个出队的元素为%d", _out->data);
        return OK;
    }
    for (size_t i = 0; i < m - 1; i++)
    {
        _out = _out->Next;
    }
    printf("出队的元素为%d\n", _out->data);
    for (size_t i = 0;; i++)
    {
        if (_pre->Next == _out)
            break;
        _pre = _pre->Next; 
    }
    _pre->Next = _out->Next;
    data = _out->data;
    if (L==_out)
    {
        L = _out->Next;
    }
    free(_out);
    outList(L, data);
    return OK;
}