#include <unistd.h>

unsigned char reverse_bits2(unsigned char b)
{
	b = (b & 0xF0) >> 4 | (b & 0x0F) << 4; // 1)
	b = (b & 0xCC) >> 2 | (b & 0x33) << 2; // 2)
	b = (b & 0xAA) >> 1 | (b & 0x55) << 1; // 3)
	return (b);
}