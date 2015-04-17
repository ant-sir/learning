/*
 ============================================================================
 Name        : linklist.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};


struct node * add(int key, struct node *head)
{
	struct node* pnode_new = (struct node*)malloc( sizeof(struct node) );
	pnode_new->data = key;
	pnode_new->next = NULL;

	if( head == NULL )
	{
		head = pnode_new;
	}
	else
	{
		struct node* p = NULL;
		for(p = head; p->next != NULL; p = p->next);
		p->next = pnode_new;
	}
	return head;
}

void del_once(int key, struct node *head)
{
	struct node *p = NULL, *n = NULL;

	if(head == NULL)
	{
		return;
	}
	for(p = n = head; n->data != key && n->next != NULL; p = n, n = n->next);
	if(n->data == key)
	{
		if(n == head)
			head = n->next;
		else
			p->next = n->next;

		free(n);
	}
	else
	{
		printf("Couln't find the key.\n");
		return;
	}
	printf("Delete success.\n");
}
void del_all(int key, struct node *head)
{
	struct node *p = NULL, *n = NULL;
	/**
	 * 没有元素
	 */
	if(head == NULL)
		return;
	/**
	 * 只有一个元素或最后一个元素均不在此处理
	 */
	for(p = n = head; n->next != NULL; p = n, n = n->next)
	{
		if(n->data == key)
		{
			p->next = n->next;
			free(n);
			n = p;
		}
	}
	/**
	 * 处理只有一个元素或最后一个元素
	 */
	if(n->data == key)
	{
		if(n == head)
			head = n->next;
		else
			p->next = n->next;
		free(n);
	}

	printf("Delete all success.\n");
}
void linklist_print(struct node * head)
{
	for(; head->next != NULL; head = head->next)
	{
		printf("%d ", head->data);
	}
	printf("%d\n", head->data);
}

int test_linklist(void) {

	struct node* head = NULL;
	head = add(100, head);
	head = add(101, head);
	head = add(102, head);
	head = add(103, head);
	head = add(102, head);
	head = add(104, head);
	linklist_print(head);
	del_all(102, head);
	linklist_print(head);

	return 0;
}
