/*
 * =====================================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年01月18日 09时53分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  changgongxiaorong, cgxryy@gmail.com
 *        Company:  Class 1203 of Network Engineering
 *
 * =====================================================================================
 */


#include <malloc.h>
#include <string.h>
#include "stack.h"

int stack_init(Stack **head)
{
	if ((*head = malloc(sizeof(Stack))) == NULL)
	      return 0;

	(*head)->next = NULL;
	return 1;
}

int stack_empty(Stack *head)
{
	if (head->next == NULL)
	      return 1;
	else  return 0;
}

int stack_push(Stack *head, void *temp, int size)
{
	Stack *push;
	
	//new point
	if ((push = (Stack *)malloc(sizeof(Stack))) == NULL)
	      return 0;
	
	//data copy
	if ((push->pointer = malloc(size)) == NULL)
	      return 0;
	memcpy(push->pointer, temp, size);
	push->elem_size = size;
	
	//push
	push->next = head->next;
	head->next = push;

	return 1;
}

int stack_pop(Stack *head, void *temp, int size)
{
	Stack *del;

	if (stack_empty(head))
	      return 0;

	memcpy(temp, head->next->pointer, size);
	del = head->next;
	head->next = head->next->next;
	free(del);

	return 1;
}

int stack_gettop(Stack *head, void *temp, int size)
{
	if (stack_empty(head))
	      return 0;

	memcpy(temp, head->next->pointer, size);
	return 1;
}

int stack_dis(Stack *head)
{
	Stack *del_next;

	if (head == NULL)
	      return 0;

	if (head->next == NULL)
	      free(head);

	for ( del_next = head->next; del_next != NULL; del_next = del_next->next)
	      free(head);

	return 1;
}


