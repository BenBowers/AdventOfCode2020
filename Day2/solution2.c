#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE* file = fopen("input", "r");
    uint32_t totalCount = 0;
    uint32_t idx1;
    uint32_t idx2;
    char character;
    char password[256];
    
    while ( !feof(file) )
    {
        fscanf(file, "%u-%u %c: %s\n", &idx1, &idx2, &character, password);

        if ( password[idx1-1] == character )
        {
            if ( password[idx2-1] != character )
            {
                totalCount++;
            }
        }
        else
        {
            if ( password[idx2-1] == character )
            {
                totalCount++;
            }
        }
        
    }
    fclose(file);
    
    printf("%d\n", totalCount);

    return 0;
}


