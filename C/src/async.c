#include "async.h"
#include "stdlib.h"

#define ScheduledAsync_OPEN 		1
#define ScheduledAsync_CONDITION 	2
#define ScheduledAsync_LOOP 		4
#define ScheduledAsync_CLOSE 		8

typedef struct ScheduledAsync {
	void	(*	open)();
	void	(*	condition)(bool *ref);
	void	(*	loop)();
	void	(*	close)();

	void	(*	closeHandler)();
	void	(*	closeHandler2)();

	bool	conditionValue;
	int		state;

	struct ScheduledAsync *next;
} ScheduledAsync;

ScheduledAsync *STACK_TOP = 0;

void pushStack(void (*open)(), void (*condition)(bool *ref), void (*loop)(), void (*close)()) {
	ScheduledAsync *async;
	async = malloc(sizeof(ScheduledAsync));

	async->open = open;
	async->condition = condition;
	async->loop = loop;
	async->close = close;

	async->closeHandler = 0;
	async->closeHandler2 = 0;

	async->state = ScheduledAsync_OPEN;
	async->conditionValue = false;
	async->next = STACK_TOP;

	STACK_TOP = async;
}

void popStack() {
	ScheduledAsync *async;

	if (!STACK_TOP) {
		return;
	}

	async = STACK_TOP;
	STACK_TOP = async->next;
}

void Async_InvokeInLoop(void (*open)(), void (*condition)(bool *ref), void (*loop)(), void (*close)()) {
	pushStack(open, condition, loop, close);
}

void Async_InvokeAfterAsync(void (*callback)()) {
	if (!STACK_TOP) {
		abort();
	}

	if (!STACK_TOP->closeHandler) {
		STACK_TOP->closeHandler = callback;
	} else if (!STACK_TOP->closeHandler2) {
		STACK_TOP->closeHandler2 = callback;
	} else {
		abort();
	}
}

void Async_InvokeAfterAsyncOrNow(void (*callback)()) {
	if (!STACK_TOP) {
		callback();
	} else {
		Async_InvokeAfterAsync(callback);
	}
}

bool Async_IsPending() {
	return STACK_TOP != 0;
}

void Async_Loop() {
	ScheduledAsync *top = STACK_TOP;

	switch (top->state) {
		case ScheduledAsync_OPEN: {
			top->open();
			top->state = ScheduledAsync_CONDITION;

			return;
		}

		case ScheduledAsync_CONDITION: {
			top->condition(&top->conditionValue);
			top->state = ScheduledAsync_LOOP;

			return;
		}

		case ScheduledAsync_LOOP: {
			if (top->conditionValue) {
				top->loop();
				top->state = ScheduledAsync_CONDITION;
			} else {
				top->state = ScheduledAsync_CLOSE;
			}

			return;
		}

		case ScheduledAsync_CLOSE: {
			popStack();
			top->close();

			if (top->closeHandler) {
				top->closeHandler();
			}

			if (top->closeHandler2) {
				top->closeHandler2();
			}


			free(top);
			return;
		}

		default:
			abort();
	}
}

void async_noop() {
}

void async_false(bool *condition) {
	*condition = false;
}

void async_true(bool *condition) {
	*condition = true;
}


/* STORAGE */

typedef struct StackStorage {
	uint16* s_uint16;
	struct StackStorage *next;
} StackStorage;

StackStorage *STACK_STORAGE = 0;


uint16 *__uint16Storage = 0;

void Async_Storage_uint16(uint16* s_uint16) {
	StackStorage *storage = malloc(sizeof(StackStorage));

	storage->s_uint16 = s_uint16;
	storage->next = STACK_STORAGE;

	STACK_STORAGE = storage;
}

void Async_StorageSet_uint16(uint16 value) {
	if (STACK_STORAGE) {
		*STACK_STORAGE->s_uint16 = value;
		STACK_STORAGE = STACK_STORAGE->next;
	}
}



