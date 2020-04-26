#include "../head/BinaryTree.h"
#include "BinaryTree.c"
#include<stdio.h>


int main(){
	
	BiTree T;
	int sum;
	int i, n, num, t;
	T = NULL;
	char s[MAX] = "+2*34";
	char a[MAX];
	num = 0;
	do{
		menu();
		printf("\n\n������ָ�");
		i = select();
		switch(i){
			case 1:
				InitBiTree(&T);
				break;
			case 2:
				if(T == NULL){
					printf("\nδ��ʼ��\n");
					break;
				}
				DestroyBiTree(&T);
				break;
			case 3:
				if(T == NULL){
					printf("\nδ��ʼ��\n");
					break;
				}
				printf("\n #����Ҷ�ӽڵ� \n");
				printf("eg: '1##','123###4##'(1����һ�����ڵ�)\n");
				printf("    1           1         \n");
				printf("   / \\         / \\         \n");
			 	printf("  #   #       2   4        \n");    
			 	printf("             / \\ / \\     \n");
			 	printf("            3  # #  #   \n");
			 	printf("           / \\          \n");
			 	printf("          #   #       \n");
			 	printf("�����루�ַ����ͣ�����:");
				getchar();  //���ջس� 
				CreateBiTree(&T);

				break;
			case 4:
				if(T == NULL){
					printf("\nδ��ʼ��\n");
					break;
				}
				printf("\nԪ��Ϊ��");
				PreOrderTraverse(T,APrint);
				break;
			case 5:
				if(T == NULL){
					printf("\nδ��ʼ��\n");
					break;
				}
				printf("\nԪ��Ϊ��");
				InOrderTraverse(T,APrint);
				break;
			case 6:
				if(T == NULL){
					printf("\nδ��ʼ��\n");
					break;
				}
				printf("\nԪ��Ϊ��");
				PostOrderTraverse(T,APrint);
				break;
			case 7:
				if(T == NULL){
					printf("\nδ��ʼ��\n");
					break;
				}
				printf("\nԪ��Ϊ��");
				LevelOrderTraverse(T, APrint);
				break;
			case 8:
				printf("\n1���Լ�����ǰ׺���ʽ\n2��������\n");
				printf("ָ�");
				n =  select();
				while(n > 2 || n < 1){
					printf("\n�����������������\n");
					n =  select();
				}
				if(n == 1){
					printf("\n������ǰ׺���ʽ��"); 
					scanf("%s",a); 
					num = strlen(a);
					T = PerTree(a,num);
					printf("\n�����");
					InOrderTraverse(T,APrint);
					sum = Value(T);
					printf(" = %d",sum);
				}
				else if(n == 2){
					printf("\nǰ׺���ʽ��%s",s);
					T = PerTree(s,strlen(s));
					printf("\n�����");
					InOrderTraverse(T,APrint);
					sum = Value(T);
					printf(" = %d",sum);
				}
				break;
			case 0:
				printf("\nEND\n"); 
				break;
			default:
				printf("\n�����������������\n");	 
		}
		printf("\n\n");
		if(i != 0){
			system("pause");  //��ͣ
			system("cls");  //����
	 }
	}while(i != 0);
	return 0;
}
