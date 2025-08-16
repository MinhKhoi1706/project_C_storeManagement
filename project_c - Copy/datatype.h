//khai bao struct
#ifndef DATATYPE_H
#define DATATYPE_H
#define MAX_CATEGORY 100
#define MAX_PRODUCT 100

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

#endif



