//khai bao struct
#ifndef DATATYPE_H
#define MAX_CATEGORY 100
#define MAX_PRODUCT 100
#define DATATYPE_H


typedef struct {
    char categoryId[10];
    char categoryName[10];
}Category;

typedef struct {
	char productId[10];
	char categoryId[10];
	char productName[10];
	int quantity;
	float price;
}Product;

extern int categoryCount;
extern Category categories[MAX_CATEGORY];

extern int productCount;
extern Product products[MAX_PRODUCT];

#endif


