#include <stddef.h>
#include "to_hex.h"

void to_hex(const unsigned char *bytes,size_t len,char *buf)
{
    const char *hex_chars = "0123456789abcdef";

    int i;
    for (i = 0; i < len; ++i) {
        buf[i << 1]       = hex_chars[(bytes[i] >> 4) & 0x0f];
        buf[(i << 1) + 1] = hex_chars[bytes[i] & 0x0f];
    }
}