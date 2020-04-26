#include "../head/BinaryTree.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



//�˵� 
void menu()
{
	printf("*************Ŀ¼********************\n");
	printf("******    1.��ʼ��������        *****\n");
	printf("******    2.���ٶ�����          *****\n");
	printf("******    3.����������          *****\n");
	printf("******    (ǰ�������ʽ����)    *****\n");
	printf("******    4.�������            *****\n");
	printf("******    5.�������            *****\n");
	printf("******    6.�������            *****\n");
	printf("******    7.�������            *****\n");
	printf("******    8.������������        *****\n");
	printf("******    0.����                *****\n"); 
	printf("*************************************\n");
}

//һ����������ֹ���� 
int select(){ 
	int num;
	while((scanf("%d",&num)) != 1){
		printf("\n����������������룺");
		while(getchar()!='\n');		//��������� 
	}	
	return num;
} 

//�������������ն�����T
Status InitBiTree(BiTree *T){
	
	*T = (BiTree)malloc(sizeof(BiTNode)); 
	(*T)->lchild = NULL;
	(*T)->rchild = NULL;
	printf("\n��ʼ���ɹ�\n");
	return SUCCESS;
}


//��ʼ������������T����
//����������ݻٶ�����T
Status DestroyBiTree(BiTree *T){
	
	if((*T) != NULL){
		 //������
 		if((*T)->lchild){
            DestroyBiTree(&(*T)->lchild); 
		}
		 // ���Һ���
        if((*T)->rchild){
            DestroyBiTree(&(*T)->rchild); 
		}
        free(*T);
        *T=NULL;
	}
	printf("\n������\n");
	return SUCCESS;
}

//����������(����ǰ�������ʽ����������)
Status CreateBiTree(BiTree *T){
	
	char definition;
//	printf("�����루�ַ����ͣ�����(�ո����Ҷ�ӽڵ�):"); 
	scanf("%c",&definition);
//	definition = getchar();
	//#����Ҷ�ӽڵ� 
	if('#' == definition){
		*T = NULL;
	}
	else{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if(*T == NULL){
			return ERROR;
		}
		(*T)->data = definition;
		 CreateBiTree(&(*T)->lchild);
		 CreateBiTree(&(*T)->rchild);
		 return SUCCESS;
	}
	
}

//������� 
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
	
	if(T != NULL){
		visit(T->data);
		PreOrderTraverse(T->lchild,APrint);
		PreOrderTraverse(T->rchild,APrint);
	}
	return SUCCESS;
}

//�������
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
	
	if(T != NULL){
		InOrderTraverse(T->lchild,APrint);
		visit(T->data);
		InOrderTraverse(T->rchild,APrint);
	}
	return SUCCESS;
}

//�������
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
	
	if(T != NULL){	
		PostOrderTraverse(T->lchild,APrint);
		PostOrderTraverse(T->rchild,APrint);
		visit(T->data);
	}
	return SUCCESS;	
}


//�������
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
	
	TElemType *data;
	AQueue *Q;
	BiTNode *p;
	p = T;
	Q = (AQueue*)malloc(sizeof(AQueue));
	//��ʼ�����У�˳����У� 
	InitAQueue(Q);
	if(p != NULL){
		EnAQueue(Q, p);
	}
	while(Q->front != Q->rear){
		
		p = DeAQueue(Q);
		visit(p->data);
		if(p->lchild != NULL){
			EnAQueue(Q, p->lchild);
		}
		if(p->rchild != NULL){
			EnAQueue(Q, p->rchild);
		}
	}

}

//���ʽڵ� 
Status APrint(TElemType e){
	
	if(e <= '9' && e >= '0'){
		printf("%d ",(int)e-'0'); 
	}
	else{
		printf("%c ",e);
	}
	return SUCCESS;
}


//������Ķ�������ֵ
int Value(BiTree T){
	
	if(T==NULL){
			return 0;
	}	
	if(T->data <='9'&&T->data >='0'){
		return (T->data-'0');
	}
	else{
		switch(T->data) {         
			case'+':
				return Value(T->lchild) + Value(T->rchild);
				break;
			case'-':
				return Value(T->lchild) - Value(T->rchild);
				break;
			case'*':
				return Value(T->lchild) * Value(T->rchild);
				break;
			case'/':
				return Value(T->lchild) / Value(T->rchild);
				break;
		}
	}
}

//ǰ׺���ʽ����
BiTree PerTree(char s[],int len){
	
	int i;
	BiTree p, T;
	//��ʱջ - �������ָ�����ڵ��ָ��
	struct stack{
		BiTNode *vec[MAX];
		int top;
	};
	struct stack q;
	q.top = 0;
	for(i = len - 1; i >= 0; i--){
		if(s[i] == '+' || s[i] == '/' || s[i] == '-' || s[i] == '*'){
			p = (BiTree)malloc(sizeof(BiTNode));
			p->data = s[i];
			//�ȵ�����Ϊ��ڵ�
			p->lchild = q.vec[q.top--];
			//�󵯳���Ϊ�ҽڵ� 
			p->rchild = q.vec[q.top--];
			//�����ڵ���ջ 
			q.vec[++q.top] = p;
		}
		else{
			p = (BiTree)malloc(sizeof(BiTNode));
			p->data = s[i];
			p->lchild = NULL;
			p->rchild = NULL;
			q.vec[++q.top] = p;
		}	
	}
	T = q.vec[q.top--];
	return T;
} 

//��ʼ������
void InitAQueue(AQueue *Q){

	Q->front = 0;
	Q->rear = 0;
}


//��Ӳ���
Status EnAQueue(AQueue *Q, BiTNode *p){
	
	if(Q->front == (Q->rear + 1) % MAX){  
		return ERROR;
	}
	if(Q->front == Q->rear){
		Q->data[Q->rear] = p;
		Q->rear = (Q->rear+1) % MAX;
		return SUCCESS;
	}
	Q->data[Q->rear] = p;
	Q->rear = (Q->rear + 1) % MAX;
	return SUCCESS;
}

//���Ӳ���
BiTNode *DeAQueue(AQueue *Q){
	
	return Q->data[(Q->front)++];
} 
