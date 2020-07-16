#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

//��ʽ���нṹ
typedef struct node
{
    void *data;                   //������ָ��
    struct node *next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node *front;                   //��ͷ
    Node *rear;                    //��β
    int length;            //���г���
    char datatype[30];
} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;
char type;					
	
	
//����ʵ�ַ���	
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


