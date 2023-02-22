//
// Created by ncc on 21/02/2023.
//

#ifndef NCC_ONLINE_SECURE_BANK_CORN_ENCRYPTION_H
#define NCC_ONLINE_SECURE_BANK_CORN_ENCRYPTION_H

#include "secure_bank.h"

// function declaration
void encryption(char to_encrypt[200]);
void ascii_to_binary_converter(int ascii);
int sizeof_binary_array(int bin_array[16]);
int key_encrypt(char key[4]);
void char_to_binary(char to_encrypt[200],char user_key[4]);
void corn_encrypt(int one_word_array[16],int key_bin_array[16]);
void show_16Bin_array(int toprint[16]);
int binary_to_ascii(int encrypted_bin[16]);
int my_pow(int number);


//Global array and var
int sixteen_array[16];
int encrypted_binary_array[16];
int user_key_binary_array[16];



void char_to_binary(char to_encrypt[200],char user_key[4]){ // username , email , password, transaction record , personal or business

    int ascii_user_key= key_encrypt(user_key);
    ascii_to_binary_converter(ascii_user_key);

    for(int i=0; i<16 ; i++){
        user_key_binary_array[i] = sixteen_array[i];
    }




    int char_counter = char_counting(to_encrypt);

    for(register int i=0; i<char_counter; i++){

        int one_word = to_encrypt[i];
        printf("%d :",one_word);
        ascii_to_binary_converter(one_word);

//        for (int bin = 0; bin < 16; bin++) {
//            printf("%d",sixteen_array[bin]);
//        }
        corn_encrypt(sixteen_array ,user_key_binary_array );

        printf("\n");
    }



}

void ascii_to_binary_converter(int ascii) {

    int bin_array[16] = {11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11};

    for (register int i = 0; ascii > 0; i++) {
        bin_array[i] = ascii % 2;
        ascii = ascii / 2;

    }
    int counter = sizeof_binary_array(bin_array);

    int to_insert = 16-counter;

    for(int i=0; i<to_insert;i++){
        sixteen_array[i]=0;
    }
    int reverse = counter-1;
    for (int x = 0; x < counter; ++x) {

        sixteen_array[to_insert] = bin_array[reverse];
        reverse--;
        to_insert++;
    }



}

int sizeof_binary_array(int bin_array[16]){
    int counter=0;
    for(register int i=0; i<16; i++){

        if(bin_array[i] == 11){
            break;
        }
        counter++;

    }
    return counter;
}

int key_encrypt(char key[4]){
    int key_counter = char_counting(key);
    int keyData=0;
    for(int i=0; i<key_counter; i++){

        keyData += key[i];

    }

    return keyData;

}

void corn_encrypt(int one_word_array[16],int key_bin_array[16]){

    for(int i=0; i<16; i++){
        encrypted_binary_array[i] = one_word_array[i]^key_bin_array[i];
    }

    show_16Bin_array(one_word_array);
    printf(" ^ ");
    show_16Bin_array(key_bin_array);
    printf(" = ");
    show_16Bin_array(encrypted_binary_array);
    //printf("\n");
    int my_ascii = binary_to_ascii(encrypted_binary_array);

    printf("Ascii for final %d\n",my_ascii);

}

int binary_to_ascii(int encrypted_bin[16]){
    int final_ascii=0;
    int bin_counter =0;
    for(int i=0; i<16; i++){
        if(encrypted_bin[i]==1){
            break;
        } else{
            bin_counter++;
        }
    }
    int start  = 16-bin_counter;
    int power = start-1;

    printf("bin_counter %d",bin_counter);

    for(int i=0; i<start; i++){

        if(encrypted_bin[bin_counter]==1){
            final_ascii +=my_pow(power);

            bin_counter++;
        } else{
            bin_counter++;

        }
        power--;


    }
//    if(encrypted_bin[15]==1){
//        final_ascii++;
//    }

    return final_ascii;
}


int my_pow(int number){
    int result=1;

    while (number!=0){
        result *= 2;
        number--;
    }

    return result;
}

void show_16Bin_array(int toprint[16]){

    for(int i=0; i<16; i++){
        printf("%d",toprint[i]);
    }
}




//void copy_two_16bin_array(int receiver[16],int transmitter[16]){
//
//
//    for(int i =0 ; i<16 ; i++){
//        receiver[i] = transmitter[i];
//    }
//
//}

#endif //NCC_ONLINE_SECURE_BANK_CORN_ENCRYPTION_H
