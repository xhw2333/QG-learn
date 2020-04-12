#include "LQueue.h"
#include "LQueue.c"


int main(){
	LQueue *Q;
	int i, n;
	void *data, *e;
	Q = NULL;
	data = (void*)malloc(10);
	e = (void*)malloc(10);
	do{
		menu();
		printf("\n\n请输入指令：");
		i = select();
		switch(i){
			case 1:
				InitLQueue(&Q);
				break;
			case 2:
				DestoryLQueue(&Q);
				break;
			case 3:
				IsEmptyLQueue(Q);
				break;
			case 4:
				n = GetHeadLQueue(Q, e);
				if(n == 1){
					printf("\n队头元素为：");
					APrint(e, Q->datatype[0]);
				}
				else{
					printf("\nNONE");
				}
				printf("\n");
				break;
			case 5:
				n = LengthLQueue(Q);
				if(n != -1){
					printf("\n队列长度为%d\n",n);
				}
				else{
					printf("\nERROR\n");
				}
				break;
			case 6:
				SelectType(Q);
				break;
			case 7:
				DeLQueue(Q);
				break;
			case 8:
				ClearLQueue(Q);
				break;
			case 9:
				TraverseLQueue(Q, APrint);
				break;
			case 0:
				printf("\nEND\n"); 
				break;
			default:
				printf("输入错误，请重新输入\n");	 
		}
		printf("\n\n");
		if(i != 0){
			system("pause");  //暂停
			system("cls");  //清屏
		}
	}while(i != 0);
	return 0;
}
