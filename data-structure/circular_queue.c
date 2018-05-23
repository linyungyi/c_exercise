#include<stdio.h>

#define SIZE 5

void push(int);
void pop();
void display();

int cQueue[SIZE], front = -1, rear = -1;

void main()
{

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);    
	display();
	
	pop();
	display();	

	pop();
	display();	
	
	pop();
	display();	
	
	pop();
	display();	
	
	pop();
	display();	
	
	pop();
	display();	
	
	pop();
	display();		


}
void push(int value)
{
   if(front == (rear+1)%SIZE)
      printf("\nCircular Queue is Full! Insertion not possible!!!\n");
   else{
      rear = (rear+1)%SIZE;
      cQueue[rear] = value;
      printf("\nInsertion Success!!!\n");
      if(front == -1)
	    front = 0;
   }
}
void pop()
{
   if(front == -1 && rear == -1)
      printf("\nCircular Queue is Empty! Deletion is not possible!!!\n");
   else{
       
      printf("\nDeleted element : %d\n",cQueue[front]);
      front = (front+1)%SIZE;
      if(front-1 == rear || (front==0 && rear == SIZE-1))
	    front = rear = -1;
   }
}
void display()
{
   if(front == -1)
      printf("\nCircular Queue is Empty!!!\n");
   else{
      int i = front;
      printf("\nCircular Queue Elements are : \n");
      if(front <= rear){
	 while(i <= rear)
	    printf("%d\t",cQueue[i++]);
      }
      else{
	 while(i <= SIZE - 1)
	    printf("%d\t", cQueue[i++]);
	 i = 0;
	 while(i <= rear)
	    printf("%d\t",cQueue[i++]);
      }
   }
}