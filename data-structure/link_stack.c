#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node{
	int data; 
	struct Node *next;  
}Stack_Node, *Linked_Stack;

Linked_Stack top=NULL; //指向堆疊頂端的指標 
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
	if(top==NULL){
		return 1; 
	}else{
		return 0;
	}
} 
/*將指定的資料存入堆疊*/
void push(int data){
	Linked_Stack new_add_node;  //新加入節點的指標
	/*配置新節點的記憶體*/
	new_add_node=(Linked_Stack)malloc(sizeof(Stack_Node));
	new_add_node->data=data;  //將傳入的值設為節點的內容 
	new_add_node->next=top;   //將新節點指向堆疊的點端 
	top=new_add_node;  //新節點成為堆疊的頂端 
} 
/*從堆疊取出資料*/
int pop(){
	Linked_Stack ptr;  //指向堆疊頂端的指標
	int temp;
	if(isEmpty()){
		printf("堆疊為空\n");
		return -1;
	}else{
		ptr=top;  //指向堆疊的頂端
		temp=ptr->data; //取出堆疊資料
		top=top->next; //將堆疊頂端的指標指向下一個節點 
		free(ptr); //將節點占用的記憶體釋放
		return temp; 
	}
}