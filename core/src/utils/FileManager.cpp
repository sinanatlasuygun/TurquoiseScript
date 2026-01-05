#include "../../include/utils/FileManager.h"
#include <fstream>
#include <sstream>
#include <filesystem>

namespace TQS
{
    bool FileManager::isValidExtension(const std::string &filePath)
    {
        return std::filesystem::path(filePath).extension() == ".tqs";
    }

    bool FileManager::fileExists(const std::string &filePath)
    {
        return std::filesystem::exists(filePath);
    }

    std::string FileManager::readFile(const std::string &filePath)
    {
        if (fileExists(filePath))
            return "";

        std::ifstream file(filePath);
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }
}