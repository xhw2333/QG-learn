#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

//链式队列结构
typedef struct node
{
    void *data;                   //数据域指针
    struct node *next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node *front;                   //队头
    Node *rear;                    //队尾
    int length;            //队列长度
    char datatype[30];
} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;
char type;					
	
	
//方便实现泛型	
int num = 0;		 
int head = 0;    

void menu();
int select();
void InitLQueue(LQueue **Q);
void DestoryLQueue(LQueue **Q);
Status IsEmptyLQueue(const LQueue *Q);
Status GetHeadLQueue(LQueue *Q, void *e);
int LengthLQueue(LQueue *Q);
Status EnLQueue(LQueue *Q, void *data);
Status DeLQueue(LQueue *Q);
void ClearLQueue(LQueue *Q);
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q, char type));
void APrint(void *q, char type);




#endif


