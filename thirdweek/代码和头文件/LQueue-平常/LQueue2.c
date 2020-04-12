#include "LQueue2.h" 
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 					
			

//菜单 
void menu()
{
	printf("*************目录********************\n");
	printf("******    1.初始化队列          *****\n");
	printf("******    2.销毁队列            *****\n");
	printf("******    3.检查队列是否为空    *****\n");
	printf("******    4.查看队头元素        *****\n");
	printf("******    5.确定队列长度        *****\n");
	printf("******    6.入队操作            *****\n");
	printf("******    7.出队操作            *****\n");
	printf("******    8.清空队列            *****\n");
	printf("******    9.遍历函数操作        *****\n");
	printf("******    0.结束                *****\n"); 
	printf("*************************************\n");
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

//初始化队列
void InitLQueue(LQueue **Q){
	
	(*Q) = (LQueue*)malloc(sizeof(LQueue));
	(*Q)->front = (Node*)malloc(sizeof(Node)); 
	if((*Q)->front == NULL){
		printf("申请内存空间失败\n");
		return;
	} 
	(*Q)->rear = (*Q)->front;
	(*Q)->front->next = NULL;
	printf("\n初始化成功\n");

}

//销毁队列
void DestoryLQueue(LQueue **Q){
	
	if((*Q) == NULL){
		printf("\n未初始化\n");
		return ;
	}
	free(*Q);
	*Q = NULL;
	printf("\n销毁成功\n"); 
}

//检查队列是否为空
Status IsEmptyLQueue(LQueue *Q){
	
	if(Q == NULL){
		printf("\n未初始化\n");
		return FALSE;
	}
	if(Q->front == Q->rear){
		printf("\n队列为空\n");
		return TRUE;
	}
	else{
		printf("\n队列不空\n"); 
		return FALSE;
	}
}

//查看队头元素
Status GetHeadLQueue(LQueue *Q, ElemType *e){
	
	if(Q == NULL){
		printf("\n未初始化\n");
		return FALSE;
	}
	if(Q->front == Q->rear){
		return FALSE;
	}
	*e = Q->front->next->data;
	return TRUE;
}

//确定队列长度
int LengthLQueue(LQueue *Q){
	
	if(Q == NULL){
		printf("\n未初始化\n");
		return -1;
	}
	int i = 0;
	Node *p = Q->front->next;
	while(p != NULL){
		p = p->next;
		i++;
	}
	return i;
}

// 入队操作
Status EnLQueue(LQueue *Q, ElemType e){
	
	if(Q == NULL){
		printf("\n未初始化\n");
		return FALSE;
	}
	Node *p = (Node*)malloc(sizeof(Node));
		if(p== NULL){
		printf("申请内存空间失败\n");
		return FALSE;
	}
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	printf("\n入队成功\n");
	return TRUE;
}


//出队操作
Status DeLQueue(LQueue *Q, ElemType *e){
	
	if(Q == NULL){
		printf("\n未初始化\n");
		return FALSE;
	}
	if(Q->front == Q->rear){
		printf("\n队列为空\n"); 
		return FALSE;
	}
	Node *p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next; 
	if(Q->rear == p){
		Q->rear = Q->front;
	}
	free(p);
	return TRUE;
}

//清空队列.
void ClearLQueue(LQueue *Q){
	
	if(Q == NULL){
		printf("\n未初始化\n");
		return;
	}
	if(Q->front == Q->rear){
		printf("\n队列已空\n"); 
		return;
	}
	Node *p, *q;
	Q->rear = Q->front;
	p = Q->front->next;
	while(p != NULL){
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	printf("\n已清空\n"); 
}

//遍历函数操作
Status TraverseLQueue(LQueue *Q){
	
	if(Q == NULL){
		printf("\n未初始化\n");
		return FALSE;
	}
	if(Q->front == Q->rear){
		printf("\n队列为空\n");
		return FALSE;
	}
	Node *p = Q->front;
	printf("\n队列元素为：");
	while(p != Q->rear){
		p = p->next;
		printf("%d  ",p->data);
	}
	printf("\n");
}








