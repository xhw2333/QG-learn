#include "../head/linkedList.h"
#include "linkedList.c"
#include<stdio.h>


int main(){
	
	LinkedList L = NULL;
	ElemType e;
	int i,n;
	do{
		menu();
		printf("\n������ָ�");
		i = select();
		switch(i){
			case 1:
				if(L != NULL){
					printf("�ѳ�ʼ��\n");
					break;
				}
				L = InitList(L);
				break;
			case 2:
				printf("����ڵ������");
				n = select();
				CreateList(L, n);
				break;
			case 3:
				DestroyList(&L);
				break;
			case 4:
				printf("�������λ�ã�");
				n = select();
				printf("\n����������֣�");
				e = select();
				InsertList(L, n, e);
				break;
			case 5:
				printf("����ɾ�������֣�");
				e = select();
				DeleteList(L, e);
				break;
			case 6:
				TraverseList(L); 
				break;
			case 7:
				printf("������ҵ����֣�");
				e = select();
				if(L == NULL){
					printf("\n�޳�ʼ��\n");
					break;
				}
				if(L->next == NULL){
					printf("\nδ����\n");
					break;
				}
				n = SearchList(L, e);
				if(n == 0){
					printf("No Find!\n");
				}
				else{
					printf("\nλ���ڵ�%dλ\n",n);
				}
				break;
			case 8:
				if(L == NULL){
					printf("�޳�ʼ��\n");
					break;
				}
				if(L->next == NULL){
					printf("δ����\n");
					break;
				}
				L = ReverseList(L);
				TraverseList(L);
				break;
			case 9:
				if(L == NULL){
					printf("�޳�ʼ��\n");
					break;
				}
				if(L->next == NULL){
					printf("δ����\n");
					break;
				}
				printf("%d\n",IsLoopList(L));
				printf("**tip:  0-�޻�   1-�л�**\n");
				break;		
			case 0:
				printf("�ѽ���\n");
				break; 
			default:
				printf("\n��������,��������\n");
		}
		printf("\n\n");
		if(i != 0){
			system("pause");  //��ͣ
			system("cls");  //����
		} 
	}while(i != 0);
	return 0;
} 
	
