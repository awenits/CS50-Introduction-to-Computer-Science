#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

void print_ini(char c);
int main()
{
    string name;
    name=get_string();
    int i,len;

    print_ini(name[0]);

    for(i=0,len=strlen(name);i<len;i++)
    {
        if(name[i]==' ')
         {
            print_ini(name[i+1]);
         }
    }

    printf("\n");

    return 0;
}

void print_ini(char c)
{
    if(islower(c))
        printf("%c", toupper(c));
    else
        printf("%c",c);
}