#include "../inc/qgsort.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>


//�˵�
void menu()
{
	printf("*************Ŀ¼********************\n");
	printf("******    1.һ�������������    *****\n");
	printf("******    2.����С����          *****\n");
	printf("******    0.����                *****\n"); 
	printf("*************************************\n");
}


//�˵�1
void menu1()
{
	printf("*************Ŀ¼********************\n");
	printf("******    1.��������            *****\n");
	printf("******    2.�鲢����            *****\n");
	printf("******    3.��������            *****\n");
	printf("******    4.��������            *****\n");
	printf("******    5.������������        *****\n");
	printf("******    0.����                *****\n"); 
	printf("*************************************\n");
}


//�˵�2
void menu2()
{
	printf("*************Ŀ¼********************\n");
	printf("******    1.��ɫ����            *****\n");
	printf("******    2.�����ҵڼ�С����    *****\n");
	printf("******    0.����                *****\n"); 
	printf("*************************************\n");
}


//һ����������ֹ���� 
int select(){ 
	int num;
	while((scanf("%d",&num)) != 1){
		printf("����������������룺");
		while(getchar()!='\n');		//��������� 
	}	
	return num;
}

//��������
void insertSort(int *a,int n){
	
	int i, j, temp;
	i = j = temp = 0;
	//��a[1]��ʼ 
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

//�鲢���򣨺ϲ����飩
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
	//a[]��ʣ�µľ���a[]ʣ�µĸ���temp[] 
	while(i <= mid){
		temp[k++] = a[i++];
	}
	while(j <= end){
		temp[k++] = a[j++];
	}
	//temp[]����a[] 
	for(i = begin;i <= end; i++){
		a[i] = temp[i];
	}
}

//�鲢����
void MergeSort(int *a,int begin,int end,int *temp){
	
	int mid = (begin + end)/2;
	if(begin < end ){
		//��� 
		MergeSort(a, begin, mid, temp);
		//�ұ� 
		MergeSort(a, mid + 1,end, temp);
		//�ϲ� 
		MergeArray(a, begin, mid, end, temp);
	}
}

// �������򣨵ݹ�棩
void QuickSort_Recursion(int *a, int begin, int end){
	
	int point;
	if(begin < end){
		//�涨���� 
		point = Partition(a, begin, end);
		//��� 
		QuickSort_Recursion(a, begin, point - 1);
		//�ұ� 
		QuickSort_Recursion(a, point + 1, end);
	}
}

//�������������ţ�
int Partition(int *a, int begin, int end){
	
	int point;
	point = *(a + begin);
	while(begin < end){
		//���ұ��ұ�pointС�� ���󽻻�  
		while(begin < end && *(a+end) >= point){
			end--;
		}
		swap(a, begin, end);
		//������ұ�point��ģ��󽻻� 
		while(begin < end && *(a+begin) <= point){
			begin++;
		}
		swap(a, begin, end);
	}
	return begin;
}

//�������� 
void swap(int *a, int begin, int end){
	long long temp;
	temp = *(a+begin);
	*(a+begin) = *(a+end);
	*(a+end) = temp;
}

//��������
void CountSort(int *a, int size , int max){
	
	int *c, *b;
	int i;
	//��ʱ���飬 ��Ҫ(max+1)*sizeof(int)�����浥λ 
	c = (int*)malloc(sizeof(int)*(max + 1)); 
	//��������������� 
	b = (int*)malloc(sizeof(int)*size);
	for(i = 0; i <= max; i++){
		c[i] = 0;
	}
	for(i = 0; i < size; i++){
		//ͳ��a[i]ֵ���ֵĴ��� 
		c[a[i]] ++;
	}
	for(i = 1; i <= max; i++){
		//ȷ��a[i]��c[]���ֵ�λ�� 
		c[i] += c[i - 1];
	} 
	for(i = size - 1; i >= 0; i--){
		//��a[]���Ӻ�ȷ��ÿ��Ԫ�����ڵ�����λ�� 
		b[c[a[i]]-1] = a[i];
		c[a[i]] --;
	} 
	for(i = 0; i < size; i++){
		a[i] = b[i];
	}
	free(c);
	free(b);
}

//������������
void RadixCountSort(int *a,int size, int max){
	
	int i, b[size]; 
	int num = 1;
	//�Ӹ�λ������ 
	while(max / num > 0){
		int c[10] = {0};
		//ͳ��λ�����ֵĴ��� 
		for(i = 0;i < size; i++){
			c[(a[i] / num)%10]++;
		}
		//ȷ��λ�� 
		for(i = 1; i < 10; i++){
			c[i] += c[i - 1];
		}
		//�Ӻ�����ȷ��λ�� 
		for(i = size -1; i >= 0; i--){
			b[--c[(a[i] / num) % 10]] = a[i];
		}
		for(i = 0; i < size; i++){
			a[i] = b[i];
		}
		num *= 10;
	} 
}

//��ɫ����
void ColorSort(int *a,int size){
	
	//��� 
	int left = 0;
	//�ұ� 
	int right = size - 1;
	//���� 
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


//��һ�������������ҵ���KС����(����)
int SpecialCount(int *a, int begin, int end, int k){
	
	int point;
	int left = begin;
	int right = end;
	point = a[begin];
	while(left < right){
		//���ұ��ұ�pointС�� 
		while(begin < right && a[right] >= point){
			right--;
		}
		//������ұ�point��� 
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
	//��� 
	if(k < right){
		return SpecialCount(a, begin, right - 1, k);
	}
	//�ұ� 
	else{
		return SpecialCount(a, right + 1, end, k);
	}
}

//��ӡ���� 
void PrintCount(int *a, int size){
	
	int i; 
	for(i = 0; i < size; i++){
		printf("%d ",a[i]);
	}
}

//����������鲢�ҵ����ֵ 
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
