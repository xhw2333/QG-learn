#include "../head/BinaryTree.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



//菜单 
void menu()
{
	printf("*************目录********************\n");
	printf("******    1.初始化二叉树        *****\n");
	printf("******    2.销毁二叉树          *****\n");
	printf("******    3.创建二叉树          *****\n");
	printf("******    (前序遍历方式构建)    *****\n");
	printf("******    4.先序遍历            *****\n");
	printf("******    5.中序遍历            *****\n");
	printf("******    6.后序遍历            *****\n");
	printf("******    7.层序遍历            *****\n");
	printf("******    8.二叉树计算器        *****\n");
	printf("******    0.结束                *****\n"); 
	printf("*************************************\n");
}

//一个函数，防止乱输 
int select(){ 
	int num;
	while((scanf("%d",&num)) != 1){
		printf("\n输入错误，请重新输入：");
		while(getchar()!='\n');		//清理输出流 
	}	
	return num;
} 

//操作结果：构造空二叉树T
Status InitBiTree(BiTree *T){
	
	*T = (BiTree)malloc(sizeof(BiTNode)); 
	(*T)->lchild = NULL;
	(*T)->rchild = NULL;
	printf("\n初始化成功\n");
	return SUCCESS;
}


//初始条件：二叉树T存在
//操作结果：摧毁二叉树T
Status DestroyBiTree(BiTree *T){
	
	if((*T) != NULL){
		 //有左孩子
 		if((*T)->lchild){
            DestroyBiTree(&(*T)->lchild); 
		}
		 // 有右孩子
        if((*T)->rchild){
            DestroyBiTree(&(*T)->rchild); 
		}
        free(*T);
        *T=NULL;
	}
	printf("\n已销毁\n");
	return SUCCESS;
}

//创建二叉树(按照前序遍历方式构建二叉树)
Status CreateBiTree(BiTree *T){
	
	char definition;
//	printf("请输入（字符类型）数据(空格代表叶子节点):"); 
	scanf("%c",&definition);
//	definition = getchar();
	//#代表叶子节点 
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

//先序遍历 
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
	
	if(T != NULL){
		visit(T->data);
		PreOrderTraverse(T->lchild,APrint);
		PreOrderTraverse(T->rchild,APrint);
	}
	return SUCCESS;
}

//中序遍历
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
	
	if(T != NULL){
		InOrderTraverse(T->lchild,APrint);
		visit(T->data);
		InOrderTraverse(T->rchild,APrint);
	}
	return SUCCESS;
}

//后序遍历
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
	
	if(T != NULL){	
		PostOrderTraverse(T->lchild,APrint);
		PostOrderTraverse(T->rchild,APrint);
		visit(T->data);
	}
	return SUCCESS;	
}


//层序遍历
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e)){
	
	TElemType *data;
	AQueue *Q;
	BiTNode *p;
	p = T;
	Q = (AQueue*)malloc(sizeof(AQueue));
	//初始化队列（顺序队列） 
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

//访问节点 
Status APrint(TElemType e){
	
	if(e <= '9' && e >= '0'){
		printf("%d ",(int)e-'0'); 
	}
	else{
		printf("%c ",e);
	}
	return SUCCESS;
}


//构造出的二叉树求值
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

//前缀表达式建树
BiTree PerTree(char s[],int len){
	
	int i;
	BiTree p, T;
	//临时栈 - 用来存放指向树节点的指针
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
			//先弹出的为左节点
			p->lchild = q.vec[q.top--];
			//后弹出的为右节点 
			p->rchild = q.vec[q.top--];
			//将根节点入栈 
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

//初始化队列
void InitAQueue(AQueue *Q){

	Q->front = 0;
	Q->rear = 0;
}


//入队操作
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

//出队操作
BiTNode *DeAQueue(AQueue *Q){
	
	return Q->data[(Q->front)++];
} 
