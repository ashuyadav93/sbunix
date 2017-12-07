#ifndef _SYS_CALL_H_
#define _SYS_CALL_H_

#include "sys/defs.h"

#define __NR_read 0
#define __NR_write 1
#define __NR_open 2
#define __NR_close 3
#define __NR_yield 24
#define __NR_fork 57
#define __NR_execve 59
#define __NR_exit 60
#define __NR_wait4 61
#define __NR_getdents 78
#define __NR_getcwd 79
#define __NR_chdir 80
#define __NR_pipe 22
#define __NR_dup2 33

void initSyscalls();

void userWrite(uint64_t fileDescriptor, char* data, uint64_t len);
void writeSyscall(uint64_t sysNum, uint64_t fd, uint64_t data, uint64_t len);
pid_t forkSyscall(uint64_t sysNum);
void systemCallHandler();
void sysHandler();
void systemWrite(uint64_t fd, uint64_t data, uint64_t len);
void systemRead(uint64_t fileDescriptor, uint64_t data, uint64_t len);
pid_t systemFork();
pid_t userFork();
void systemExit(uint64_t status);
void systemYield();

#endif
