#include "SqList.h"
#include <stdio.h>
#include <stdlib.h>

SqList *initSqList(unsigned capacity)
{
    // 为顺序表表头及数据域申请空间
    SqList *list = (SqList *)malloc(sizeof(SqList));
    list->data = (int *)calloc(capacity, sizeof(int));

    // 初始化表头
    list->size = 0;
    list->capacity = capacity;

    return list;
}

bool destroySqList(SqList *list)
{
    // 释放申请的空间
    free(list->data);
    free(list);

    return true;
}

bool insertSqList(SqList *list, int position, int new_data)
{
    // 判断插入位置是否合法，若不合法，返回false
    if (position < 0 || position > list->size)
        return false;

    // 判断是否有闲置存储空间，若没有，进行扩容
    // 若扩容失败，返回false
    if (list->size >= list->capacity && !enlargeSqList(list))
        return false;

    // 将要插入位置后的元素依次向后移动一个位置
    for (int i = list->size; i > position; i--)
        list->data[i] = list->data[i - 1];

    // 将新元素插入，更新表头
    list->data[position] = new_data;
    list->size++;

    return true;
}

bool enlargeSqList(SqList *list)
{
    // 申请更大的数据域
    int new_capacity = list->capacity << 1;
    int *new_data = realloc(list->data, sizeof(int) * new_capacity);

    // 更新表头
    list->data = new_data;
    list->capacity = new_capacity;

    return true;
}

bool deleteSqList(SqList *list, int position)
{
    // 判断删除位置是否合理
    if (position < 0 || position >= list->size)
        return false;

    // 覆盖该元素
    // 将该位置后的元素依次向前移动一个位置
    for (int i = position; i < list->size - 1; i++)
        list->data[i] = list->data[i + 1];

    // 更新表头
    list->size--;

    return true;
}

int findSqList(SqList *list, int target)
{
    // 遍历顺序表，若找到目标，则返回索引
    for (int i = 0; i < list->size; i++)
        if (list->data[i] == target)
            return i;

    return -1;
}
