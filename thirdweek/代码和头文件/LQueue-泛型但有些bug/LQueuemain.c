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
		printf("\n\n������ָ�");
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
					printf("\n��ͷԪ��Ϊ��");
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
					printf("\n���г���Ϊ%d\n",n);
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
				printf("�����������������\n");	 
		}
		printf("\n\n");
		if(i != 0){
			system("pause");  //��ͣ
			system("cls");  //����
		}
	}while(i != 0);
	return 0;
}
