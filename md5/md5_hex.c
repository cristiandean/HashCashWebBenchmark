#include <stddef.h>
#include "md5.h"
#include "md5_hex.h"
#include "to_hex.h"
#include <emscripten.h>
#include <string.h>
#include <stdio.h>

MD5_CTX g_ctx;
char g_buf[MD5_HEX_LENGTH + 1] = { 0 };

char* EMSCRIPTEN_KEEPALIVE md5_hex(const char *data)
{
    unsigned char md5[MD5_LENGTH];
    MD5_CTX ctx;


    MD5_Init(&ctx);
    size_t len = strlen(data);
    MD5_Update(&ctx, data, len);
    MD5_Final(md5, &ctx);

    to_hex(md5, MD5_LENGTH, g_buf);
    
    printf("md5(\"%s\") = \"%s\"\n", data, g_buf);
    return g_buf;
}

void EMSCRIPTEN_KEEPALIVE md5_init()
{
    MD5_Init(&g_ctx);
}

void EMSCRIPTEN_KEEPALIVE md5_update(const char *data)
{
    size_t len = strlen(data);
    MD5_Update(&g_ctx, data, len);
}

char* EMSCRIPTEN_KEEPALIVE md5_final()
{
    unsigned char md5[MD5_LENGTH];
    MD5_Final(md5, &g_ctx);
    
    to_hex(md5, MD5_LENGTH, g_buf);
    return g_buf;
}