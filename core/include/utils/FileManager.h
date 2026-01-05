#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <vector>

namespace TQS

{
    class FileManager
    {
    public:
        static std::string readFile(const std::string &filePath);
        static bool isValidExtension(const std::string &filePath);
        static bool fileExists(const std::string &filePath);
    };
}

#endif