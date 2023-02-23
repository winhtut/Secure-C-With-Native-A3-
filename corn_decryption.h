//
// Created by ncc on 23/02/2023.
//

#ifndef NCC_ONLINE_SECURE_BANK_CORN_DECRYPTION_H
#define NCC_ONLINE_SECURE_BANK_CORN_DECRYPTION_H
#include "stdio.h"
#include "corn_encryption.h"

int ascii_value=0;
int ascii_value_array[200];

void reading_encrypted_data_from_file();
void reading_encrypted_data_from_file(){

    FILE *fptr = fopen("encryptedtest.txt","r");
    int index=0;
    if(fptr!= NULL){
        fscanf(fptr,"%d",&ascii_value);

        while (!feof(fptr)){
            if(ascii_value != 12){
                if(ascii_value==32){
                    continue;
                }

                ascii_value_array[index]=ascii_value;
                fscanf(fptr,"%d",&ascii_value);
                index++;

            }else {
                index=0;
                //decrypt here
            }





        }




    }


}



#endif //NCC_ONLINE_SECURE_BANK_CORN_DECRYPTION_H
