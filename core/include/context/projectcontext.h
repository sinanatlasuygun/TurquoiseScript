
#ifndef PROJECT_CONTEXT_H
#define PROJECT_CONTEXT_H

#include "ProjectSetting.h"

namespace TQS
{
    class ProjectContext
    {
    public:
        static ProjectContext &getInstance();
        void configure(const ProjectSetting &settings);
        bool is3DSupported() const;
        const ProjectSetting &getData() const { return m_settings; }

    private:
        ProjectContext() = default;
        ProjectSetting m_settings;
        void runAssistantCheck();
    };
}
#endif