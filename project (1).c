
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


struct acc
{

     char acc_holder_name[30];
     char nid[20];
     char phone_number[20];
     char acc_holder_address[100];
     int acc_number;
     float available_balance;
}a;
struct acc a1[20];



int num_acc;

void Create_new_account();
void Cash_Deposit();
void Cash_withdrawl();
void search_Account();
void Log_out();
void display_options();


int main()
{
    char option;

    num_acc=0;

    while(1)
    {
       printf("\n***** Welcome to Bank Application *****\n");

       display_options();
       printf("Please enter any options (1/2/3/4/5/6) ");
       printf("to continue : ");

        option = getch();
        printf("%c \n", option);
        switch(option)
        {
          case '1': Create_new_account();
                    break;
          case '2': Cash_Deposit();
                    break;
          case '3': Cash_withdrawl();
                    break;
          case '4': search_account();
                    break;
          case '5': return 0;
          case '6': system("cls");
                    break;
          default : system("cls");
                    printf("Please enter one of the options");
                    printf("(1/2/3/4/5/6) to continue \n ");
                    break;
        }
    }

    return 0;
}


void display_options()
{
    printf("\n1. Create new account \n");
    printf("\n2. Cash Deposit \n");
    printf("\n3. Cash withdrawl \n");
    printf("\n4. Search Account information \n");
    printf("\n5. Log out \n");
    printf("\n6. Clear the screen and display available ");
    printf("options \n\n");
}



void Create_new_account()
{


system("cls");
   char acc_holder_name[30];
   char phone_number[20];
   char nid[20];
   int acc_number;
   char acc_holder_address[100];
   float available_balance = 0;
   int option;
   FILE *fp;
   fflush(stdin);
    label1:
    printf("\nEnter the account holder name    : ");
   scanf("%s", &acc_holder_name);
   printf("\nEnter National id             : ");
   scanf("%s", &nid);
   printf("\nEnter phone number            : ");
   scanf("%s", &phone_number);
   printf("\nEnter the account holder address : ");
   scanf("%s", &acc_holder_address);
   printf("\nEnter the account number(1 to 10): ");
   scanf("%d", &acc_number);


   strcpy(a1[acc_number-1].acc_holder_name,acc_holder_name);
   strcpy(a1[acc_number-1].nid,nid);
   strcpy(a1[acc_number-1].phone_number,phone_number);
   a1[acc_number-1].acc_number=acc_number;
   strcpy(a1[acc_number-1].acc_holder_address,
   acc_holder_address);
   a1[acc_number-1].available_balance=available_balance;






   num_acc++;
   fp=fopen("account information.txt","a+");

        if(fp==NULL)
   {

       printf("FILE DOESNOT EXIT!!!!");
   }
   else
   {
       fprintf(fp,"%s\n",acc_holder_name);
       fprintf(fp,"%s\n",nid);
       fprintf(fp,"%s\n",phone_number);

       fprintf(fp,"%s\n",acc_holder_address);
       fprintf(fp,"%d\n",acc_number);
       fprintf(fp,"%f\n",available_balance);

               }
       printf("\nAccount has been created successfully \n\n");
       fclose(fp);

       display_options();
       printf("Please enter any options (1/2/3/4/5/6) ");
       printf("to continue : ");

        option = getch();
        printf("%c \n", option);
       if(option==1)
       {
           goto  label1;
       }

}

void Cash_Deposit()
{
   auto int acc_no;
   int g;
   float add_money;
   FILE *fp;

   printf("Enter account number you want to deposit money:");
   scanf("%d",&acc_no);
   printf("\nThe current balance for account %d is %f \n",acc_no, a1[acc_no-1].available_balance);
   printf("\nEnter money you want to deposit :  ");
   scanf("%f",&add_money);

   while (acc_no=a1[acc_no-1].acc_number)
   {
         a1[acc_no-1].available_balance=
         g=a1[acc_no-1].available_balance+add_money;
         printf("\nThe New balance for account %d is %f \n",acc_no, a1[acc_no-1].available_balance);
         break;
   }acc_no++;
   fp=fopen("account information.txt","a+");
   if(fp=NULL)
   {
       printf("file dont found");
   }
   else{
    fprintf(fp,"%f\n",g);
   }
}

void Cash_withdrawl()
{
   auto int acc_no;
   float withdraw_money;

   printf("Enter account number you want to withdraw money:");
   scanf("%d",&acc_no);
   printf("\nThe current balance for account %d is %f \n",
   acc_no, a1[acc_no-1].available_balance);
   printf("\nEnter money you want to withdraw from account ");
   scanf("%f",&withdraw_money);

   while (acc_no=a1[acc_no-1].acc_number)
   {
         a1[acc_no-1].available_balance=
         a1[acc_no-1].available_balance-withdraw_money;
         printf("\nThe New balance for account %d is %f \n",
         acc_no, a1[acc_no-1].available_balance);
         break;
   }
   acc_no++;
}






void search_account()

   {
       int f;
       float available_blance;
        int ano;
        char acc_holder_name[30];
   char phone_number[20];
   char nid[20];
   int acc_number;
   char acc_holder_address[100];
   float available_balance ;

   system("cls");
   FILE *fp;

        printf("\n*****SEARCH RECORDS*****\n");
        fp = fopen ("account information.txt", "r");
        printf("\nEnter account number : ");
        scanf("%d",ano);



        while(fread(&a1,sizeof(a1),1,fp)==1)
{
        {
        if(a.acc_number==ano)
        {
            f=1;
            break;
        }
    }
    if (f==1)
    {
        printf("\nACCOUNT EXISTS DETAILS ARE :");
        printf("\n%s \n%s \n%s  \n%s",a.acc_holder_name,a.nid,a.phone_number,a.acc_holder_address,a.acc_number,available_blance);
    }
    else
    {
        printf("\n RECORD NOT EXISTS\n");
        fclose(fp);
    }
}

}








