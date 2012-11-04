/*
 * async.h
 *
 *  Created on: 19.10.2012
 *      Author: caiiiycuk
 */

#ifndef ASYNC_H_
#define ASYNC_H_

#include "types.h"

extern void async_noop();
extern void async_false(bool *condition);
extern void async_true(bool *condition);

extern void	Async_InvokeInLoop(void (*open)(), void (*condition)(bool* ref), void (*loop)(), void (*close)());
extern bool	Async_IsPending();
extern void Async_Loop();

extern void	Async_InvokeAfterAsync(void (*callback)());
extern void	Async_InvokeAfterAsyncOrNow(void (*callback)());

extern void	Async_Storage_uint16(uint16* storage);
extern void	Async_StorageSet_uint16(uint16 value);


#endif /* ASYNC_H_ */
