/* $Id: crashlog_none.c 2435 2011-08-29 22:15:09Z truebrain $ */

#include "types.h"

#include "crashlog.h"

void CrashLog_Init()
{
}

void CrashLog_LogError(char *buffer)
{
	VARIABLE_NOT_USED(buffer);
}

void CrashLog_LogRegisters(char *buffer)
{
	VARIABLE_NOT_USED(buffer);
}

void CrashLog_LogStacktrace(char *buffer)
{
	VARIABLE_NOT_USED(buffer);
}

void CrashLog_LogOSVersion(char *buffer)
{
	VARIABLE_NOT_USED(buffer);
}
