#include "../head/SqStack.h" 
#include<stdio.h>
#include<stdlib.h>


//最大长度 
#define SIZE 10 


//基于数组的顺序栈

//菜单 
void menu()
{
	printf("*************目录*****************\n");
	printf("******    1.初始化栈         *****\n");
	printf("******    2.判断栈是否为空   *****\n");
	printf("******    3.得到栈顶元素     *****\n");
	printf("******    4.清空栈           *****\n");
	printf("******    5.销毁栈           *****\n");
	printf("******    6.检测栈长度       *****\n");
	printf("******    7.入栈             *****\n");
	printf("******    8.出栈             *****\n");
	printf("******    9.打印(同时会出栈) *****\n");
	printf("******    0.结束             *****\n"); 
	printf("**********************************\n");
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



//初始化栈
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

//判断栈是否为空
Status isEmptyStack(SqStack *s){
	
	if(s == NULL)
		return SUCCESS;
	if(s->top == s->base)
		return SUCCESS;
	else
		return ERROR;
}

 //得到栈顶元素
Status getTopStack(SqStack *s,ElemType *e){
	
	if(s == NULL)    // 无初始化 
		return ERROR;
	if(s->top > s->base){
		*e = *(s->top -1);
		return SUCCESS;
	}
	else
		return ERROR;
}

//清空栈
Status clearStack(SqStack *s){
	
	if(s == NULL)              // 无初始化 
		return ERROR;
	if(s->base == NULL)
		return ERROR;
	if(s->top == s->base)
		return ERROR;
	s->top = s->base;
	return SUCCESS;
}

//销毁栈
Status destroyStack(SqStack *s){
	
	if(s == NULL)            // 无初始化 
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

//检测栈长度
Status stackLength(SqStack *s,int *length){
	
	if(s == NULL)               // 无初始化 
		return ERROR;
	if(s->base == NULL){
		return ERROR;
	}
	*length = s->top - s->base;
	return SUCCESS;
}

//入栈
Status pushStack(SqStack *s,ElemType data){
	
	if(s == NULL)                // 无初始化 
		return ERROR;
	if((s->top - s->base) >= s->size){
		return ERROR;
	}
	*(s->top) = data;
	(s->top)++;
	return SUCCESS;
}

//出栈
Status popStack(SqStack *s,ElemType *data){
	
	
	if(s == NULL)                  // 无初始化 
		return ERROR;
	if(s->top == s->base){
		return ERROR;
	}
	(s->top)--;
	*data = *(s->top);
	return SUCCESS;
}

//打印栈
void printStack(SqStack *s){
	
	int *length;
	length =(int*)malloc(sizeof(int));
	if (stackLength(s, length) == 0 || s->top == s->base || s == NULL){
        printf("\n无法遍历\n");
        return;
     }
    printf("\n栈中元素为：");
	while (s->top != s->base){
		printf("%d ",*--(s->top));
	}
     printf("\n"); 
} 
