#include "AQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 



//菜单 
void menu()
{
	printf("*************目录********************\n");
	printf("******    1.初始化队列          *****\n");
	printf("******    2.销毁队列            *****\n");
	printf("******    3.检查队列是否已满    *****\n");
	printf("******    4.检查队列是否为空    *****\n");
	printf("******    5.查看队头元素        *****\n");
	printf("******    6.确定队列长度        *****\n");
	printf("******    7.入队操作            *****\n");
	printf("******    8.出队操作            *****\n");
	printf("******    9.清空队列            *****\n");
	printf("******    10.遍历函数操作       *****\n");
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
void InitAQueue(AQueue *Q){
	int i;
	Q->length = MAXQUEUE;
	for(i = 0; i < Q->length; i++){  //
		Q->data[i] = (void*)malloc(Q->length);
	}
	Q->front = 0;
	Q->rear = 0;
	printf("\n初始化成功\n");
}

//销毁队列
void DestoryAQueue(AQueue *Q){
	
	if(Q->data[0] == NULL){
		printf("\n未初始化\n");
		return;
	}
	int i;
	for(i = 0; i < Q->length; i++){  
		free(Q->data[i]);
	}
	Q->data[0] = NULL;
	printf("\n销毁成功\n"); 
}

//检查队列是否已满
Status IsFullAQueue(const AQueue *Q){
	
	if(Q->data[0] == NULL){
		printf("\n未初始化\n");
		return FALSE; 
	}
	if(Q->front == (Q->rear + 1) % MAXQUEUE){  
		printf("\n队列已满\n");
		return TRUE;
	}
	else{ 
		printf("\n队列不满\n");
		return FALSE;
	} 
}

//检查队列是否为空
Status IsEmptyAQueue(const AQueue *Q){
	
	if(Q->data[0] == NULL){
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
Status GetHeadAQueue(AQueue *Q, void *e){
	
	if(Q->data[0] == NULL){
		printf("\n未初始化\n");
		return FALSE; 
	}
	if(Q->front == Q->rear){
		return FALSE;
	}
	int i = Q->front;
	i = i % MAXQUEUE; 
	//	拷贝进e
	memcpy(e, Q->data[i],Q->length);
	return TRUE; 
	
}

//确定队列长度
int LengthAQueue(AQueue *Q){
	
	if(Q->data[0] == NULL){
		printf("\n未初始化\n");
		return -1; 
	}
	int i;
	i = (Q->rear - Q->front + Q->length) % Q->length;
	return i;
}


//入队操作
Status EnAQueue(AQueue *Q, void *data){
	
	
	if(Q->front == (Q->rear + 1) % Q->length){  
		return FALSE;
	}
	if(Q->front == Q->rear){
		memcpy(Q->data[Q->front], data, Q->length);
		Q->rear = (Q->rear+1) % Q->length;
		return TRUE;
	}		
	memcpy(Q->data[Q->rear], data, Q->length);
	Q->rear = (Q->rear + 1) % Q->length;
	return TRUE;
}


void SelectType(AQueue *Q){
	
	if(Q->data[0] == NULL){
		printf("\n未初始化\n");
		return ; 
	}
	int t;
    printf("\n1. 整型\n2. 字符型\n3. 浮点型(精确到小数点后2位)\n4. 字符串（最大长度为10）\n");
    printf("输入入队类型:");
    t = select();
    while(t<1 || t>4)
    {
     	printf("输入错误，请重输：");
      	t = select();
    }
	printf("\n想入队的数据 :");
    switch(t)
    {
     	case 1:{
			int a;
			scanf("%d", &a);
			Q->datatype[Q->rear]='i';
			EnAQueue(Q, &a);
			break;
		}
		case 2: {
			char a ;
			getchar();
			scanf("%c", &a);
			Q->datatype[Q->rear]='c';
			EnAQueue(Q, &a);
			break;
		}
        case 3:{
			double a ;
			scanf("%lf", &a);
			Q->datatype[Q->rear]='d';
			EnAQueue(Q, &a);
			break;
		}
        case 4:{
			char a[10];
			scanf("%s", a);
			Q->datatype[Q->rear]='s';
			EnAQueue(Q, a);
			break;
		}
	}
}

//出队操作
Status DeAQueue(AQueue *Q){
	if(Q->front == Q->rear){
		printf("\n队列为空\n"); 
		return FALSE;
	}
	Q->front = (Q->front + 1) % Q->length;
	printf("\n出队成功\n");
	return TRUE;
}

//清空队列
void ClearAQueue(AQueue *Q){

	if(Q->front == Q->rear){
		printf("\n队列已空\n"); 
		return ;
	}
	Q->front = 0;
	Q->rear = 0;
	printf("\n已清空\n"); 
	return;
}

//遍历函数操作
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, char type)){
	
    if(Q->data[0] == NULL)
    {
        printf("\n未初始化\n");
        return FALSE;
    }
	if(Q->front == Q->rear){
		printf("\n队列为空\n");
		return FALSE;
	}
	int i = 0;
	//从队头打印 
	printf("\n队列元素为："); 
	while(i <= (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE){  
		foo(Q->data[Q->front + i], Q->datatype[Q->front + i]);
		i = (i + 1) % MAXQUEUE;  
	}
	printf("\n");
	return TRUE;
}

//操作函数
void APrint(void *q, char type){
	if(type == 'd'){
		printf("%.2lf\t",*(double *)q);
	}	
	else if(type == 'c'){
		printf("%c\t",*(char *)q);
	}
	else if(type == 'i'){
		printf("%d\t",*(int *)q);
	}
	else if(type == 's'){
		printf("%s\t",(char *)q);
	}
}




