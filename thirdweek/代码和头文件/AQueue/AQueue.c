#include "AQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 



//�˵� 
void menu()
{
	printf("*************Ŀ¼********************\n");
	printf("******    1.��ʼ������          *****\n");
	printf("******    2.���ٶ���            *****\n");
	printf("******    3.�������Ƿ�����    *****\n");
	printf("******    4.�������Ƿ�Ϊ��    *****\n");
	printf("******    5.�鿴��ͷԪ��        *****\n");
	printf("******    6.ȷ�����г���        *****\n");
	printf("******    7.��Ӳ���            *****\n");
	printf("******    8.���Ӳ���            *****\n");
	printf("******    9.��ն���            *****\n");
	printf("******    10.������������       *****\n");
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
void InitAQueue(AQueue *Q){
	int i;
	Q->length = MAXQUEUE;
	for(i = 0; i < Q->length; i++){  //
		Q->data[i] = (void*)malloc(Q->length);
	}
	Q->front = 0;
	Q->rear = 0;
	printf("\n��ʼ���ɹ�\n");
}

//���ٶ���
void DestoryAQueue(AQueue *Q){
	
	if(Q->data[0] == NULL){
		printf("\nδ��ʼ��\n");
		return;
	}
	int i;
	for(i = 0; i < Q->length; i++){  
		free(Q->data[i]);
	}
	Q->data[0] = NULL;
	printf("\n���ٳɹ�\n"); 
}

//�������Ƿ�����
Status IsFullAQueue(const AQueue *Q){
	
	if(Q->data[0] == NULL){
		printf("\nδ��ʼ��\n");
		return FALSE; 
	}
	if(Q->front == (Q->rear + 1) % MAXQUEUE){  
		printf("\n��������\n");
		return TRUE;
	}
	else{ 
		printf("\n���в���\n");
		return FALSE;
	} 
}

//�������Ƿ�Ϊ��
Status IsEmptyAQueue(const AQueue *Q){
	
	if(Q->data[0] == NULL){
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
Status GetHeadAQueue(AQueue *Q, void *e){
	
	if(Q->data[0] == NULL){
		printf("\nδ��ʼ��\n");
		return FALSE; 
	}
	if(Q->front == Q->rear){
		return FALSE;
	}
	int i = Q->front;
	i = i % MAXQUEUE; 
	//	������e
	memcpy(e, Q->data[i],Q->length);
	return TRUE; 
	
}

//ȷ�����г���
int LengthAQueue(AQueue *Q){
	
	if(Q->data[0] == NULL){
		printf("\nδ��ʼ��\n");
		return -1; 
	}
	int i;
	i = (Q->rear - Q->front + Q->length) % Q->length;
	return i;
}


//��Ӳ���
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
		printf("\nδ��ʼ��\n");
		return ; 
	}
	int t;
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

//���Ӳ���
Status DeAQueue(AQueue *Q){
	if(Q->front == Q->rear){
		printf("\n����Ϊ��\n"); 
		return FALSE;
	}
	Q->front = (Q->front + 1) % Q->length;
	printf("\n���ӳɹ�\n");
	return TRUE;
}

//��ն���
void ClearAQueue(AQueue *Q){

	if(Q->front == Q->rear){
		printf("\n�����ѿ�\n"); 
		return ;
	}
	Q->front = 0;
	Q->rear = 0;
	printf("\n�����\n"); 
	return;
}

//������������
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, char type)){
	
    if(Q->data[0] == NULL)
    {
        printf("\nδ��ʼ��\n");
        return FALSE;
    }
	if(Q->front == Q->rear){
		printf("\n����Ϊ��\n");
		return FALSE;
	}
	int i = 0;
	//�Ӷ�ͷ��ӡ 
	printf("\n����Ԫ��Ϊ��"); 
	while(i <= (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE){  
		foo(Q->data[Q->front + i], Q->datatype[Q->front + i]);
		i = (i + 1) % MAXQUEUE;  
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




