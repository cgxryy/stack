/*
 * =====================================================================================
 *
 *       Filename:  calculate.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年01月18日 22时10分59秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  changgongxiaorong, cgxryy@gmail.com
 *        Company:  Class 1203 of Network Engineering
 *
 * =====================================================================================
 */
#include <stdio.h>
#include "stack.h"
#include "calculate.h"

inline int judge_opt(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '#')
	      return 1;
	return 0;
}

inline int judge_num(char ch)
{
	if ( ch >= '0' && ch <= '9')
	      return 1;
	return 0;
}

inline int judge_pri(char ch)
{
	if (ch == '#')
	      return -1;
	if (ch == '+' || ch == '-')
	      return 1;
	if (ch == '*' || ch == '/')
	      return 2;
	if (ch == '(' )
	      return 3;
	if (ch == ')')
	      return 4;

	return 0;
}

void my_scanf(char *s)
{
	while ((*s = (char)getchar()) != '\n')
	{
		s++;
	}
	*s = '\0';
}

void infix_to_postfix(char *infix, char *postfix)
{
	Stack 	*opt;
	char 	*in, *out;
	char 	temp;//always is the top value 
	int  	flag = 0;//end the do_while
	int 	flag_top = 0;//value is 1 when ')' occurs
	char 	end = '#';

	stack_init(&opt);
	stack_push(opt, (void*)&end, 1);

	for ( in = infix, out = postfix; *in != '\0'; in++, flag = 0)
	{
		if (*in == ' ' || *in == '\t')
		      continue;
		if (judge_num(*in))
		{
			*out = *in;
			out++;
		}
		else if (judge_opt(*in))
		{
			do
			{
				if (!stack_gettop(opt, (void*)&temp, 1))
				{
					stack_push(opt, (void*)in, 1);
				}
				else 
				{
					//judge priority choose situation
					//')' never push to the stack,it is a signal to find '('
					switch (compare(temp, *in))
					{
						// '#' '#'
						case 1:
							flag = 1;
							break;
						//priority *in higher than temp
						case 2:
							if (flag_top == 1)
							{
								flag_top = 0;
								flag = 1;
								stack_pop(opt, (void*)&temp, 1);
								*out = *in;
								out++;
							}
							else  
							{
								stack_push(opt, (void*)in, 1);
								flag = 1;
							}
							break;
						//priority *in lower than temp or the same as temp
						case 3:
							if (flag_top == 0 && temp == '(')
							{
								stack_push(opt, (void*)in, 1);
								flag = 1;
								break;
							}
							if (temp == '(')
							{
								*out = *in;
								out++;
								flag = 1;
								flag_top = 0;
							}
							else 
							{
								stack_pop(opt, (void*)out, 1);
								stack_push(opt, (void*)in, 1);
								out++;
								flag = 0;
							}
							break;
						//come ')'
						case 4:
							flag_top = 1;
							flag = 0;
							break;
						//come ')' pop '('
						case 5:
							stack_pop(opt, (void*)&temp, 1);
							flag = 1;
							break;
						default:
							printf("compare has a mistake!\n");
					}

					if (flag == 0)
					{
						stack_pop(opt, (void*)in, 1);
					}
				}
			}while (flag == 0);
		}
	}
	*out = '\0';

	stack_dis(opt);
}

int compare(char top, char ch)
{
	int v_top, v_ch;

	v_top = judge_pri(top);
	v_ch = judge_pri(ch);

	//come ')'
	if (v_ch == 4 && v_top != 3)
	      return 4;
	else if (v_ch == 4 && v_top == 3)
	      return 5;

	//come '(' the situation such as (((
	if (v_ch == 3)
	      return 2;

	//pre '(' come +-*/ but ')' doesn't occur
	if (v_top == 3 && v_ch <= 2)
	      return 2;

	//"##" means end
	if (v_top == -1 && v_ch == -1)
	      return 1;

	//pri +-*/
	if (v_top < v_ch)
	      return 2;
	if (v_top >= v_ch)
	      return 3;

	return 0;
}
