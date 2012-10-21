/*
 * async.h
 *
 *  Created on: 19.10.2012
 *      Author: caiiiycuk
 */

#ifndef ASYNC_H_
#define ASYNC_H_

#include "types.h"

extern void AsyncInvokeWhile(void (*open)(), bool (*condition)(), void (*loop)(), void (*close)());
extern bool isAsyncPending();
extern void AsyncLoop();

#endif /* ASYNC_H_ */
