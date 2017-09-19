#ifndef __KPRINTF_H
#define __KPRINTF_H

#include <stdarg.h>
#include <sys/defs.h>
void kprintf(const char *fmt, ...);
void parsefmt(char *kstring, const char *fmt, va_list val);
void convert(uint64_t a, char* ch, int base);
void memshift();
void printtimer(uint64_t a);
void printkeyboard(char *s);
#endif
