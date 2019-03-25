#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int shift(char c);

int main(int argc, string argv[])
{
    if (argc!=2) //checks that there's 1 key
    {
        printf("Usage ./vigenere key\n");
        return 1;
    }
    else
    {
        for (int i = 1; i < strlen(argv[1]); i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Usage ./vigenere key\n");
                return 1;
            }
        }
    }
    // Get string from user
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, j = 0; i < strlen(plaintext); i++)
    {
        int key = shift(argv[1][j % strlen(argv[1])]);
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
            continue;
        }
        int ascii = isupper(plaintext[i]) ? 65 :97;
        int pi = plaintext[i] - ascii;
        int ci = (pi + key) % 26;
        printf("%c", ci + ascii);
        j++;
    }
    printf("\n");
    return 0;
}

int shift(char c)
{
    char key = c;
    if (isupper(key)) 
    {
       key -= 65; 
    }
    else if (islower(key))
    {
       key -= 97;
    }
    return key;
}
