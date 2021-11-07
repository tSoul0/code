#include "cdecl.h"

enum type_tag classify_string(void)
{
    char *s = this_token.string;
    if ( !strcmp( s, "const" ) )
    {
        strcpy( s, "read-only" );
        return QUALIFIER;
    }
    if ( !strcmp( s, "volatile" ) ) return QUALIFIER;
    if ( !strcmp( s, "void" ) ) return TYPE;
    if ( !strcmp( s, "char" ) ) return TYPE;
    if ( !strcmp( s, "signed" ) ) return TYPE;
    if ( !strcmp( s, "unsigned" ) ) return TYPE;
    if ( !strcmp( s, "short" ) ) return TYPE;
    if ( !strcmp( s, "int" ) ) return TYPE;
    if ( !strcmp( s, "long" ) ) return TYPE;
    if ( !strcmp( s , "float" ) ) return TYPE;
    if ( !strcmp( s, "double" ) ) return TYPE;
    if ( !strcmp( s, "struct" ) ) return TYPE;
    if ( !strcmp( s, "union" ) ) return TYPE;
    if ( !strcmp( s, "enum" ) ) return TYPE;
    return IDENTIFIER;
}

void gettoken(void)
{
    char *p = this_token.string;

    while ( ( *p = getchar() ) == ' ' )
    ;
    if ( isalnum(*p) )
    {
        while ( isalnum( *++p = getchar() ) );
        ungetc( *p, stdin);
        *p = '\0';
        this_token.type = classify_string();
        return;
    }

    if ( *p == '*' )
    {
        strcpy( this_token.string, "pointer to" );
        this_token.type = '*';
        return;
    }

    this_token.string[1] = '\0';
    this_token.type = *p;
    return;
}

void read_to_first_identifier(void)
{
    gettoken();
    while ( this_token.type != IDENTIFIER )
    {
        push(this_token);
        gettoken();
    }

    printf( "%s is ", this_token.string );
    gettoken();
}
