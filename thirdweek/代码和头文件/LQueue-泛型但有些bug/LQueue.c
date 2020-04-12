#include "LQueue.h" 
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

//typedef struct node
//{
//    void *data;                   //������ָ��
//    struct node *next;            //ָ��ǰ������һ���
//} Node;
//
//typedef struct Lqueue
//{
//    Node *front;                   //��ͷ
//    Node *rear;                    //��β
//    int length;            //���г���
//    char datatype[30];    //����������� 
//} LQueue;
//
//typedef enum
//{
//    FALSE=0, TRUE=1
//} Status;
//char type;
//int num = 0;					
			



//�˵� 
void menu()
{
	printf("*************Ŀ¼********************\n");
	printf("******    1.��ʼ������          *****\n");
	printf("******    2.���ٶ���            *****\n");
	printf("******    3.�������Ƿ�Ϊ��    *****\n");
	printf("******    4.�鿴��ͷԪ��        *****\n");
	printf("******    5.ȷ�����г���        *****\n");
	printf("******    6.��Ӳ���            *****\n");
	printf("******    7.���Ӳ���            *****\n");
	printf("******    8.��ն���            *****\n");
	printf("******    9.������������        *****\n");
	printf("******    0.����                *****\n"); 
	printf("*************************************\n");
}


//һ����������ֹ���� 
int select(){ 
	int num;
	while((scanf("%d",&num)) != 1){
		printf("����������������룺");
		while(getchar()!='\n');		//��������� 
	}	
	return num;
} 

//��ʼ������
void InitLQueue(LQueue **Q){
	
	Node *p;
	p = (Node*)malloc(sizeof(Node));
	(*Q) = (LQueue*)malloc(sizeof(LQueue));
	if(p == NULL){
		printf("�����ڴ�ռ�ʧ��\n");
		return;
	} 
	p->next = NULL;
	(*Q)->front = p;
	(*Q)->rear = p;
	(*Q)->length = 30;
	num = 0;
	printf("\n��ʼ���ɹ�\n");
}

//���ٶ���
void DestoryLQueue(LQueue **Q){
	
	if((*Q) == NULL){
		printf("\nδ��ʼ��\n");
		return ;
	}
	free((*Q)->front);
	free((*Q)->rear);
	free(*Q);
	*Q = NULL;
	num = 0;
	printf("\n���ٳɹ�\n"); 
}

//�������Ƿ�Ϊ��
Status IsEmptyLQueue(const LQueue *Q){
	
	if(Q == NULL){
		printf("\nδ��ʼ��\n");
		return FALSE;
	}
	if(Q->front == Q->rear){
		printf("\n����Ϊ��\n");
		return TRUE;
	}
	else{
		printf("\n���в���\n"); 
		return FALSE;
	}
}

//�鿴��ͷԪ��
Status GetHeadLQueue(LQueue *Q, void *e){
	
	if(Q == NULL){
		printf("\nδ��ʼ��\n");
		return FALSE;
	}
	if(Q->front == Q->rear){
		return FALSE;
	}
	memcpy(e, Q->front->next->data, Q->length);
	return TRUE;
}

//ȷ�����г���
int LengthLQueue(LQueue *Q){
	
	if(Q == NULL){
		printf("\nδ��ʼ��\n");
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

// ��Ӳ���
Status EnLQueue(LQueue *Q, void *data){
	
	if(Q == NULL){
		printf("\nδ��ʼ��\n");
		return FALSE;
	}
	Node *p = (Node*)malloc(sizeof(Node));
	if(p== NULL){
		printf("�����ڴ�ռ�ʧ��\n");
		return FALSE;
	}
	p->data = (void*)malloc(sizeof(Q->length));

	memcpy(p->data, data, Q->length);
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;            //ָ���β 
	num++;
	return TRUE;
}

void SelectType(LQueue *Q){
	
	if(Q == NULL){
		printf("\nδ��ʼ��\n");
		return ;
	}
	int t;
//	static i = 0;
    printf("\n1. ����\n2. �ַ���\n3. ������(��ȷ��С�����2λ)\n4. �ַ�������󳤶�Ϊ10��\n");
    printf("�����������:");
    t = select();
    while(t<1 || t>4)
    {
     	printf("������������䣺");
      	t = select();
    }
	printf("\n����ӵ����� :");
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

//���Ӳ���
Status DeLQueue(LQueue *Q){
	
	if(Q == NULL){
		printf("\nδ��ʼ��\n");
		return FALSE;
	}
	if(Q->front == Q->rear){
		printf("\n����Ϊ��\n"); 
		return FALSE;
	}
	Node *p = (Node*)malloc(sizeof(Node));
	p = Q->front->next;
	Q->front->next = p->next;
	if(Q->front->next = NULL){
		Q->rear = Q->front;
	}
	free(p);
	printf("\n���ӳɹ�\n");
	return TRUE;
}

//��ն���
void ClearLQueue(LQueue *Q){
	
	if(Q == NULL){
		printf("\nδ��ʼ��\n");
		return;
	}
	if(Q->front == Q->rear){
		printf("\n�����ѿ�\n"); 
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
	printf("\n�����\n"); 
}

//������������
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q, char type)){
	
	if(Q == NULL){
		printf("\nδ��ʼ��\n");
		return FALSE;
	}
	if(Q->front == Q->rear){
		printf("\n����Ϊ��\n");
		return FALSE;
	}
	Node *p = (void*)malloc(sizeof(Q->length));
	p = Q->front->next;
	int i = 0;
	printf("\n����Ԫ��Ϊ��"); 
	while(p != NULL ){
		foo(p->data,Q->datatype[i]);
		p = p->next;
		i++;
			printf("\n"); 
	}
	printf("\n");
	return TRUE;
}


//��������
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






