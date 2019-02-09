#ifndef __MD5_HEX_H__
#define __MD5_HEX_H__

#define MD5_LENGTH     16
#define MD5_HEX_LENGTH 32

char* md5_hex(const char *data);
void md5_init();
void md5_update(const char *data);
char* md5_final();

#endif
