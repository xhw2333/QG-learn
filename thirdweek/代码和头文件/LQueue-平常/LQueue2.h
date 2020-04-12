#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

//��ʽ���нṹ

typedef int ElemType;

typedef struct node
{
 	ElemType data;                  //������ָ��
    struct node *next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node *front;                   //��ͷ
    Node *rear;                    //��β
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


