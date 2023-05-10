#include "stdafx.h"
#include "RLE.h"

unsigned int RLE::RLEDeflate(const unsigned char* src, unsigned len, unsigned char* dst) {
    unsigned int dstIndex = 0;
    for (unsigned int i = 0; i < len; i++) {
        int runLength = 1;
        while (i + 1 < len && src[i] == src[i + 1] && runLength < 255) {
            i++;
            runLength++;
        }
        dst[dstIndex++] = src[i];
        dst[dstIndex++] = runLength;
    }
    return dstIndex;
}
unsigned int RLE::RLEInflate(const unsigned char* src, unsigned len, unsigned char* dst) {
    unsigned int dstIndex = 0;
    for (unsigned int i = 0; i < len; i += 2) {
        for (int j = 0; j < src[i + 1]; j++) {
            dst[dstIndex++] = src[i];
        }
    }
    return dstIndex;
}

unsigned int RLE::Size(const unsigned* src, int len) {
    unsigned int size = 0;
    for (int i = 0; i < len; i += 2) {
        size += src[i + 1];
    }
    return size;
}