#include "wd_exercise.h"
#include <stdio.h>

bool deleteMin(SqList *list)
{
    // 若顺序表为空，输出错误信息并退出
    if (list->size == 0)
    {
        fprintf(stderr, "List is empty!\n");
        return false;
    }

    // 寻找最小元素的索引
    int min_pos = 0;
    for (int i = 1; i < list->size; i++)
        if (list->data[min_pos] > list->data[i])
            min_pos = i;

    // 覆盖最小元素
    for (int i = min_pos; i < list->size - 1; i++)
        list->data[i] = list->data[i + 1];

    return true;
}

void reverseSqList(SqList *list)
{
    int tmp;
    for (int i = 0; i < list->size / 2; i++)
    {
        tmp = list->data[i];
        list->data[i] = list->data[list->size - i - 1];
        list->data[list->size - i - 1] = tmp;
    }
}

void deleteX(SqList *list, int x)
{
    int slow = 0;
    for (int fast = 0; fast < list->size; fast++)
        if (list->data[fast] != x)
            list->data[slow++] = list->data[fast];

    list->size = slow;
}

void deleteStoT(SqList *list, int s, int t)
{
    if (s >= t)
        fprintf(stderr, "The values of s and t are illegal!\n");

    if (list->size == 0)
        fprintf(stderr, "List is empty!\n");

    int slow = 0;
    for (int fast = 0; fast < list->size; fast++)
        if (list->data[fast] < s || list->data[fast] > t)
            list->data[slow++] = list->data[fast];

    list->size = slow;
}

void deleteDuplicates(SqList *list)
{
    if (list->size == 1) return;

    int slow = 1;
    for (int fast = 1; fast < list->size; fast++) 
        if (list->data[fast] != list->data[fast - 1])
            list->data[slow++] = list->data[fast];
    
    list->size = slow;
}

SqList *mergeSqList(SqList *source1, SqList *source2)
{
    SqList *new_list = initSqList(source1->size + source2->size);

    int i = 0, j = 0, k = 0;
    while (i < source1->size && j < source2->size) {
        if (source1->data[i] <= source2->data[j]) 
            new_list->data[k++] = source1->data[i++];
        else
            new_list->data[k++] = source2->data[j++];
    }

    while (i < source1->size) 
        new_list->data[k++] = source1->data[i++];
    while (j < source2->size)
        new_list->data[k++] = source2->data[j++];

    new_list->size = k;

    return new_list;
}
