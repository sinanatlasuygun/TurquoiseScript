#include "interpreter/include/lexer/Lexer.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Betik dosyasını okuyan yardımcı fonksiyon
std::string readFile(const std::string &path)
{
    std::ifstream file(path);
    if (!file.is_open())
    {
        std::cerr << "Hata: Dosya açılamadı: " << path << std::endl;
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main(int argc, char *argv[])
{
    std::cout << "--- MyGameLang Betik Dili - Lexer Testi ---" << std::endl;

    // Örnek betik kodunuz (Sizin verdiğiniz syntax örneğinin bir kısmı)
    std::string sourceCode = R"(
Use "../others";
Use math;

# tek satır yorum

###
blok yorum 1
blok yorum 2
###

Class ClassExample:
    example_str:string = "hello world";
    example_int:int = 0;
    
    private function function_example(**args):
        if 10 == 10:
            # code
        end
    end
end
)";

    // Veya dosyadan okumak için:
    // std::string sourceCode = readFile("examples/test.mylang");

    if (sourceCode.empty())
    {
        return 1;
    }

    Lexer lexer(sourceCode);
    std::vector<Token> tokens = lexer.scanTokens();

    std::cout << "\n[Taranan Token'lar]:" << std::endl;

    // Taranan token'ları listele
    for (const auto &token : tokens)
    {
        if (token.type != TokenType::EOF_TOKEN)
        {
            // Lexeme'yi ve satır numarasını yazdır
            std::cout << "Line " << token.line << ": " << token.toString() << std::endl;
        }
        else
        {
            std::cout << "Line " << token.line << ": EOF" << std::endl;
        }
    }

    return 0;
}