
#ifndef PPOJECT_SETTING_H
#define PPOJECT_SETTING_H

#include <string>
#include <vector>

namespace Context
{
    enum class Dimension
    {
        D2,
        D2_5,
        D3,
        NONE
    };
    enum class DimensionType
    {
        PIXEL_ART,
        STYLIZED,
        REALISTIC,
        VOXEL,
        DEFAULT
    };
    enum class MemoryStrategy
    {
        ARENA,
        DYNAMIC,
        NONE
    };

    struct ProjectSetting
    {
        std::string project_name = "NewTurquazProject";
        Dimension dimension = Dimension::NONE;
        DimensionType dimension_type = DimensionType::DEFAULT;
        MemoryStrategy memoryMode = MemoryStrategy::ARENA;
        size_t memoryBudgetMB = 256;
    };

}
#endif