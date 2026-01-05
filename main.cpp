#include <iostream>

int testActOne();

int main()
{
    try
    {
        // Testi başlat
        return testActOne();
    }
    catch (const std::exception &e)
    {
        std::cerr << "❌ An unexpected error has occurred: " << e.what() << std::endl;
        return -1;
    }
}