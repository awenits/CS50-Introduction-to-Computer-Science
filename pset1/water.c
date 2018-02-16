#include<stdio.h>
#include<cs50.h>
int main(void)
{
    int min,bottles;
    
    printf("\nminutes: ");
    min = GetInt();
    
    bottles=min*12;
    
    printf("bottles: %i\n",bottles);
   
    return 0;
}