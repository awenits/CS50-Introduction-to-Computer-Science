#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int height,i,space,hash;
    
    do
    {
        printf("\nheight: ");
        height = get_int();
    }while( (height < 0) || (height > 23) );
    
    for( i = height ; i > 0 ; i-- )
    {
        for( space = 1 ; space <= i-1 ; space++ )
        {
            printf(" ");
        }
        for( hash = 0 ; hash <= (height+1)-space ; hash++ )
        {
            printf("#");
        }
        printf("\n");
    }
    
    return 0;
}