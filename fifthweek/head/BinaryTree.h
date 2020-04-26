#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#define MAX 100

typedef char TElemType;     // �������������Ԫ������Ϊ�ַ�

typedef struct  BiTNode {
    TElemType      data;     // ������
    struct BiTNode  *lchild,*rchild;  // ���Һ���ָ��
//    int tag; //��־ 
} BiTNode,*BiTree;   // ��������

typedef enum Status{
	SUCCESS,
	ERROR
}Status;

typedef struct Aqueue
{
	BiTNode *data[MAX];
    int front;
    int rear;
} AQueue;

void menu();
int select(); 
Status InitBiTree(BiTree *T);
//�������������ն�����T
Status DestroyBiTree(BiTree *T);
//��ʼ������������T����
//����������ݻٶ�����T
Status CreateBiTree(BiTree *T);
//��ʼ������ definition�����������Ķ���
//�����������definition���������T


//���²��ֺ�������δָ����������
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
//��ʼ������������T���ڣ�visitΪ�Խ��Ĳ�����Ӧ�ú���
//����������������T����ÿ��������visit����һ���ҽ�һ�Σ�һ��visitʧ�ܣ������ʧ��
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));	//�������
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e));	//�������
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));	//�������
int Value(BiTree T);			//������Ķ�������ֵ
Status APrint(TElemType e);
BiTree PerTree(char s[],int len);
/*
��ʾ�����ڽ��ṹ�������ø�Tagֵ��־������������������������
�ɸ�����Ҫ�������Ӳ���.
*/

void InitAQueue(AQueue *Q);
Status EnAQueue(AQueue *Q, BiTNode *p);
BiTNode *DeAQueue(AQueue *Q);


#endif 
