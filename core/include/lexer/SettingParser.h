#ifndef SETTING_PARSER
#define SETTING_PARSER

#include "../context/ProjectContext.h"
#include <string>
#include <map>

namespace TQS
{

    class SettingsParser
    {
    public:
        SettingsParser(const std::string &source);
        bool parse();

    private:
        std::string m_source;
        size_t m_cursor = 0;

        std::string getNextWord();
        void skipWhitespace();
        bool match(const std::string &expected);
    };

}
#endif