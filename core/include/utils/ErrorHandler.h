
#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <string>
#include <iostream>

namespace TQS
{

    class ErrorHandler
    {
    public:
        static void assistantNotify(const std::string &message)
        {
            std::cout << "📢 [Turquoise Assistant]: " << message << std::endl;
        }

        static void error(int line, const std::string &message)
        {
            std::cerr << "❌ [Error - Line " << line << "]: " << message << std::endl;
        }
    };

}

#endif