#include "../inc/qgsort.h"
#include "qgsort.c"

int main(){
	int i, t, k, num;
	int color[6] = {1, 0, 1,2, 2, 0};
	int array[10] = {1, 45, 34, 53, 53, 43, 154, 95, 96, 34};
	int n = 6;
	int size = 10;
	do{
		menu2();
		printf("\n\n������ָ�");
		t = select();
		switch(t){
			case 1:
				printf("����ǰ��");
				PrintCount(color, n);
				ColorSort(color, n);
				printf("\n�����");
				PrintCount(color, n);
				break;
			case 2:
				printf("���飺");
				PrintCount(array, size); 
				printf("\n������ڼ�С����[1,10]��");
				k = select();
				while(k < 1 || k > 10)
			    {
			     	printf("������������䣺");
			      	t = select();
			    }
				num = SpecialCount(array, 0, size - 1, k - 1);
				printf("Ԫ��Ϊ%d\n",num);
				break;
			case 0:
				printf("END"); 
				break;
			default:
				printf("�����������������\n");	
		}
		printf("\n\n");
		if(t != 0){
			system("pause");  //��ͣ
			system("cls");  //����
		}
	}while(t != 0);
	return 0;
}
