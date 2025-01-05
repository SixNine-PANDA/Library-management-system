#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

void create_account(){
    char Username;
    char Password;
    printf("Enter Username:\n");
    scanf("%d", &Username);
    printf("Enter Password:\n");
    scanf("%d", &Password);
}
void user_login(){
    char Username;
    char Password;
    printf("Enter Username:\n");
    scanf("%d", &Username);
    printf("Enter Password:\n");
    scanf("%d", &Password);
}
void admin_login(){
    char Username;
    char Password;
    printf("Enter Username:\n");
    scanf("%d", &Username);
    printf("Enter Password:\n");
    scanf("%d", &Password);
}
int main(){
    printf("Library access page:\n");
    printf("--------------------\n");

    int number;
    bool mainmenu=false;

    do{
        mainmenu=true;
        printf("1.Create account:\n");
        printf("2.Login account:\n");
        printf("3.Admin Login:\n");
        printf("Enter 0 to exit program,\n");
        printf("Enter number:\n");
        scanf("%d", &number);

        if(number>=1 && number<=4){
            switch (number){
                case 1:
                    //create account
                    printf("-----\n");
                    break;
                case 2:
                    //login account
                    printf("-----\n");
                    break;
                case 3:
                    //admin login
                    printf("-----\n");
                    break;
                default:
                    break;
            }
        }else if(number ==0){
            printf("Thank you for using the application.\n");
            mainmenu=false;
        }else{
            printf("Enter a valid number:\n");
        }
    }while(mainmenu);

    return 0;
}
