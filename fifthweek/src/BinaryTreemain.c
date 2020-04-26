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
		printf("\n\n请输入指令：");
		i = select();
		switch(i){
			case 1:
				InitBiTree(&T);
				break;
			case 2:
				if(T == NULL){
					printf("\n未初始化\n");
					break;
				}
				DestroyBiTree(&T);
				break;
			case 3:
				if(T == NULL){
					printf("\n未初始化\n");
					break;
				}
				printf("\n #代表叶子节点 \n");
				printf("eg: '1##','123###4##'(1就是一个根节点)\n");
				printf("    1           1         \n");
				printf("   / \\         / \\         \n");
			 	printf("  #   #       2   4        \n");    
			 	printf("             / \\ / \\     \n");
			 	printf("            3  # #  #   \n");
			 	printf("           / \\          \n");
			 	printf("          #   #       \n");
			 	printf("请输入（字符类型）数据:");
				getchar();  //接收回车 
				CreateBiTree(&T);

				break;
			case 4:
				if(T == NULL){
					printf("\n未初始化\n");
					break;
				}
				printf("\n元素为：");
				PreOrderTraverse(T,APrint);
				break;
			case 5:
				if(T == NULL){
					printf("\n未初始化\n");
					break;
				}
				printf("\n元素为：");
				InOrderTraverse(T,APrint);
				break;
			case 6:
				if(T == NULL){
					printf("\n未初始化\n");
					break;
				}
				printf("\n元素为：");
				PostOrderTraverse(T,APrint);
				break;
			case 7:
				if(T == NULL){
					printf("\n未初始化\n");
					break;
				}
				printf("\n元素为：");
				LevelOrderTraverse(T, APrint);
				break;
			case 8:
				printf("\n1、自己输入前缀表达式\n2、看例子\n");
				printf("指令：");
				n =  select();
				while(n > 2 || n < 1){
					printf("\n输入错误，请重新输入\n");
					n =  select();
				}
				if(n == 1){
					printf("\n请输入前缀表达式："); 
					scanf("%s",a); 
					num = strlen(a);
					T = PerTree(a,num);
					printf("\n输出：");
					InOrderTraverse(T,APrint);
					sum = Value(T);
					printf(" = %d",sum);
				}
				else if(n == 2){
					printf("\n前缀表达式：%s",s);
					T = PerTree(s,strlen(s));
					printf("\n输出：");
					InOrderTraverse(T,APrint);
					sum = Value(T);
					printf(" = %d",sum);
				}
				break;
			case 0:
				printf("\nEND\n"); 
				break;
			default:
				printf("\n输入错误，请重新输入\n");	 
		}
		printf("\n\n");
		if(i != 0){
			system("pause");  //暂停
			system("cls");  //清屏
	 }
	}while(i != 0);
	return 0;
}
