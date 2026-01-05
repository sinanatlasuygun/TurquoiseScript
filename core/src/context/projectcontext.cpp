
#include "../../include/context/ProjectContext.h"
#include <iostream>

namespace TQS
{
    ProjectContext &ProjectContext::getInstance()
    {
        static ProjectContext instance;
        return instance;
    }
    void ProjectContext::configure(const ProjectSetting &settings)
    {
        m_settings = settings;
        std::cout << "The project is being structured:" << m_settings.project_name << std::endl;
        runAssistantCheck();
    }

    bool ProjectContext::is3DSupported() const
    {
        return m_settings.dimension == Dimension::D3 || m_settings.dimension == Dimension::D2_5;
    }

    void ProjectContext::runAssistantCheck()
    {
        if (m_settings.dimension == Dimension::D2 && m_settings.dimension_type == DimensionType::REALISTIC)
        {
            std::cout << "  > [ASSISTANT WARNING]: You have selected the “REALISTIC” style in a 2D project. "
                      << "This mode is generally optimised for 3D projects. "
                      << "If you encounter a visual error, you can try the “STYLIZED” mode." << std::endl;
        }

        if (m_settings.memoryMode == MemoryStrategy::ARENA && m_settings.memoryBudgetMB < 64)
        {
            std::cout << "  > [ASSISTANT WARNING]: Less than 64MB may be risky for Arena memory mode. "
                      << "If the pool is insufficient, your game may crash." << std::endl;
        }
    }
}