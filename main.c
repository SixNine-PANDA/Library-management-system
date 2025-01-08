#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

typedef struct UserAccount
{
    char username[50];
    char name[100];
    char password[50];
    bool isAdmin;
}UserAccount;

void libraryHomePage(UserAccount account){
    printf("\nHomepage\n");
    printf("--------------------\n");

    printf("Hello %s! Welcome to Zihan's Library!\n",account.name);
}

void create_account(){
    
    char confirmPassword[50];

    UserAccount newAccount;

    newAccount.isAdmin=false;

    FILE *file = fopen("user.txt", "a");
    if(!file){
        printf("Error\n");
        return;
    }
    printf("\nCreate Account\n");
    printf("--------------------\n");

    printf("Enter your full name: ");
    scanf("%s", &newAccount.name);
    fflush(stdin);
    printf("\nEnter Username: ");
    scanf("%s", &newAccount.username);
    fflush(stdin);
    printf("\nEnter Password: ");
    scanf("%s", &newAccount.password);
    fflush(stdin);
    printf("\nConfirm Password: ");
    scanf("%s", &confirmPassword);
    fflush(stdin);
    if((strcmp(newAccount.password,confirmPassword))==0){
        
        fprintf(file, "%s,%s,%s,%d\n", newAccount.name,newAccount.username,newAccount.password,newAccount.isAdmin);
        fclose(file);

        printf("Account Created Successfully");

        libraryHomePage(newAccount);

    }else{
        printf("Two passwords did not match!");
        create_account();
    }

}
void user_login(){
    char username[50];
    char password[50];
    printf("Enter Username:\n");
    scanf("%s", &username);
    fflush(stdin);
    printf("Enter Password:\n");
    scanf("%s", &password);
    fflush(stdin);

    printf("Username: %s",username);
    printf("\nPassword: %s",password);

    FILE *file = fopen("user.txt", "r");
    if(!file){
        printf("Error\n");
        return;
    }

    UserAccount tempAccount;

    while(fscanf(file,"%s","%s","%s",&tempAccount.name,&tempAccount.username,&tempAccount.password)==3){
        printf("Scanned successful!");
        // printf("Username: %s",account.username);
    }

    // if(strcmp(username)==0){
    //     if(strcmp(password)==0){
    //         printf("Welcome.Login Successful");
    //     }else{
    //         printf("Wrong information");
    //     }
    // }

    




}
void admin_login(){
    char Username;
    char Password;
    printf("Enter Username:\n");
    scanf("%s", &Username);
    printf("Enter Password:\n");
    scanf("%s", &Password);
}

void libraryAccessPage(){\
    int number;
    bool accessPage=false;

    printf("Library access page:\n");
    printf("\n--------------------\n");

    do{
        accessPage=true;
        printf("1.Create account:\n");
        printf("2.Login account:\n");
        printf("3.Admin Login:\n");
        printf("Enter 0 to exit program,\n");
        printf("Enter number:\n");
        scanf("%d", &number);

        if(number>=1 && number<=4){
            switch (number){
                case 1:
                    create_account();
                    printf("\n-----\n");
                    break;
                case 2:
                    user_login();
                    printf("\n-----\n");
                    break;
                case 3:
                    admin_login();
                    printf("\n-----\n");
                    break;
                default:
                    break;
            }
        }else if(number ==0){
            printf("Thank you for using the application.\n");
            accessPage=false;
        }else{
            printf("Enter a valid number:\n");
        }
    }while(accessPage);
}



int main(){
    
    libraryAccessPage();

    return 0;
}
