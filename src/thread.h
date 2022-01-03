#ifndef _RA_THREAD_H
#define _RA_THREAD_H

#ifdef _WIN32
#include <process.h>

#define RA_THREAD_WAIT_TIMEOUT WAIT_TIMEOUT

typedef uintptr_t ra_thread_t;
#else
#include <pthread.h>

typedef pthread_t ra_thread_t;
#endif

typedef void ra_thread_func(void *);

void ra_sleep(unsigned int seconds);

ra_thread_t ra_thread_start(ra_thread_func *routine, void *data, int *err);
void ra_thread_exit();
int ra_thread_join(ra_thread_t thread);
int ra_thread_join_timeout(ra_thread_t thread, time_t seconds);

#endif
