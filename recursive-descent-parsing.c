#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
char token;
int lookahead;
char s[100];
void funa();
void funb();
void fun();
char getToken()
{
    lookahead+=1;
    return s[lookahead];
}
void funa()
{
    if(token == 'b')
    {
        token = getToken();
        if(token == 'a')
            token = getToken();
        else
        {
            printf("Error in Parsing");
            exit(0);
        }
    }
    else
    {
        if(token == 'a' || token == 'c')
        {
            fun();
            funb();
        }
        else
        {
            printf("Error in Parsing");
            exit(0);
        }

    }
}


void funb()
{
    if(token == 'b')
    {
        token = getToken();
        funa();
    }
    else
    {
        if(token == 'a' || token == 'c')
            fun();
        else
        {
            printf("Error in Parsing");
            exit(0);
        }

    }
}
void fun()
{
    if(token == 'a')
    {
        token = getToken();
        funa();
        fun();
    }
    else 
        if (token == 'c')
            token=getToken();
        else
        {
            printf("Error in Parsing");
            exit(0);
        }
}
int main() {
    gets(s);
    char ch = '$';
    strncat(s, &ch, 1);
    token = s[0];
    fun();
    if(token == '$')
     printf("Sucessfully Parsed");
    else
      printf("Error in Parsing");
    return 0;
}
