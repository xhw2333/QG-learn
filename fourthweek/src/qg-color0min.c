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
		printf("\n\n请输入指令：");
		t = select();
		switch(t){
			case 1:
				printf("排序前：");
				PrintCount(color, n);
				ColorSort(color, n);
				printf("\n排序后：");
				PrintCount(color, n);
				break;
			case 2:
				printf("数组：");
				PrintCount(array, size); 
				printf("\n请输入第几小的数[1,10]：");
				k = select();
				while(k < 1 || k > 10)
			    {
			     	printf("输入错误，请重输：");
			      	t = select();
			    }
				num = SpecialCount(array, 0, size - 1, k - 1);
				printf("元素为%d\n",num);
				break;
			case 0:
				printf("END"); 
				break;
			default:
				printf("输入错误，请重新输入\n");	
		}
		printf("\n\n");
		if(t != 0){
			system("pause");  //暂停
			system("cls");  //清屏
		}
	}while(t != 0);
	return 0;
}
