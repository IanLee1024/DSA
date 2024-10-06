#ifndef WD_EXERCISE_H
#define WD_EXERCISE_H

#include "SqList.h"
#include <stdbool.h>

/*
 * 01 题目描述：
 * 从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。
 * 空出的位置由最后一个元素填补，若顺序表为空，则输出错误信息并退出。
 */
bool deleteMin(SqList *list);

/*
 * 02 题目描述：
 * 设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)。
 */
void reverseSqList(SqList *list);

/*
 * 03 题目描述：
 * 对长度为n的顺序表L，编写一个时间复杂度为O(n)、时间复杂度为O(1)的算法，
 * 该算法删除顺序表中所有值为x的数据元素。 
 */
void deleteX(SqList *list, int x);

/*
 * 04 题目描述：
 * 从顺序表中删除其值在给定值s和t之间（包含s和t，要求s<t）的所有元素，
 * 若s或t不合理或顺序表为空，则显示出错信息并退出运行。
 */
void deleteStoT(SqList *list, int s, int t);

/*
 * 05 题目描述
 * 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
 */
void deleteDuplicates(SqList *list);

/*
 * 06 题目描述
 * 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。
 */
SqList *mergeSqList(SqList *source1, SqList *source2);

/*
 * 07 题目描述
 * 已知在一维数组A[m+n]中依次存放两个线性表（a1,a2,...,am）和（b1,b2,...,bn）。
 * 编写一个函数，将数组中两个顺序表的位置互换，即将（b1,b2,...,bn）放在（a1,a2,...,am）的前面。
 */



#endif