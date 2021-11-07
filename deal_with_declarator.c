#include "cdecl.h"

int top = -1;
struct token stack[MAXTOKENS];
struct token this_token;

void deal_with_arrays(void)
{
    while ( this_token.type == '[' )
    {
        printf("array ");
        gettoken();
        if ( isdigit( this_token.string[0] ) )
        {
            printf( "0..%d ", atoi( this_token.string ) - 1 );
            gettoken();
        }
        gettoken();
        printf("of ");
    }
}

void deal_with_function_args()
{
    while ( this_token.type != ')' )
    {
        gettoken();
    }
    gettoken();
    printf( "function returning " );
}

void deal_with_pointers(void)
{
    while ( stack[top].type == '*' )
    {
        printf( "%s ", pop.string);
    }
}

void deal_with_declarator(void)
{
    switch (this_token.type)
    {
        case '[' : deal_with_arrays();
            break;
        case '(' : deal_with_function_args();
            break;
    }

    deal_with_pointers();

    while ( top >= 0 )
    {
        if ( stack[top].type == '(' ) 
        {
            pop;
            gettoken();
            deal_with_declarator();
        }
        else
        {
            printf( "%s ", pop.string );
        }
    }
}
