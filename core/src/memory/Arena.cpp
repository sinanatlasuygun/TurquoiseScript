#include "../../include/memory/Arena.h"
#include <cstdlib>
#include <iostream>

namespace TQS
{
    Arena::Arena(size_t sizeInByte) : m_size(sizeInByte), m_offset(0)
    {
        m_buffer = static_cast<uint8_t *>(std::malloc(m_size));
        if (!m_buffer)
        {
            std::cerr << "❌ [ Error ]: Memory could not be allocated for the arena!" << std::endl;
        }
    }

    Arena::~Arena()
    {
        std::free(m_buffer);
    }

    void *Arena::alloc(size_t size)
    {
        size = (size + 7) & 7;

        if (m_offset + size > m_size)
        {
            std::cerr << "⚠️ [ Warning ]: The arena is full! Overflow to dynamic memory is possible." << std::endl;
            return nullptr;
        }
        void *ptr = m_buffer + m_offset;
        m_offset += size;
        return ptr;
    }

    void Arena::reset()
    {
        m_offset = 0;
    }
}