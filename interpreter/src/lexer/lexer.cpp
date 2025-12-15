#include "../../include/lexer/lexer.h"
#include <algorithm>
#include <cctype>

const std::unordered_map<std::string, TokenType> Lexer::keywords = {
    {"Use", TokenType::USE},
    {"Class", TokenType::CLASS},
    {"private", TokenType::PRIVATE},
    {"public", TokenType::PUBLIC},
    {"function", TokenType::FUNCTION},
    {"end", TokenType::END},
    {"if", TokenType::IF},
    {"elif", TokenType::ELIF},
    {"else", TokenType::ELSE},
    {"while", TokenType::WHILE},
    {"for", TokenType::FOR},
    {"in", TokenType::IN},
    {"try", TokenType::TRY},
    {"catch", TokenType::CATCH},
    {"GameObject", TokenType::GAMEOBJECT},
    {"Prefab", TokenType::PREFAB},
    {"Inheritance", TokenType::INHERITANCE},
    {"Component", TokenType::COMPONENT},
    {"start", TokenType::START},
    {"update", TokenType::UPDATE},
    {"awake", TokenType::AWAKE},
    {"string", TokenType::STRING},
    {"int", TokenType::INT},
    {"double", TokenType::DOUBLE},
    {"list", TokenType::LIST},
    {"map", TokenType::MAP}};

Lexer::Lexer(const std::string &source) : source(source) {}

bool Lexer::isAtEnd() const
{
    return current >= source.length();
}

char Lexer::advance()
{
    return source[current++];
}

char Lexer::peek() const
{
    if (isAtEnd())
        return '\0';
    return source[current];
}

char Lexer::peekNext() const
{
    if (current + 1 >= source.length())
        return '\0';
    return source[current + 1];
}

bool Lexer::match(char expected)
{
    if (isAtEnd())
        return false;
    if (source[current] != expected)
        return false;

    current++;
    return true;
}

void Lexer::addToken(TokenType type, const std::string &lexeme)
{
    std::string tokenLexeme = lexeme.empty()
                                  ? source.substr(start, current - start)
                                  : lexeme;

    tokens.emplace_back(type, tokenLexeme, line);
}

void Lexer::skipWhitespaceAndComment()
{
    while (true)
    {
        if (isAtEnd())
            break;

        char c = peek();
        if (std::isspace(c))
        {
            if (c == '\n')
                line++;
            advance();
        }
        else if (c == '#')
        {
            if (peekNext() != '#')
            {
                while (peek() != '\n' && !isAtEnd())
                    advance();
            }
            else
            {
                advance();
                advance();
                advance();
                while (!isAtEnd())
                {
                    if (peek() == '#' && peekNext() == '#' && source[current + 2] == '#')
                    {
                        advance();
                        advance();
                        advance();
                        break;
                    }
                    if (peek() == '\n')
                        line++;
                    advance();
                }
            }
        }
        else
        {
            break;
        }
    }
}

void Lexer::identifier()
{
    while (std::isalnum(peek()) || peek() == '_')
        advance();

    std::string text = source.substr(start, current - start);

    auto it = keywords.find(text);
    if (it != keywords.end())
    {
        addToken(it->second);
    }
    else
    {
        addToken(TokenType::IDENTIFIER);
    }
}

void Lexer::numberLiteral()
{
    while (std::isdigit(peek()))
        advance();

    if (peek() == '.' && std::isdigit(peekNext()))
    {
        advance();
        while (std::isdigit(peek()))
            advance();
    }

    addToken(TokenType::NUMBER);
}

void Lexer::stringLiteral()
{
    while (peek() != '"' && !isAtEnd())
    {
        if (peek() == '\n')
            line++;
        advance();
    }

    if (isAtEnd())
    {
        return;
    }

    advance();

    std::string value = source.substr(start + 1, current - start - 2);
    addToken(TokenType::STRING, value);
}

void Lexer::scanToken()
{
    char c = advance();

    switch (c)
    {
    // Tek karakterli simgeler
    case ':':
        addToken(TokenType::COLON);
        break;
    case ';':
        addToken(TokenType::SEMICOLON);
        break;
    case '(':
        addToken(TokenType::LPAREN);
        break;
    case ')':
        addToken(TokenType::RPAREN);
        break;
    case '{':
        addToken(TokenType::LBRACE);
        break;
    case '}':
        addToken(TokenType::RBRACE);
        break;
    case '[':
        addToken(TokenType::LBRACKET);
        break;
    case ']':
        addToken(TokenType::RBRACKET);
        break;
    case ',':
        addToken(TokenType::COMMA);
        break;

    case '=':
        if (match('='))
        {
            addToken(TokenType::EQ_EQ);
        }
        else
        {
            addToken(TokenType::EQUAL);
        }
        break;
    case '!':
        if (match('='))
        {
            addToken(TokenType::BANG_EQ); // !=
        }
        else
        {
            // error only !
        }
        break;
    case '.':
        if (match('.'))
        {
            addToken(TokenType::DOT_DOT);
        }
        else
        {
            // error only .
        }
        break;
    case '*':
        if (match('*'))
        {
            addToken(TokenType::STAR_STAR); // **
        }
        else
        {
            // error only *
        }
        break;

    case '"':
        stringLiteral();
        break;

    default:
        if (std::isalpha(c) || c == '_')
        {
            identifier();
        }
        else if (std::isdigit(c))
        {
            numberLiteral();
        }
        else
        {
            // unknown character
        }
        break;
    }
}

std::vector<Token> Lexer::scanTokens()
{
    while (!isAtEnd())
    {
        start = current;
        skipWhitespaceAndComment();

        if (isAtEnd())
            break;

        start = current;
        scanToken();
    }

    tokens.emplace_back(TokenType::EOF_TOKEN, "", line);
    return tokens;
}