#include "LQueue.h" 
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

//typedef struct node
//{
//    void *data;                   //数据域指针
//    struct node *next;            //指向当前结点的下一结点
//} Node;
//
//typedef struct Lqueue
//{
//    Node *front;                   //队头
//    Node *rear;                    //队尾
//    int length;            //队列长度
//    char datatype[30];    //存放数据类型 
//} LQueue;
//
//typedef enum
//{
//    FALSE=0, TRUE=1
//} Status;
//char type;
//int num = 0;					
			



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
	
	Node *p;
	p = (Node*)malloc(sizeof(Node));
	(*Q) = (LQueue*)malloc(sizeof(LQueue));
	if(p == NULL){
		printf("申请内存空间失败\n");
		return;
	} 
	p->next = NULL;
	(*Q)->front = p;
	(*Q)->rear = p;
	(*Q)->length = 30;
	num = 0;
	printf("\n初始化成功\n");
}

//销毁队列
void DestoryLQueue(LQueue **Q){
	
	if((*Q) == NULL){
		printf("\n未初始化\n");
		return ;
	}
	free((*Q)->front);
	free((*Q)->rear);
	free(*Q);
	*Q = NULL;
	num = 0;
	printf("\n销毁成功\n"); 
}

//检查队列是否为空
Status IsEmptyLQueue(const LQueue *Q){
	
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
Status GetHeadLQueue(LQueue *Q, void *e){
	
	if(Q == NULL){
		printf("\n未初始化\n");
		return FALSE;
	}
	if(Q->front == Q->rear){
		return FALSE;
	}
	memcpy(e, Q->front->next->data, Q->length);
	return TRUE;
}

//确定队列长度
int LengthLQueue(LQueue *Q){
	
	if(Q == NULL){
		printf("\n未初始化\n");
		return -1;
	}
	int i;
	Node *p = (Node*)malloc(sizeof(Node));
	p = Q->front;
	for(i = 0; p != Q->rear; i++){
		p = p->next;
	}
	return i;
}

// 入队操作
Status EnLQueue(LQueue *Q, void *data){
	
	if(Q == NULL){
		printf("\n未初始化\n");
		return FALSE;
	}
	Node *p = (Node*)malloc(sizeof(Node));
	if(p== NULL){
		printf("申请内存空间失败\n");
		return FALSE;
	}
	p->data = (void*)malloc(sizeof(Q->length));

	memcpy(p->data, data, Q->length);
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;            //指向队尾 
	num++;
	return TRUE;
}

void SelectType(LQueue *Q){
	
	if(Q == NULL){
		printf("\n未初始化\n");
		return ;
	}
	int t;
//	static i = 0;
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
			Q->datatype[num]='i';
			EnLQueue(Q, &a);
			break;
		}
		case 2: {
			char a ;
			getchar();
			scanf("%c", &a);
			Q->datatype[num]='c';
			EnLQueue(Q, &a);
			break;
		}
        case 3:{
			double a ;
			scanf("%lf", &a);
			Q->datatype[num]='d';
			EnLQueue(Q, &a);
			break;
		}
        case 4:{
			char a[10];
			scanf("%s", a);
			Q->datatype[num]='s';
			EnLQueue(Q, a);
			break;
		}
	}
//	i++;
}

//出队操作
Status DeLQueue(LQueue *Q){
	
	if(Q == NULL){
		printf("\n未初始化\n");
		return FALSE;
	}
	if(Q->front == Q->rear){
		printf("\n队列为空\n"); 
		return FALSE;
	}
	Node *p = (Node*)malloc(sizeof(Node));
	p = Q->front->next;
	Q->front->next = p->next;
	if(Q->front->next = NULL){
		Q->rear = Q->front;
	}
	free(p);
	printf("\n出队成功\n");
	return TRUE;
}

//清空队列
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
	num = 0;
	free(p);
	printf("\n已清空\n"); 
}

//遍历函数操作
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q, char type)){
	
	if(Q == NULL){
		printf("\n未初始化\n");
		return FALSE;
	}
	if(Q->front == Q->rear){
		printf("\n队列为空\n");
		return FALSE;
	}
	Node *p = (void*)malloc(sizeof(Q->length));
	p = Q->front->next;
	int i = 0;
	printf("\n队列元素为："); 
	while(p != NULL ){
		foo(p->data,Q->datatype[i]);
		p = p->next;
		i++;
			printf("\n"); 
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






