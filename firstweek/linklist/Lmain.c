#include "../head/linkedList.h"
#include "linkedList.c"
#include<stdio.h>


int main(){
	
	LinkedList L = NULL;
	ElemType e;
	int i,n;
	do{
		menu();
		printf("\n请输入指令：");
		i = select();
		switch(i){
			case 1:
				if(L != NULL){
					printf("已初始化\n");
					break;
				}
				L = InitList(L);
				break;
			case 2:
				printf("输入节点个数：");
				n = select();
				CreateList(L, n);
				break;
			case 3:
				DestroyList(&L);
				break;
			case 4:
				printf("输入插入位置：");
				n = select();
				printf("\n输入插入数字：");
				e = select();
				InsertList(L, n, e);
				break;
			case 5:
				printf("输入删除的数字：");
				e = select();
				DeleteList(L, e);
				break;
			case 6:
				TraverseList(L); 
				break;
			case 7:
				printf("输入查找的数字：");
				e = select();
				if(L == NULL){
					printf("\n无初始化\n");
					break;
				}
				if(L->next == NULL){
					printf("\n未创建\n");
					break;
				}
				n = SearchList(L, e);
				if(n == 0){
					printf("No Find!\n");
				}
				else{
					printf("\n位置在第%d位\n",n);
				}
				break;
			case 8:
				if(L == NULL){
					printf("无初始化\n");
					break;
				}
				if(L->next == NULL){
					printf("未创建\n");
					break;
				}
				L = ReverseList(L);
				TraverseList(L);
				break;
			case 9:
				if(L == NULL){
					printf("无初始化\n");
					break;
				}
				if(L->next == NULL){
					printf("未创建\n");
					break;
				}
				printf("%d\n",IsLoopList(L));
				printf("**tip:  0-无环   1-有环**\n");
				break;		
			case 0:
				printf("已结束\n");
				break; 
			default:
				printf("\n输入有误,重新输入\n");
		}
		printf("\n\n");
		if(i != 0){
			system("pause");  //暂停
			system("cls");  //清屏
		} 
	}while(i != 0);
	return 0;
} 
	
