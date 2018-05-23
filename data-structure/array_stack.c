#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 100 /*定義最大堆疊容量*/
int stack[MAXSTACK];  //堆疊的陣列宣告 
int top=-1;		//堆疊的頂端
int isEmpty();
void push(int); 
int pop();
 
int main(int argc, char *argv[]) {

	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	push(7);
	
	while(!isEmpty()){
		printf("堆疊彈出的順序為:%d\n",pop()); 
	}
	pop();
	return 0;
}
/*判斷是否為空堆疊*/
int isEmpty(){
	if(top==-1){
		return 1; 
	}else{
		return 0;
	}
} 
/*將指定的資料存入堆疊*/
void push(int data){
	if(top>=MAXSTACK){
		printf("堆疊已滿,無法再加入\n");	
	}else{
		top++;
		stack[top]=data;
	}
 
} 
/*從堆疊取出資料*/
int pop(){
	int data;
	if(isEmpty()){
		printf("堆疊已空\n");
	}else{
		data=stack[top];
		top--;
		return data; 
	}
}