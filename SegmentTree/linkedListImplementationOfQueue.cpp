#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* next;
};


void enQueue(int data,struct node** rear,struct node** head)
{

	if((*head)==NULL)
	{
		(*head)=(struct node*) malloc(sizeof(struct node));
		(*head)->data=data;
		(*head)->next=NULL;
		(*rear)=(*head);
	}
	else{

	struct node* new_mem = (struct node*) malloc(sizeof(struct node));
	new_mem->data = data;
	new_mem->next=NULL;

	(*rear)->next = new_mem;
	(*rear)= new_mem;
	}


}

void deQueue(struct node** head)
{
	if((*head)==NULL)
	{
		cout<<"error"<<endl;
		exit(0);
	}
	else
	{
		struct node* q = (*head);
		cout<<q->data<<endl;

	(*head) = (*head)->next;

	free(q);
	}
	
}


int main(){

	struct node* head = NULL;
	struct node* rear = (struct node*) malloc(sizeof(struct node));
	
	enQueue(5,&rear,&head);
	enQueue(6,&rear,&head);
	deQueue(&head);
	deQueue(&head);
	enQueue(7,&rear,&head);
	
	deQueue(&head);
	deQueue(&head);


}