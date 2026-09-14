// Arithmetic compiler in c

// Import Libraries
    // standard IO library
#include <stdio.h>
    // POSIX
#include <unistd.h>
    // memoty allocation
#include <stdlib.h>
    // for type
#include <ctype.h>
    // String Manipulation
#include <string.h>

#define BUFFER_SIZE 1024

// Tokenization


// enumeration for deticting type of tokens
typedef enum {
    NUMBER,
    OPERATOR,
    END,
}Token_type


// structure to represent a certain token
typedef struct s_node{
    int value;
    token type;
    struct s_node next;
} Token;

int check_opr(char opt){
    return (opt == '+' || opt == '-');
}
Token *parser(char *input)
{
    int pos;
    char *endpoint;
    Token tokens_chain = malloc(300 * sizeof(Token));
    if(!tokens_chain){
        perror("malloc");
        exit(1);
    }

    pos = 0;
    endpoint = NULL;
    while(*input)
    {
        if(isdigit(*input)){
            long num = strtol(*input, &endpoint, 10);
            if(endpoint == input){
                fprintf(stderr, "No valid digits were found.\n");
                exit(EXIT_FAILURE);
            }
            tokens_chain[pos].type = NUMBER;
            tokene_chain[pos].value = num;
            pos++
        }else if(check_opr(*input)){
            tokens_chain[pos].type = OPERATOR;
            tokens_chain[pos].value = (int)*input;
            pos++;
            input++;
            }
        }
        else
            input++;
    }


}


int main(void){


}