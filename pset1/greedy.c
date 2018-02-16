#include<stdio.h>
#include<math.h>
#include<cs50.h>
int get_n(int);
int main(void)
{
    float dol,rnd;
    int cents;
    
    do
    {
        printf("\nO hai! How much change is owed?\n");
        dol=GetFloat();
    }while(dol<0);
    
    dol=dol*100;
    rnd=roundf(dol);
    cents=(int)rnd;
    
    int n,q,count=0;
    
    while(cents!=0)
    {
        n=get_n(cents);
        q=cents/n;
        cents=cents%n;
        count=count+q;
    }
    
    printf("%i\n",count);
    
    return 0;
}

int get_n(int x)
{
    if(x>=25)
        return 25;
    else if(x>=10)
            return 10;
        else if(x>=5)
                return 5;
            else
                return 1;
}