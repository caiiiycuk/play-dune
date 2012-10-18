/* $Id: common.h 2078 2011-07-29 17:23:07Z truebrain $ */

/** @file src/os/common.h Compiler-independent common statements. */

#ifndef OS_COMMON_H
#define OS_COMMON_H

/**
 * Compute length of an array.
 * @param address of the array.
 * @return Number of elements of the array.
 */
#define lengthof(array) (sizeof(array) / sizeof((array)[0]))

#endif /* OS_COMMON_H */
