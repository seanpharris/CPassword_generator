#include <math.h>
#include <stdio.h>
#include <stdlib.h>
  

void passwordGenerator(int desiredLength)
{   
    char numbers[] = "0123456789";
  
    char letter[] = "abcdefghijklmnoqprstuvwyzx";
  
    char capital[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
  
    char symbols[] = "!@#$^&*?/";
  
    char password[desiredLength];
  
    int counter = 0;
}
  

  
int main()
{
    int desiredLength;
    printf("How many character do you want your password to be?\n");
    scanf("%i", &desiredLength);
    
    passwordGenerator(desiredLength);
  
    return 0;
}