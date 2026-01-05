#include "../../include/lexer/SettingParser.h"
#include "../../include/utils/ErrorHandler.h"
#include "../../include/context/ProjectContext.h"
#include <iostream>

namespace TQS
{
    SettingsParser::SettingsParser(const std::string &source) : m_source(source), m_cursor(0) {}

    void SettingsParser::skipWhitespace()
    {
        while (m_cursor < m_source.length() && std::isspace(m_source[m_cursor]))
        {
            m_cursor++;
        }
    }

    std::string SettingsParser::getNextWord()
    {
        skipWhitespace();
        std::string word = "";

        while (m_cursor < m_source.length() && (std::isalnum(m_source[m_cursor]) || m_source[m_cursor] == '_'))
        {
            word += m_source[m_cursor++];
        }
        return word;
    }

    bool SettingsParser::parse()
    {
        std::cout << "[Debug] Parsing basladi..." << std::endl;

        std::string header = getNextWord();
        std::cout << "[Debug] Baslik: " << header << std::endl;

        if (header != "ProjectSettings")
            return false;

        skipWhitespace();
        if (m_cursor < m_source.length() && m_source[m_cursor] == ':')
        {
            m_cursor++;
            std::cout << "[Debug] ':' atlandi." << std::endl;
        }

        ProjectSetting settings;

        // 3. Blok içindeki anahtarları oku
        while (m_cursor < m_source.length())
        {
            skipWhitespace();
            std::string key = getNextWord();

            if (key == "end")
            {
                std::cout << "[Debug] 'end' bulundu." << std::endl;
                break;
            }

            if (key.empty())
            {
                m_cursor++;
                continue;
            }

            skipWhitespace();
            if (m_cursor < m_source.length() && m_source[m_cursor] == ':')
                m_cursor++;

            std::string value = getNextWord();
            std::cout << "[Debug] Anahtar: " << key << " | Deger: " << value << std::endl;

            if (key == "name")
            {
                settings.project_name = value;
            }
            else if (key == "dimension")
            {
                if (value == "2D")
                    settings.dimension = Dimension::D2;
                else if (value == "3D")
                    settings.dimension = Dimension::D3;
            }
            else if (key == "type")
            {
                if (value == "PixelArt")
                    settings.dimension_type = DimensionType::PIXEL_ART;
                else if (value == "Realistic")
                    settings.dimension_type = DimensionType::REALISTIC;
            }
            else if (key == "memory_budget")
            {
                settings.memoryBudgetMB = std::stoi(value);
            }

            // ';' karakterini atla
            skipWhitespace();
            if (m_cursor < m_source.length() && m_source[m_cursor] == ';')
                m_cursor++;
        }

        ProjectContext::getInstance().configure(settings);
        return true;
    }
}