/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./modifycopy n infile outfile\n");
        return 1;
    }

    //remember n
    int n = atoi(argv[1]);
    
    // checking for validity of n
    if ( n < 1 || n > 100)
    {
        fprintf(stderr, "n must be positive integer less than 100 !\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    //remember old height and width
    long int originalWidth = bi.biWidth; 
    long int originalHeight = abs(bi.biHeight); 
   
    //remember old padding
    int oldpadding = (4 - (originalWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    //change the width and height
    bi.biWidth *= n;
    bi.biHeight *= n;
    
    // determine new padding for scanlines
    int newpadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // size of image
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + newpadding) * abs(bi.biHeight);
    
    // total size of new file
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    //variables to store the position of inptr
    long int rowstart;
    long int rowend = 0;
        
    // iterate over infile's scanlines
    for (int i = 0; i < originalHeight; i++)
    {
        //remember start of the row
        rowstart = ftell(inptr);
        
        // for n-1 times
        for (int a = 0; a < n-1; a++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < originalWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple n times to outfile
                for (int p = 0; p < n; p++)    
                {    
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }            
                    
            }
        
            //padding to outfile
            for (int k = 0; k < newpadding; k++)
            {
                fputc(0x00, outptr);
            }
            
            //remember end of row
            rowend = ftell(inptr);
            
            //sending cursor back to starting of row
            fseek(inptr, -(rowend - rowstart), SEEK_CUR);
        }
        
        for (int h = 0; h < originalWidth; h++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple n times to outfile
            for (int p = 0; p < n; p++)    
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }    
        
        // then add it back (to demonstrate how)
        for (int l = 0; l < newpadding; l++)
        {
            fputc(0x00, outptr);
        }      

        // skip over padding, if any
        fseek(inptr, oldpadding, SEEK_CUR);

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
