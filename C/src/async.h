/*
 * async.h
 *
 *  Created on: 19.10.2012
 *      Author: caiiiycuk
 */

#ifndef ASYNC_H_
#define ASYNC_H_

#if EMSCRIPTEN

extern void Async_InvokeWhile(void (*open)(), bool (*condition)(), void (*loop)(), void (*close)());

#else

void Async_InvokeWhile(void (*open)(), bool (*condition)(), void (*loop)(), void (*close)()) {
	open();

	while (condition()) {
		loop();
	}

	close();
}

#endif

#endif /* ASYNC_H_ */
