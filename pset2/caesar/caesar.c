#include<cs50.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int main(int argc,string argv[])
{
	if(argc!=2)
	{
		printf("Error in argument passing !!!");
		return 1;
	}
	string s;
	int k=atoi(argv[1]);
	printf("plaintext: ");
	s=get_string();
	int i;
	int len=strlen(s);
	printf("ciphertext: ");
	for(i=0;i<len;i++)
	{
		if(isalpha(s[i]))
		{	
			if(isupper(s[i]))
			{
				s[i]-=65;
				s[i]=(s[i]+k)%26;
				s[i]+=65;
				printf("%c",s[i]);			
			}
			else 
			{
				s[i]-=97;
				s[i]=(s[i]+k)%26;
				s[i]+=97;
				printf("%c",s[i]);
			}
		}
		else
		{
			printf("%c",s[i]);
		}
	}
	printf("\n");
	return 0;
}
