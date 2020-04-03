/***************************************************************************************
 *	File Name				:	duLinkedList.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2020.3.28
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/

#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct DuLNode {
	ElemType data;
  	struct DuLNode *prior,  *next;
} DuLNode, *DuLinkedList;

// define status
typedef enum Status {
	ERROR,
	SUCCESS,
} Status;

void menu();

int select();

void tip();

DuLinkedList InitList_DuL(DuLinkedList L);

DuLinkedList CreatList_DuL(DuLinkedList L,int n);

void DestroyList_DuL(DuLinkedList *L);

Status InsertBeforeList_DuL(DuLinkedList *L,ElemType e, ElemType x);

Status InsertAfterList_DuL(DuLinkedList *L,ElemType e, ElemType x);

Status DeleteList_DuL(DuLinkedList *L, ElemType e);

void TraverseList_DuL(DuLinkedList L);


 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
