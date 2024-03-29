#ifndef LIBASM_H
#define LIBASM_H

#include <stdio.h>
#include <stdlib.h>

size_t asm_putc(int c);
size_t asm_strlen(const char *str);
size_t asm_puts(const char *str);
void *asm_memcpy(void *dest, const void *src, int n);
int asm_strcmp(const char *s1, const char *s2);
int asm_strncmp(const char *s1, const char *s2, size_t n);
char *asm_strchr(const char *s, int c);
char *asm_strstr(const char *haystack, const char *needle);
size_t asm_strspn(const char *s, const char *accept);
char *asm_strpbrk(const char *s, const char *accept);
size_t asm_puti(int n);
int asm_strcasecmp(const char *s1, const char *s2);
size_t asm_strcspn(const char *s, const char *reject);
#endif /* LIBASM_H */
