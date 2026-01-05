
#ifndef ARENA_H
#define ARENA_H

#include <cstddef>
#include <vector>
#include <cstdint>

namespace TQS
{
    class Arena
    {
    public:
        Arena(size_t sizeInByte);
        ~Arena();

        void *alloc(size_t size);

        void reset();

    private:
        uint8_t *m_buffer;
        size_t m_size;
        size_t m_offset;
    };
}
#endif