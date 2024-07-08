
#include <math.h>
#include<conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct bank {
  char First_name[20];
  char Middile_name[20];
  char Last_name[20];
  long long int phone;
  char password[10];
  char email[20];
  long long int aadhar;
  long int amount;
} p, check;

void create_account();
void login();
void withdraw(long long int account);
void deposit(long long int account);
void check_balance(long long int account);
void change_password(long long int account);
void Acc_info(long long int account );
void menu(long long int account);
void transfer(long long int account);
void edit(long long int account);
void admin();
void delete_acc();
void ad_deposit();
void Account_info();
void Details();
void logout();
void forgot_pass();

int main()
{

   char password[10];
   char pass[6]="9356";
  int found = 0;
  int i=0;
    system("cls");
    printf("\033[0;31m");                       //red
    
  printf("\n\t\t\t\t=========: WEL-COME TO PM BANK :=========\n");
  int choice;
  char ch; 

  printf("\n\t\t\t\tEnter your choice\n");  
  printf("\t\t\t\t1.Admin\n\t\t\t\t2.Create account\n\t\t\t\t3.Login\n\t\t\t\t4.Forgot Password\n\t\t\t\t5.Exit\n");   
  printf("\t\t\t\tENTER HERE:");
  scanf("%d", &choice);

  if (choice == 1) {
  printf("\n\t\t\t\tEnter your password:");
   while((ch=getch())!=13){
    password[i]=ch;
    i++;
    printf("*");
  }
  
  password[i]='\0';
   if(strcmp(password,pass)==0){
    admin();
   }
   else{
    main();
   }
  
  } else if (choice == 2) {
    create_account();
  } else if (choice == 3) {
    login();
  } else if (choice == 4) {
    forgot_pass();
  } else {
    logout();
  }
}

void create_account()
{
    
    FILE *old;

    old=fopen("record.dat","a+");
     system("cls");
  p person;

  check ck;
  int i=0;
  char ch;

  
  int aadhar_length;
  
 
  printf("\033[1;33m");                     //yellow color


  printf("\n\t\t\t\tEnter your Aadhar number (12 digits): ");
  scanf("%lld", &ck.aadhar);
  aadhar_length = floor(log10(llabs(ck.aadhar))) + 1;
  if (aadhar_length != 12) {
    printf("\n\t\t\t\tInvalid Aadhar number length! Aadhar number should be 12 digits.\n\t\t\t\tPlease try again.\n");
     system("\t\t\t\tpause");
    create_account();
    return;
  } 
 

  while (fscanf(old, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
                person.Middile_name, person.Last_name, &person.phone,
                &person.password, person.email, &person.aadhar,
                &person.amount) != EOF) {
    if (ck.aadhar == person.aadhar) {
      printf("\n\t\t\t\tThis account number is already exist\n");
      system("\t\t\t\tpause");
      create_account();
    }
  }
      person.aadhar = ck.aadhar;
    
  

  printf("\n\t\t\t\tEnter your name: ");
  scanf("%s", person.First_name);
  printf("\n\t\t\t\tEnter your middle name: ");
  scanf("%s", person.Middile_name);
  printf("\n\t\t\t\tEnter your last name: ");
  scanf("%s", person.Last_name);

  printf("\n\t\t\t\tEnter your Mobile number (10 digits): ");
  scanf("%lld", &person.phone);
  
  printf("\n\t\t\t\tEnter your password : ");
   while((ch=getch())!=13){
    person.password[i]=ch;
    i++;
    printf("*");
  }
  person.password[i]='\0';
  
  printf("\n\n\t\t\t\tEnter your email: ");
  scanf("%s", person.email);
  

  printf("\n\t\t\t\tEnter amount to add to your new account: ");
  scanf("%ld", &person.amount);

  fprintf(old, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
          person.Middile_name, person.Last_name, person.phone, person.password,
          person.email, person.aadhar, person.amount);

  fclose(old);
  printf("\n\t\t\t\tCONGRATULATIONS!! YOUR ACCOUNT IS CREATED SUCCESSFULLY\n");
  printf("\t\t\t\tYour account number is: %lld\n", person.aadhar);
 int choice;
  printf("\n\t\t\t\tEnter your choice:");
  printf("\n\t\t\t\t1. Main\n\t\t\t\t2. Logout\n");
  printf("\t\t\t\tENTER HERE:");
  scanf("%d", &choice);

  if (choice == 1) {
    main();
  } else {
    logout();
  }
}
void forgot_pass()
{
    FILE *old;
    old=fopen("record.dat","r");
   
    system("cls");
   p person;

    long long int aadhar, mobile;
   char email[20];
    int found = 0;
    
    printf("\033[0;32m");                                 //green
    printf("\n\t\t\t\t=========: Let's Find your Password :=========\n");
    printf("\n\t\t\t\tEnter your account number: ");
    scanf("%lld", &aadhar);

    printf("\n\t\t\t\tEnter your mobile number: ");
    scanf("%lld", &mobile);
    
    printf("\n\t\t\t\tEnter your E-Mail ID : ");
    scanf("%s", email);
    while (fscanf(old, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
                  person.Middile_name, person.Last_name, &person.phone,
                  person.password, person.email, &person.aadhar,
                  &person.amount) != EOF) {
        if (  mobile == person.phone && strcmp(email,person.email) == 0 && aadhar == person.aadhar) {
            found = 1;
            printf("\n\t\t\t\tYour password is: %s\n", person.password);
            break;
        }
    

   
                  }
        if(!found) {
        printf("\n\t\t\t\tNo account found matching the provided details.\n");
    }
    fclose(old);
    printf("\n\t\t\t\t1.for main\n\t\t\t\t2.any key for Logout \n");
    int choice;
    printf("\t\t\t\tEnter your choice : ");
    scanf("%d", &choice);
    if (choice == 1)
        main();
    else
        logout();
}
void login()
{
  system("cls");
  printf("\033[0;37m");           //white color
    int test=0;
    FILE *old;
    old=fopen("record.dat","r");
    char ch;
    int i=0;
 p person; long long int account;
 
  char password[10];
  int found = 0;
  printf("\n\t\t\t\t =========:Log-In:=========\n");

  printf("\n\t\t\t\tEnter your account number:");
  scanf("%lld", &account);
  printf("\n\t\t\t\tEnter your password:");
   while((ch=getch())!=13){
    password[i]=ch;
    i++;
    printf("*");
  }
  password[i]='\0';

  while (fscanf(old, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
                person.Middile_name, person.Last_name, &person.phone,
                &person.password, person.email, &person.aadhar,
                &person.amount) != EOF) {
    if (account == person.aadhar && strcmp(password,person.password)==0) {
      found = 1;
      printf("\n\t\t\t\tLogin successfully..!\n");
      printf("\n\t\t\t\tWelcome, %s\n", person.First_name);
      printf("\t\t\t\t");
      system("pause");
      fclose(old);
      menu(account);
      break;
    }
  }

  if (!found) {
    printf("\n\t\t\t\tLogin failed. Invalid account number or password.\n");
    int choice;
    printf("\n\t\t\t\tEnter your choice:\n");
    printf("\t\t\t\t1. Main\n\t\t\t\t2. Exit\n");
    printf("\t\t\t\tENTER HERE: ");
    scanf("%d", &choice);
    if (choice == 1) {
      main();
    } else {
      logout();
    }
  }

    fclose(old);
    

int choice;
  printf("\n\t\t\t\t1. Main\n\t\t\t\t2. Menu\n\t\t\t\t3.Logout\n");
  
  printf("\t\t\t\tEnter your choice: ");
  scanf("%d", &choice);
  if (choice == 1)
    main();
  else if (choice == 2)
    menu(account);
  else
    logout();
}

void deposit(long long int account)
{
   system("cls");
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    p person; 
    long int amount;
    char password[10];
  
 int i=0;
 char ch;
 printf("\033[0;36m");                              //cyan
  printf("\n\t\t\t\tEnter your account password:");
    while((ch=getch())!=13){
    password[i]=ch;
    i++;
    printf("*");
  }
  password[i]='\0';
  
 while (fscanf(old, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
                person.Middile_name, person.Last_name, &person.phone,
                &person.password, person.email, &person.aadhar,
                &person.amount) != EOF) {
    if (strcmp(password,person.password)==0 && account == person.aadhar) {
      printf("\n\t\t\t\tEnter the amount to deposit:");
      scanf("%ld", &amount);
      person.amount += amount;
             fprintf(newrec, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
              person.Middile_name, person.Last_name, person.phone,
              person.password, person.email, person.aadhar, person.amount);

      printf("\n\t\t\t\tPrevious Balance: %ld", person.amount - amount);
      printf("\n\t\t\t\tAmount Deposited: %ld", amount);
      printf("\n\t\t\t\tNew Balance: %ld", person.amount);

      printf("\n\t\t\t\tDeposit successful..!");
      printf("\n\t\t\t\t");

    } else {
     
      fprintf(newrec, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
              person.Middile_name, person.Last_name, person.phone,
              person.password, person.email, person.aadhar, person.amount);
    }
  }

 
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

int choice;
  printf("\n\t\t\t\t1. Menu\n\t\t\t\t2.Logout\n");
  printf("\t\t\t\tEnter your choice: ");
  scanf("%d", &choice);
  
   if (choice == 1)
    menu( account);
  else if(choice == 2)
    logout();
    else printf("\n\t\t\t\tInvalid Choice\n");
}
void Acc_info(long long int account)
{
  system("cls");
    int test = 0;
    FILE *old;
    old = fopen("record.dat", "r");

    p person; 

    char password[10];
    int found = 0;

    printf("\n\t\t\t\tEnter your account password:");
    int i = 0;
    char ch;
    while ((ch = getch()) != 13) {
        password[i] = ch;
        i++;
        printf("*");
    }
    password[i] = '\0';

    while (fscanf(old, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
                  person.Middile_name, person.Last_name, &person.phone,
                  &person.password, person.email, &person.aadhar,
                  &person.amount) != EOF) {
        if (account == person.aadhar && strcmp(password, person.password) == 0) {
            found = 1;
            printf("\n\t\t\t\tName: %s %s %s\n", person.First_name, person.Middile_name,
                   person.Last_name);
            printf("\t\t\t\tPhone: %lld\n", person.phone);
            printf("\t\t\t\tAadhar: %lld\n", person.aadhar);
            printf("\t\t\t\tAmount: %ld\n", person.amount);

        }

    }

    if (!found) {
        printf("\n\t\t\t\tNo account found matching the provided details.\n");
    }

    fclose(old);

   int choice;
  printf("\n\t\t\t\t1. Menu\n\t\t\t\t2.Logout\n");
  printf("\t\t\t\tEnter your choice: ");
  scanf("%d", &choice);
  
   if (choice == 1)
    menu(  account);
  else if(choice == 2)
    logout();
    else printf("\n\t\t\t\tInvalid Choice\n");
}
void withdraw(long long int account)
{
  system("cls");
    int test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
 p person; 

  long int amount;
  char password[10];
  int found = 0;

  
 int i=0;
 char ch;
 printf("\033[0;35m"); //purple color
  printf("\n\t\t\t\tEnter your account password:");
    while((ch=getch())!=13){
    password[i]=ch;
    i++;
    printf("*");
  }
  password[i]='\0';

  while (fscanf(old, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
                person.Middile_name, person.Last_name, &person.phone,
                &person.password, person.email, &person.aadhar,
                &person.amount) != EOF) {

    if ( strcmp(password,person.password)==0  && account == person.aadhar) {
      printf("\n\t\t\t\tEnter the amount to withdraw:");
      scanf("%ld", &amount);

      if (amount > person.amount) {
        printf("\n\t\t\t\tINSUFFICIENT BALANCE");
      } else {
        person.amount -= amount;

        fprintf(newrec, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
                person.Middile_name, person.Last_name, person.phone,
                person.password, person.email, person.aadhar, person.amount);

        printf("\n\t\t\t\t%ld is debited from your account", amount);
        printf("\n\t\t\t\tYour remaining balance is %ld", person.amount);
        printf("\n\t\t\t\tWithdraw Successfully..!");
      }
    } else {
    
      fprintf(newrec, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
              person.Middile_name, person.Last_name, person.phone,
              person.password, person.email, person.aadhar, person.amount);
    }
  }


 
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

int choice;
  printf("\n\t\t\t\t1. Menu\n\t\t\t\t2.Logout\n");
  printf("\t\t\t\tEnter your choice: ");
  scanf("%d", &choice);
  
   if (choice == 1)
    menu(  account);
  else if(choice == 2)
    logout();
    else printf("\n\t\t\t\tInvalid Choice\n");
}
void change_password( long long int account)
{
  system("cls");
    int test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
 p person; 
  long int amount;
  char password[10],new_password[10];
  int found = 0;

 
  printf("\033[0;34m");                              //blue color
  

  while (fscanf(old, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
                person.Middile_name, person.Last_name, &person.phone,
                &person.password, person.email, &person.aadhar,
                &person.amount) != EOF) {
    if (account == person.aadhar) {
      found = 1;
      printf("\n\t\t\t\tEnter your current password: ");
      int i=0;
 char ch;
  
    while((ch=getch())!=13){
    password[i]=ch;
    i++;
    printf("*");
  }
  password[i]='\0';

      if (strcmp(password,person.password)==0) {
        printf("\n\t\t\t\tEnter your new password: ");
        int p=0;
        char ch;
  
    while((ch=getch())!=13){
    new_password[p]=ch;
    p++;
    printf("*");
  }
  new_password[p]='\0';

      strcpy(person.password,new_password);

        fprintf(newrec, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
                person.Middile_name, person.Last_name, person.phone,
                person.password, person.email, person.aadhar, person.amount);

        printf("\n\t\t\t\tPassword changed successfully!\n");
      } else {
        printf("\n\t\t\t\tIncorrect current password!\n");
      }
    } else {
      fprintf(newrec, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
              person.Middile_name, person.Last_name, person.phone,
              person.password, person.email, person.aadhar, person.amount);
    }
  }

  if (!found) {
    printf("\t\t\t\taccount number not found!\n");
  }

    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

int choice;
  printf("\n\t\t\t\t1. Menu\n\t\t\t\t2.Logout\n");
  printf("\t\t\t\tEnter your choice: ");
  scanf("%d", &choice);
  
   if (choice == 1)
    menu(  account);
  else if(choice == 2)
    logout();
    else printf("\n\t\t\t\tInvalid Choice\n");
}


void delete_acc()
{
  system("cls");
    
    FILE *old,*newrec;
    
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
 p person; 
 long long int ad_account;
  long int amount;
  int c;
  int password,new_password;
  int found = 0;
 printf("\033[0;31m");                    //red color
 printf("\n\t\t\t\t =========: Delete Account :=========\n");
   printf("\n\t\t\t\tEnter customer's account number:");
   scanf("%lld", &ad_account);
  printf("\n\t\t\t\tCustomer Really Want To Delete Account");
  printf("\n\t\t\t\t1.Yes\n\t\t\t\t2.No");
  printf("\n\t\t\t\tEnter Here : ");
  scanf("%d",&c);
  if (c==2)
  {
   admin();
  }
  else if (c!=1)
  {
    printf("\n\t\t\t\tInvalid Choice\n");
 system("pause");
 admin();

  }
  else{
  int accountDeleted = 0;

  while (fscanf(old, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
                person.Middile_name, person.Last_name, &person.phone,
                &person.password, person.email, &person.aadhar,
                &person.amount) != EOF) {
    if (ad_account == person.aadhar) {
      printf("\t\t\t\tAccount number %lld found and deleted.\n", ad_account);
      accountDeleted = 1;
    } else {
      fprintf(newrec, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
              person.Middile_name, person.Last_name, person.phone,
              person.password, person.email, person.aadhar, person.amount);
    }
  }

  if (!accountDeleted) {
    printf("\n\t\t\t\tAccount with name %lld not found.\n", ad_account);
  }

    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

 int choice;
  printf("\n\t\t\t\tEnter your choice:");
  printf("\n\t\t\t\t1.Main\n\t\t\t\t2.Admin\n\t\t\t\t3.Logout\n");
  printf("\t\t\t\tENTER HERE:");
  scanf("%d", &choice);
  if (choice == 1)
    main();
  else if (choice == 2)
    admin();
  else
    logout();
  }
}
void ad_deposit()
{
  system("cls");
    
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
 p person;
  long long int ad_account;
  long int amount;
  
printf("\033[0;36m");                                        // cyn 
  printf("\n\t\t\t\tEnter your account number:");
   scanf("%lld", &ad_account);
  
 while (fscanf(old, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
                person.Middile_name, person.Last_name, &person.phone,
                &person.password, person.email, &person.aadhar,
                &person.amount) != EOF) {
    if (ad_account == person.aadhar) {
      printf("\n\t\t\t\tEnter the amount to deposit:");
      scanf("%ld", &amount);
      person.amount += amount;

      printf("\n\t\t\t\tPrevious Balance: %ld", person.amount - amount);
      printf("\n\t\t\t\tAmount Deposited: %ld", amount);
      printf("\n\t\t\t\tNew Balance: %ld", person.amount);

      fprintf(newrec, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
              person.Middile_name, person.Last_name, person.phone,
              person.password, person.email, person.aadhar, person.amount);

      printf("\n\t\t\t\tDeposit successful..!");
    } else {
      fprintf(newrec, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
              person.Middile_name, person.Last_name, person.phone,
              person.password, person.email, person.aadhar, person.amount);
    }
  }


    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

int choice;
  printf("\n\t\t\t\t1. Main\n\t\t\t\t2. admin\n\t\t\t\t3.Logout\n");
  printf("\n\t\t\t\tEnter your choice: ");
  scanf("%d", &choice);
  if (choice == 1)
    main();
  else if (choice == 2)
    admin();
  else
    logout();
}

void  check_balance(long long int account)
{
   system("cls");
    FILE *old;
    old=fopen("record.dat","r");
    
    p person; 
 
  char password[10];
 
printf("\033[0;37m");                       //white color
 printf("\n\t\t\t\tEnter your password:");
   int i=0;
        char ch;
  
    while((ch=getch())!=13){
    password[i]=ch;
    i++;
    printf("*");
  }
  password[i]='\0';
  while (fscanf(old, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
                person.Middile_name, person.Last_name, &person.phone,
                &person.password, person.email, &person.aadhar,
                &person.amount) != EOF) {
    if (strcmp(password,person.password)==0 && account == person.aadhar) {
      printf("\n\t\t\t\tYour balance is %ld", person.amount);
    fclose(old);
    }
                }

int choice;
  printf("\n\t\t\t\t1. Menu\n\t\t\t\t2.Logout\n");
  printf("\t\t\t\tEnter your choice: ");
  scanf("%d", &choice);
  
   if (choice == 1)
    menu(  account);
  else if(choice == 2)
    logout();
    else printf("\n\t\t\t\tInvalid Choice\n");
                  

}

void Details()
{
  system("cls");
    int test=0;
    FILE *old;
    old=fopen("record.dat","r");
    
 p person;
 
  
printf("\033[0;32m");   //green color

  while (fscanf(old, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
                person.Middile_name, person.Last_name, &person.phone,
                &person.password, person.email, &person.aadhar,
                &person.amount) != EOF) {
    printf("\t\t\t\tName: %s %s %s\n", person.First_name, person.Middile_name,
           person.Last_name);
    printf("\t\t\t\tPhone: %lld\n", person.phone);
    printf("\t\t\t\tAadhar: %lld\n", person.aadhar);
    printf("\t\t\t\tAmount: %ld\n", person.amount);
    printf("\n\n");

    test++;
  }
    fclose(old);
     if (test == 0) {
    printf("\t\t\t\tNO RECORDS FOUND\n");
  }

int choice;
   printf("\n\t\t\t\tEnter your choice:\n");
  printf("\t\t\t\t1. Main\n\t\t\t\t2. Admin\n\t\t\t\t3.Logout\n");
  printf("\t\t\t\tENTER HERE: ");
  scanf("%d", &choice);

  if (choice == 1)
    main();
  else if (choice == 2)
    admin();
  else
    logout();

 
}

void Account_info()
{
    
    system("cls");
    FILE *old;
    old=fopen("record.dat","r");
    
 p person; 
 long long int ad_account;
 printf("\033[0;33m");          //yellow coclor
  printf("\n\t\t\t\tEnter customer's account number: ");
  scanf("%lld", &ad_account);


 while (fscanf(old, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
                person.Middile_name, person.Last_name, &person.phone,
                &person.password, person.email, &person.aadhar,
                &person.amount) != EOF) {
    if (ad_account == person.aadhar) {
      printf("\t\t\t\tName : %s %s %s\n", person.First_name, person.Middile_name,
             person.Last_name);
      printf("\t\t\t\tPhone : %lld\n", person.phone);
      printf("\t\t\t\tAadhar : %lld\n", person.aadhar);
      printf("\t\t\t\tAmount : %ld\n", person.amount);
      fclose(old);
      int choice;
      printf("\n\t\t\t\tEnter your choice:");
      printf("\n\t\t\t\t1.Main\n\t\t\t\t2.Admin\n\t\t\t\t3.Logout\n");
      printf("\t\t\t\tENTER HERE:");
      scanf("%d", &choice);
      if (choice == 1)
        main();
      else if (choice == 2)
        admin();
      else if (choice == 3) {
        exit(0);
      }
    }
  }
    
}   





void logout()
{
     system("cls");
  printf("\t\t\t\t...Thank you...!");
  exit(0);
    }


void menu( long long int account)
{  
   system("cls");
  int choice;
  printf("\033[0;32m"); //green
  printf("\t\t\t\tEnter your choice:");
  printf("\n\t\t\t\t1.Withdraw\n\t\t\t\t2.Deposit\n\t\t\t\t3.Check balance\n\t\t\t\t4.Change "
         "password\n\t\t\t\t5.Account details\n\t\t\t\t6.transfer\n\t\t\t\t7.Edit \n\t\t\t\t8.logout");
  printf("\t\t\t\tENTER HERE:");
  scanf("%d", &choice);
  if (choice == 1)
    withdraw(account);
  else if (choice == 2)
    deposit(account);
  else if (choice == 3)
    check_balance(account);
 
  else if (choice == 4)
    change_password(account);
  else if (choice == 5)
    Acc_info(account);
     else if(choice == 6){
    transfer(account);
  }
  else if (choice == 7)
    edit(account);
 else if (choice == 8)
 {
  logout();
 }
 
  else {
    printf("\t\t\t\tINVALID CHOICE");
    printf("\t\t\t\t");
    system("pause");
    menu(account);
  }
}

void admin() {
  system("cls");
  int choice;
  printf("\033[0;35m");                //purple
  printf("\t\t\t\tEnter your choice:");
  printf("\n\t\t\t\t1.Add new account\n\t\t\t\t2.Delete account\n\t\t\t\t3.View account "
         "details\n\t\t\t\t4.Deposite money\n\t\t\t\t5.Details\n\t\t\t\t6.Logout\n");
  printf("\t\t\t\tENTER HERE:");
  scanf("%d", &choice);
  if (choice == 1)
    create_account();
  else if (choice == 2)
    delete_acc();
  else if (choice == 3)
    Account_info();
  else if (choice == 4)
    ad_deposit();
 
  else if (choice == 5)
    Details();
  else if (choice == 6)
    logout();
  else {
    printf("\t\t\t\tINVALID CHOICE");
    admin();
  }
}
 void trans(long long int recipient_account,long int amount){
  
  FILE *old,*newrec;
  old=fopen("record.dat","r");
    newrec = fopen("new.dat","w");
    p person;
     while (fscanf(old,"%s %s %s %lld %s %s %lld %ld\n", person.First_name,
                person.Middile_name, person.Last_name, &person.phone,
                &person.password, person.email, &person.aadhar,
                &person.amount) != EOF){
                  if(recipient_account==person.aadhar){
                   
                    person.amount+=amount;
                     
                      fprintf(newrec, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
              person.Middile_name, person.Last_name, person.phone,
              person.password, person.email, person.aadhar, person.amount);
                    
                  }
                  else{
                     fprintf(newrec, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
              person.Middile_name, person.Last_name, person.phone,
              person.password, person.email, person.aadhar, person.amount);
                  }
                }
                 fclose(old);
                 fclose(newrec);
                 remove("record.dat");
                 rename("new.dat","record.dat");

}
void transfer(long long int account){
   system("cls");
  printf("\033[0;37m");           //white color
    int test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec = fopen("new.dat","w");
    char ch;
    int i=0;
    int aadhar_length;
 p person; long long int recipient_account;
 long int amount;
  char password[10];
  int found = 0;
  printf("\n\t\t\t\t=========:Money Transfer Section:=========\n");
  printf("\n\t\t\t\tEnter your password:");
   while((ch=getch())!=13){
    password[i]=ch;
    i++;
    printf("*");
  }

 
  password[i]='\0';
    printf("\n\t\t\t\tEnter Recipient Account number : ");
   scanf("%lld",&recipient_account);
   aadhar_length = floor(log10(llabs(recipient_account))) + 1;
   if (aadhar_length != 12) {
    printf("\n\t\t\t\tInvalid Account number length! Account number should be 12 digits.\n\n\t\t\t\tPlease try again.\n\n");
    printf("\t\t\t\t");
     system("pause");
    transfer(account);
    return;
  } 

   printf("\n\t\t\t\tEnter amount : ");
   scanf("%ld",&amount);
   while (fscanf(old,"%s %s %s %lld %s %s %lld %ld\n", person.First_name,
                person.Middile_name, person.Last_name, &person.phone,
                &person.password, person.email, &person.aadhar,
                &person.amount) != EOF){
                  if(account==person.aadhar && strcmp(password,person.password)==0){
                   
                    person.amount-=amount;
                     
                      fprintf(newrec, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
              person.Middile_name, person.Last_name, person.phone,
              person.password, person.email, person.aadhar, person.amount);
                    printf("\n\t\t\t\tAmount transfer to account number %lld ",recipient_account);
                  }
                  else{
                     fprintf(newrec, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
              person.Middile_name, person.Last_name, person.phone,
              person.password, person.email, person.aadhar, person.amount);
                  }
                }
                 fclose(old);
                 fclose(newrec);
                 remove("record.dat");
                 rename("new.dat","record.dat");

                 trans(recipient_account,amount);
   
 
 int choice;
  printf("\n\t\t\t\t1. Menu\n\t\t\t\t2.Logout\n");
  printf("\t\t\t\tEnter your choice: ");
  scanf("%d", &choice);
  
   if (choice == 1)
    menu(  account);
  else if(choice == 2)
    logout();
    else printf("\n\t\t\t\tInvalid Choice\n");

}
void mobile_no(long long int account){
   system("cls");
  printf("\033[0;37m");           //white color
    int test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec = fopen("new.dat","w");
    char ch;
    int i=0;
    int aadhar_length;
 p person; long long int mobile;

  char password[10];
  int found = 0;
    printf("\n\t\t\t\tEnter new mobile number : ");
    scanf("%lld",&mobile);
  printf("\n\t\t\t\tEnter your password:");
   while((ch=getch())!=13){
    password[i]=ch;
    i++;
    printf("*");
  }

 
  password[i]='\0';

   while (fscanf(old, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
                person.Middile_name, person.Last_name, &person.phone,
                &person.password, person.email, &person.aadhar,
                &person.amount) != EOF){
                  if(account == person.aadhar  && strcmp(password,person.password)==0){
                    person.phone = mobile;
                     fprintf(newrec, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
                person.Middile_name, person.Last_name, person.phone,
                person.password, person.email, person.aadhar, person.amount);
                     printf("\n\t\t\t\tMobile Number changed successfully!\n");
                  }
                  else {
      fprintf(newrec, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
              person.Middile_name, person.Last_name, person.phone,
              person.password, person.email, person.aadhar, person.amount);
    }
                }
                fclose(old);
                fclose(newrec);
                 remove("record.dat");
                 rename("new.dat","record.dat");

        int choice;
  printf("\n\t\t\t\t1. Menu\n\t\t\t\t2.Logout\n");
  printf("\t\t\t\tEnter your choice: ");
  scanf("%d", &choice);
  
   if (choice == 1)
    menu(  account);
  else if(choice == 2)
    logout();
    else printf("\n\t\t\t\tInvalid Choice\n");
}
void name(long long int account){
 system("cls");
  printf("\033[0;37m");           //white color
    int test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec = fopen("new.dat","w");
    char ch;
    int i=0;
    int aadhar_length;
 p person; 
 char fname[10],mname[10],lname[10];

  char password[10];
  int found = 0;
   

  printf("\n\t\t\t\tEnter your password:");
   while((ch=getch())!=13){
    password[i]=ch;
    i++;
    printf("*");
  }

    password[i]='\0';
  while (fscanf(old, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
                person.Middile_name, person.Last_name, &person.phone,
                &person.password, person.email, &person.aadhar,
                &person.amount) != EOF){
                  if(account == person.aadhar  && strcmp(password,person.password)==0){
                     printf("\n\t\t\t\tEnter first name : ");
                     scanf("%s",fname);

                      printf("\n\t\t\t\tEnter middle name : ");
                    scanf("%s",mname);
 
                     printf("\n\t\t\t\tEnter last name : ");
                     scanf("%s",lname);

                   strcpy(person.First_name,fname);
                   strcpy(person.Middile_name,mname);
                   strcpy(person.Last_name,lname);

                     fprintf(newrec, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
                person.Middile_name, person.Last_name, person.phone,
                person.password, person.email, person.aadhar, person.amount);
                     printf("\n\t\t\t\tName changed successfully!\n");
                  }
                  else {
      fprintf(newrec, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
              person.Middile_name, person.Last_name, person.phone,
              person.password, person.email, person.aadhar, person.amount);
    }
                }
                fclose(old);
                fclose(newrec);
                 remove("record.dat");
                 rename("new.dat","record.dat");

     int choice;
  printf("\n\t\t\t\t1. Menu\n\t\t\t\t2.Logout\n");
  printf("\t\t\t\tEnter your choice: ");
  scanf("%d", &choice);
  
   if (choice == 1)
    menu(  account);
  else if(choice == 2)
    logout();
    else printf("\n\t\t\t\tInvalid Choice\n");

}
void email(long long int account){
  system("cls");
  printf("\033[0;37m");           //white color
    int test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec = fopen("new.dat","w");
    char ch;
    int i=0;
   
 p person; 
 char mail[20];

  char password[10];
  int found = 0;
   

  printf("\n\t\t\t\tEnter your password:");
   while((ch=getch())!=13){
    password[i]=ch;
    i++;
    printf("*");
  }

    password[i]='\0';
  while (fscanf(old, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
                person.Middile_name, person.Last_name, &person.phone,
                &person.password, person.email, &person.aadhar,
                &person.amount) != EOF){
                  if(account == person.aadhar  && strcmp(password,person.password)==0){
                    printf("\n\t\t\t\tEnter new E-mail ID : ");
                    scanf("%s",mail);

                      strcpy(person.email,mail);

                     fprintf(newrec, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
                person.Middile_name, person.Last_name, person.phone,
                person.password, person.email, person.aadhar, person.amount);
                     printf("\n\t\t\t\tEmail changed successfully!\n");
                  }
                  else {
      fprintf(newrec, "%s %s %s %lld %s %s %lld %ld\n", person.First_name,
              person.Middile_name, person.Last_name, person.phone,
              person.password, person.email, person.aadhar, person.amount);
    }
                }
                fclose(old);
                fclose(newrec);
                 remove("record.dat");
                 rename("new.dat","record.dat");

             int choice;
  printf("\n\t\t\t\t1. Menu\n\t\t\t\t2.Logout\n");
  printf("\t\t\t\tEnter your choice: ");
  scanf("%d", &choice);
  
   if (choice == 1)
    menu(  account);
  else if(choice == 2)
    logout();
    else printf("\n\t\t\t\tInvalid Choice\n");

}
void edit(long long int account){
  system("cls");
  int choice;
  printf("\t\t\t\tWhat Do you want to edit : ");
  printf("\n\t\t\t\t1.Mobile Number\n\t\t\t\t2.Name\n\t\t\t\t3.E-mail ID\n");
  printf("\t\t\t\tEnter Here : ");
  scanf("%d",&choice);
  if(choice == 1) mobile_no(account);
  else if(choice == 2) name(account);
  else if(choice == 3) email(account);
  else printf("\n\t\t\t\tInvalid choice");


  int choice1;
  printf("\n\t\t\t\t1. Menu\n\t\t\t\t2.Logout\n");
  printf("\t\t\t\tEnter your choice: ");
  scanf("%d", &choice1);
  
   if (choice1 == 1)
    menu(  account);
  else if(choice1 == 2)
    logout();
    else printf("\n\t\t\t\tInvalid Choice\n");
}