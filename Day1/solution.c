#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
int readFile(char *filename, uint16_t** array, size_t* arraySize);
int twoSum( uint16_t* array, size_t arraySize, uint16_t target, uint16_t* out);
int threeSum( uint16_t* array, size_t arraySize, uint16_t target, uint16_t* out);

int main(int argc, char const *argv[])
{
    uint16_t* array;
    size_t size;
    uint16_t out[3];
    if ( readFile("input", &array, &size) == 0 )
    {
        twoSum(array, size, 2020, out);
        printf("{%u, %u} Product = %u\n", out[0], out[1], out[0] * out[1]);
        threeSum(array, size, 2020, out);
        printf("{%u, %u, %u} Product = %u\n", out[0], out[1], out[2], out[0] * out[1] * out[2]);
        free(array);
    }

    return 0;
}

int threeSum( uint16_t* array, size_t arraySize, uint16_t target, uint16_t* out)
{
    for ( size_t ii = 0; ii < arraySize - 2; ii++ )
    {
        for ( size_t jj = ii + 1; jj < arraySize - 1; jj++ )
        {
            for ( size_t kk = jj + 1; kk < arraySize; kk++)
                if ( array[ii] + array[jj] + array[kk] == target )
                {
                    out[0] = array[ii];
                    out[1] = array[jj];
                    out[2] = array[kk];
                    return 0;
                }
        }
    }
    return 1;
}

int twoSum( uint16_t* array, size_t arraySize, uint16_t target, uint16_t* out)
{
    for ( size_t ii = 0; ii < arraySize - 1; ii++ )
    {
        for ( size_t jj = ii + 1; jj < arraySize; jj++ )
        {
            if ( array[ii] + array[jj] == target )
            {
                out[0] = array[ii];
                out[1] = array[jj];
                return 0;
            }
        }
    }
    return 1;
}

int readFile(char *filename, uint16_t** array, size_t* arraySize)
{
    uint16_t temp;
    int returnVal = 0;
    FILE *file = fopen(filename, "r");
    *arraySize = 0;

    if ( file != NULL )
    {
        while ( !feof(file) )
            if ( getc(file) == '\n' )
                (*arraySize)++;

        rewind(file);
        *array = malloc((*arraySize)* sizeof(uint16_t));

        for (unsigned int line = 0; line < *arraySize; line++)
        {
            if( fscanf(file, "%" SCNu16 "\n", &temp) == 1 )
            {
                (*array)[line] = temp;
            }
            else
            {
                fprintf(stderr, "Error parsing file.\n");
                free(*array);
                returnVal = 1;
                break;
            }

        }
        fclose(file);
    }
    else
    {
        fprintf(stderr, "Error opening file\n");
        return returnVal = 2;
    }
    
    return returnVal;
}