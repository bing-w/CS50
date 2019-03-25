#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc!=2) //checks that there's 1 key
    {
        printf("Usage ./caesar key\n");
        return 1;
    }
    
   for (int i=0, s=strlen(argv[1]);i<s;i++)
    {
        if (isdigit(argv[1][i])==false) //makes sure the key is a positive number
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Convert string to integer and make sure it less than 26
    int k = atoi(argv[1]) % 26;
    
    // Get a string
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
            continue;
        }

        int ascii_offset = isupper(plaintext[i]) ? 65 : 97;

        int pi = plaintext[i] - ascii_offset;
        int ci = (pi + k) % 26;

        printf("%c", ci + ascii_offset);
    }

    printf("\n");
    return 0;
}
