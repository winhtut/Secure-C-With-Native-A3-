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
