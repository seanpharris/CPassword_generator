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

    printf("What is the minimum amount of special characters?\n");
    scanf("%i", &desiredSpecCharAmount);
    printf("%i of %i characters will be special characters.\n", desiredSpecCharAmount, desiredLength);

    printf("What is the minimum amount of upper case characters?\n");
    scanf("%i", &desiredUpperCharAmount);
    printf("%i of %i characters will be upper case characters.\n", desiredUpperCharAmount, desiredLength);

    printf("What is the minimum amount of lower case  characters?\n");
    scanf("%i", &desiredLowerCharAmount);
    printf("%i of %i characters will be lower case characters.\n", desiredLowerCharAmount, desiredLength);

    printf("What is the minimum amount of number characters?\n");
    scanf("%i", &desiresdIntAmount);
    printf("%i of %i characters will be number characters.\n", desiresdIntAmount, desiredLength);

    int counter = 0;

    srand(time(NULL));

    for(counter = 0 ; counter < desiredLength ; counter++ ) {
        int index = rand() % 4;
        int specCharCount = 0;
        int upperCharCount = 0;
        int lowerCharCount = 0;
        int intCharcount = 0;

        if (index == 1 && specCharCount < desiredSpecCharAmount){
            int dice = rand() % 28;
            password[counter] = specChar[dice];
            printf("%c", password[counter]);
            specCharCount++;
        }
        else if (index == 2 && upperCharCount < desiredUpperCharAmount){
            int dice = rand() % 26;
            password[counter] = upperCase[dice];
            printf("%c", password[counter]);
            upperCharCount++;
        }
        else if (index == 3 && lowerCharCount < desiredLowerCharAmount){
            int dice = rand() % 26;
            password[counter] = lowerCase[dice];
            printf("%c", password[counter]);
            lowerCharCount++;
        }
        else if (index == 4 && intCharcount < desiresdIntAmount){
            int dice = rand() % 10;
            password[counter] = number[dice];
            printf("%c", password[counter]);
            intCharcount++;
        }
    }
   
}
  
int main()
{
    int desiredLength;
    char yesOrNo;
    char y = 'y';
    char Y = 'Y';
    char n = 'n';
    char N = 'N';

    printf("How many characters do you want your password to be?\n");

    scanf("%i", &desiredLength);

    printf("Your password will be %i characters long.\n", desiredLength);
    
    printf("Do you want to modify the types and amount of characters in your password? (\"yes\" or \"no\")\n");
    
    scanf("%s", &yesOrNo);



    printf("%p\n", &yesOrNo);

    if (yesOrNo == y || yesOrNo == Y) {
        printf("\n---------------------------------------------\n");
        printf("%i\n", desiredLength);
        printf("Your specialized password is: \n");
        modifiedPasswordGenerator(desiredLength);
    }
    else if(yesOrNo == n || yesOrNo == N) {
        printf("\n---------------------------------------------\n");
        printf("Your password is: \n");
        passwordGenerator(desiredLength);
    }

    printf("\n---------------------------------------------\n");
    printf("END\n");
     
    return 0;
}





