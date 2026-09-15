// Arithmetic compiler in c
#include "prototypes.h"




Token *tokenize(char *input)
{
    int pos;
    char *endpoint;
    Token *tokens_chain = malloc(300 * sizeof(Token));
    if(!tokens_chain){
        perror("malloc");
        exit(1);
    }

    pos = 0;
    endpoint = NULL;
    while(*input)
    {
        if(isdigit(*input)){
            long num = strtol(input, &endpoint, 10);
            if(endpoint == input){
                fprintf(stderr, "No valid digits were found.\n");
                exit(EXIT_FAILURE);
            }
            tokens_chain[pos].type = NUMBER;
            tokens_chain[pos].value = num;
            pos++;
            input = endpoint;
        }else if(check_opr(*input)){
            tokens_chain[pos].type = OPERATOR;
            tokens_chain[pos].value = (int)*input;
            pos++;
            input++;
        }else if(isspace(*input)){
            input++;
        }else{
            fprintf(stderr, RED "Invalid character: %c\n" RESET, *input);
            exit(EXIT_FAILURE); 
        }
    }
    tokens_chain[pos].type = END;
    tokens_chain[pos].value = 0;
    return tokens_chain;
}



int parser(Token *tokens, int *res){
    int pos = 0;
    if((tokens)[pos].type != NUMBER){
        return 0;
    }

    *res = tokens[pos].value;
    pos++;

    while(tokens[pos].type != END){

        if(tokens[pos].type != OPERATOR)
            return 0;

        char op = (char)tokens[pos].value;
        pos++;
        if(tokens[pos].type != NUMBER){
            return 0;
        }
        *res = calcul(*res, op, tokens[pos].value);
        pos++;
    }

    return 1;
}


int main(int argc, char *argv[]){
    (void)argv; // Suppress unused parameter warning
    if(argc > 1){
        fprintf(stderr,  RED "Error: This program does not accept command line arguments.\n" RESET);
        exit(EXIT_FAILURE);
    }
    int result = 0;
    int size_input;


    char input[BUFFER_SIZE];
    fgets(input, BUFFER_SIZE, stdin);
    if(input[0] == '\0'){
        error(NULL, "Failed to read input");
        exit(EXIT_FAILURE);
    }

    size_input = strlen(input);
    input[size_input - 1] = '\0'; // Remove the newline character

    Token *tokens = tokenize(input);
    if(parser(tokens, &result)){
        generate_assembly(tokens);
        printf("Result: %d\n", result);
    }else{
        error(tokens, "Invalid expression");
    }

    free_tokens(tokens);
    return 0;
}