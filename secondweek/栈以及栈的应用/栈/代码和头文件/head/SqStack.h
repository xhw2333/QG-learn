#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status 
{
	ERROR = 0, SUCCESS = 1 
} Status;

typedef int ElemType;

typedef struct SqStack 
{
	ElemType *base; //栈底指针 
	ElemType *top; //栈顶指针
	int size; 
} SqStack;


//基于数组的顺序栈
void menu(); 
int select(); 
Status initStack(SqStack **s);//初始化栈
Status isEmptyStack(SqStack *s);//判断栈是否为空
Status getTopStack(SqStack *s,ElemType *e); //得到栈顶元素
Status clearStack(SqStack *s);//清空栈
Status destroyStack(SqStack *s);//销毁栈
Status stackLength(SqStack *s,int *length);//检测栈长度
Status pushStack(SqStack *s,ElemType num);//入栈
Status popStack(SqStack *s,ElemType *data);//出栈
void printStack(SqStack *s);

#endif 
