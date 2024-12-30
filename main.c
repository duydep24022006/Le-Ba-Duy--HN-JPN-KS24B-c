#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char *argv[]) {
	Transaction *Transaction;
	AccountInfo *AccountInfo;
	User *User;
	
	do{
		printf("\n ");
		displayRoleMenu();
		scanf("%d",&choice);
		switch(choice) {
			case 1:
				selectAmindMenu(Transaction,AccountInfo,User);
				break;
			case 2:
				break;
			case 0:
				displayExitMessage();
           	 	return 0;
		default:
			printf("Invalid choice. Please try again.\n");
		}
		
	}while(1);
}
