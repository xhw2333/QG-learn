#include "AQueue.h"
#include "AQueue.c"



int main(){
	AQueue *Q;
	int i, n;
	void *data, *e;
	Q = NULL;
	Q = (AQueue*)malloc(sizeof(AQueue));
	data = (void*)malloc(10);
	e = (void*)malloc(10);
	do{
		menu();
		printf("\n\n������ָ�");
		i = select();
		switch(i){
			case 1:
				InitAQueue(Q);
				break;
			case 2:
				DestoryAQueue(Q);
				break;
			case 3:
				IsFullAQueue(Q);
				break;
			case 4:
				IsEmptyAQueue(Q);
				break;
			case 5:
				n = GetHeadAQueue(Q, e);
				if(n == 1){
					printf("\n��ͷԪ��Ϊ��");
					APrint(e, Q->datatype[Q->front]);
				}
				else{
					printf("\nNO");
				}
				printf("\n");
				break;
			case 6:
				n = LengthAQueue(Q);
				if(n != -1){
					printf("\n���г���Ϊ%d\n",n);
				}
				else{
					printf("\nERROR\n");
				}
				break;
			case 7:
				SelectType(Q);
				break;
			case 8:
				DeAQueue(Q);
				break;
			case 9:
				ClearAQueue(Q);
				break;
			case 10:
				TraverseAQueue(Q, APrint);
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


