//khai bao struct
#ifndef DATATYPE_H
#define MAX_CATEGORY 100
#define DATATYPE_H


typedef struct {
    char categoryId[10];
    char categoryName[101];
}Category;

extern int categoryCount;
extern Category categories[MAX_CATEGORY];

#endif


