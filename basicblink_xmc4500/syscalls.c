#include <sys/stat.h>
#include <stddef.h>

extern unsigned long _ebss;

char *__brkval = (char *)&_ebss;

void * _sbrk(int incr)
{
	char *prev = __brkval;
	__brkval += incr;
	return prev;
}

int _read(int file, char *ptr, int len)
{
	return 0;
}

int _write(int file, char *ptr, int len)
{
	return 0;
}

int _close(int fd)
{
	return -1;
}

int _lseek(int fd, long long offset, int whence)
{
	return -1;
}

void _exit(int status)
{
	while (1);
}

void __cxa_pure_virtual()
{
	while (1);
}

int __cxa_guard_acquire (int *g) 
{
	return 1;
}

void __cxa_guard_release(int *g)
{
}

void _init() __attribute__((weak));
void _init()
{
}  

void _kill()
{
	while (1);
}

void _getpid()
{
	while (1);
}
