#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
int main() {
	int x = 0;
	int k = 0;
	LinkList L;
	init(L);
	printf("��ѡ����Ĳ���:\n1.ͷ�巨��������  2.β�巨��������  3.�����������\n");
	printf("4.������ֵ����  5.������λ����  6.�������ѯ��\n");
	printf("7.�������������(ǰ��)  8.��������  9.������ɾ��  10.�˳�����\n");
		int e = 0;
		int i = 0;
		while (1) {
			scanf("%d", &x);
			if (x == 1) { Head_insert(L); }		
			else if (x == 2) { Tail_Insert(L); }
			else if (x != 1 && x != 2) { printf("���ȴ�������\n"); continue; }//continue��������������ѭ��
			while (1) {
				printf("���ٴ���������ţ�\n");
				scanf("%d", &k);
				if (k == 1 || k == 2) {
					printf("�������´�����������������ţ�\n");
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
						printf("������Ҫ���ҵ�ֵ��\n");
						scanf("%d", &e);
						printf("�ҵ���λ���ǵ�%d�����\n", Locatelem(L, e));
						break;
					case 5:
						printf("������Ҫ���ҵ�λ�ã�\n");
						scanf("%d", &i);
						printf("�鵽��ֵΪ%d\n", GetElem(L, i));
						break;
					case 6:
						printf("%d", Length(L));
						break;
					case 7:
						printf("������Ҫ�����ֵ��\n");
						scanf("%d", &e);
						printf("������Ҫ�����λ�ã�\n");
						scanf("%d", &i);
						Insert(L, i, e);
						break;
					case 8:
						Reverse(L);
						break;
					case 9:
						printf("��������Ҫɾ���Ľ��λ��:\n");
						scanf("%d", &i);
						printf("�����ɾ����ɾ���Ľ������Ԫ��Ϊ%d\n", Delet(L, i));
						break;
					case 10:
						exit(0);
						break;
					}
				}
			}
		}



}
