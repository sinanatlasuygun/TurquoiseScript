#ifndef LEXER_IN
#define LEXER_IN

#include "token.h"
#include <vector>
#include <unordered_map>

class Lexer
{
public:
    Lexer(const std::string &source);
    Token next_token;
    std::vector<Token> scanTokens();

private:
    const std::string source;
    std::vector<Token> tokens;
    int start = 0;   // tokens starter
    int current = 0; // character's position
    int line = 1;    // line's position

    void scanToken();
    bool isAtEnd() const;
    char advance();
    char peek() const;
    char peekNext() const;
    void addToken(TokenType type, const std::string &lexeme = "");
    bool match(char expected);
    void skipWhitespaceAndComment();

    void identifier();
    void stringLiteral();
    void numberLiteral();

    static const std::unordered_map<std::string, TokenType> keywords;
};
#endif