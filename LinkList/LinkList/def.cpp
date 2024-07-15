#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>
#include "Node.h"

//�������ʼ��
void init(LinkList& L) {
	L = new LNode();
	L->data = 0;         //L�Ǹ�ָ��"L->data"�ȼ���"*L.data"
	L->next = NULL;
}
//ͷ�巨����������
void Head_insert(LNode*& L) {
	init(L);
	int x;
	scanf("%d", &x);
	while (x != 9999) {
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = x;		s->next = L->next;
		L->next = s;      //s�Ǹ�ָ�루��ַ��������s=UFB7701��L->next=s����˵nextָ�����ַ��UFB7701����nextָ��s��ָ��Ľ�㣩
		scanf("%d", &x);
	}
}
//β�巨����������	
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
		r = s;					//s��ָ�룬rҲ��ָ�룬���ｫsָ��Ľ��ĵ�ַ��ֵ��r���൱��rҲָ��ý��;
		scanf("%d", &x);
	}
}
//�������������
void ListVisit(LinkList L) {
	LNode* p = L->next;
	for (; p!= NULL; p = p->next) {
		printf("%d->", p->data);
		
	}
	printf("NULL");

}
//������ֵ����
int Locatelem(LinkList L, int e) {
	int m = 1;
	LNode* p;
	init(p);
	if (L == NULL)return 0;
	for (p = L->next; p != NULL; ++m) {
		if (p->data == e)return m;
		p=p->next;
	}
	return -1;					//ʲô��û�ҵ�����-1
}
//������λ����
int GetElem(LinkList L,int i) {
	int k=1;
	LNode* p;
	for ( p = L->next; k <i&&p!=NULL; p = p->next)
		++k;
	return p->data;

}
//�������ѯ��
int Length(LinkList L) {
	int k = 0;
	LNode* p;
	for (p = L->next; p != NULL; p = p->next)
		++k;
	return k;
}
//�������������(ǰ��)
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
//��������
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
//������ɾ��
LinkList Getelem(LinkList L, int i) {						//�����޸����䷵�ص�i��λ�õ�ǰ�����ָ��
	int k = 2;
	LNode* p;
	for (p = L->next; k < i && p != NULL; p = p->next)
		++k;
	return p;

} 

int Delet(LinkList& L,int i) {
	LNode* h = Getelem(L, i);
	if (h->next == NULL) return 0;
	LNode* q = h->next;					//��q�Ȱ�Ҫɾ����ʶ���������������˼�ͷ����Ҳ����ˣ�û��free
	int z = q->data;
	h->next = q->next;
	free(q);
	return z;
}