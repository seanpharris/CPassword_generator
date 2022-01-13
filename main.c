#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/* 
TO DO
- Add specific modifiers such as:
    - Min amount of specific characters (i.e. Capitals, Numbers, Special char)
- Save passwords with an association
- Some sort of encryption for saved password
- decrypt when viewing password and association
*/

/*
compile code - gcc -o main main.c
run code - ./main
*/
void passwordGenerator(int desiredLength)
{   
    
    char characters[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@|#$%^&*()-{}[]:;\\<>./?~`";

    char specChar[28] = {"!@|#$%^&*()-{}[]:;\\<>./?~`\""};

    char password[desiredLength];
    
    char symbols[desiredLength];

    int counter = 0;

    srand(time(NULL));

    for(counter = 0 ; counter < desiredLength ; counter++ ) {
        int index = rand() % 89;
        password[counter] = characters[index];
        printf("%c", password[counter]);
        symbols[counter] = specChar[counter];
    }
    

    printf("\n%s", symbols);  
   
}
  
  
int main()
{
    int desiredLength;

    printf("How many character do you want your password to be?\n");

    printf("Your password will be ");

    scanf("%i", &desiredLength);

    printf("characters long.\n");

    printf("---------------------------------------------\n");

    printf("Your password is: \n");

    passwordGenerator(desiredLength);

    printf("\n---------------------------------------------\n");
     
    return 0;
}





