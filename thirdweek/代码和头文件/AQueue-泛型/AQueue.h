#ifndef AQUEUE_H_INCLUDED
#define AQUEUE_H_INCLUDED


#define MAXQUEUE 10


//循环队列结构

typedef struct Aqueue
{
    void *data[MAXQUEUE];      //数据域
    int front;
    int rear;
    int length;        //队列长度
    char datatype[MAXQUEUE];
} AQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;
char type;
//char datatype[MAXQUEUE];

void menu();
int select();
void InitAQueue(AQueue *Q);
void DestoryAQueue(AQueue *Q);
Status IsFullAQueue(const AQueue *Q);
Status IsEmptyAQueue(const AQueue *Q);
Status GetHeadAQueue(AQueue *Q, void *e);		
int LengthAQueue(AQueue *Q);	
Status EnAQueue(AQueue *Q, void *data);	
Status DeAQueue(AQueue *Q);		
void ClearAQueue(AQueue *Q);	
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, char type));	
void APrint(void *q,  char type);	
void SelectType(AQueue *Q);



#endif 

