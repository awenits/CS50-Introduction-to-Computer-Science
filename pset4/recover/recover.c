#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    //ensures proper usage
    if (argc != 2)
    {
        fprintf(stderr,"Usage : ./recover image\n");
        return 1;
    }

    //remember filename
    char *infile = argv[1];
    
    //opens infile for reading 
    FILE *inptr = fopen(infile,"rb");
    if(inptr == NULL)
    {
        fprintf(stderr,"Could not open %s\n",infile);
        return 2;
    }
    
    // for naming files starting from 0
    int filenumber = 0;
     
    // for storing filename
    char filename[8];
    
    // to store a block of 512 bytes
    uint8_t buffer[512];
    
    //pointer to outfile
    FILE *outptr = NULL;
    
    //reads blocks till the end
    while(fread(buffer, sizeof(buffer), 1, inptr) == 1)
    {
        // to find beginning of jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        { 
            //to close the previous jpg file if any opened file is available
            if (outptr != NULL)
            {
                fclose(outptr);
                outptr = NULL;
            }
            
            //create filename
            sprintf(filename,"%03i.jpg", filenumber);
            
            //opens the outfile filename
            outptr = fopen(filename, "wb");
            if (outptr == NULL) //ensures opening of file
            {
                fprintf(stderr, "Could not open %s.\n", filename);
                return 3;
            }
            
            // write the block to outfile 
            fwrite(buffer, sizeof(buffer), 1, outptr);
        
            //increments the filenumber to change the filename
            filenumber++;
        }
        else if (outptr != NULL)
        {
            //continue writing the blocks to previous file if it is not the beginning of file
            fwrite(buffer, sizeof(buffer), 1, outptr);
        }
    }
    
    //closes last jpg file
    fclose(outptr);
    
    //closes infile
    fclose(inptr);
    
    return 0;
}