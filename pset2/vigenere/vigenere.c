#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, string argv[])
{
    if( argc != 2 ) 
    {
        //check no. of arguments
        printf("Error in argument passing !!");
        return 1;
    }
    else
    {
    // check argv is all alpha
        int keyLength = strlen(argv[1]);
        for (int ctr = 0; ctr < keyLength; ctr++)
        {
            if(isalpha(argv[1][ctr]) == false)
            {
                printf("You must enter only alphabetical letters! \n");
                return 1;
            }
        }
    }
    
    string k,s;
    k=argv[1];
        
    int i,j,p=0;
    int key[strlen(k)];
        
    printf("plaintext: ");
    s=get_string();
    
    for(i = 0; i < strlen(k); i++)
    {
        if(isalpha(k[i]))
        {
            if(isupper(k[i]))
            {
                key[p]=k[i]-65;
                p++;
            }    
            else
            {
                key[p]=k[i]-97;
                p++;
            }
        }
    }
    
    printf("ciphertext: ");
    
    for(j=0,p=0; j<strlen(s); j++)
    {
        if(p >= strlen(k))
            p=p%strlen(k);
           
        if(isalpha(s[j]))
	    {	
		    if(isupper(s[j]))
		    {
			    s[j]-=65;
			    s[j]=(s[j]+key[p])%26;
			    p++;
			    s[j]+=65;
			    printf("%c",s[j]);			
			}
    		else 
	    	{
		    	s[j]-=97;
	    		s[j]=(s[j]+key[p])%26;
		    	p++;
				s[j]+=97;
    			printf("%c",s[j]);
	    	}
	    }
	    else
	    {
		    printf("%c",s[j]);
		}
    }	
    
    printf("\n");
  
    return 0;
}