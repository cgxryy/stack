/*
 * =====================================================================================
 *
 *       Filename:  calculate.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年01月18日 22时09分48秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  changgongxiaorong, cgxryy@gmail.com
 *        Company:  Class 1203 of Network Engineering
 *
 * =====================================================================================
 */
inline int judge_opt(char ch);
inline int judge_num(char ch);
inline int judge_pri(char ch);

void my_scanf(char *s);

void infix_to_postfix(char *infix, char *postfix);
int  compare(char top, char ch);

//int  calculate();
