#include "../head/duLinkedList.h"
#include "duLinkedList.c"
#include<stdio.h>

int main(){
	DuLinkedList L = NULL;
	ElemType e,x;
	int i,n,k;
	menu();
	do{
		printf("������ָ�");
		i = select();
		switch(i){
			case 1:
				L = InitList_DuL(L);
				break;
			case 2:
				printf("������Ԫ�ظ�����");
				n = select();
				CreatList_DuL(L,n);
				break;
			case 3:
				DestroyList_DuL(&L);
				break;
			case 4:
				printf("������Ҫ�����ĸ�Ԫ��ǰ�棺");
				e = select();
				printf("����������Ԫ�أ�");
				x = select(); 
				k = InsertBeforeList_DuL(&L, e, x);
				printf("%d\n",k);
				tip();
				break;
			case 5:
				printf("������Ҫ�����ĸ�Ԫ�غ��棺");
				e = select();
				printf("����������Ԫ�أ�");
				x = select();
				k = InsertAfterList_DuL(&L, e, x);
				printf("%d\n",k);
				tip();
				break;
			case 6:
				printf("����ɾ�������֣�");
				e = select();
				k = DeleteList_DuL(&L, e);
				printf("%d\n",k);
				tip();
				break;
			case 7:
				TraverseList_DuL(L);
				break;
			case 0:
				break;
			default:
				printf("\n��������,��������\n");
		}
	}while(i != 0);
	return 0;
} 
