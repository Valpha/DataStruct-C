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

    printf("������n��ֵ��");
    scanf("%d", &n);
    fflush(stdin);
    printf("�Ƿ�Ҫ�ֶ��������룿(Y/N)");
    scanf("%c", &ch);
    fflush(stdin);
    if (!initList(L, n, ch))
    {
        printf("��ʼ������");
        getchar();
        exit(0);
    }
    printLNode(L);
    printf("������m��ֵ��");
    scanf("%d", &m);
    if (!outList(L, m))
    {
        printf("���Ӵ���");
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
        printf("����");
        return ERROR;
    }
    LinkList p = L;
    if (ch == 'Y' || ch == 'y')
    {
        printf("���������룺");
        for (size_t i = 0; i < n; i++)
        {
            scanf("%d", &data);
            p->data = data;
            printf("���������%d\n", p->data);
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
            printf("������ɵ�������%d\n", p->data);
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
        printf("���ǵ�%d��Ԫ�أ�����ֵΪ%d.\n", i + 1, p->data);

        if (p->Next == L)
            break;
        p = p->Next;
    }
    return OK;
}

int randomNum()
{
    int number;
    number = rand() % 10 + 1; //����0-10�������
    // printf("%d ", number);
    return number;
}

Status outList(LinkList &L, int m)
{
    LinkList _out = L, _pre = L;
    int data;
    if (_out == _out->Next)
    {
        printf("���һ�����ӵ�Ԫ��Ϊ%d", _out->data);
        return OK;
    }
    for (size_t i = 0; i < m - 1; i++)
    {
        _out = _out->Next;
    }
    printf("���ӵ�Ԫ��Ϊ%d\n", _out->data);
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