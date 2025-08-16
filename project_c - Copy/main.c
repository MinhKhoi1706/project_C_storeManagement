#include <stdio.h>
#include "function.h"

int main() {
	loadFile("category.txt");
	loadProductFile("product.txt"); 
	role();
	saveFile("category.txt");
	saveProductFile("product.txt"); 
	return 0;
}


