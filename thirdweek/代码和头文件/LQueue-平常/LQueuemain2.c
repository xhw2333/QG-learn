#include "LQueue2.h"
#include "LQueue2.c"


int main(){
	LQueue *Q;
	int i, n, num;
	ElemType e;
	Q = NULL;
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
				n = GetHeadLQueue(Q,&e);
				if(n == 1){
					printf("\n��ͷԪ��Ϊ%d\n",e);
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
				printf("\n����������:");
				num = select(); 
				EnLQueue(Q,num);
				break;
			case 7:
				n = DeLQueue(Q,&e);
				if(n == 1){
					printf("\n����ͷԪ��Ϊ%d\n",e);
				}
				else{
					printf("\nNONE");
				}
				break;
			case 8:
				ClearLQueue(Q);
				break;
			case 9:
				TraverseLQueue(Q);
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
