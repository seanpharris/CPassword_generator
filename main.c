#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include<string.h>

/* 
TO DO
- Add specific modifiers such as:
    - Min amount of specific characters (i.e. Capitals, Numbers, Special char)
- Save passwords with an association
- Some sort of encryption for saved password
- decrypt when viewing password and association
*/

/*
Notes:
compile code - gcc -o main main.c
run code - ./main
*/
void passwordGenerator(int desiredLength)
{   
    char characters[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@|#$%^&*()-{}[]:;\\<>./?~`";

    char password[desiredLength];

    int counter = 0;

    srand(time(NULL));

    for(counter = 0 ; counter < desiredLength ; counter++ ) {
        int index = rand() % 89;
        password[counter] = characters[index];
        printf("%c", password[counter]);
    }
}

void modifiedPasswordGenerator(int desiredLength)
{   
    int desiredSpecCharAmount;

    int desiredUpperCharAmount;

    int desiredLowerCharAmount;

    int desiresdIntAmount;

    char specChar[28] = {"!@|#$%^&*()-{}[]:;\\<>./?~`\""};

    char number[10] = {"0123456789"};

    char lowerCase[26] = {"abcdefghijklmnopqrstuvwxyz"};

    char upperCase[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    char password[desiredLength];
    
    char symbols[desiredLength];

    int counter = 0;

    srand(time(NULL));

    printf("What is the minimum amount of special characters?");
    scanf("%i", &desiredSpecCharAmount);

    printf("What is the minimum amount of upper case characters?");
    scanf("%i", &desiredUpperCharAmount);

    printf("What is the minimum amount of lower case  characters?");
    scanf("%i", &desiredLowerCharAmount);

    printf("What is the minimum amount of number characters?");
    scanf("%i", &desiresdIntAmount);

    /* TODO - Allocate space for the minimum amount of characters in the password*/

    for(counter = 0 ; counter < desiredLength ; counter++ ) {
        int index = rand() % 4;

        if (index == 1){
            int dice = rand() % 28;
            password[counter] = specChar[dice];
            printf("%c", password[counter]);
        }
        else if (index == 2){
            int dice = rand() % 26;
            password[counter] = upperCase[dice];
            printf("%c", password[counter]);
        }
        else if (index == 3){
            int dice = rand() % 26;
            password[counter] = lowerCase[dice];
            printf("%c", password[counter]);
        }
        else if (index == 4){
            int dice = rand() % 10;
            password[counter] = number[dice];
            printf("%c", password[counter]);
        }
    }
   
}
  
int main()
{
    int desiredLength;

    char yesOrNo;

    printf("How many characters do you want your password to be?\n");

    scanf("%i", &desiredLength);

    printf("Your password will be %i characters long.\n", desiredLength);

    printf("Do you want to modify the types and amount of characters in your password? (\"yes\" or \"no\")\n");

    scanf("%s", &yesOrNo);

    if (yesOrNo == 121 || yesOrNo == 89) {
        printf("---------------------------------------------\n");
        printf("Your specialized password is: \n");
        modifiedPasswordGenerator(desiredLength);
    }
    else if(yesOrNo == 110 || yesOrNo == 78) {
        printf("---------------------------------------------\n");
        printf("Your password is: \n");
        passwordGenerator(desiredLength);
    }

    printf("\n---------------------------------------------\n");
     
    return 0;
}





