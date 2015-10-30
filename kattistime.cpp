/*
 * Time module for cprog06lab2*. Written 2006-09-27 by Gunnar Kreitz <gkreitz>
 *
 * Since we need reproducable results when testing on Kattis, it's not a good
 * idea to read the actual system clock and use that as a default day. Thus
 * we provide our own time(2)-replacement.
 *
 * If you need to modify this file to solve the assignment, you're more likely
 * solving it the wrong way.
 */

#include "kattistime.h"
#include <cassert>

/* Anonymous namespace */
namespace {
	time_t curtime;
	bool initialized = false; // Has set_k_time been called?
}

time_t k_time(time_t *tloc) {
	assert(initialized);
	if(tloc)
		*tloc = curtime;
	return curtime;
}

void set_k_time(time_t t) {
	initialized = true;
	curtime = t;
}
