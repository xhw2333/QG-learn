#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

//链式队列结构

typedef int ElemType;

typedef struct node
{
 	ElemType data;                  //数据域指针
    struct node *next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node *front;                   //队头
    Node *rear;                    //队尾
} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;
	
void menu();
int select();
void InitLQueue(LQueue **Q);
void DestoryLQueue(LQueue **Q);
Status IsEmptyLQueue(LQueue *Q);
Status GetHeadLQueue(LQueue *Q, ElemType *e);
int LengthLQueue(LQueue *Q);
Status EnLQueue(LQueue *Q, ElemType e);
Status DeLQueue(LQueue *Q, ElemType *e);
void ClearLQueue(LQueue *Q);
Status TraverseLQueue(LQueue *Q);





#endif


