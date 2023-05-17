// module to interact with linked lists.
#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
struct node *createnode(int value)
{
	struct node *newnode;
	newnode = (node *)malloc(sizeof(struct node));
	if (newnode != NULL)
	{
		newnode->data = value;
		newnode->next = NULL;
	}
	return newnode;
}
struct node * insertAtEnd(struct node **head, int value)
{
	struct node *newnode = createnode(value);
	if (newnode == NULL)
	{
		
	}
	if ((*head) == NULL)
	{
		(*head) = newnode;
		
	}
	else
	{
		struct node *temp = (*head);
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
		
	}
	return newnode;
}
struct node * insertAtBeginning(struct node **head, int value)
{
	struct node *temp = createnode(value);
	if (temp == NULL)
	{

	}
	if ((*head) == NULL)
	{
		(*head) = temp;
	}
	else
	{
		temp->next = (*head);
		(*head) = temp;
		
	}
	return temp;
}
int deleteFirst(struct node **head)
{
	if ((*head) == NULL)
	{
		return 0;
	}
	else
	{
		struct node *temp = *head;
		int value = temp->data;
		(*head) = temp->next;
		free(temp);
		return value;
	}
}
int deleteLast(struct node **head)
{
	if ((*head) == NULL)
	{
		return 0;
	}
	else
	{
		struct node *temp = *head;
		while ((temp->next)->next != NULL)
		{
			temp = temp->next;
		}
		struct node *del = temp->next;
		temp->next = NULL;
		int val = del->data;
		free(del);
		return val;
	}
}
// int display(struct node *head)
// {
// 	while (head != NULL)
// 	{
// 		printf(" %d", head->data);
// 		head = head->next;
// 	}
// }
int insertAfter(struct node **head, int value, int pos)
{
	int counter = 1;
	int success = 0;
	struct node *temp = (*head);
	struct node *insert = createnode(value);
	if (insert == NULL)
	{
		return 0;
	}
	if ((*head) == NULL)
	{
		return 0;
	}
	if ((*head)->next == NULL && pos == 1)
	{
		insert->next = (*head);
		(*head) = insert;
		return 0;
	}
	else
	{
		do
		{
			if (counter == pos - 1)
			{
				struct node *nextnode = temp->next;
				temp->next = insert;
				insert->next = nextnode;
				success = 1;
				break;
			}
			counter++;
			temp = temp->next;
		} while (temp != NULL);
		if (success == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}
int deleteAt(struct node **head, int pos)
{
	int counter = 1;
	int success = 0;
	struct node *temp = (*head);
	if ((*head) == NULL)
	{
		return 0;
	}
	if ((*head)->next == NULL && pos == 1)
	{
		(*head) = NULL;
		int data = temp->data;
		free(temp);
		return data;
	}
	else
	{
		while (temp != NULL)
		{
			if (counter == pos - 1)
			{
				int data = (temp->next)->data;
				struct node *todel = temp->next;
				temp->next = todel->next;
				free(todel);
				success = 1;
				return data;
			}
			counter++;
			temp = temp->next;
		}
		return 0;
	}
}
int deleteElement(struct node **head, int value)
{
	struct node *temp = (*head);
	if ((*head) == NULL)
	{
		return 0;
	}
	if ((*head)->next == NULL && value == (*head)->data)
	{
		(*head) = NULL;
		int data = temp->data;
		free(temp);
		return data;
	}
	else
	{
		while (temp->next != NULL)
		{
			if ((temp->next)->data == value)
			{
				int data = (temp->next)->data;
				struct node *todel = temp->next;
				temp->next = todel->next;
				free(todel);
			}
			temp = temp->next;
		}
		return 0;
	}
}
int reverse(struct node **head){
	struct node *temp,*curr,*prev,*ptr;
	temp = *head;
	if((*head) == NULL||(*head)->next == NULL){
		return 0;
	}
	else{
		curr = *head;
		prev = curr->next;
		curr->next = NULL;
		while(prev->next != NULL){
			ptr = prev->next;
			prev->next = curr;
			curr=prev;
			prev = ptr;
		}
		prev->next = curr;
		*head = prev;
	}

}
int displayReverse(struct node *head){
	if(head->next == NULL){
		printf(" %d ",head->data);
	}
	else{
		displayReverse(head->next);
		printf(" %d ",head->data);
	}
}
struct node * search(struct node *head,int value){
	struct node *res = NULL;
	while(head != NULL){
		if(head->data == value){
			res = head;
		}
	}
	return res;
}