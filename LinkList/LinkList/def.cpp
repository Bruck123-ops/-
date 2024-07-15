#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>
#include "Node.h"

//单链表初始化
void init(LinkList& L) {
	L = new LNode();
	L->data = 0;         //L是个指针"L->data"等价于"*L.data"
	L->next = NULL;
}
//头插法创建单链表
void Head_insert(LNode*& L) {
	init(L);
	int x;
	scanf("%d", &x);
	while (x != 9999) {
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = x;		s->next = L->next;
		L->next = s;      //s是个指针（地址），假设s=UFB7701，L->next=s就是说next指针域地址填UFB7701（即next指向s所指向的结点）
		scanf("%d", &x);
	}
}
//尾插法创建单链表	
void Tail_Insert(LNode*& L) {
	init(L);
	int x;
	scanf("%d", &x);
	LNode* r = L;
	while (x != 9999) {
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = NULL;
		r->next = s;
		r = s;					//s是指针，r也是指针，这里将s指向的结点的地址赋值给r，相当于r也指向该结点;
		scanf("%d", &x);
	}
}
//遍历输出单链表
void ListVisit(LinkList L) {
	LNode* p = L->next;
	for (; p!= NULL; p = p->next) {
		printf("%d->", p->data);
		
	}
	printf("NULL");

}
//单链表按值查找
int Locatelem(LinkList L, int e) {
	int m = 1;
	LNode* p;
	init(p);
	if (L == NULL)return 0;
	for (p = L->next; p != NULL; ++m) {
		if (p->data == e)return m;
		p=p->next;
	}
	return -1;					//什么都没找到返回-1
}
//单链表按位查找
int GetElem(LinkList L,int i) {
	int k=1;
	LNode* p;
	for ( p = L->next; k <i&&p!=NULL; p = p->next)
		++k;
	return p->data;

}
//单链表查询表长
int Length(LinkList L) {
	int k = 0;
	LNode* p;
	for (p = L->next; p != NULL; p = p->next)
		++k;
	return k;
}
//单链表遍历插入(前插)
bool Insert(LinkList L, int i, int e) {
	int k = 1;
	LNode* p;
	for (p = L->next; k < i - 1; p = p->next) {
		++k;
		if (p == NULL)return false;
	}
	LNode* s=(LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;

}
//单链表倒置
void Reverse(LinkList &L) {
	LNode* p=L->next ,*ppre = NULL, *pnext = NULL;	
	if (p == NULL || p->next == NULL)
		return;
	for (; p != NULL;p=pnext) {
		pnext = p->next;
		p->next = ppre;
		ppre = p;
	}
	L->next = ppre;
}
//单链表删除
LinkList Getelem(LinkList L, int i) {						//稍作修改让其返回第i个位置的前驱结点指针
	int k = 2;
	LNode* p;
	for (p = L->next; k < i && p != NULL; p = p->next)
		++k;
	return p;

} 

int Delet(LinkList& L,int i) {
	LNode* h = Getelem(L, i);
	if (h->next == NULL) return 0;
	LNode* q = h->next;					//用q先把要删结点标识出来，否则后面改了箭头后就找不到了，没法free
	int z = q->data;
	h->next = q->next;
	free(q);
	return z;
}