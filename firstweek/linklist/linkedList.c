#include "../head/linkedList.h"
#include<stdio.h>
#include<stdlib.h> 

#define ERROR 0

//�˵� 
void menu()
{
	printf("*************Ŀ¼**************\n");
	printf("******    1.��ʼ��        *****\n");
	printf("******    2.��������      *****\n");
	printf("******    3.��������      *****\n");
	printf("******    4.��������      *****\n");
	printf("******    5.ɾ������ڵ�  *****\n");
	printf("******    6.��������      *****\n");
	printf("******    7.��������      *****\n");
	printf("******    8.��ת����      *****\n");	
	printf("******    9.�ж��Ƿ��л�  *****\n");	
	printf("******    0.����          *****\n"); 
	printf("*******************************\n");
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
//��ʼ�� 
LinkedList InitList(LinkedList L){	
	LNode *p = NULL;	
	p = (LinkedList)malloc(sizeof(LNode));	
	if(!p){		
		printf("�����ڴ�ռ�ʧ��\n");
		return 0;
	}	
	p->next = NULL;	
	L = p;	
	printf("��ʼ���ɹ�\n");
	return L;
}


//�������� (ͷ�巨�� 
LinkedList CreateList(LinkedList L,int n)
{	
	int i;	
	LNode *p = NULL;
	if(L == NULL){
		printf("�޳�ʼ��\n");
		return 0;
	}
	for(i = n; i > 0; i--){	
		p=(LinkedList)malloc(sizeof(LNode));
		printf("����������(����һ��Ԫ�غ󰴻س�)��");	
//		scanf("%d",&p->data);
	 	p->data = select();			
		p->next=L->next;		
		L->next=p;
	}
	printf("\nover\n");
	return L;
} 

//�������� 
void DestroyList(LinkedList *L) {

	LNode *p = NULL;
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
						
//�������� 
LinkedList InsertList(LinkedList L,int n,ElemType e) {
	
	int i = 0;
	LNode *p,*q,*temp;
	p = L;
	q = (LinkedList)malloc(sizeof(LNode));
	if(L == NULL){
		printf("�޳�ʼ��\n");
		return 0;
	}
	while(p != NULL && i < n - 1){
		p = p->next;
		i++; 
	}
	if(p == NULL || i > n - 1){
		printf("ERROR!\n");
		return L;
	}
	q->data = e;
	q->next = p->next;
	p->next = q;
	return L;
}

//ɾ������ڵ� 
LinkedList DeleteList(LinkedList L, ElemType e) {
	
	LNode *q,*p;
	p = q = NULL;
	p = L;
	if(L == NULL){
		printf("�޳�ʼ��\n");
		return 0;
	}
	if(L->next == NULL){
		printf("δ����\n");
		return 0;
	}
	while(p != NULL && p->data != e){
		q = p;
		p = p->next;
	}
	if(p == NULL || p->data != e){
		printf("ERROR\n");
		return L;
	}
	q->next = p->next;
	free(p);
	return L;
}
	
//�������� 
void TraverseList(LinkedList L) {
	
	LNode *p;
	if(L == NULL){
		printf("�޳�ʼ��\n");
		return;
	}
	if(L->next == NULL){
		printf("δ����\n");
		return ;
	}
	p = NULL;
	p = L->next;
	while(p != NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

//�������� 
int SearchList(LinkedList L, ElemType e) {
	
	LNode *p;
	int i ;
	p = L->next;
//	if(L == NULL){
//		printf("�޳�ʼ��\n");
//		return 0;
//	}
//	if(L->next == NULL){
//		printf("δ����\n");
//		return 0;
//	}
	if(p->next == NULL){
		return 0;
	}
	for(i = 1; p != NULL; i++){
		if(p->data == e){
			return i;
		}
		p = p->next;
	}
	return 0; 
}

//��ת���� 
LinkedList ReverseList(LinkedList L) {
	
	LNode *p = NULL;
	LNode *q = L->next;
	if(L == NULL || L->next == NULL){
		return L;
	}
	while(q != NULL){
		LNode *temp = q;
		q = q->next;
		temp->next = p;
		p = temp;
	}
	L->next = p;
	return L;
}

//�ж��Ƿ��л� 
Status IsLoopList(LinkedList L) {
	
	LNode *slow, *fast;
	slow = L->next;
	fast = slow->next;
	if(L == NULL || L->next == NULL){
		return ERROR;
	}
	while(fast != NULL && slow != NULL){
		if(fast == slow){
			return SUCCESS;
		}
		slow = slow->next;
		fast = fast->next;
		if(fast != NULL){
			fast = fast->next;
		}
	}
	return ERROR;
}




/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {

}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {

}
