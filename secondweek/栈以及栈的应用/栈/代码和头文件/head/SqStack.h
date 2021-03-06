#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status 
{
	ERROR = 0, SUCCESS = 1 
} Status;

typedef int ElemType;

typedef struct SqStack 
{
	ElemType *base; //ջ��ָ�� 
	ElemType *top; //ջ��ָ��
	int size; 
} SqStack;


//���������˳��ջ
void menu(); 
int select(); 
Status initStack(SqStack **s);//��ʼ��ջ
Status isEmptyStack(SqStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopStack(SqStack *s,ElemType *e); //�õ�ջ��Ԫ��
Status clearStack(SqStack *s);//���ջ
Status destroyStack(SqStack *s);//����ջ
Status stackLength(SqStack *s,int *length);//���ջ����
Status pushStack(SqStack *s,ElemType num);//��ջ
Status popStack(SqStack *s,ElemType *data);//��ջ
void printStack(SqStack *s);

#endif 
