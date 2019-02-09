#ifndef __SHA1_HEX_H__
#define __SHA1_HEX_H__

#define SHA1_LENGTH     20
#define SHA1_HEX_LENGTH 40

void sha1_init();
void sha1_update(const char *data);
char* sha1_final();
int hashCashSolve(const int requiredZeros, const char *hashCash);

#endif
