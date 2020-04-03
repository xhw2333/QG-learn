#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#define OVERFLOW -1


// define element type
typedef int ElemType;

// define struct of linked list
typedef struct LNode {
	ElemType data;
  	struct LNode *next;
} LNode, *LinkedList;
//// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;

void menu();
int select(); 
LinkedList InitList(LinkedList L); 
LinkedList CreateList(LinkedList L,int n);
void DestroyList(LinkedList *L);
LinkedList InsertList(LinkedList L,int n,ElemType e);
LinkedList DeleteList(LinkedList L, ElemType e);
void TraverseList(LinkedList L);
int SearchList(LinkedList L, ElemType e);
LinkedList ReverseList(LinkedList L);
Status IsLoopList(LinkedList L);




Status IsLoopList(LinkedList L);

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L);

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L);

 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
