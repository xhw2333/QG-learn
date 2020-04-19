#include "../inc/qgsort.h"
#include "qgsort.c"



int main(){
	
	FILE *fp = NULL;  //写入文件 
	//测时间 
	long start,end; 
	int array1[10000],*array2,*array3;
	int array[100];
	int *temp1, *temp2, *temp3,*temp;
	int i, j, k, t, max1, max2, max3, max, num;
	srand((unsigned)time(NULL));
	max1 = max2 = max3 = max = 0;
	array2 = (int*)malloc(50000*sizeof(int)); 
	array3 = (int*)malloc(200000*sizeof(int));
	temp1 = (int*)malloc(10000*sizeof(int));
	temp2 = (int*)malloc(50000*sizeof(int));
	temp3 = (int*)malloc(200000*sizeof(int));
	temp = (int*)malloc(100*sizeof(int));
	fp = fopen("test.txt", "w");
	if(!fp){
		printf("打开文件失败，程序退出\n");
		exit(1);
	}
	for(i = 0; i < 10000; i++){
		array1[i] = rand()%(MAX - MIN);
		fprintf(fp, "%d ", array1[i]);
	}
	for(i = 0; i < 50000; i++){
		array2[i] = rand()%(MAX - MIN);
		fprintf(fp, "%d ", array2[i]);
	}
	for(i = 0; i < 200000; i++){
		array3[i] = rand()%(MAX - MIN);
		fprintf(fp, "%d ", array3[i]);
	}
	for(i = 0; i < 100; i++){
		array[i] = rand()%(MAX - MIN);
		fprintf(fp, "%d ", array[i]);
	}
	fclose(fp);//关闭文件

	menu();
	do{
		printf("\n请输入指令：");
		t = select();
		switch(t){
			case 1:	
				fp = fopen("test.txt","r");//读文件
       			printf("\n---- 10000数据 ----\n");
       			for(i = 0; i < 10000; i++){
					fscanf(fp,"%d",&array1[i]);
				}
//       			MaxandCreatCount(array1, 10000);
       			printf("插入排序:");
       			start = clock();
       			insertSort(array1, 10000);
       			end = clock();
       			printf("%ldms\n",end-start);
//       			PrintCount(array1, 10000 - 1);
       			
       			for(i = 0; i < 10000; i++){
					fscanf(fp,"%d",&array1[i]);
				}
//       			MaxandCreatCount(array1, 10000);
       			printf("归并排序:");
       			start = clock();
       			MergeSort(array1, 0, 10000-1, temp1);
       			end = clock();
       			printf("%ldms\n",end-start);
       			
       			for(i = 0; i < 10000; i++){
					fscanf(fp,"%d",&array1[i]);
				}
//       			MaxandCreatCount(array1, 10000);
       			printf("快速排序(递归版):");
       			start = clock();
       			QuickSort_Recursion(array1, 0, 10000 - 1);
       			end = clock();
       			printf("%ldms\n",end-start);
       			
       			for(i = 0; i < 10000; i++){
					fscanf(fp,"%d",&array1[i]);
				}
       			max1 = MaxandCreatCount(array1, 10000);
       			printf("计数排序:");
       			start = clock();
       			CountSort(array1, 10000, max1);
       			end = clock();
       			printf("%ldms\n",end-start);
       			
       			for(i = 0; i < 10000; i++){
					fscanf(fp,"%d",&array1[i]);
				}
       			max1 = MaxandCreatCount(array1, 10000);
       			printf("基数计数排序:");
       			start = clock();
       			RadixCountSort(array1, 10000, max1);
       			end = clock();
       			printf("%ldms\n",end-start);
       			
       			printf("\n---- 50000数据 ----\n");
       			for(i = 0; i < 50000; i++){
					fscanf(fp,"%d",&array2[i]);
				}
//       			MaxandCreatCount(array2, 50000);
       			printf("插入排序:");
       			start = clock();
       			insertSort(array2, 50000);
       			end = clock();
       			printf("%ldms\n",end-start);
       			
       			for(i = 0; i < 50000; i++){
					fscanf(fp,"%d",&array2[i]);
				}
//       			MaxandCreatCount(array2, 50000);
       			printf("归并排序:");
       			start = clock();
       			MergeSort(array2, 0, 50000-1, temp2);
       			end = clock();
       			printf("%ldms\n",end-start);
       			
       			for(i = 0; i < 50000; i++){
					fscanf(fp,"%d",&array2[i]);
				}
//       			MaxandCreatCount(array2, 50000);
       			printf("快速排序(递归版):");
       			start = clock();
       			QuickSort_Recursion(array2, 0, 50000 - 1);
       			end = clock();
       			printf("%ldms\n",end-start);
       			
       			for(i = 0; i < 50000; i++){
					fscanf(fp,"%d",&array2[i]);
				}
       			max2 = MaxandCreatCount(array2, 50000);
       			printf("计数排序:");
       			start = clock();
       			CountSort(array2, 50000, max2); 
       			end = clock();
       			printf("%ldms\n",end-start);
       			
       			for(i = 0; i < 50000; i++){
					fscanf(fp,"%d",&array2[i]);
				}
       			max2 = MaxandCreatCount(array2, 50000);
       			printf("基数计数排序:");
       			start = clock();
       			RadixCountSort(array2, 50000, max2);
       			end = clock();
       			printf("%ldms\n",end-start);
       			
       			printf("\n---- 200000数据 ----\n");
       			for(i = 0; i < 200000; i++){
					fscanf(fp,"%d",&array3[i]);
				}
//       			MaxandCreatCount(array3, 200000);
       			printf("插入排序:");
       			start = clock();
       			insertSort(array3, 200000);
       			end = clock();
       			printf("%ldms\n",end-start);
       			
       			for(i = 0; i < 200000; i++){
					fscanf(fp,"%d",&array3[i]);
				}
//       			MaxandCreatCount(array3, 200000);
       			printf("归并排序:");
       			start = clock();
       			MergeSort(array3, 0, 200000 - 1, temp3);
       			end = clock();
       			printf("%ldms\n",end-start);
       			
       			for(i = 0; i < 200000; i++){
					array3[i] = rand()%(MAX - MIN);
				}
//       			MaxandCreatCount(array3, 200000);
       			printf("快速排序(递归版):");
       			start = clock();
       			QuickSort_Recursion(array3, 0, 200000 - 1);
       			end = clock();
       			printf("%ldms\n",end-start);
       			
       			for(i = 0; i < 200000; i++){
					fscanf(fp,"%d",&array3[i]);
				}
       			max3 = MaxandCreatCount(array3, 200000);
       			printf("计数排序:");
       			start = clock();
       			CountSort(array3, 200000, max3); 
       			end = clock();
       			printf("%ldms\n",end-start);
       			
       			for(i = 0; i < 200000; i++){
					fscanf(fp,"%d",&array3[i]);
				}
       			max3 = MaxandCreatCount(array3, 200000);
       			printf("基数计数排序:");
       			start = clock();
       			RadixCountSort(array3, 200000, max3);
       			end = clock();
       			printf("%ldms\n",end-start);
       			
       			free(temp1);
       			free(temp2);
       			free(temp3);
       			free(array2);
       			free(array3);
	       		fclose(fp);
				break;
			case 2:	
				fp = fopen("test.txt","r");//读文件
				printf("\n---- 1k * 100数据 ----\n");
       			printf("插入排序:");
       			start = clock();
       			for(i = 0;i < 100000; i++){
					for(j = 0; j < 100; j++){
						fscanf(fp,"%d",&array[j]);
					}
       				insertSort(array, 100);
				}
       			end = clock();
       			printf("%ldms\n",end-start);
				
				printf("归并排序:");
       			start = clock();
       			for(i = 0;i < 100000; i++){
       				for(j = 0; j < 100; j++){
						fscanf(fp,"%d",&array[j]);
					}
       				MergeSort(array, 0, 100 - 1, temp);
				}
       			end = clock();
       			printf("%ldms\n",end-start);
				
				printf("快速排序(递归版):");
       			start = clock();
       			for(i = 0;i < 100000; i++){
       				for(j = 0; j < 100; j++){
						fscanf(fp,"%d",&array[j]);
					}
       				QuickSort_Recursion(array, 0, 100 - 1);
				}
       			end = clock();
       			printf("%ldms\n",end-start);
       			
       			printf("计数排序:");
       			start = clock();
      			for(i = 0;i < 100000; i++){
      				max = 0;
       				for(j = 0; j < 100; j++){
						fscanf(fp,"%d",&array[j]);
       					if(max < array[j]){
       						max = array[j];
						}
					}
       				CountSort(array, 100, max);
				} 
       			end = clock();
       			printf("%ldms\n",end-start);
       			
       			printf("基数计数排序:");
       			start = clock();
       			for(i = 0;i < 100000; i++){
       				max = 0;
       				for(j = 0; j < 100; j++){
						fscanf(fp,"%d",&array[j]);
       					if(max < array[j]){
       						max = array[j];
						}
					}
       				RadixCountSort(array, 100, max);
				} 
       			end = clock();
       			printf("%ldms\n",end-start);
       			
       			free(temp);
       			fclose(fp);
				break;
			case 0:
				printf("\nEND"); 
				free(temp1);
       			free(temp2);
       			free(temp3);
       			free(temp);
       			free(array2);
       			free(array3);
				break;
			default:
				printf("输入错误，请重新输入\n");	
		}
//		printf("\n\n");
//		if(t != 0){
//			system("pause");  //暂停
//			system("cls");  //清屏
//	 	}
	}while(t != 0);
	fclose(fp);
	return 0;
}

