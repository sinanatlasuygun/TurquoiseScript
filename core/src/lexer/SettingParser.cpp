#include "../../include/lexer/SettingParser.h"
#include "../../include/utils/ErrorHandler.h"

namespace TQS
{
    SettingsParser::SettingsParser(const std::string &source) : m_source(source) {}

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
        while (m_cursor < m_source.length() && std::isalnum(m_source[m_cursor]))
        {
            word += m_source[m_cursor];
        }
        return word;
    }

    bool SettingsParser::parse()
    {
        skipWhitespace();
        if (getNextWord() != "ProjectSettings")
            return false;
        if (m_source[m_cursor++] != ':')
            return false;

        ProjectSetting settings;

        while (m_cursor < m_source.length())
        {
            std::string key = getNextWord();
            if (key == "end")
                break;
            if (m_source[m_cursor++] != ':')
                break;

            skipWhitespace();

            if (key == "dimension")
            {
                std::string val = getNextWord();

                if (val == "2D")
                    settings.dimension = Dimension::D2;
                else if (val == "2.5D")
                    settings.dimension = Dimension::D2_5;
                else if (val == "3D")
                    settings.dimension = Dimension::D3;
                else
                    settings.dimension = Dimension::NONE;
            }
            else if (key == "type")
            {
                std::string val = getNextWord();

                if (val == "PixelArt")
                    settings.dimension_type = DimensionType::PIXEL_ART;
                else if (val == "Realistic")
                    settings.dimension_type = DimensionType::REALISTIC;
                else if (val == "Stylized")
                    settings.dimension_type = DimensionType::STYLIZED;
                else if (val == "Voxel")
                    settings.dimension_type = DimensionType::VOXEL;
                else
                    settings.dimension_type = DimensionType::DEFAULT;
            }
            else if (key == "memorybudget")
            {
                std::string val = getNextWord();
                settings.memoryBudgetMB = std::stoi(val);
            }

            if (m_source[m_cursor] == ';')
                m_cursor++;
        }
        ProjectContext::getInstance().configure(settings);
        return true;
    }
}