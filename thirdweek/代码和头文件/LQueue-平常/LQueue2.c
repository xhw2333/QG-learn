#include "LQueue2.h" 
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 					
			

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
	
	(*Q) = (LQueue*)malloc(sizeof(LQueue));
	(*Q)->front = (Node*)malloc(sizeof(Node)); 
	if((*Q)->front == NULL){
		printf("�����ڴ�ռ�ʧ��\n");
		return;
	} 
	(*Q)->rear = (*Q)->front;
	(*Q)->front->next = NULL;
	printf("\n��ʼ���ɹ�\n");

}

//���ٶ���
void DestoryLQueue(LQueue **Q){
	
	if((*Q) == NULL){
		printf("\nδ��ʼ��\n");
		return ;
	}
	free(*Q);
	*Q = NULL;
	printf("\n���ٳɹ�\n"); 
}

//�������Ƿ�Ϊ��
Status IsEmptyLQueue(LQueue *Q){
	
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
Status GetHeadLQueue(LQueue *Q, ElemType *e){
	
	if(Q == NULL){
		printf("\nδ��ʼ��\n");
		return FALSE;
	}
	if(Q->front == Q->rear){
		return FALSE;
	}
	*e = Q->front->next->data;
	return TRUE;
}

//ȷ�����г���
int LengthLQueue(LQueue *Q){
	
	if(Q == NULL){
		printf("\nδ��ʼ��\n");
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

// ��Ӳ���
Status EnLQueue(LQueue *Q, ElemType e){
	
	if(Q == NULL){
		printf("\nδ��ʼ��\n");
		return FALSE;
	}
	Node *p = (Node*)malloc(sizeof(Node));
		if(p== NULL){
		printf("�����ڴ�ռ�ʧ��\n");
		return FALSE;
	}
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	printf("\n��ӳɹ�\n");
	return TRUE;
}


//���Ӳ���
Status DeLQueue(LQueue *Q, ElemType *e){
	
	if(Q == NULL){
		printf("\nδ��ʼ��\n");
		return FALSE;
	}
	if(Q->front == Q->rear){
		printf("\n����Ϊ��\n"); 
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

//��ն���.
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
	free(p);
	printf("\n�����\n"); 
}

//������������
Status TraverseLQueue(LQueue *Q){
	
	if(Q == NULL){
		printf("\nδ��ʼ��\n");
		return FALSE;
	}
	if(Q->front == Q->rear){
		printf("\n����Ϊ��\n");
		return FALSE;
	}
	Node *p = Q->front;
	printf("\n����Ԫ��Ϊ��");
	while(p != Q->rear){
		p = p->next;
		printf("%d  ",p->data);
	}
	printf("\n");
}








