#include <iostream>
#include "../core/include/context/ProjectContext.h"
#include "../core/include/lexer/SettingParser.h"
#include "../core/include/utils/FileManager.h"
#include "../core/include/utils/ErrorHandler.h"

using namespace TQS;

int testActOne()
{
    std::cout << "--- Turquaz Scripting Language | Act 1 Final Test ---" << std::endl;

    std::string mockSource =
        "ProjectSettings:\n"
        "    name: MyEpicAdventure;\n"
        "    dimension: 2D;\n"
        "    type: PixelArt;\n"
        "    memory_budget: 128;\n"
        "end\n"
        "\n"
        "Class Player:\n"
        "    # Oyun kodları buraya gelecek...\n"
        "end";

    SettingsParser sParser(mockSource);
    if (sParser.parse())
    {
        std::cout << "✅ Proje ayarlari basariyla yuklendi." << std::endl;
    }
    else
    {
        ErrorHandler::error(0, "ProjectSettings blogu bulunamadi veya hatali!");
        return -1;
    }

    auto &ctx = ProjectContext::getInstance();
    std::cout << "\n[PROJE BILGILERI]:" << std::endl;
    std::cout << "Isim: " << ctx.getData().project_name << std::endl;
    std::cout << "Boyut: " << (ctx.getData().dimension == Dimension::D2 ? "2D" : "3D") << std::endl;
    std::cout << "Bellek Butcesi: " << ctx.getData().memoryBudgetMB << " MB" << std::endl;

    void *someData = AllocateInArena(1024);
    if (someData)
    {
        std::cout << "✅ Arena bellek tahsisi basarili." << std::endl;
    }

    std::cout << "\n--- Act 1 Basariyla Tamamlandi. II. Bolume Haziriz! ---" << std::endl;

    return 0;
}