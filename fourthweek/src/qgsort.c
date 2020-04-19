#include "../inc/qgsort.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>


//菜单
void menu()
{
	printf("*************目录********************\n");
	printf("******    1.一个数组大量数据    *****\n");
	printf("******    2.大量小数组          *****\n");
	printf("******    0.结束                *****\n"); 
	printf("*************************************\n");
}


//菜单1
void menu1()
{
	printf("*************目录********************\n");
	printf("******    1.插入排序            *****\n");
	printf("******    2.归并排序            *****\n");
	printf("******    3.快排排序            *****\n");
	printf("******    4.计数排序            *****\n");
	printf("******    5.基数计数排序        *****\n");
	printf("******    0.结束                *****\n"); 
	printf("*************************************\n");
}


//菜单2
void menu2()
{
	printf("*************目录********************\n");
	printf("******    1.颜色排序            *****\n");
	printf("******    2.无序找第几小的数    *****\n");
	printf("******    0.结束                *****\n"); 
	printf("*************************************\n");
}


//一个函数，防止乱输 
int select(){ 
	int num;
	while((scanf("%d",&num)) != 1){
		printf("输入错误，请重新输入：");
		while(getchar()!='\n');		//清理输出流 
	}	
	return num;
}

//插入排序
void insertSort(int *a,int n){
	
	int i, j, temp;
	i = j = temp = 0;
	//从a[1]开始 
	for(i = 1; i < n; i++){
		temp = a[i];
		j = i;
		while(j > 0 && temp < a[j -1]){
			a[j] = a[j - 1];
			j--;
		}
		a[j] = temp;
	}
}

//归并排序（合并数组）
void MergeArray(int *a,int begin,int mid,int end,int *temp){
	
	int i = begin;
	int j = mid + 1;
	int k = begin;
	while( i <= mid && j <= end){
		if(a[i] < a[j]){
			temp[k++] = a[i++];
		}
		else{
			temp[k++] = a[j++];
		}
	}
	//a[]有剩下的就让a[]剩下的赋给temp[] 
	while(i <= mid){
		temp[k++] = a[i++];
	}
	while(j <= end){
		temp[k++] = a[j++];
	}
	//temp[]赋给a[] 
	for(i = begin;i <= end; i++){
		a[i] = temp[i];
	}
}

//归并排序
void MergeSort(int *a,int begin,int end,int *temp){
	
	int mid = (begin + end)/2;
	if(begin < end ){
		//左边 
		MergeSort(a, begin, mid, temp);
		//右边 
		MergeSort(a, mid + 1,end, temp);
		//合并 
		MergeArray(a, begin, mid, end, temp);
	}
}

// 快速排序（递归版）
void QuickSort_Recursion(int *a, int begin, int end){
	
	int point;
	if(begin < end){
		//规定枢轴 
		point = Partition(a, begin, end);
		//左边 
		QuickSort_Recursion(a, begin, point - 1);
		//右边 
		QuickSort_Recursion(a, point + 1, end);
	}
}

//快速排序（枢轴存放）
int Partition(int *a, int begin, int end){
	
	int point;
	point = *(a + begin);
	while(begin < end){
		//从右边找比point小的 ，后交换  
		while(begin < end && *(a+end) >= point){
			end--;
		}
		swap(a, begin, end);
		//从左边找比point大的，后交换 
		while(begin < end && *(a+begin) <= point){
			begin++;
		}
		swap(a, begin, end);
	}
	return begin;
}

//交换两数 
void swap(int *a, int begin, int end){
	long long temp;
	temp = *(a+begin);
	*(a+begin) = *(a+end);
	*(a+end) = temp;
}

//计数排序
void CountSort(int *a, int size , int max){
	
	int *c, *b;
	int i;
	//临时数组， 需要(max+1)*sizeof(int)个储存单位 
	c = (int*)malloc(sizeof(int)*(max + 1)); 
	//存放排序结果的数组 
	b = (int*)malloc(sizeof(int)*size);
	for(i = 0; i <= max; i++){
		c[i] = 0;
	}
	for(i = 0; i < size; i++){
		//统计a[i]值出现的次数 
		c[a[i]] ++;
	}
	for(i = 1; i <= max; i++){
		//确定a[i]在c[]出现的位置 
		c[i] += c[i - 1];
	} 
	for(i = size - 1; i >= 0; i--){
		//对a[]，从后确定每个元素所在的最终位置 
		b[c[a[i]]-1] = a[i];
		c[a[i]] --;
	} 
	for(i = 0; i < size; i++){
		a[i] = b[i];
	}
	free(c);
	free(b);
}

//基数计数排序
void RadixCountSort(int *a,int size, int max){
	
	int i, b[size]; 
	int num = 1;
	//从个位到。。 
	while(max / num > 0){
		int c[10] = {0};
		//统计位数出现的次数 
		for(i = 0;i < size; i++){
			c[(a[i] / num)%10]++;
		}
		//确定位置 
		for(i = 1; i < 10; i++){
			c[i] += c[i - 1];
		}
		//从后最终确定位置 
		for(i = size -1; i >= 0; i--){
			b[--c[(a[i] / num) % 10]] = a[i];
		}
		for(i = 0; i < size; i++){
			a[i] = b[i];
		}
		num *= 10;
	} 
}

//颜色排序
void ColorSort(int *a,int size){
	
	//左边 
	int left = 0;
	//右边 
	int right = size - 1;
	//遍历 
	int p = 0;
	while(p <= right){
		if(a[p] == 0 && p >= left){
			swap(a, p, left);
			left++;
		}
		else if(a[p] == 2){
			swap(a, p, right);
			right--;
		}
		else{
			p++;
		}
	}
}


//在一个无序序列中找到第K小的数(自拟)
int SpecialCount(int *a, int begin, int end, int k){
	
	int point;
	int left = begin;
	int right = end;
	point = a[begin];
	while(left < right){
		//从右边找比point小的 
		while(begin < right && a[right] >= point){
			right--;
		}
		//从左边找比point大的 
		while(left < end && a[left] <= point){
			left++;
		}
		if(left < right){
			swap(a, left, right);
		}
	}
	a[begin] = a[right];
	a[right] = point;
	if(k == right){
		return a[right];
	}
	//左边 
	if(k < right){
		return SpecialCount(a, begin, right - 1, k);
	}
	//右边 
	else{
		return SpecialCount(a, right + 1, end, k);
	}
}

//打印数字 
void PrintCount(int *a, int size){
	
	int i; 
	for(i = 0; i < size; i++){
		printf("%d ",a[i]);
	}
}

//创建随机数组并找到最大值 
int MaxandCreatCount(int *a,int size){
	
	int i, max;
	max = 0;
//	for(i = 0; i < size; i++){
//		a[i] = rand();
//	}
	for(i = 0; i < size; i++){
		if(a[i] > max){
			max = a[i];
		}
	}
	return max;
}

//int MaxandCreativeTCount(int *a, int size, int size){
//	
//	for(i = 0; i < 1000; i++){
//		for(j = 0;j < 100; j++){
//			array[i][j] = rand();
//		}
//	}
//	for(i = 0; i < 1000; i++){
//		for(j = 0;j < 100; j++){
//			if(max[i] < array[i][j]){
//				max[i] = array[i][j];
//			}
//		}
//	}
//}
