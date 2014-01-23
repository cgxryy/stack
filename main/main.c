/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年01月18日 09时51分51秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  changgongxiaorong, cgxryy@gmail.com
 *        Company:  Class 1203 of Network Engineering
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "calculate.h"

int main(int argc, char *argv[])
{
/*	Stack *head;
	
	char a[10] = "123123";
	char b[10] = "456456";
	char c[10] = "789789";

	char d[10];

	stack_init(&head);
	stack_push(head, (void*)c, 10);
	stack_push(head, (void*)b, 10);
	stack_push(head, (void*)a, 10);
	
	stack_pop(head, (void*)d, 10);
	printf("%s\n", d);
	stack_pop(head, (void*)d, 10);
	printf("%s\n", d);
	stack_pop(head, (void*)d, 10);
	printf("%s\n", d);

	stack_dis(head);
*/
	char infix[50] = "9+(3-1)*3+10/2#";
	char postfix[50];

//	my_scanf(infix);
	printf("infix\t%s\n", infix);
	infix_to_postfix(infix, postfix);
	printf("postfix\t%s\n", postfix);
	
	return EXIT_SUCCESS;
}

