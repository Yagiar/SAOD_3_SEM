#pragma once

#ifdef COBS_EXPORTS
#define COBS_API __declspec(dllexport)
#else
#define COBS_API __declspec(dllimport)
#endif

extern "C" COBS_API unsigned COBSEncode(const unsigned char *src, unsigned len, unsigned char *dst);
extern "C" COBS_API unsigned COBSDecode(const unsigned char *src, unsigned len, unsigned char *dst);