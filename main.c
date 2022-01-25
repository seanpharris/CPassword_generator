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

    printf("\n---------------------------------------------\n");
    printf("Your password is:\n");

    srand(time(NULL));

    for(counter = 0 ; counter < desiredLength ; counter++ ) {
        int index = rand() % 89;
        password[counter] = characters[index];
        printf("%c", password[counter]);
    }
}

void modifiedPasswordGenerator(int desiredLength, int desiredSpecCharAmount, int desiredUpperCharAmount, int desiredLowerCharAmount, int desiresdIntAmount)
{   

    char specChar[28] = {"!@|#$%^&*()-{}[]:;\\<>./?~`\""};

    char number[10] = {"0123456789"};

    char lowerCase[26] = {"abcdefghijklmnopqrstuvwxyz"};

    char upperCase[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    char password[desiredLength];
    
    char symbols[desiredLength];

    printf("\n---------------------------------------------\n");
    printf("Your specialized password is: \n");

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

void modifyParameters(int desiredLength)
{
    int desiredSpecCharAmount = 0;
    int desiredUpperCharAmount = 0;
    int desiredLowerCharAmount = 0;
    int desiresdIntAmount = 0;
    char yesOrNo;
    int totalLength = desiredSpecCharAmount + desiredUpperCharAmount + desiredLowerCharAmount + desiresdIntAmount;

    printf("%i", desiredLowerCharAmount);

    while(desiredLength >= totalLength)
    {
        printf("What is the minimum amount of special characters you would like in your password?\n" 
                "special characters: ");
        scanf("%i", &desiredSpecCharAmount);

        if (totalLength > desiredLength)
        {
            printf("The amount of total characters you have specified have surpassed the desired length of %i\n"
                    "Would you like to change the amount of special characters?", desiredLength);
            scanf("%s", &yesOrNo);
            if (yesOrNo == 'y' || yesOrNo == 'Y') 
            {
            printf("What is the minimum amount of special characters you would like in your password?\n");
            printf("Length of specialized password:");
            scanf("%i", &desiredLength);
            }
        }
        printf("%i of %i remaining characters for the desired length of your password.\n", (desiredLength - desiredSpecCharAmount), desiredLength);

        /*
        printf("What is the minimum amount of upper case characters you would like in your password?\n"
            "upper case characters: ");
        scanf("%i", &desiredUpperCharAmount);
        printf("%i of %i remaining characters for the desired length of your password.\n", (desiredLength - desiredUpperCharAmount), desiredLength);
        */

        /*
        printf("What is the minimum amount of lower case characters you would like in your password?\n"
            "lower case characters: ");
        scanf("%i", &desiredLowerCharAmount);
        printf("%i of %i remaining characters for the desired length of your password.\n", (desiredLength - desiredLowerCharAmount), desiredLength);
        */

        /*
        printf("What is the minimum amount of numerical characters you would like in your password?\n"
            "numerical characters: ");
        scanf("%i", &desiresdIntAmount);
        printf("%i of %i remaining characters for the desired length of your password.\n", (desiredLength - desiresdIntAmount), desiredLength);
        */
    }
    

    modifiedPasswordGenerator(desiredLength, desiredSpecCharAmount, desiredUpperCharAmount, desiredLowerCharAmount, desiresdIntAmount);
}


int main()
{
    int desiredLength;
    char yesOrNo;

    printf("Hello, this is a password generator\n");
    printf("Do you want a specialized password? (\"yes\" or \"no\")\n");
    scanf("%s", &yesOrNo);

    if (yesOrNo == 'y' || yesOrNo == 'Y') {
        printf("How many characters do you want your specialized password to be?\n");
        printf("Length of specialized password:");
        scanf("%i", &desiredLength);
        modifyParameters(desiredLength);
    }
    else if(yesOrNo == 'n' || yesOrNo == 'N') {
        printf("How many characters do you want your password to be?\n");
        printf("Length of password:");
        scanf("%i", &desiredLength);
        passwordGenerator(desiredLength);
    }
     
    printf("\n---------------------------------------------\n");
    printf("END\n");

    return 0;
}





