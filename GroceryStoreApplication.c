#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ANS 20
#define ACS 5

void clrscr()
{
	system("@cls||clear");
}

void menuwindow();
void customerwindow();
void adminwindow();

int main()
{

	printf("\n\t\t\t  --------------------------------------------------------------");
    printf("\n\t\t\t  +      ++++++++++++++++++++++++++++++++++++++++++++++++      +");
    printf("\n\t\t\t  +      *                                              *      +");
    printf("\n\t\t\t  +      *                                              *      +");
    printf("\n\t\t\t  +      *        WELCOME TO GROCERY STORE SYSTEM       *      +");
    printf("\n\t\t\t  +      *                                              *      +");
    printf("\n\t\t\t  +      *                                              *      +");
    printf("\n\t\t\t  +      ++++++++++++++++++++++++++++++++++++++++++++++++      +");
    printf("\n\t\t\t  --------------------------------------------------------------\n");
    printf("\n\t\t\t  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	
	menuwindow();
}

void menuwindow()
{


	int choice = 0;
	printf("\n");


	printf("\n\t\t\t\t MENU \n\t\t\t\t");
	printf("\n\t\t\t\t | (1) CUSTOMER |");
	printf("\n\t\t\t\t | (2) ADMIN    |");
	printf("\n\t\t\t\t | (3) EXIT     |");


	printf("\n\t\t\t\t PLEASE CHOOSE A NUMBER : ");
	scanf("%d", &choice);
	
	switch (choice)
	{
		case 1: customerwindow();
		break;
		
		case 2:
			system("cls");

		{
			int id=123, pass=123;
			printf("\n\t\t\t\t\t ENTER ADMIN ID = ");
			scanf("%d",&id);
			switch(id)
				{
					case 123:
					printf("\n\t\t\t\t\t ENTER ADMIN PASSWORD = ");
					scanf("%d",&pass);
					switch(pass)
						{
							case 123:
							clrscr();
							adminwindow();
							break;
							default:
							printf("INCORRECT PASSWORD");
							break;
						}
					break;
					default:
					printf("INCORRECT ID");
					break;
				}
		}
		case 3:
		printf("\n\t\t\t\t\t THANKS FOR OPENING ");
		break;
		default:
		printf("INVALID CHOICE!!!");
		menuwindow();
	}
}

void customerwindow()
{
	int choice;
	printf("\n");
	
	printf("\n\t\t\t\t\t CUSTOMER MENU \n\t\t\t\t\t");
	printf("\n\t\t\t\t\t | (1) BUY PRODUCT |");
	printf("\n\t\t\t\t\t | (2) AVAILABLE PRODUCT |");
	printf("\n\t\t\t\t\t | (3) BACK | \n\t\t\t\t\t");

	printf("\n\t\t\t\t\t CHOOSE A NUMBER : ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1: 
		printf("heelo");
		break;
		case 2:
		printf("hehehehehhe");
		break;
		case 3: 
		menuwindow();
		break;
		default:
		printf("INVALID CHOICE!!!");
		customerwindow();
	}
}

void adminwindow()
{
	int choice;
	printf("\n");
	
	printf("\n\t\t\t\t\t CUSTOMER MENU \n\t\t\t\t\t");
	printf("\n\t\t\t\t\t | (1) ADD PRODUCT |");
	printf("\n\t\t\t\t\t | (2) DELETE PRODUCT |");
	printf("\n\t\t\t\t\t | (3) MODIFY PRODUCT |");
	printf("\n\t\t\t\t\t | (4) VIEW ALL PRODUCT |");
	printf("\n\t\t\t\t\t | (5) BACK |");

	printf("\n\t\t\t\t\t CHOOSE A NUMBER :");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
		printf("add");
		break;
		case 2:
		printf("delete");
		break;
		case 3:
		printf("modify");
		break;
		case 4:
		printf("all product");
		break;
		case 5: menuwindow();
		break;
		default:
		printf("INVALID CHOISE!!!");
		adminwindow();


	}


}
