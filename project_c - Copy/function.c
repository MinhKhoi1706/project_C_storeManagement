//trien khai ham
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "function.h"
#include "datatype.h"
//category
#define MAX_CATEGORY 100
//ADMIN
#define ADMIN_EMAIL "minhkhoi@gmail.com"
#define ADMIN_PASSWORD "1234"
//product
#define MAX_PRODUCT 100

int categoryCount;
Category categories[MAX_CATEGORY];

int productCount;
Product products[MAX_PRODUCT];

int role(){
	int choice;
	
	do{
		printf("\n***Student Management System Using C***\n");
		printf("\nCHOOSE YOUR ROLE\n");
		printf("================\n");
		printf("[1] Admin\n");
		printf("[0] Exit\n");
		printf("================\n");
		printf("enter your choice: ");
		scanf("%d",&choice);
		
		
		switch(choice){
			case 1: 
				login();
				break;
			
			case 0:
				printf("exit.");
				return 0;
			default:
				printf("invalid choice\n");
				return 0;	
		}	
	}while(choice != 0);
}


void inputPassword(char *password, int maxLen) {
    int i = 0;
    char ch;

    while (1) {
        ch = getch();
        if (ch == 13) { 
            password[i] = '\0';
            break;
        } 
        else if (ch == 8) { 
            if (i > 0) {
                i--;
                printf("\b \b"); 
            }
        } 
        else if (i < maxLen - 1) {
            password[i++] = ch;
            printf("*");
        }
    }
}

void login() {
    char email[20], password[10];
	system("cls");
	
    while (1) {
        printf("\n%22s","LOGIN\n");
        printf("minhkhoi@gmail.com\n");
        printf("1234\n");
        printf("=========================================\n");
        printf("Email: ");
        scanf("%s", email);
        printf("Password: ");
        inputPassword(password, sizeof(password));

        
        if (strcmp(email, ADMIN_EMAIL) == 0 && strcmp(password, ADMIN_PASSWORD) == 0) {
            printf("\nlogin successful\n");     
			mainMenu();       
            break;
        } else {
            printf("\nInvalid login! Please try again.\n");
        }
    }
}

int mainMenu() {
    int choice;
    while (1) {
        system("cls");
        printf("\n***System Management System Using C***\n");
		printf("\n=============MENU=============\n");
        printf("[1] category management\n");
        printf("[2] product management\n");
        printf("[0] log out\n");
        printf("=================================\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("cls");
    			menu();
                break;
            case 2:
                system("cls");
                productMenu();
                break;
            case 0:
                printf("\nlog out\n");
                system("cls");
                return 0;
            default:
                printf("invalid choice!\n");
                break;
        }
    }
}

//PRODUCT

void productMenu(){
	int choice;
	
	while(1){
		system("cls");
		printf("\n***System Management System Using C***\n");
		printf("\n=============MENU=============\n");
		printf("[1] add product\n");
        printf("[2] show all products\n");
        printf("[3] edit product\n");
        printf("[4] delete product\n");
        printf("[5] search product by name\n");
        printf("[6] sort products by price\n");
        printf("[7] filter products\n");
        printf("[0] exit\n");
        printf("====================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
		
		
		switch(choice){
			case 1:
                addProduct();
                break;
            case 2:
                showAllProduct();
                break;
            case 3:
                editProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            case 7:
                
                break;
            case 0:
                return;
            default:
                printf("invalid choice!\n");
                backToMenu();
                break;
		}
	}
	
}

void addProduct() {
    system("cls");
    if (productCount >= MAX_PRODUCT) {
        printf("product list is full!\n");
        return;
    }

    printf("\n=== enter product ===\n");

    char tempId[10];
    int isDuplicate;
    do {
        isDuplicate = 0;
        printf("product ID: ");
        scanf("%s", tempId);
        while (getchar() != '\n');
        for (int i = 0; i < productCount; i++) {
            if (strcmp(products[i].productId, tempId) == 0) {
                isDuplicate = 1;
                printf("ID already exists!\n");
                break;
            }
        }
    } while (isDuplicate);
    strcpy(products[productCount].productId, tempId);

    char tempName[12];
    int isValid;
    do {
        isValid = 1;
        printf("enter product name (max 10 characters): ");
        fgets(tempName, sizeof(tempName), stdin);
        if (strchr(tempName, '\n') == NULL) {
            while (getchar() != '\n');
            printf("name too long!\n");
            isValid = 0;
            continue;
        }
        tempName[strcspn(tempName, "\n")] = '\0';
        int allSpace = 1;
        for (int i = 0; tempName[i] != '\0'; i++) {
            if (tempName[i] != ' ') {
                allSpace = 0;
                break;
            }
        }
        if (strlen(tempName) == 0 || allSpace) {
            printf("name cannot be empty!\n");
            isValid = 0;
            continue;
        }
        for (int i = 0; i < productCount; i++) {
            if (strcmp(products[i].productName, tempName) == 0) {
                printf("product name already exists!\n");
                isValid = 0;
                break;
            }
        }
    } while (!isValid);
    strcpy(products[productCount].productName, tempName);

    do {
        printf("enter product price: ");
        if (scanf("%f", &products[productCount].price) != 1 || products[productCount].price <= 0) {
            printf("invalid price!\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    } while (1);
    while (getchar() != '\n');

    do {
        printf("enter product quantity: ");
        if (scanf("%d", &products[productCount].quantity) != 1 || products[productCount].quantity < 0) {
            printf("invalid quantity!\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    } while (1);
    while (getchar() != '\n');
	renderCategory();
    do {
        isValid = 0;
        printf("enter category ID: ");
        scanf("%s", products[productCount].categoryId);
        while (getchar() != '\n');
        for (int i = 0; i < categoryCount; i++) {
            if (strcmp(categories[i].categoryId, products[productCount].categoryId) == 0) {
                isValid = 1;
                break;
            }
        }
        if (!isValid) {
            printf("category ID does not exist!\n");
        }
    } while (!isValid);

    productCount++;
    printf("product added successfully!\n");
    saveProductFile("product.txt"); 
    backToMenu();
}

void showAllProduct() {
    system("cls");
    if (productCount == 0) {
        printf("no products available!\n");
        backToMenu();
        return;
    }

    printf("\n%-10s %-30s %-10s %-10s %-20s\n", 
           "ID", "Name", "Price", "Quantity", "Category");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < productCount; i++) {
        char categoryName[50] = "N/A";
        for (int j = 0; j < categoryCount; j++) {
            if (strcmp(products[i].categoryId, categories[j].categoryId) == 0) {
                strcpy(categoryName, categories[j].categoryName);
                break;
            }
        }
        printf("%-10s %-30s %-10.2f %-10d %-20s\n",
               products[i].productId,
               products[i].productName,
               products[i].price,
               products[i].quantity,
               categoryName);
    }
    backToMenu();
}

void editProduct() {
	system("cls");
    char id[10];
    int found = 0;

    printf("enter the product ID to edit: ");
    scanf("%s", id);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].productId, id) == 0) {
            found = 1;

            printf("current product name: %s\n", products[i].productName);
            getchar();
            printf("enter new product name: ");
            fgets(products[i].productName, sizeof(products[i].productName), stdin);
            products[i].productName[strcspn(products[i].productName, "\n")] = '\0';
			
			renderCategory();
            printf("current category ID: %s\n", products[i].categoryId);
            int isValid;
            do {
                isValid = 0;
                printf("enter new category ID: ");
                scanf("%s", products[i].categoryId);
                while (getchar() != '\n');
                for (int j = 0; j < categoryCount; j++) {
                    if (strcmp(categories[j].categoryId, products[i].categoryId) == 0) {
                        isValid = 1;
                        break;
                    }
                }
                if (!isValid) printf("category ID does not exist!\n");
            } while (!isValid);

            printf("current quantity: %d\n", products[i].quantity);
            printf("enter new quantity: ");
            scanf("%d", &products[i].quantity);

            printf("current price: %.2f\n", products[i].price);
            printf("enter new price: ");
            scanf("%f", &products[i].price);

            printf("product updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("no product found ID %s\n", id);
    }
    saveProductFile("product.txt"); 
    backToMenu();
}

void deleteProduct() {
    system("cls");

    if (productCount == 0) {
        printf("no products available to delete.\n");
        backToMenu();
        return;
    }

    char id[10];
    printf("enter the product ID to delete: ");
    scanf("%s", id);

    int found = -1;
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].productId, id) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("product ID not found!\n");
        backToMenu();
        return;
    }

    printf("product name: %s\n", products[found].productName);
    printf("are you sure you want to delete product?\n");
    printf("[1] yes\n");
    printf("[2] no\n");
    printf("enter your choice: ");

    int confirm;
    scanf("%d", &confirm);

    if (confirm == 1) {
        
        for (int i = found; i < productCount - 1; i++) {
            products[i] = products[i + 1];
        }
        productCount--;

        printf("product deleted successfully!\n");
        saveProductFile("product.txt"); 
    } else {
        printf("delete cancelled.\n");
    }
	
    backToMenu();
}

//luu file
void saveProductFile(const char *file) {
    FILE *f = fopen(file, "w");
    if (f == NULL) {
        printf("cannot open file to save products.\n");
        return;
    }
    for (int i = 0; i < productCount; i++) {
        fprintf(f, "%s|%s|%.2f|%d|%s\n",
            products[i].productId,
            products[i].productName,
            products[i].price,
            products[i].quantity,
            products[i].categoryId);
    }
    fclose(f);
    printf("\nproducts saved successfully\n");
}

void loadProductFile(const char *file) {
    FILE *f = fopen(file, "r");
    if (f == NULL) {
        printf("no existing product data found.\n");
        return;
    }

    productCount = 0;
    while (fscanf(f, "%[^|]|%[^|]|%f|%d|%[^\n]\n",
        products[productCount].productId,
        products[productCount].productName,
        &products[productCount].price,
        &products[productCount].quantity,
        products[productCount].categoryId) == 5) {
        
        productCount++;
        if (productCount >= MAX_PRODUCT) break;
    }

    fclose(f);
}


//CATEGORY
void menu(){
	int choice;
	
	while(1){
		system("cls");
		printf("\n***System Management System Using C***\n");
		printf("\n=============MENU=============\n");
		printf("[1] add category\n");
		printf("[2] show category\n");
		printf("[3] edit category\n");
		printf("[4] delete category\n");
		printf("[5] sort category\n");
		printf("[6] search category\n");
		printf("[0] exit\n");
		printf("=================================\n");
		
		printf("enter your choice: ");
		scanf("%d", &choice);
		
		switch (choice){
			case 1: 
				addCategory();
				break;
			
			case 2: 				
				showAllCategory();
				break;
				
			case 3: 
				editCategory();
				break;
			case 4: 
				deleteCategory();
				break;
				
			case 5: 
    			sortCategoryMenu();
    			break;
    			
    		case 6:
    			searchCategory();
    			break;
				
			case 0: 
				printf("exit.");
				return;					
			
			default:
				printf("invalid choice");
				break;
		}	
	}
	
}

void backToMenu() {
    char ch;
    printf("\n[0] back to menu: ");
    while (1) {
        ch = getch();  
        if (ch == '0') break;
        printf("\ninvalid choice. Press [0] to go back: ");
    }
    system("cls");
}


void addCategory() {
	system("cls");
    if (categoryCount >= MAX_CATEGORY) {
        printf("category list is full!\n");
        return;
    }

    printf("\n=== Enter category ===\n");

    char tempId[10];
    int isDuplicate;

    do {
        isDuplicate = 0;
        printf("category ID: ");
        scanf("%s", tempId);
        while (getchar() != '\n');

        for (int i = 0; i < categoryCount; i++) {
            if (strcmp(categories[i].categoryId, tempId) == 0) {
                isDuplicate = 1;
                printf("ID already exists.\n");
                break;
            }
        }
    } while (isDuplicate);

    strcpy(categories[categoryCount].categoryId, tempId);

    char tempName[12];
    int isValid;

    do {
        isValid = 1;
        printf("enter category name (max 10 character): ");
        fgets(tempName, sizeof(tempName), stdin);

        if (strchr(tempName, '\n') == NULL) {
            int ch;
            while ((ch = getchar()) != '\n');
            printf("name too long!\n");
            isValid = 0;
            continue;
        }

        tempName[strcspn(tempName, "\n")] = '\0';

        int allSpace = 1;
        for (int i = 0; tempName[i] != '\0'; i++) {
            if (tempName[i] != ' ') {
                allSpace = 0;
                break;
            }
        }

        if (strlen(tempName) == 0 || allSpace) {
            printf("name cannot be empty!\n");
            isValid = 0;
            continue;
        }

        for (int i = 0; i < categoryCount; i++) {
            if (strcmp(categories[i].categoryName, tempName) == 0) {
                printf("category name already exists!\n");
                isValid = 0;
                break;
            }
        }

    } while (!isValid);

    strcpy(categories[categoryCount].categoryName, tempName);
    categoryCount++;
    printf("category added successfully!\n");
	saveFile("category.txt");
  	backToMenu();
	return;
    
}

void renderCategory() {
	printf("\n*** CATEGORY LIST ***\n");
    printf("|--------------|-----------------------------|\n");
    printf("| Category ID  | Category Name               |\n");
    printf("|--------------|-----------------------------|\n");

    for (int i = 0; i < categoryCount; i++) {
        printf("| %-12s | %-27s |\n",
               categories[i].categoryId,
               categories[i].categoryName);
    }

    printf("|--------------|-----------------------------|\n");

}

void showAllCategory() {
	system("cls");
	printf("\n*** CATEGORY LIST ***\n");
    printf("|--------------|-----------------------------|\n");
    printf("| Category ID  | Category Name               |\n");
    printf("|--------------|-----------------------------|\n");

    for (int i = 0; i < categoryCount; i++) {
        printf("| %-12s | %-27s |\n",
               categories[i].categoryId,
               categories[i].categoryName);
    }

    printf("|--------------|-----------------------------|\n");
	backToMenu();
	return;
}

void editCategory() {
	system("cls");
    if (categoryCount == 0) {
        printf("\nno category available to edit!\n");
        return;
    }

    char id[10];
    printf("\nenter category ID to edit: ");
    scanf("%s", id);

    int found = -1;
    for (int i = 0; i < categoryCount; i++) {
        if (strcmp(categories[i].categoryId, id) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("\ncategory ID not found!\n");
        return;
    }

    printf("category name: %s\n", categories[found].categoryName);

    char newName[30];
    printf("new category name [%s]: ", categories[found].categoryName);
    getchar(); 
    fgets(newName, sizeof(newName), stdin);
    if (newName[0] != '\n') {
        newName[strcspn(newName, "\n")] = 0; 
        strcpy(categories[found].categoryName, newName);
    }

    printf("\nupdate successfully\n");
	saveFile("category.txt");
    backToMenu();
	return;
}

void deleteCategory() {
	system("cls");
    if (categoryCount == 0) {
        printf("\nno categories available to delete.\n");
        return;
    }

	char id[10];
    printf("\nenter the category id to delete: ");
    scanf("%s", id);

    int found = -1;
    for (int i = 0; i < categoryCount; i++) {
        if (strcmp(categories[i].categoryId, id) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("\ncategory id not found!\n");
        return;
    }

    printf("\ncategory name: %s\n", categories[found].categoryName);
    printf("are you sure you want to delete this category?\n");
    printf("[1] yes\n");
    printf("[2] no\n");
    printf("enter your choice: ");

    int confirm;
    scanf("%d", &confirm);

    if (confirm == 1) {
        for (int i = found; i < categoryCount - 1; i++) {
            categories[i] = categories[i + 1];
        }
        categoryCount--;

        printf("\ncategory deleted successfully!\n");
    } else {
        printf("\ndelete cancelled.\n");
    }
	saveFile("category.txt");
    backToMenu();
	return;
}

void sortCategoryByName(int n) {
	system("cls");
    if (categoryCount == 0) {
        printf("\nno categories to sort.\n");
        return;
    }

    for (int i = 0; i < categoryCount - 1; i++) {
        for (int j = i + 1; j < categoryCount; j++) {
            int cmp = strcmp(categories[i].categoryName, categories[j].categoryName);
            
            if ((n && cmp > 0) || (!n && cmp < 0)) {
                Category temp = categories[i];
                categories[i] = categories[j];
                categories[j] = temp;
            }
        }
    }

}

void sortCategoryMenu() {
    int choice;
    while (1) {
        system("cls");
        printf("\n=== SORT CATEGORY MENU ===\n");
        printf("[1] sort by name (ascending)\n");
        printf("[2] sort by name (descending)\n");
        printf("[0] back to menu\n");
        printf("==========================\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sortCategoryByName(1); 
                showAllCategory();
                return;
            case 2:
                sortCategoryByName(0); 
                showAllCategory();
                return;
            case 0:
                return;
            default:
                printf("invalid choice. try again.\n");
                break;
        }
    }
}

void searchCategory() {
	system("cls");
    if (categoryCount == 0) {
        printf("\ncategory not found.\n");
        return;
    }

    char name[30];
    printf("\nenter category name to search: ");
    scanf(" %[^\n]", name);

    for (int i = 0; name[i]; i++) {
        if (name[i] >= 'A' && name[i] <= 'Z') {
            name[i] += 32;
        }
    }

    int found = 0;

    for (int i = 0; i < categoryCount; i++) {
        char temp[101];
        strcpy(temp, categories[i].categoryName);
        for (int j = 0; temp[j]; j++) {
            if (temp[j] >= 'A' && temp[j] <= 'Z') {
                temp[j] += 32;
            }
        }
        if (strstr(temp, name) != NULL) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\ncategory not found\n");
    } else {
        printf("\n*** SEARCH RESULT ***\n");
        printf("|--------------|-----------------------------|\n");
        printf("| Category ID  | Category Name               |\n");
        printf("|--------------|-----------------------------|\n");

        for (int i = 0; i < categoryCount; i++) {
            char temp[101];
            strcpy(temp, categories[i].categoryName);
            for (int j = 0; temp[j]; j++) {
                if (temp[j] >= 'A' && temp[j] <= 'Z') {
                    temp[j] += 32;
                }
            }
            if (strstr(temp, name) != NULL) {
                printf("| %-12s | %-27s |\n",
                       categories[i].categoryId,
                       categories[i].categoryName);
            }
        }

        printf("|--------------|-----------------------------|\n");
    }

	backToMenu();
	saveFile("category.txt");
	return;
}

void saveFile(const char *file){
	FILE *f = fopen(file,"w");
	if(f == NULL){
		printf("cannot open file to save.\n");
		return;
	}
	for(int i = 0; i < categoryCount; i++){
		fprintf(f,"%s|%s\n",categories[i].categoryId, categories[i].categoryName);
	}
	fclose(f);
	printf("\nsave successfully");
}

void loadFile(const char *file) {
    FILE *f = fopen(file, "r");
    if (f == NULL) {
        printf("no existing data found.\n");
        return;
    }

    categoryCount = 0;
    while (fscanf(f, "%[^|]|%[^\n]\n", 
        categories[categoryCount].categoryId, 
        categories[categoryCount].categoryName) == 2) {
        
        categoryCount++;
        if (categoryCount >= MAX_CATEGORY) break;
    }

    fclose(f);
}





