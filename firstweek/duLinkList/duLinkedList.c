#include "../head/duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>

//�˵� 
void menu()
{
	printf("************Ŀ¼******************\n");
	printf("******   1.��ʼ��            *****\n");
	printf("******   2.��������          *****\n");
	printf("******   3.��������          *****\n");
	printf("******   4.�ض�λ��ǰ��ڵ�  *****\n");
	printf("******   5.�ض�λ�ú��ڵ�  *****\n");
	printf("******   6.ɾ������ڵ�      *****\n");
	printf("******   7.��������          *****\n");
	printf("******   0.����              *****\n"); 
	printf("**********************************\n");
}

void tip(){
	printf("******************\n");
	printf("**   0 -- ʧ��  **\n");
	printf("**   1 -- �ɹ�  **\n");
	printf("******************\n");
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
DuLinkedList InitList_DuL(DuLinkedList L) {
	L = (DuLinkedList)malloc(sizeof(DuLNode));
	if(!L){		
		printf("�����ڴ�ռ�ʧ��\n");
		return ERROR;
	}	
	L->next = NULL;
	L->prior = NULL;
	printf("��ʼ���ɹ�\n");
	return L;
}

//��������
DuLinkedList CreatList_DuL(DuLinkedList L,int n){
	
	int i;
	DuLNode *q,*p;
	p = q = NULL;
	p = L;
	if(L == NULL){
		printf("�޳�ʼ��\n");
		return 0;
	}
	for(i = 1; i <= n; i++){
		q = (DuLinkedList)malloc(sizeof(DuLNode));
		if(!q)
		{
			return ERROR;
		}
		printf("�������%d�����ݣ�",i);
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

//�������� 
void DestroyList_DuL(DuLinkedList *L) {
	DuLNode *p = NULL;
	if(*L == NULL){
		printf("�޳�ʼ��\n");
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
	printf("������\n");
} 

//���ض�λ��֮ǰ����ڵ�
Status InsertBeforeList_DuL(DuLinkedList *L,ElemType e, ElemType x) {
	
	DuLNode *p,*q;
	p = *L;
	if(*L == NULL){
		printf("�޳�ʼ��\n");
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

//���ض�λ��֮�����ڵ�
Status InsertAfterList_DuL(DuLinkedList *L,ElemType e, ElemType x) {
	
	DuLNode *p, *q;
	p = *L;
	if(*L == NULL){
		printf("�޳�ʼ��\n");
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


//ɾ������ڵ� 
Status DeleteList_DuL(DuLinkedList *L, ElemType e) {
	
	DuLNode *p, *q;
	p = q = NULL;
	p = *L;
	if(*L == NULL){
		printf("�޳�ʼ��\n");
		return ERROR;
	}
	if((*L)->next == NULL){
		printf("δ����\n");
		return ERROR;
	}
	while(p != NULL && p->data != e){
		q = p;
		p = p->next;
	}
	if(p == NULL || p->data != e){
		return ERROR;
	}
	//ɾ�����һ���ڵ� 
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

//�������� 
void TraverseList_DuL(DuLinkedList L) {
	DuLNode *p, *q;
	q = p = NULL;
	if(L == NULL){
		printf("�޳�ʼ��\n");
		return;
	}
	if(L->next == NULL){
		printf("δ����\n");
		return ;
	}
	p = L->next;
	printf("����"); 
	while(p != NULL){
		printf("%d ",p->data);
		q = p;
		p = p->next;
	}
	printf("\n����");
	while(q->prior != NULL){
		printf("%d ",q->data);
		q = q->prior;
	}
	printf("\n");
}
