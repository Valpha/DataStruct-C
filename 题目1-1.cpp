#include<stdio.h>
#include<stdlib.h>
#include<time.h> 

typedef struct LNode
{	
	int num;
	int data;
	struct LNode *next;
}LNode,*LinkList;

void CreatList(LinkList &L,int n)
{
	LNode *p;
	int i;
	L=(LinkList)malloc(sizeof(LNode));
	if(L==NULL)
	{
		printf("����");
		exit(0);
	}
	else
	{
		p=L;
		for(i=0;i<n-1;i++)
		{
			p->next=(LinkList)malloc(sizeof(LNode));
			p=p->next;
		}
		p->next=L;
	}
}

void NumList(LinkList &L,int n)
{
	LNode *p;
	int i,d,t=0;
	p=L;
	printf("�Ƿ�����������루1��\\0��:");
	scanf("%d",&t);
	for(i=0;i<n;i++)
	{
		if(t==0)
		{
			printf("���������룺");
			scanf("%d",&d);		
		}
		else
			d=rand()%10+1;
		p->data=d;
		p->num=i+1;
		p=p->next;
	}
}

void RunList(LinkList &L,int n,int m)
{
	LNode *p,*q,*f;
	int i,j,t,pass=m;
	p=L;
	printf("����˳��Ϊ��"); 
	for(i=0;i<n;i++)
	{	
		for(j=1;j<pass;j++)
			p=p->next;
		q=p;
		for(j=0;j<n-i-1;j++)
			q=q->next;
		printf("%d ",p->num);
		pass=p->data;
		q->next=p->next;
		f=p;
		p=p->next;
		free(f);		
	}	
}

int main()
{
	LNode *L,*p;
	int m,n,i;
	srand((unsigned)time(NULL));
	printf("����������n:");
	scanf("%d",&n);
	printf("�����뱨������m:");
	scanf("%d",&m);
	CreatList(L,n);
	NumList(L,n);
	RunList(L,n,m);	
}
