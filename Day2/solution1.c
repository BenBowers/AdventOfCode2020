#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE* file = fopen("input", "r");
    uint32_t ii;
    uint32_t passCount;
    uint32_t totalCount = 0;
    uint32_t min;
    uint32_t max;
    char character;
    char password[256];
    
    while ( !feof(file) )
    {
        ii = 0;
        passCount = 0;
        fscanf(file, "%u-%u %c: %s\n", &min, &max, &character, password);
        while ( password[ii] != '\0' )
        {
            if ( password[ii] == character )
            {
                passCount++;
            }
            ii++;
        }

        if ( passCount <= max && passCount >= min )
        {
            totalCount++;
        }
    }
    fclose(file);
    
    printf("%d\n", totalCount);

    return 0;
}


