#include "async.h"
#include "stdlib.h"

typedef struct ScheduledAsync {
	void	(*	open)();
	bool	(*	condition)();
	void	(*	loop)();
	void	(*	close)();
	bool	firstRun;
	void	(*	after)();
} ScheduledAsync;

#define 		MAX_SCHEDULED_COUNT 5
ScheduledAsync 	scheduled[MAX_SCHEDULED_COUNT];
int 			scheduledCount = 0;
void			(*scheduledAfter)() = 0;

void pushAsync(void (*open)(), bool (*condition)(), void (*loop)(), void (*close)()) {
	int index = scheduledCount;
	++scheduledCount;

	if (scheduledCount > MAX_SCHEDULED_COUNT) {
		abort();
	}

	scheduled[index].open = open;
	scheduled[index].condition = condition;
	scheduled[index].loop = loop;
	scheduled[index].close = close;
	scheduled[index].firstRun = true;
	scheduled[index].after = scheduledAfter;

	scheduledAfter = 0;
}

ScheduledAsync* touchAsync() {
	if (scheduledCount == 0) {
		abort();
	}

	return &scheduled[0];
}

void popAsync() {
	int first;
	int second;

	for (second = 1; second<scheduledCount; ++second) {
		first = second - 1;

		scheduled[first].open 		= scheduled[second].open;
		scheduled[first].condition 	= scheduled[second].condition;
		scheduled[first].loop 		= scheduled[second].loop;
		scheduled[first].close 		= scheduled[second].close;
		scheduled[first].firstRun 	= scheduled[second].firstRun;
		scheduled[first].after 		= scheduled[second].after;
	}

	--scheduledCount;
}

void Async_InvokeInLoop(void (*open)(), bool (*condition)(), void (*loop)(), void (*close)()) {
	pushAsync(open, condition, loop, close);
}

void Async_InvokeAfterNextLoop(void (*callback)()) {
	if (scheduledAfter) {
		abort();
	}

	scheduledAfter = callback;
}

bool Async_IsPending() {
	return scheduledCount > 0;
}

void Async_Loop() {
	ScheduledAsync* async = touchAsync();

	if (async->firstRun) {
		async->open();
		async->firstRun = false;
	}

	if (async->condition()) {
		async->loop();
	} else {
		async->close();

		if (async->after) {
			async->after();
		}

		popAsync();
	}
}

