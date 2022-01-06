#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/* 
TO DO
- Add specific modifiers such as:
    - Min amount of specifc characters (i.e. Capitals, Numbers, Special char)
- Save passwords with an association
- Some sort of encryption for saved password
- decrypt when viewing password and association
*/

void passwordGenerator(int desiredLength)
{   
    
    char characters[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@|#$%^&*()-{}[]:;\\<>./?~`";
    
    char password[desiredLength];

    int counter = 0;

    srand(time(NULL));

    printf("Your password is: \n");

    printf("---------------------------------------------\n");

    for(counter = 0 ; counter < desiredLength ; counter++ ) {
        int index = rand() % 89;
        password[counter] = characters[index];
        printf("%c", password[counter]);
    }
    

    printf("\n");
    printf("---------------------------------------------\n");
   
}
  
  
int main()
{
    int desiredLength;

    printf("How many character do you want your password to be?\n");
    printf("The password will be this long: ");
    scanf("%i", &desiredLength);
    printf("---------------------------------------------\n");
    passwordGenerator(desiredLength);
     
    return 0;
}





