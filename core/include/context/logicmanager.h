
#ifndef LOGIC_MANAGER_H
#define LOGIC_MANAGER_H

#include "datacontainer.h"

namespace Context
{
    class LogicManager
    {
    public:
        static LogicManager &getInstance();
        void configure(const DataContainer &data);
        bool is3DSupported() const;
        const DataContainer &getData() const { return m_settings; }

    private:
        LogicManager() = default;
        DataContainer m_settings;
        void runAssistantCheck();
    };
}
#endif