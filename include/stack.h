/*
 * =====================================================================================
 *
 *       Filename:  stack.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年01月18日 09时53分43秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  changgongxiaorong, cgxryy@gmail.com
 *        Company:  Class 1203 of Network Engineering
 *
 * =====================================================================================
 */
typedef struct stack
{
	void 	*pointer; 	//elem pointer
	int 	elem_size; 	//elem size
	struct stack *next; 	//next stack point
}Stack;


//return success 1 or fail 0

//initialize the stack
int stack_init(Stack **head);

//whether the stack is empty
int stack_empty(Stack *head);

//push the element to the stack
int stack_push(Stack *head, void *temp, int size);

//pop the element out of the stack
int stack_pop(Stack *head, void *temp, int size);

//get the top element 
int stack_gettop(Stack *head, void *temp, int size);

//destroy the stack
int stack_dis(Stack *head);
