#include "prototypes.h"




void free_tokens(Token *tokens){
    if(tokens != NULL){
        free(tokens);
    }
}

void error(Token *tokens, const char *msg){
    fprintf(stderr, "Error: %s\n", msg);
    free_tokens(tokens);
    exit(EXIT_FAILURE);
}

int calcul(int a, char op, int b){
    switch(op){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if(b == 0){
                fprintf(stderr, "Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
            return a / b;
        case '%':
            if(b == 0){
                fprintf(stderr, "Error: Modulo by zero\n");
                exit(EXIT_FAILURE);
            }
            return a % b;
        default:
            fprintf(stderr, "Error: Unknown operator %c\n", op);
            exit(EXIT_FAILURE);
    }
}

int check_opr(char opt){
    return (opt == '+' || opt == '-' || opt == '*' || opt == '/' || opt == '%');
}

void print_tokens(Token *tokens){
    int pos = 0;
    while(tokens[pos].type != END){
        if(tokens[pos].type == NUMBER){
            printf("Token %d: NUMBER, value: %d\n", pos, tokens[pos].value);
        }else if(tokens[pos].type == OPERATOR){
            printf("Token %d: OPERATOR, value: %c\n", pos, (char)tokens[pos].value);
        }
        pos++;
    }
}


void generate_assembly(Token *tokens){
    
    int pos = 0;
    printf(GREEN "LOAD  " RESET);
    printf(YELLOW "  %d\n" RESET, tokens[pos].value);
    pos++;
    while(tokens[pos].type != END){
        if(tokens[pos].type == OPERATOR){
            char op = (char)tokens[pos].value;
            pos++;
            if(tokens[pos].type == NUMBER){
                // printf(GREEN "LOAD  " RESET);
                // printf(YELLOW "  %d\n" RESET, tokens[pos].value);
                switch(op){
                    case '+':           
                        printf(GREEN "ADD %d\n" RESET, tokens[pos].value);
                        break;
                    case '-':                       
                        printf(YELLOW "SUB %d\n" RESET, tokens[pos].value);
                        break;
                    case '*':
                        printf( BLUE "MUL %d\n" RESET, tokens[pos].value);
                        break;
                    case '/':               
                        printf( PURPLE"DIV %d\n" RESET, tokens[pos].value);
                        break;
                    case '%':
                        printf( RED "MOD %d\n" RESET, tokens[pos].value);
                        break;
                    default:
                        fprintf(stderr, RED "Error: Unknown operator %c\n" RESET, op);
                        exit(EXIT_FAILURE);
                }
            }else{
                fprintf(stderr, RED "Error: Expected NUMBER after OPERATOR\n" RESET);
                exit(EXIT_FAILURE);
            }
        }else{
            fprintf(stderr,RED "Error: Expected OPERATOR\n" RESET);
            exit(EXIT_FAILURE);
        }
        pos++;
    }
}