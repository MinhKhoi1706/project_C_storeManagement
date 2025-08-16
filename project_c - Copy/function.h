//khai bao ham
#define FUNCTION_H
#include "datatype.h"

void login();
int mainMenu();
void menu();

void productMenu();
void addProduct();
void showAllProduct();
void editProduct();
void deleteProduct();

void addCategory();
void showAllCategory();
void editCategory();
void deleteCategory();
void sortCategoryByName(int n);
void sortCategoryMenu();
void searchCategory();
void renderCategory();
void backToMenu();
void saveFile(const char *file);
void loadFile(const char *file);


