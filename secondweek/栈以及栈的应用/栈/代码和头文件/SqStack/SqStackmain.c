#include "../head/SqStack.h" 
#include "SqStack.c" 


int main(){
	
	int i,n;
	SqStack *s;
	s = NULL;
	ElemType *e, *data, num;
	int *length;
	e = (ElemType*)malloc(sizeof(ElemType));
	data = (ElemType*)malloc(sizeof(ElemType));
	length =(int*)malloc(sizeof(int));
	 do{
	 	menu();
	 	printf("\n\n请输入指令：");
	 	i = select();
	 	switch(i){
	 		case 1:
	 			n = initStack(&s);
	 			if(n == 1){
	 				printf("\n初始化成功\n");
				}
				if(n == 0){
					printf("\n初始化失败\n");
				} 
	 			break;
	 		case 2:
	 			n = isEmptyStack(s);
	 			if(n == 1){
	 				printf("\n栈为空\n");
				}
				if(n == 0){
					printf("\n栈不空\n");
				} 
	 			break;
			case 3:
				n = getTopStack(s, e); //得到栈顶元素
				if(n == 1){
	 				printf("\n元素为%d\n",*e);
				}
				if(n == 0){
					printf("\n无\n");
				} 
				break;
			case 4:
				n = clearStack(s);//清空栈
				if(n == 1){
	 				printf("\n已清空\n");
				}
				if(n == 0){
					printf("\n清除失败\n");
				} 
				break;
			case 5:	
				n = destroyStack(s);//销毁栈
				if(n == 1){
	 				printf("\n销毁成功\n");
				}
				if(n == 0){
					printf("\n销毁失败\n");
				} 
				break;
			case 6:
				n = stackLength(s,length);//检测栈长度
				if(n == 1){
	 				printf("\n长度为%d\n",*length);
				}
				if(n == 0){
					printf("\n无初始化\n");
				} 
				break;
			case 7:	
				printf("\n请输入元素：");
				num = select(); 
				n = pushStack(s, num);//入栈
				if(n == 1){
	 				printf("\n入栈成功\n");
				}
				if(n == 0){
					printf("\n入栈失败\n");
				} 
				break;
			case 8:
				n = popStack(s, data);//出栈
				if(n == 1){
	 				printf("\n出栈元素为%d\n",*data);
				}
				if(n == 0){
					printf("\n出栈失败\n");
				} 
				break;
			case 9:
				printStack(s);
				break;
			case 0:
				printf("\nEND\n");
				break;
			default:
				printf("输入错误，请重新输入\n");	 			
		 }
		 printf("\n\n");
		 if(i != 0){
			system("pause");  //暂停
			system("cls");  //清屏
	 }
	 }while( i != 0);
	return 0;
}
