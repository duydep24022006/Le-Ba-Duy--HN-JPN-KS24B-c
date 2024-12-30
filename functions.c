#include <stdio.h>
#include "functions.h"

void displayRoleMenu() {
    printf("\n***Bank Management System Using C***\n");
    printf("\n");
    printf("	CHOOSE YOUR ROLE\n");
    printf("     ======================\n");
    printf("	[1] Admin.\n");
    printf("	[2] User.\n");
    printf("	[0] Exit the Program.\n");
    printf("     ======================\n");
    printf("	Enter The Choice: ");
}

void displayLoginScreen() {
    printf("\n***Bank Management System Using C***\n");
    printf("\n");
    printf("		LOGIN\n");
    printf("     ======================\n");
    printf("     Email: test@gmail.com\n");
    printf("     Password: ******\n");
    printf("     ======================\n");
}

void displayMenu(){
	printf(" ***Student Management System Using C*** \n");
    printf("=========================================\n");
    printf("                  MENU                   \n");
    printf("=========================================\n");
    printf("[1] Add A New user.\n");
    printf("[2] Show All users.\n");
    printf("[3] Show detail an user.\n");
    printf("[4] Lock (Unlock) an user.\n");
    printf("[5] User Guideline.\n");
    printf("[6] About Us.\n");
    printf("[0] Exit the Program.\n");
    printf("=========================================\n");
    printf("Enter The Choice: ");
}
void displayExitMessage() {
	printf("\n");
    printf("==========  Thank You  ==========\n");
    printf("========== See You Soon =========\n");
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

bool isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
    if (month == 2) {
        // Kiểm tra tháng 2 (năm nhuận hay không)
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day > 29) return false;
        } else {
            if (day > 28) return false;
        }
    }
    return true;
}

bool isValidPhone(char *phone) {
    for (int i = 0; i < strlen(phone); i++) {
        if (phone[i] < '0' || phone[i] > '9') {
            return false;
        }
    }
    return true;
}

bool isValidBalance(double balance) {
    return (balance >= 0);
}

void saveUserToFile(User *user) {
    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Error opening file for saving user!\n");
        return;
    }
            user->userId, user->userName, user->name,
            user->dateOfBirth.day, user->dateOfBirth.month, user->dateOfBirth.year,
            user->gender, user->phone, user->email,
            user->UserAccount.balance, user->UserAccount.status;
    fclose(file);
    printf("\nUser added successfully!\n");
}

void addANewUser(User *user) {

    getchar();
    printf("Enter the user ID (10 characters): ");
    fgets(user->userId, 11, stdin);
    user->userId[strcspn(user->userId, "\n")] = '\0';

    while (strlen(user->userId) != 10) {
        printf("ID must be exactly 10 characters. Please enter again: ");
        fgets(user->userId, 11, stdin);
        user->userId[strcspn(user->userId, "\n")] = '\0';
    }

    printf("Enter the username: ");
    fgets(user->userName, 20, stdin);
    user->userName[strcspn(user->userName, "\n")] = '\0';

    printf("Enter the full name: ");
    fgets(user->name, 20, stdin);
    user->name[strcspn(user->name, "\n")] = '\0';
    
    do {
        printf("Enter the date of birth:\n");
        printf("    Enter the day: ");
        scanf("%d", &day);
        printf("    Enter the month: ");
        scanf("%d", &month);
        printf("    Enter the year: ");
        scanf("%d", &year);
    } while (!isValidDate(day, month, year));
    user->dateOfBirth.day = day;
    user->dateOfBirth.month = month;
    user->dateOfBirth.year = year;
    getchar();

    do {
        printf("Enter the gender (male=1, female=0): ");
        scanf("%d", &user->gender);
        printf("log 1 %d",user->gender);
    } while (user->gender != 0  || user->gender != 1);

    do {
        printf("Enter the phone (10 digits): ");
        fgets(user->phone, 11, stdin);
        user->phone[strcspn(user->phone, "\n")] = '\0';
    } while (!isValidPhone(user->phone));

    printf("Enter the email: ");
    fgets(user->email, 20, stdin);
    user->email[strcspn(user->email, "\n")] = '\0';

    // Nhập số dư tài khoản
    double balance;
    do {
        printf("Enter the account balance: ");
        scanf("%lf", &balance);
    } while (balance < 0); // Bạn có thể kiểm tra điều kiện khác nếu cần
    user->UserAccount.balance = balance;

    user->UserAccount.status = true;

    

    saveUserToFile(user);
}

void inputPassword(char *password) {
    int i = 0;
    char ch;

    while (1) {
        ch = getch();
        if (ch == '\n' || ch == '\r') {
            password[i] = '\0';
            break;
        } else if (ch == '\b' || ch == 127) {
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        } else if (i < 49) {
            password[i++] = ch;
            printf("*");
        }
    }
    printf("\n");
}

void printfUsers(){
    printf("|===============|================|==================|===================|========|\n");
    printf("| 		ID 		|	 	Name	 | 		Email 		|	 	Phone 		| Status |\n");
    printf("|===============|================|==================|===================|========|\n");
    printf("");
    printf("|===============|================|==================|===================|========|\n");
    
    printf("Go back(b)? or Exit(0)?: ");
    return 0;
}

void selectAmindMenu(Transaction *Transaction,AccountInfo *AccountInfo,User *User){
	int choice;
	do{
		displayMenu();
		scanf("%d",&choice);
		switch(choice){
		case 1:
			addANewUser(&User);
			break;
		case 2:
			printf("2");
			break;
		case 3:
			printf("3");
			break;
		case 4:
			printf("4");
			break;
		case 5:
			printf("5");
			break;
		case 6:
			printf("6");
			break;
		case 0:
           	return 0;
    	default:
			printf("Invalid choice. Please try again.\n");
		}
	}while(1);
}


