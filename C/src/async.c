#include "async.h"
#include "stdlib.h"

typedef struct ScheduledAsync {
	void	(*	open)();
	bool	(*	condition)();
	void	(*	loop)();
	void	(*	close)();
	bool	firstRun;
} ScheduledAsync;

#define 		MAX_SCHEDULED_COUNT 5
ScheduledAsync 	scheduled[MAX_SCHEDULED_COUNT];
int 			scheduledCount = 0;

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
	}

	--scheduledCount;
}

void AsyncInvokeWhile(void (*open)(), bool (*condition)(), void (*loop)(), void (*close)()) {
	pushAsync(open, condition, loop, close);
}

bool isAsyncPending() {
	return scheduledCount > 0;
}

void AsyncLoop() {
	ScheduledAsync* async = touchAsync();

	if (async->firstRun) {
		async->open();
		async->firstRun = false;
	}

	if (async->condition()) {
		async->loop();
	} else {
		async->close();
		popAsync();
	}
}

