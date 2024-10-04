#ifndef SQLIST_H
#define SQLIST_H

#include <stdbool.h>

typedef struct SqList
{
    int *data;
    unsigned size;
    unsigned capacity;
} SqList;

// 初始化顺序表
SqList *initSqList(unsigned capacity);
// 销毁顺序表
bool destroySqList(SqList *list);

// 在指定位置插入元素
bool insertSqList(SqList *list, int position, int new_data);
// 对顺序表扩容
bool enlargeSqList(SqList *list);
// 删除指定位置的元素
bool deleteSqList(SqList *list, int position);
// 查找某个元素的索引
int findSqList(SqList *list, int target);

#endif