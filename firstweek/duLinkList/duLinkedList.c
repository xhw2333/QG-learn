#include "../head/duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>

//菜单 
void menu()
{
	printf("************目录******************\n");
	printf("******   1.初始化            *****\n");
	printf("******   2.创建链表          *****\n");
	printf("******   3.销毁链表          *****\n");
	printf("******   4.特定位置前插节点  *****\n");
	printf("******   5.特定位置后插节点  *****\n");
	printf("******   6.删除链表节点      *****\n");
	printf("******   7.遍历链表          *****\n");
	printf("******   0.结束              *****\n"); 
	printf("**********************************\n");
}

void tip(){
	printf("******************\n");
	printf("**   0 -- 失败  **\n");
	printf("**   1 -- 成功  **\n");
	printf("******************\n");
}
//一个函数，防止乱输 
int select(){ 
	int num;
	while((scanf("%d",&num)) != 1){
		printf("输入错误，请重新输入：");
		while(getchar()!='\n');		//清理输出流 
	}	
	return num;
} 

//初始化链表 
DuLinkedList InitList_DuL(DuLinkedList L) {
	L = (DuLinkedList)malloc(sizeof(DuLNode));
	if(!L){		
		printf("申请内存空间失败\n");
		return ERROR;
	}	
	L->next = NULL;
	L->prior = NULL;
	printf("初始化成功\n");
	return L;
}

//创建链表
DuLinkedList CreatList_DuL(DuLinkedList L,int n){
	
	int i;
	DuLNode *q,*p;
	p = q = NULL;
	p = L;
	if(L == NULL){
		printf("无初始化\n");
		return 0;
	}
	for(i = 1; i <= n; i++){
		q = (DuLinkedList)malloc(sizeof(DuLNode));
		if(!q)
		{
			return ERROR;
		}
		printf("请输入第%d个数据：",i);
		q->data =select();	
		q->prior = p;
		q->next = p->next;
		p->next = q;
		p = q; 
		
	}
	p->next = NULL;
//	q = p->next;
	return L;
	
}

//销毁链表 
void DestroyList_DuL(DuLinkedList *L) {
	DuLNode *p = NULL;
	if(*L == NULL){
		printf("无初始化\n");
		return ;
	}
	p = (*L)->next;
	while(p != NULL){
		*L = p->next;
		free(p);
		p = *L;
	}
	free(*L);
	*L = NULL;
	printf("已销毁\n");
} 

//在特定位置之前插入节点
Status InsertBeforeList_DuL(DuLinkedList *L,ElemType e, ElemType x) {
	
	DuLNode *p,*q;
	p = *L;
	if(*L == NULL){
		printf("无初始化\n");
		return ERROR;
	}
	while(p != NULL && p->data != e){
		p = p->next;
	}
	if(p == NULL && p->data != e){
		return ERROR;
	}
	q = (DuLinkedList)malloc(sizeof(DuLNode));
	q->data = x;
	q->next = p;
	q->prior = p->prior;
	p->prior->next = q;
	p->prior = q;
	return SUCCESS;
}

//在特定位置之后插入节点
Status InsertAfterList_DuL(DuLinkedList *L,ElemType e, ElemType x) {
	
	DuLNode *p, *q;
	p = *L;
	if(*L == NULL){
		printf("无初始化\n");
		return ERROR;
	}
	while(p != NULL && p->data !=e){
		p = p->next;
	}
	if(p == NULL && p->data != e){
		return ERROR;
	}
	q = (DuLinkedList)malloc(sizeof(DuLNode));
	q->data = x;
	q->next = p->next;
	q->prior = p;
	p->next->prior = q;
	p->next = q;
	return SUCCESS;
}


//删除链表节点 
Status DeleteList_DuL(DuLinkedList *L, ElemType e) {
	
	DuLNode *p, *q;
	p = q = NULL;
	p = *L;
	if(*L == NULL){
		printf("无初始化\n");
		return ERROR;
	}
	if((*L)->next == NULL){
		printf("未创建\n");
		return ERROR;
	}
	while(p != NULL && p->data != e){
		q = p;
		p = p->next;
	}
	if(p == NULL || p->data != e){
		return ERROR;
	}
	//删除最后一个节点 
	if(p->next == NULL){
		q->next = NULL;
		free(p);
		return SUCCESS;
	}
	q->next = p->next;
	p->next->prior = q;
	free(p); 
	return SUCCESS;
}

//遍历链表 
void TraverseList_DuL(DuLinkedList L) {
	DuLNode *p, *q;
	q = p = NULL;
	if(L == NULL){
		printf("无初始化\n");
		return;
	}
	if(L->next == NULL){
		printf("未创建\n");
		return ;
	}
	p = L->next;
	printf("正向："); 
	while(p != NULL){
		printf("%d ",p->data);
		q = p;
		p = p->next;
	}
	printf("\n反向：");
	while(q->prior != NULL){
		printf("%d ",q->data);
		q = q->prior;
	}
	printf("\n");
}
