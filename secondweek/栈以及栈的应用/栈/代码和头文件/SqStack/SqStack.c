#include "../head/SqStack.h" 
#include<stdio.h>
#include<stdlib.h>


//��󳤶� 
#define SIZE 10 


//���������˳��ջ

//�˵� 
void menu()
{
	printf("*************Ŀ¼*****************\n");
	printf("******    1.��ʼ��ջ         *****\n");
	printf("******    2.�ж�ջ�Ƿ�Ϊ��   *****\n");
	printf("******    3.�õ�ջ��Ԫ��     *****\n");
	printf("******    4.���ջ           *****\n");
	printf("******    5.����ջ           *****\n");
	printf("******    6.���ջ����       *****\n");
	printf("******    7.��ջ             *****\n");
	printf("******    8.��ջ             *****\n");
	printf("******    9.��ӡ(ͬʱ���ջ) *****\n");
	printf("******    0.����             *****\n"); 
	printf("**********************************\n");
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



//��ʼ��ջ
Status initStack(SqStack **s){
	
	*s = (SqStack*)malloc(sizeof(SqStack));
	(*s)->base = (ElemType*)malloc(sizeof(ElemType));
	if((*s)->base == NULL){
		return ERROR;
	}
	(*s)->top = (*s)->base;
	(*s)->size = SIZE;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyStack(SqStack *s){
	
	if(s == NULL)
		return SUCCESS;
	if(s->top == s->base)
		return SUCCESS;
	else
		return ERROR;
}

 //�õ�ջ��Ԫ��
Status getTopStack(SqStack *s,ElemType *e){
	
	if(s == NULL)    // �޳�ʼ�� 
		return ERROR;
	if(s->top > s->base){
		*e = *(s->top -1);
		return SUCCESS;
	}
	else
		return ERROR;
}

//���ջ
Status clearStack(SqStack *s){
	
	if(s == NULL)              // �޳�ʼ�� 
		return ERROR;
	if(s->base == NULL)
		return ERROR;
	if(s->top == s->base)
		return ERROR;
	s->top = s->base;
	return SUCCESS;
}

//����ջ
Status destroyStack(SqStack *s){
	
	if(s == NULL)            // �޳�ʼ�� 
		return ERROR;
	if(s->base == NULL){
		return ERROR;
	}
	free(s->base);
	s->base = NULL;
	s->top = NULL;
	s->size = 0;
	return SUCCESS;
	
}

//���ջ����
Status stackLength(SqStack *s,int *length){
	
	if(s == NULL)               // �޳�ʼ�� 
		return ERROR;
	if(s->base == NULL){
		return ERROR;
	}
	*length = s->top - s->base;
	return SUCCESS;
}

//��ջ
Status pushStack(SqStack *s,ElemType data){
	
	if(s == NULL)                // �޳�ʼ�� 
		return ERROR;
	if((s->top - s->base) >= s->size){
		return ERROR;
	}
	*(s->top) = data;
	(s->top)++;
	return SUCCESS;
}

//��ջ
Status popStack(SqStack *s,ElemType *data){
	
	
	if(s == NULL)                  // �޳�ʼ�� 
		return ERROR;
	if(s->top == s->base){
		return ERROR;
	}
	(s->top)--;
	*data = *(s->top);
	return SUCCESS;
}

//��ӡջ
void printStack(SqStack *s){
	
	int *length;
	length =(int*)malloc(sizeof(int));
	if (stackLength(s, length) == 0 || s->top == s->base || s == NULL){
        printf("\n�޷�����\n");
        return;
     }
    printf("\nջ��Ԫ��Ϊ��");
	while (s->top != s->base){
		printf("%d ",*--(s->top));
	}
     printf("\n"); 
} 
