//
// Created by ncc on 23/02/2023.
//
#ifndef NCC_ONLINE_SECURE_BANK_CORN_DECRYPTION_H
#define NCC_ONLINE_SECURE_BANK_CORN_DECRYPTION_H
#include "stdio.h"
#include "corn_encryption.h"

int ascii_value=0;
int ascii_value_array[200];
int decrypted_binary_array[16];
char decrypted_char_array[200];
char encrypt_key[6];
int toDecrypt_key_binary_array[16];

void reading_encrypted_data_from_file();
void decryption_for_ascii_array(int ascii_array[200]);
void decrypt_main();

void decrypt_main(){
    printf("[+][+][+]This is from Corn Decryption:\n");
    printf("Enter key for corn_cipher:");
    scanf(" %[^\n]",&encrypt_key[0]);
    int encrypt_ascii = key_encrypt(encrypt_key);
    ascii_to_binary_converter(encrypt_ascii);
    for(int a=0; a<16; a++){

        toDecrypt_key_binary_array[a]=sixteen_array[a];
    }
    reading_encrypted_data_from_file();
}

void reading_encrypted_data_from_file(){

    FILE *fptr = fopen("encryptedtest.txt","r");
    int index=0;
    if(fptr!= NULL){
        fscanf(fptr,"%d",&ascii_value);

        while (!feof(fptr)){
            if(ascii_value != 1){

                ascii_value_array[index]=ascii_value;
                fscanf(fptr,"%d",&ascii_value);
                index++;

            }else {
                //index=0;
                //decrypt here
                for(int a=0; a<index; a++){
                    printf("%d ",ascii_value_array[a]);
                }
                printf("\n");


                decryption_for_ascii_array(ascii_value_array);
                for(int i=0; i<index; i++){
                    ascii_value_array[i]=0;

                }

                fscanf(fptr,"%d",&ascii_value);
                index=0;
            }

        }

    }

}

void decryption_for_ascii_array(int ascii_array[200]){

    int element_counter=integer_array_counting_withZero(ascii_array);


    for(int a=0; a<element_counter; a++){


        ascii_to_binary_converter(ascii_array[a]);
        for(int aa=0; aa<16; aa++){
            decrypted_binary_array[aa] = sixteen_array[aa]^toDecrypt_key_binary_array[aa];
        }

        int decrypted_ascii_value = binary_to_ascii(decrypted_binary_array);
        decrypted_char_array[a] = decrypted_ascii_value;

    }
   // we can store data to database;
    printf("Decrypted data one line: %s\n",decrypted_char_array);
//    int clear_counter = char_counting(decrypted_char_array);
//    for(register int i=0; i<clear_counter; i++){
//        decrypted_char_array[i]='\0';
//    }





}


#endif //NCC_ONLINE_SECURE_BANK_CORN_DECRYPTION_H
