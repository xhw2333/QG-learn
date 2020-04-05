#include "../head/LinkStack.h" 
#include<stdio.h>
#include<stdlib.h>



//�˵� 
void menu()
{
	printf("*************Ŀ¼****************\n");
	printf("******    1.��ʼ��ջ        *****\n");
	printf("******    2.�ж�ջ�Ƿ�Ϊ��  *****\n");
	printf("******    3.�õ�ջ��Ԫ��    *****\n");
	printf("******    4.���ջ          *****\n");
	printf("******    5.����ջ          *****\n");
	printf("******    6.���ջ����      *****\n");
	printf("******    7.��ջ            *****\n");
	printf("******    8.��ջ            *****\n");
	printf("******    9.��ӡ            *****\n");
	printf("******    0.����            *****\n"); 
	printf("*********************************\n");
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
Status initLStack(LinkStack **s){
	
	(*s) = (LinkStack*)malloc(sizeof(LinkStack));
	(*s)->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if((*s)->top == NULL){
		return ERROR;
	}   
	 //Ϊ���޸�s��ֵ����ַ 
	(*s)->top = NULL; 
	(*s)->count = 0;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
	
    if(s == NULL){    //�޳�ʼ�� 
        return SUCCESS;
    }
	if(s->top == NULL){
		return SUCCESS;  //Ϊ�� 
	}
	else{
		return ERROR; //����	
	} 
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
	
    if(s == NULL){   //�޳�ʼ�� 
        return ERROR;
    }
	if(isEmptyLStack(s) == 1){  //�� 
		return ERROR;
	}
	*e = s->top->data;
	return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack *s){
	
    if(s == NULL){      //�޳�ʼ�� 
        return ERROR;
    }
	if(isEmptyLStack(s) == 1){
		return SUCCESS;
	}
    s->top->next = NULL;
    s->count = 0;
    return SUCCESS;
}
	

//����ջ
Status destroyLStack(LinkStack **s){
	
	if((*s) == NULL){   //�޳�ʼ�� 
		return ERROR;
	} 
	int i;
	LinkStackPtr p, q;   
	q = NULL;  //����p�ͷſռ� 
	p = (*s)->top;
	for(i = (*s)->count; i > 0; i--){
		q = p->next;
		free(p);
		p = q;
	}
	(*s)->count = 0;
	free(*s);
	*s = NULL;    //Ϊ���޸�s��ֵ����ַ 
	return SUCCESS;
	
}

//���ջ����
Status LStackLength(LinkStack *s,int *length){
	
	if(s == NULL)
		return ERROR;
	*length = s->count;
	return SUCCESS;
}

//��ջ
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
	s->count++;    //�ڵ��1 
	return SUCCESS;
}

//��ջ
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

  //����ջ
void printLStack(LinkStack *s) {
	
	if(s == NULL){
		printf("\n�޳�ʼ��\n");
        return ;
    }
	int i;
    if(isEmptyLStack(s) == 1){
		printf("\nջΪ��\n");
		return;
	}
	if(s->count == 0){
		printf("\n��\n");
		return;
	}
	LinkStackPtr p = s->top;
	printf("\nԪ��Ϊ��");
    for(i = s->count; i > 0; i--){
        printf("%d ", p->data);
        p = p->next;
    }
     printf("\n");
     return;
}


