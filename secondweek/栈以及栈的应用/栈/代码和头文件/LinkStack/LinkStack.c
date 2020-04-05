#include "../head/LinkStack.h" 
#include<stdio.h>
#include<stdlib.h>



//菜单 
void menu()
{
	printf("*************目录****************\n");
	printf("******    1.初始化栈        *****\n");
	printf("******    2.判断栈是否为空  *****\n");
	printf("******    3.得到栈顶元素    *****\n");
	printf("******    4.清空栈          *****\n");
	printf("******    5.销毁栈          *****\n");
	printf("******    6.检测栈长度      *****\n");
	printf("******    7.入栈            *****\n");
	printf("******    8.出栈            *****\n");
	printf("******    9.打印            *****\n");
	printf("******    0.结束            *****\n"); 
	printf("*********************************\n");
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
Status initLStack(LinkStack **s){
	
	(*s) = (LinkStack*)malloc(sizeof(LinkStack));
	(*s)->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if((*s)->top == NULL){
		return ERROR;
	}   
	 //为了修改s的值传地址 
	(*s)->top = NULL; 
	(*s)->count = 0;
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
	
    if(s == NULL){    //无初始化 
        return SUCCESS;
    }
	if(s->top == NULL){
		return SUCCESS;  //为空 
	}
	else{
		return ERROR; //不空	
	} 
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
	
    if(s == NULL){   //无初始化 
        return ERROR;
    }
	if(isEmptyLStack(s) == 1){  //空 
		return ERROR;
	}
	*e = s->top->data;
	return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack *s){
	
    if(s == NULL){      //无初始化 
        return ERROR;
    }
	if(isEmptyLStack(s) == 1){
		return SUCCESS;
	}
    s->top->next = NULL;
    s->count = 0;
    return SUCCESS;
}
	

//销毁栈
Status destroyLStack(LinkStack **s){
	
	if((*s) == NULL){   //无初始化 
		return ERROR;
	} 
	int i;
	LinkStackPtr p, q;   
	q = NULL;  //来帮p释放空间 
	p = (*s)->top;
	for(i = (*s)->count; i > 0; i--){
		q = p->next;
		free(p);
		p = q;
	}
	(*s)->count = 0;
	free(*s);
	*s = NULL;    //为了修改s的值传地址 
	return SUCCESS;
	
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length){
	
	if(s == NULL)
		return ERROR;
	*length = s->count;
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack *s,ElemType data){
	
	if(s == NULL){
        return ERROR;
    }
	LinkStackPtr p;
	p = (LinkStackPtr)malloc(sizeof(StackNode));
	if( p == NULL){
		return ERROR;
	}
	p->data = data;
	p->next = s->top;  
	s->top = p;   
	s->count++;    //节点加1 
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack *s,ElemType *data){
	
	if(s == NULL){
        return ERROR;
    }
	if(isEmptyLStack(s) == 1){
		return ERROR;
	}
	LinkStackPtr temp;
	temp = s->top;
	*data = temp->data;
	s->top = temp->next;
	s->count--;
	free(temp);
	return SUCCESS; 
	
}

  //遍历栈
void printLStack(LinkStack *s) {
	
	if(s == NULL){
		printf("\n无初始化\n");
        return ;
    }
	int i;
    if(isEmptyLStack(s) == 1){
		printf("\n栈为空\n");
		return;
	}
	if(s->count == 0){
		printf("\n无\n");
		return;
	}
	LinkStackPtr p = s->top;
	printf("\n元素为：");
    for(i = s->count; i > 0; i--){
        printf("%d ", p->data);
        p = p->next;
    }
     printf("\n");
     return;
}


