/* $Id: sleep.h 2425 2011-08-29 19:36:46Z truebrain $ */

/** @file src/os/sleep.h OS-independent inclusion of the delay routine. */

#ifndef OS_SLEEP_H
#define OS_SLEEP_H

#if defined(_WIN32)
	#include <windows.h>
	#define sleep(x) Sleep(x * 1000)
	#define msleep(x) Sleep(x)
#else
	#if !defined(__USE_BSD)
		#define __USE_BSD
		#include <unistd.h>
		#undef __USE_BSD
	#else
		#include <unistd.h>
	#endif /* __USE_BSD */

	#define msleep(x) usleep(x * 1000)
#endif /* _WIN32 */

extern void idle();

#define sleepIdle() idle()

#endif /* OS_SLEEP_H */
