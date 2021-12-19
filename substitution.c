#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool isequal(string text);
bool isvalid(string text);
bool isone(int count);
void ciphertext(string keytext, string text);

int main(int argc, string argv[])
{
    if(!isone(argc) || !isequal(argv[1]) || !isvalid(argv[1]))
    {
        //printf("invalid\n");
        return 1;
    }
    else
    {
        printf("valid\n");
    }

    string plaintext = get_string("plaintext: ");
    ciphertext(argv[1], plaintext);
    //printf("%c\n", cipher);
}

void ciphertext(string keytext, string text)
{
    int cipher;
    for(int i = 0; i < strlen(text); i++)
    {
        if(isupper(text[i]))
        {
                int numeric = text[i] - 'A';
                cipher = toupper(keytext[numeric]);
                printf("%c", cipher);
        }
        else if(islower(text[i]))
        {
                int numeric = text[i] - 'a';
                cipher = tolower(keytext[numeric]);
                printf("%c", cipher);
        }
        else
        {
            int nocipher = text[i];
            printf("%c", nocipher);
        }

    }
    printf("\n");
}

bool isequal(string text)
{
    int equality = 0;
    for(int i = 0; i < strlen(text); i++)
    {
        for(int j = 0; j < strlen(text); j++)
        {
            if(text[i] == text[j] || text[i] - text[j] == 32)
            {
                equality++;

                if(equality > strlen(text))
                {
                    printf("no repeating chars!\n");
                    return false;
                }
            }
        }
    }
    return true;
}

bool isvalid(string text)
{
    if(strlen(text) != 26)
    {
        printf("26 chars plz!\n");
        return false;
    }
    else
    {
        for(int i = 0; i < 26; i++)
        {
            if(!isalpha(text[i]))
            {
                printf("not alpha!\n");
                return false;
            }

        }
    return true;
    }
}

bool isone(int count)
{
    if(count != 2)
    {
        printf("1 string only!\n");
        return false;
    }
    return true;
}


