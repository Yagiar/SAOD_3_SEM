#include <vector>
class RLE
{
public:
	RLE() {};
	unsigned int RLEDeflate(const unsigned char* src, unsigned len, unsigned char* dst);
	unsigned int RLEInflate(const unsigned char* src, unsigned len, unsigned char* dst);
	unsigned int Size(const unsigned* src, int len);
};

