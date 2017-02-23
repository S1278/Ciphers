#include <stdio.h>
#include <string.h>
#include <ctype.h>
/**
 * Pass a keyword as command line argument
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
    
    char* keyword = argv[1];
    int keylen = strlen(keyword);
    
    // Generate an error if any character in keyword is non-alphabetical.
    for (int i = 0; i < keylen; i++)
    {
        if (isalpha(keyword[i]) == 0) 
        {
            printf("Error!\n");
            return 1;
        }
    }
    
    char text[50];
    printf("Enter plain text: ");
    scanf("%[^\n]%*c", text);
    int n = strlen(text), key = 0;
    char temp;
    for (int i = 0, k = 0; i < n; i++)
    {
        temp = keyword[k];
        // 'A'(ascii-65) and 'a'(ascii-97) taken as 0.
        key = (int) (temp) - (!isupper(temp)) * 97 - (!islower(temp)) * 65;
        
        if (isupper(text[i]) != 0)
        {
            text[i] = 'A' + (text[i] - 'A' + key) % 26;
            k++;
        }
        else if (islower(text[i]) != 0)
        {
            text[i] = 'a' + (text[i] - 'a' + key) % 26;
            k++; 
        }
        
        if (k == keylen) 
        {
            // Reset the index to first letter.
            k = 0;
        }
    }
    printf("Encoded text: %s\n", text);
    return 0;
}
