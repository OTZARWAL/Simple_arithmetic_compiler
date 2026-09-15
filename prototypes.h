
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

//colors
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define RESET "\033[0m"


typedef enum {
    UNKOWN,
    NUMBER,
    OPERATOR,
    END,
}Token_type;

// structure to represent a certain token
typedef struct s_node{
    int value;
    Token_type type;
    struct s_node *next;
} Token;


void error(Token *tokens, const char *msg);
void free_tokens(Token *tokens);
int check_opr(char opt);
void print_tokens(Token *tokens);
int calcul(int a, char op, int b);
void generate_assembly(Token *tokens);