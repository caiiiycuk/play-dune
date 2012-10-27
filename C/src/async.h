/*
 * async.h
 *
 *  Created on: 19.10.2012
 *      Author: caiiiycuk
 */

#ifndef ASYNC_H_
#define ASYNC_H_

#include "types.h"

extern void	Async_InvokeInLoop(void (*open)(), bool (*condition)(), void (*loop)(), void (*close)());
extern void	Async_InvokeAfterNextLoop(void (*callback)());
extern bool		Async_IsPending();
extern void 	Async_Loop();


#endif /* ASYNC_H_ */
