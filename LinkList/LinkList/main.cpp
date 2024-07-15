#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
int main() {
	int x = 0;
	int k = 0;
	LinkList L;
	init(L);
	printf("请选择你的操作:\n1.头插法创建链表  2.尾插法创建链表  3.遍历输出链表\n");
	printf("4.单链表按值查找  5.单链表按位查找  6.单链表查询表长\n");
	printf("7.单链表遍历插入(前插)  8.单链表倒置  9.单链表删除  10.退出程序\n");
		int e = 0;
		int i = 0;
		while (1) {
			scanf("%d", &x);
			if (x == 1) { Head_insert(L); }		
			else if (x == 2) { Tail_Insert(L); }
			else if (x != 1 && x != 2) { printf("请先创建链表\n"); continue; }//continue作用是跳过本次循环
			while (1) {
				printf("请再次输入操作号：\n");
				scanf("%d", &k);
				if (k == 1 || k == 2) {
					printf("若想重新创表请重新输入操作号：\n");
					break;
				}
				else {
					switch (k)
					{
					case 1:break;
					case 2:break;
					case 3:
						ListVisit(L);
						break;
					case 4:
						printf("请输入要查找的值：\n");
						scanf("%d", &e);
						printf("找到的位置是第%d个结点\n", Locatelem(L, e));
						break;
					case 5:
						printf("请输入要查找的位置：\n");
						scanf("%d", &i);
						printf("查到的值为%d\n", GetElem(L, i));
						break;
					case 6:
						printf("%d", Length(L));
						break;
					case 7:
						printf("请输入要插入的值：\n");
						scanf("%d", &e);
						printf("请输入要插入的位置：\n");
						scanf("%d", &i);
						Insert(L, i, e);
						break;
					case 8:
						Reverse(L);
						break;
					case 9:
						printf("请输入想要删除的结点位置:\n");
						scanf("%d", &i);
						printf("结点已删除，删除的结点所含元素为%d\n", Delet(L, i));
						break;
					case 10:
						exit(0);
						break;
					}
				}
			}
		}



}
