#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int val;
	struct Node *next;
}NODE_T;

void display(NODE_T *top);
NODE_T* insert(NODE_T *node, NODE_T *top); //insert in the tail
NODE_T* insert_sorted(NODE_T *node, NODE_T *top); //insert in sorted
NODE_T* delete(NODE_T *head, int key); // delete from list
NODE_T* deleteDuplicates(NODE_T *head); // remove duplicates 

int collection[] = {1,2,5,3,8};

int main(int argc, char *argv[])
{
	NODE_T* nd;
	NODE_T* head;

	nd = malloc(sizeof(NODE_T));
	nd->val = 1;
	nd->next = NULL;
	printf("add elements : %d\n", nd->val);
    //head = insert(nd, head);	
	head = insert_sorted(nd, head);	
	
    
	nd = malloc(sizeof(NODE_T));
	nd->val = 3;
	nd->next = NULL;
	printf("add elements : %d\n", nd->val);
    //head = insert(nd, head);	    
	head = insert_sorted(nd, head);	
    
	nd = malloc(sizeof(NODE_T));
	nd->val = 2;
	nd->next = NULL;
	printf("add elements : %d\n", nd->val);
    //head = insert(nd, head);	    
	head = insert_sorted(nd, head);	

	/*for(int i=0; i<sizeof(collection)/sizeof(int); i++)
	{
		nd = malloc(sizeof(NODE_T));
		nd->val = collection[i];
		nd->next = NULL;
		printf("add elements : %d\n", collection[i]);
	    head = insert(nd, head);
	}*/
	
	display(head);
	
	head = delete(head, 1);
	
	display(head);
	
	return 0;
}

void display(NODE_T *top)
{
	printf("elements in the list: ");
	while(top)
	{
		printf("%d ", top->val);		
		top = top->next;
	}
	printf("\n");
}

NODE_T* insert(NODE_T *node, NODE_T *top)
{
	NODE_T* pre_node;
	
	pre_node = top;
	
	if(pre_node==NULL)
	{
		top = node;
	}else
	{
		while(pre_node->next)
		{
			pre_node = pre_node->next;
		}
		pre_node->next = node;
	}
	return top;
}

NODE_T* insert_sorted(NODE_T *node, NODE_T *top)
{
	NODE_T* pre_node;
	NODE_T* cur_node;
	
	pre_node = top;
	cur_node = top;
	
	if(top == NULL)
	{
		top = node;
		return top;
		
	}
	
	while(cur_node && cur_node->val < node->val)
	{
		pre_node = cur_node;
		cur_node = cur_node->next;
	}
	
	pre_node->next = node;
	node->next = cur_node;
	
	return top;
}

NODE_T* delete(NODE_T *head, int key)
{
	NODE_T* cur_node;
	NODE_T* pre_node;
	NODE_T* free_node;
	NODE_T* new_head;
	
	cur_node = head;
	pre_node = cur_node;
	new_head = head;
	
	while(cur_node)
	{
		if(cur_node->val == key)
		{
			if(pre_node != cur_node)
			{
				pre_node->next = cur_node->next;
			}else
			{
				pre_node = pre_node->next;
				head = pre_node;
				new_head = pre_node;
			}
			free_node = cur_node;
			cur_node = cur_node->next;
			free(free_node);

		}else
		{
			pre_node = cur_node;
			cur_node = cur_node->next;
		}		

	}
	
	return new_head;
	
}

