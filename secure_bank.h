//
// Created by ncc on 17/02/2023.
//

#ifndef NCC_ONLINE_SECURE_BANK_SECURE_BANK_H
#define NCC_ONLINE_SECURE_BANK_SECURE_BANK_H
#include "stdlib.h"
#include "stdio.h"

void login();
void rEgister();
int check_input(char option[2]);


struct trans{
    char note[200];
};
struct info{
    unsigned int id;
    char name[50];
    char nrc[20];
    char email[50];
    char password[50];
    unsigned int phoneNumber;
    char encryption_key[50];//to encrypt user data
    char recovery_key[50];// for recover account
    char account_status[10];
    int account_level;
    int minimum_opening_deposit;
    char currency[5];
    unsigned long long int current_amount;//llu
    char loanStatus[1];
    unsigned int monthly_income;
    unsigned int loan_amount;
    double loan_rate;
    char address[100];

    struct trans tr[300];

};

struct info db[1000];


void main_menu(){
    char option[2];

    int a=0;

    printf("Welcome to Swiss Secure Bank!\n");
    printf("Press 1 to Login!\n");
    printf("Press 2 to Register!\n");
    printf("Press 3 to Exit!:");

    scanf(" %[^\n]", &option[0]);
    int data = check_input(option);
    if( data == 49){
        login();
    } else if ( data == 50){
        rEgister();
    }else if ( data == 51){
        exit(2);
    } else{
        main_menu();
    }

}

void login(){
    printf("This is Swiss Secure Bank Login!\nEnter your gmail>>:");
}
void rEgister(){

    printf("This is Swiss Secure Bank Register!\nEnter your gmail>>:");
}
int check_input(char option[2]){
    if (option[0] >= 49 && option[1] == '\0' && option[0] <=57) {
        return option[0];
    } else{
        return -1;
    }
}
#endif //NCC_ONLINE_SECURE_BANK_SECURE_BANK_H
