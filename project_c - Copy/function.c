//trien khai ham
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "function.h"
#include "datatype.h"
#define MAX_CATEGORY 100
#define ADMIN_EMAIL "minhkhoi@gmail.com"
#define ADMIN_PASSWORD "1234"

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
        scanf("%s", password);

        
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

int categoryCount;
Category categories[MAX_CATEGORY];

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

    char tempName[101];
    int isValid;

    do {
        isValid = 1;
        printf("enter category name (max 100 character): ");
        fgets(tempName, sizeof(tempName), stdin);

        if (strchr(tempName, '\n') == NULL) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
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





