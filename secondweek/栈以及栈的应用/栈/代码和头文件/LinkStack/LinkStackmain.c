#include "../head/LinkStack.h" 
#include "LinkStack.c"


int main(){
	
	int i,n;
	LinkStack *s;
	s = NULL;
	ElemType *e, *data, num;
	int *length;
	e = (ElemType*)malloc(sizeof(ElemType));
	data = (ElemType*)malloc(sizeof(ElemType));
	length =(int*)malloc(sizeof(int));
	do{
		
		menu();
	 	printf("\n\n������ָ�");
	 	i = select();
	 	switch(i){
			case 1: 
				n = initLStack(&s);
	 			if(n == 1){
	 				printf("\n��ʼ���ɹ�\n");
				}
				if(n == 0){
					printf("\n��ʼ��ʧ��\n");
				} 
	 			break;
	 		case 2:
	 			n = isEmptyLStack(s);
	 			if(n == 1){
	 				printf("\nջΪ��\n");
				}
				if(n == 0){
					printf("\nջ����\n");
				} 
	 			break;
			case 3:
				n = getTopLStack(s, e); //�õ�ջ��Ԫ��
				if(n == 1){
	 				printf("\nԪ��Ϊ%d\n",*e);
				}
				if(n == 0){
					printf("\n��\n");
				} 
				break;
			case 4:
				n = clearLStack(s);//���ջ
				if(n == 1){
	 				printf("\n�����\n");
				}
				if(n == 0){
					printf("\n���ʧ��\n");
				} 
				break;
			case 5:	
				n = destroyLStack(&s);//����ջ
				if(n == 1){
	 				printf("\n���ٳɹ�\n");
				}
				if(n == 0){
					printf("\n����ʧ��\n");
				} 
				break;
			case 6:
				n = LStackLength(s,length);//���ջ����
				if(n == 1){
	 				printf("\n����Ϊ%d\n",*length);
				}
				if(n == 0){
					printf("\n�޳�ʼ��\n");
				} 
				break;
			case 7:	
				printf("\n������Ԫ�أ�");
				num = select(); 
				n = pushLStack(s, num);//��ջ
				if(n == 1){
	 				printf("\n��ջ�ɹ�\n");
				}
				if(n == 0){
					printf("\n��ջʧ��\n");
				} 
				break;
			case 8:
				n = popLStack(s, data);//��ջ
				if(n == 1){
	 				printf("\n��ջԪ��Ϊ%d\n",*data);
				}
				if(n == 0){
					printf("\n��ջʧ��\n");
				} 
				break;
			case 9:
				printLStack(s);
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
