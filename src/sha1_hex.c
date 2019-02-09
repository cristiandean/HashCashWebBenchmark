#include <stddef.h>
#include "sha1.h"
#include "sha1_hex.h"
#include "to_hex.h"
#include <emscripten.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


SHA1_CTX g_shactx;
char g_shabuf[SHA1_HEX_LENGTH + 1] = { 0 };

void EMSCRIPTEN_KEEPALIVE sha1_init()
{
    SHA1Init(&g_shactx);
}

void EMSCRIPTEN_KEEPALIVE sha1_update(const char *data)
{
    size_t len = strlen(data);
    SHA1Update(&g_shactx, (const unsigned char *)data, len);
}

char* EMSCRIPTEN_KEEPALIVE sha1_final()
{
    unsigned char sha1[SHA1_LENGTH];
    SHA1Final(sha1, &g_shactx);
    
    to_hex(sha1, SHA1_LENGTH, g_shabuf);
    return g_shabuf;
}

bool hasZerosPrefix(const int zeros, const char *str)
{
    int i;
    char *zerosString = malloc(sizeof(char) * zeros);
    strcpy(zerosString, "");
    for(i=0; i<zeros; i++){
        strcat(zerosString, "0");
    }
    return strncmp(zerosString, str, zeros) == 0;
}

int EMSCRIPTEN_KEEPALIVE hashCashSolve(const int requiredZeros, const char *hashCash)
{
    int i = 0;
    char *bufferHashCash = malloc(sizeof(char) * 64);
    while(true){
        sha1_init();
        sprintf(bufferHashCash, "%s%d", hashCash, i);
        sha1_update(bufferHashCash);
        if(hasZerosPrefix(requiredZeros, sha1_final())){
            return i;
        }
        ++i;
    }
    return -1;
}