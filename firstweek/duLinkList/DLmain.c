#include "../head/duLinkedList.h"
#include "duLinkedList.c"
#include<stdio.h>

int main(){
	DuLinkedList L = NULL;
	ElemType e,x;
	int i,n,k;
	menu();
	do{
		printf("请输入指令：");
		i = select();
		switch(i){
			case 1:
				L = InitList_DuL(L);
				break;
			case 2:
				printf("请输入元素个数：");
				n = select();
				CreatList_DuL(L,n);
				break;
			case 3:
				DestroyList_DuL(&L);
				break;
			case 4:
				printf("请输入要插在哪个元素前面：");
				e = select();
				printf("请输入插入的元素：");
				x = select(); 
				k = InsertBeforeList_DuL(&L, e, x);
				printf("%d\n",k);
				tip();
				break;
			case 5:
				printf("请输入要插在哪个元素后面：");
				e = select();
				printf("请输入插入的元素：");
				x = select();
				k = InsertAfterList_DuL(&L, e, x);
				printf("%d\n",k);
				tip();
				break;
			case 6:
				printf("输入删除的数字：");
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
				printf("\n输入有误,重新输入\n");
		}
	}while(i != 0);
	return 0;
} 
