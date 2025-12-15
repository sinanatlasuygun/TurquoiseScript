
#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <iostream>

enum class TokenType
{
    // Single-character symbols
    COLON,     // :
    SEMICOLON, // ;
    EQUAL,     // =
    LPAREN,    // (
    RPAREN,    // )
    LBRACE,    // {
    RBRACE,    // }
    LBRACKET,  // [
    RBRACKET,  // ]
    COMMA,     // ,

    // Two or more character symbols / Operators
    DOT_DOT,   // .. (Range)
    EQ_EQ,     // ==
    BANG_EQ,   // !=
    STAR_STAR, // **

    // Literals
    IDENTIFIER, // Variable, class, function
    STRING,     // "Hello World"
    NUMBER,     // 123 or 1.23

    // Keywords
    USE,         // Use
    CLASS,       // Class
    PRIVATE,     // Private
    PUBLIC,      // Public
    FUNCTION,    // Function
    END,         // End
    IF,          // If
    ELIF,        // Else If
    ELSE,        // Else
    WHILE,       // While
    FOR,         // For
    IN,          // In
    TRY,         // Try
    CATCH,       // Catch
    GAMEOBJECT,  // Game Object
    PREFAB,      // Prefab
    INHERITANCE, // Inheritance
    COMPONENT,   // Component
    START,       // Start
    UPDATE,      // Update
    AWAKE,       // Awake

    // TYPES
    STRING, // string
    INT,    // int
    DOUBLE, // double
    LIST,   // list
    MAP,    // map

    // OTHERS
    COMMENT_LINE, // #
    EOF_TOKEN,    // End Of File
};

struct Token
{
    TokenType type;
    std::string lexeme;
    int line;
    Token() : type(TokenType::EOF_TOKEN), lexeme(""), line(0) {}
    Token(TokenType type, const std::string &lexeme, int line)
        : type(type), lexeme(lexeme), line(line) {}

    std::string toString() const
    {
        return lexeme;
    }
};

#endif