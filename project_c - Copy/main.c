#include <stdio.h>
#include "function.h"

int main() {
	loadFile("category.txt");
	role();
	saveFile("category.txt");
	return 0;
}


