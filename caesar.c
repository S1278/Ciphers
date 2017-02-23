#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 * Pass a numerical key as command line argument
 * Upon prompt, enter plain text to be encoded
 */

int main(int argc, char* argv[])
{
    // Error: If more than one or no command-line argument passed.
    if (argc != 2)
    {
        printf("Error!\n");
        return 1;
    }
    
    // Convert string to an integer.
    int k = atoi(argv[1]);
    char text[50];
    printf("Enter plain text: ");
    scanf("%[^\n]%*c", text);
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if (isupper(text[i]) != 0) 
        {
            text[i] = 'A' + (text[i] - 'A' + k) % 26;         
        }
        else if (islower(text[i]) != 0)
        {
            text[i] = 'a' + (text[i] - 'a' + k) % 26;
        }
        // No alteration required for a non-alphabetical character.
    }
    printf("Encoded: %s\n", text);
    return 0;
}
