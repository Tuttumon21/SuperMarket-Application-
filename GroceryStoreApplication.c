#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

struct items
{
	int pid;
	char pName[25];
	int quantity;
	int price;
};

struct bill
{
	int bid;
	char bname[25];
	int pprice;
};

//MENU SCREEN
void menuwindow();
void customerwindow();
void adminwindow();

//ADMIN SETTINGS
void addProduct();
void displayallProduct();
void viewProduct();
void searchProduct();
void deleteoptionProduct();
void deleteallProduct();
void deleteProduct();
void updateProduct();

//CUSTOMER SETTINGS
void buyProduct();
struct items findProduct(int id);
void updateproduct(int id,int quantity);
void displayALLProduct();
void generatebill();
int total=0;

//STARTING HERE
int main()
{
	menuwindow();
}
//MENU 
void menuwindow()
{
	printf("\n\t\t\t  --------------------------------------------------------------");
    printf("\n\t\t\t               WELCOME TO GROCERY STORE SYSTEM              ");
    printf("\n\t\t\t  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

	int choice = 0;
	printf("\n");
	printf("\n\t\t\t\t            -_____MENU_____-\n");
	printf("\n\t\t\t\t            | (1) CUSTOMER |");
	printf("\n\t\t\t\t            | (2) ADMIN    |");
	printf("\n\n\t\t\t\t 	PLEASE CHOOSE A NUMBER : ");
	scanf("%d", &choice);
	system("cls");

	switch (choice)
	{
		case 1: customerwindow();
		break;
		case 2: adminwindow();
		break;
		default:
		printf("^* INVALID CHOICE!!! PLEASE CHECK ");
	}
	menuwindow();
}
//CUSTOMER MENU
void customerwindow()
{
	int choice;
	printf("\n");
	printf("\n\t\t\t\t\t -_____CUSTOMER MENU_____-\n");
	printf("\n\t\t\t\t\t  |   (1) BUY PRODUCT   |");
	printf("\n\t\t\t\t\t  |   (0) BACK          |\n");
	printf("\n\t\t\t\t\t  PLEASE CHOOSE A NUMBER : ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1: system("cls");
		buyProduct();
		break;
		case 0: system("cls");
		menuwindow();
		break;
		default:
		system("cls");
		printf("^* INVALID CHOICE!!! PLEASE CHECK");
		customerwindow();
	}
}
//ADMIN MENU
void adminwindow()
{
	int choice;
	re:
	printf("\n");
	printf("\n\t\t\t\t\t -_______ADMIN MENU_______-\n");
	printf("\n\t\t\t\t\t  | (1) ADD    PRODUCT   |");
	printf("\n\t\t\t\t\t  | (2) DELETE PRODUCT   |");
	printf("\n\t\t\t\t\t  | (3) VIEW   PRODUCT   |");
	printf("\n\t\t\t\t\t  | (4) UPDATE PRODUCT   |");
	printf("\n\t\t\t\t\t  | (0) BACK             |");
	printf("\n\n\t\t\t\t\t PLEASE CHOOSE A NUMBER :");
	scanf("%d",&choice);
	system("cls");

	switch(choice)
	{
		case 1: addProduct();
		break;
		case 2: deleteoptionProduct();
		break;
		case 3: viewProduct();
		goto re;
		break;
		case 4: updateProduct();
		break;
		case 0: menuwindow();
		break;
		default: printf("INVALID CHOICE!!! PLEASE CHECK");
		adminwindow();
	}
}
//VIEW MENU
void viewProduct()
{
	int choice;
	re:
	printf("\n");
	printf("\n\t\t\t\t-__________VIEW PRODUCT__________-");
	printf("\n\t\t\t\t\t | (1) ALL PRODUCT         |");
	printf("\n\t\t\t\t\t | (2) SEARCH PRODUCT      |");
	printf("\n\t\t\t\t\t | (0) BACK                |");
	printf("\n\n\t\t\t\t CHOOSE A NUMBER : ");
	scanf("%d",&choice);
	system("cls");

	switch(choice)
	{
		case 1: system("cls");
		displayallProduct();
		break;
		case 2: searchProduct();
		break;
		case 0: adminwindow();
		break;
		default: printf("INVALID CHOICE!!! PLEASE CHECK");
		goto re;
	}
}
//DELETE MENU
void deleteoptionProduct()
{
	int choice;
	re:
	printf("\n");
	printf("\n\t\t\t\t\t ----------DELETE PRODUCT DETAILS ----------\n");
	printf("\n\t\t\t\t\t   | (1) DELETE ALL AVAILABLE PRODUCT   |");
	printf("\n\t\t\t\t\t   | (2) DELETE ONLY ONE PRODUCT        |");
	printf("\n\t\t\t\t\t   | (0) BACK                           |");
	printf("\n\n\t\t\t\t CHOOSE A NUMBER : ");
	scanf("%d",&choice);
	system("cls");

	switch(choice)
	{
		case 1: deleteallProduct();
		break;
		case 2: deleteProduct();
		break;
		case 0: adminwindow();
		break;
		default: printf("^*INVALID CHOICE!!! PLEASE CHECK");
		goto re;
	}
}
//ADD PRODUCT DETAILS HERE
void addProduct()
{
	FILE *fp;
    struct items t1;
	printf("\n\t\t\t\t----------ADD PRODUCT DETAILS----------\n\n");
    fp=fopen("Record.txt","a");

	printf("\n\t\t\t\t  Enter Product_ID   :");
    scanf ("%d",&t1.pid);
    printf("\n\t\t\t\t  Enter Product_Name :");
    scanf ("%s",&t1.pName);
	printf("\n\t\t\t\t  Enter Quantity     :");
    scanf ("%d",&t1.quantity);
    printf("\n\t\t\t\t  Enter Price        :");
    scanf("%d",&t1.price);

	if(fp == NULL)
	{
		printf("Error in Opening file\nMake sure your file is not write protected Warning");
 	}
 	else
	{
		printf("\n\n^* THE PRODUCT ADDED SUCCESSFULLY\n");
		printf("\nPRESS ENTER TO CONTINUE");
	}
	fwrite(&t1,sizeof(t1),1,fp);
    fclose(fp);
	getch();
	system("cls");

	int choice;
	re:
	printf("\n");
	printf("\n\t\t\t\t\t DO YOU WANT TO ADD MORE PRODUCT \n\t\t\t\t\t");
	printf("\n\t\t\t\t\t | (1) ADD MORE PRODUCT |");
	printf("\n\t\t\t\t\t | (0) CANCEL           | \n");
	printf("\n\t\t\t\t\t CHOOSE A NUMBER : ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1: system("cls");
		addProduct();
		break;
		case 0: system("cls");
		adminwindow();
		break;
		default: system("cls");
		printf("INVALID CHOICE!!! CHOOSE ONLY 1  OR 0");
		goto re;
	}
}
//VIEW ALL PRODUCT HERE
void displayallProduct()
{
    FILE *fp;
    struct items t1;
	system("cls");
    fp=fopen("Record.txt","r");
	printf("\n\t\t\t\t-__________ALL AVAILABLE PRODUCT__________-\n");

	if(fp == NULL)
	{
        printf("\n\t\t\t\t   NO PRODUCT AVAILABE /  CHECK ?");
 	}
 	else
	{
    	printf("\n\t\t\t\tID\tProductName\tquantity\tprice\n\n");
	}
    while(fread(&t1,sizeof(t1),1,fp))
    {
        printf("\t\t\t\t%d\t",t1.pid);
        printf("%s\t\t",t1.pName);
    	printf("%d\t\t",t1.quantity);
		printf("%d\t\n",t1.price);
	}
	fclose(fp);
	getch();
	system("cls");
}
//VIEW ONLY ONE PRODUCT
void searchProduct()
{
	struct items t1;
	FILE *fp;
	int pid,found=0;
	fp=fopen("Record.txt","r");
	printf("\n\t\t\t\t-_____SEARCH  PRODUCT DETAILS_____-");
	printf("\n\n\t\t\t\t  ENTER THE PRODUCT ID: ");
	scanf("%d",&pid);

	while (fread(&t1,sizeof(t1),1,fp)>0)
	{
		if(t1.pid==pid)
		{
			found=1;
			printf("\n\t\t\t  PRODUCT ID        : %d",t1.pid);
			printf("\n\t\t\t  PRODUCT NAME      : %s",t1.pName);
			printf("\n\t\t\t  PRODUCT quantity  : %d",t1.quantity);
			printf("\n\t\t\t  PRODUCT PRICE     : %d",t1.price);
		}
	}
	if(!found)
	{
       printf("\n\t\t\t\t PRODUCT NOT FOUND / CHECK ?\n");
    }
    fclose(fp);
    getch();
	system("cls");

	int choice;
	re:
	printf("\n");
	printf("\n\t\t\t\t\t DO YOU WANT TO SEARCH  ANOTHER PRODUCT \n\t\t\t\t\t");
	printf("\n\t\t\t\t\t | (1) SEARCH  AGAIN  ANOTHER PRODUCT |");
	printf("\n\t\t\t\t\t | (0) CANCEL                         |");
	printf("\n\n\t\t\t\t\t CHOOSE A NUMBER : ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1: system("cls");
		searchProduct();
		break;
		case 0: system("cls");
		adminwindow();
		break;
		default: system("cls");
		printf("^*INVALID CHOICE!!! PLEASE CHECK");
		goto re;
	}
}
//DELETE ALL PRODUCT HERE
void deleteallProduct()
{
	if(remove("Record.txt")==0)
	{
		printf("\n\t\t\t\t     ALL PRODUCT DELETED SUCCESSFULLY");
	}
   else
    {
		printf("\n\t\t\t\t      UNABLE TO DELETE THE PRODUCT ?");
		printf("\n\t\t\t\t      PLEASE CHECK ANY AVAILABLE PRODUCT");
	}
	printf("\n\n PRESS ENTER TO CONTINUE");
	getch();
	system("cls");
	adminwindow();
}
//DELETE ONLY ONE PRODUCT HERE
void deleteProduct()
{
	struct items t1;
	FILE *fp, *fp1;
	int pid,found=0;
	printf("\n\t\t\t\t ----------DELETE PRODUCT DETAILS----------");

	fp=fopen("Record.txt","r");
	fp1=fopen("temp.txt","w");

	printf("\n\n\t\t\t\t         Enter the PRODUCT ID TO DELETE: ");
	scanf("%d",&pid);

	if(fp==NULL)
	{
        printf("^*CAN'T OPEN FILE  / EMPTY FILE \n");
    }
    while(fread(&t1,sizeof(t1),1,fp))
	{
        if(t1.pid == pid)
		{
            found=1;
        }
		else
		{
           fwrite(&t1,sizeof(t1),1,fp1);
        }
	}
    fclose(fp);
    fclose(fp1);

    if(!found)
	{
        printf("\n\n^*PRODUCT NOT FOUND\n");
    }
    if(found)
	{
    	remove("Record.txt");
        rename("temp.txt","Record.txt");
		printf("\n\t\t\t\tPRODUCT  DELETED SUCCESSFULLY\n");
		printf("\n\t\t\t\tPRESS ENTER TO CONTINUE\n");
    }
	getch();
    system("cls");
	
	int choice;
	re:
	printf("\n");
	printf("\n\t\t\t\t\t DO YOU WANT TO DELETE MORE PRODUCT \n\t\t\t\t\t");
	printf("\n\t\t\t\t\t | (1) DELETE MORE PRODUCT |");
	printf("\n\t\t\t\t\t | (0) CANCEL              |");
	printf("\n\n\t\t\t\t\t CHOOSE A NUMBER : ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1: system("cls");
		deleteProduct();
		break;
		case 0: system("cls");
		adminwindow();
		break;
		default: system("cls");
		printf("INVALID CHOICE!!! PLEASE CHECK");
		goto re;
	}
}
//UPDATE LATEST INFORAMATION ABOUT PRODUCT HERE
void updateProduct()
{
	FILE *fp,*fp1;
	struct items t1;
	int id,found=0,count=0;

	fp=fopen("Record.txt","rb");
	fp1=fopen("temp.dat","wb");
	printf("\n\t\t\t\t ----------UPDATE PRODUCT DETAILS----------");
	printf("\n\n\t\t\t\t ENTER THE PRODUCT  ID TO  UPDATE :");
	scanf("%d",&id);

	if(fp==NULL)
	{
        printf("^*CAN'T OPEN FILE  / EMPTY FILE \n");
    }
	while(1)
	{
		fread(&t1,sizeof(t1),1,fp);
		if(feof(fp))
		{
			break;
		}
		if(t1.pid==id)
		{
			found=1;
			printf("\n\t\t\tPRODUCT IDENTIFIED");
			printf("\n\n\t\t\tENTER NEW PRODUCT ID        :  ");
			scanf("%d",&t1.pid);
			fflush(stdin);
			printf("\n\t\t\tENTER NEW PRODUCT NAME      :  ");
			scanf("%s",&t1.pName);
			printf("\n\t\t\tENTER NEW PRODUCT QUANTITY  :  ");
			scanf("%d",&t1.quantity);
			printf("\n\t\t\tENTER NEW PRODUCT PRICE     :  ");
			scanf("%d",&t1.price);
			fwrite(&t1,sizeof(t1),1,fp1);
			printf("\n\n\t\t\t\tPRODUCT UPDATED SUCCESSFULLY\n");
			printf("\n\t\t\t\tPRESS ENTER TO CONTINUE\n");
		}
		else
		{
			fwrite(&t1,sizeof(t1),1,fp1);
		}
	}
	fclose(fp);
	fclose(fp1);

	if(found==0)
	{
		printf("\n\t\t NO PRODUCT  FOUND");
		printf("\n\t\t PRESS ENTER TO CONTINUE");
	}
	else
	{
		fp=fopen("Record.txt","wb");
		fp1=fopen("temp.dat","rb");
		while(1)
		{
			fread(&t1,sizeof(t1),1,fp1);
			if(feof(fp1))
			{
				break;
			}
			fwrite(&t1,sizeof(t1),1,fp);
		}
	}
	fclose(fp);
	fclose(fp1);

	getch();
    system("cls");
	
	int choice;
	re:
	printf("\n");
	printf("\n\t\t\t\t\t DO YOU WANT TO UPDATE MORE PRODUCT \n\t\t\t\t\t");
	printf("\n\t\t\t\t\t | (1) UPDATE MORE PRODUCT |");
	printf("\n\t\t\t\t\t | (0) CANCEL              |");
	printf("\n\n\t\t\t\t\t CHOOSE A NUMBER : ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1: system("cls");
		updateProduct();
		break;
		case 0: system("cls");
		adminwindow();
		break;
		default: system("cls");
		printf("INVALID CHOICE!!! PLEASE CHECK");
		goto re;
	}
}
//CUSTOMER CAN BUY HERE
void buyProduct()
{
	char ch1,ch2;
	int id;
	
	while(1)
	{
		displayALLProduct();
		fflush(stdin);
		printf("\n\t\t\t DO YOU WANT TO PURCHASE [Y/N] : ");
		scanf("%c",&ch1);
		if(ch1=='y'||ch1=='Y')
		{
			FILE *fp;
			struct bill t2;
			struct items t1;
			fp=fopen("cubill.txt","ab");
			printf("\n\n\t\t\t ENTER THE PRODUCT ID TO PURCHASE : ");
			scanf("%d",&id);

			t1=findProduct(id);

			t2.bid=t1.pid;
			strcpy(t2.bname,t1.pName);
			t2.pprice=t1.price;

			fwrite(&t2,sizeof(t2),1,fp);
			fclose(fp);	
		}
		fflush(stdin);
		printf("\n\t\t\t DO YOU WANT TO CONTINUE TYPE -[Y] <>");
		printf("\t\t DO YOU WANT TO GENERATE BILL TYPE -[B] : ");
		scanf("%c",&ch2);
		if(ch2=='b'||ch2=='B')
		{
			printf("\n\t\tPRESS ENTER TO GENERATE BILL");
			getch();
			system("cls");
			generatebill();
		}
	}
}
//FINDING THE ID TO MATCH PRODUCT ID
struct items findProduct(int id)
{
	FILE *fp;
	struct items t1;
	fp=fopen("Record.txt","rb");

	while(1)
	{
		fread(&t1,sizeof(t1),1,fp);
		if(feof(fp))
		{
			break;
		}
		if(t1.pid==id)
		{
			updateproduct(id,t1.quantity-1);
			break;
		}
	}
	fclose(fp);
	return t1;
}
//UPDATING PRODUCT DETAILS AFTER BUYING
void updateproduct(int id,int quantity)
{
	FILE *fp,*fp1;
	struct items t1;
	int found=0;

	fp=fopen("Record.txt","rb");
	fp1=fopen("temp.dat","wb");

	while(1)
	{
		fread(&t1,sizeof(t1),1,fp);
		if(feof(fp))
		{
			break;
		}
		if(t1.pid==id)
		{
			found=1;
			t1.quantity=quantity;
			fwrite(&t1,sizeof(t1),1,fp1);
		}
		else
		{
			fwrite(&t1,sizeof(t1),1,fp1);
		}
	}
	fclose(fp);
	fclose(fp1);

	if(found==0)
	{
		printf("\n\t\t\t NO PRODUCT FOUND");
	}
	else
	{
		fp=fopen("Record.txt","wb");
		fp1=fopen("temp.dat","rb");

		while(1)
		{
			fread(&t1,sizeof(t1),1,fp1);
			if(feof(fp1))
			{
				break;
			}
			fwrite(&t1,sizeof(t1),1,fp);
		}
	}
	fclose(fp);
	fclose(fp1);
}
//CUSTOMER CAN VIEW ALL AVAILABLE PRODUCT HERE
void displayALLProduct()
{
	FILE *fp;
	struct items t1;

	system("cls");
	fp=fopen("Record.txt","rb");

	printf("\t\t\t\t--------------------BUY PRODUCT--------------------\n\n");

	if(fp == NULL)
	{
        printf("\n\t\t\t\t   NO PRODUCT AVAILABE /  CHECK ?");
 	}
 	else
	{
    	printf("\n\t\t\t\tID\tProductName\tquantity\tprice\n\n");
	}
    while(fread(&t1,sizeof(t1),1,fp))
    {
        printf("\t\t\t\t%d\t",t1.pid);
        printf("%s\t\t",t1.pName);
    	printf("%d\t\t",t1.quantity);
		printf("%d\t\n",t1.price);
	}
	fclose(fp);
}

void  generatebill()
{
	FILE *fp;
	struct bill t2;

	system("cls");
	fp=fopen("cubill.txt","r");
	printf("\n\t\t\t\t---BILL DETAILS---\n\n");
	printf("\t\t\t\tPRODUCT ID\tPRODUCT NAME\tPRODUCT PRICE\n\n");
	
		while(fread(&t2,sizeof(t2),1,fp))
		{
		if (feof(fp))
		{
			break;
		}
		printf("\t\t\t\t%d\t",t2.bid);
		printf("\t%s\t",t2.bname);
		printf("\t%d\t\n",t2.pprice);
		total=total+t2.pprice;
	}
	printf("\n\t\t\t\tTOTAL  BILL AMOUNT = [Rs. %d]\n\n",total);
	total=0;
	fclose(fp);
	getch();
    remove("cubill.txt");
	system("cls");
    customerwindow();
}
