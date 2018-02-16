/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if ( n < 0 )
    {
        return false;
    }
    else
    {
        int middle,left,right;
        
        left = 0;
        right = n-1;
        
        while( left <= right )    
        {      
            middle = (left + right) / 2;
            if ( values[middle] == value)
            {
                return true;
            }
        
            else if ( values[middle] < value )
            {
                left = middle+1;
            }
        
            else
            {
                right = middle-1;
            }
        }
    }    
    return false;
}

/**
 * Sorts array of n values using an O(n^2) sorting algorithm
 */
void sort(int values[], int n)
{
    int i,j,temp;
    
    for( i = 0 ; i < (n-1) ; i++ )
    {
        for( j = 0 ; j < (n-i-1) ; j++ )
        {
            if( values[j] > values[j+1])
            {
                temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
            }
        }
    }
    return;
}
