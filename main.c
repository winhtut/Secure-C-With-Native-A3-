#include <stdio.h>
#include "secure_bank.h"
#include "corn_encryption.h"

//#define RESET "\x1b[0m"
//#define BOLD "\x1b[1m"
//#define FAINT "\x1b[2m"
//#define UNDERLINE "\x1b[4m"
//#define BLINK "\x1b[5m"
//#define INVERSE "\x1b[7m"
//#define RED "\x1b[31m"
//#define TEST "\x1b[5m"

int main()
{
    //printf("%sBold text%s\n",BOLD,RESET);
    char encrypt_key[4];
    char toEncrypt[50];

    printf("Enter encryption key:(only 4 character):");
    scanf(" %[^\n]",&encrypt_key[0]);
//    int key_for_operate = key_encrypt(encrypt_key);
    printf("Enter data to Encrypt!");
    scanf(" %[^\n]",&toEncrypt[0]);

    char_to_binary(toEncrypt,encrypt_key);
//    space_counter();
//    loading_from_file();
//    printing_all_data();
//    main_menu();
    return 0;
}
