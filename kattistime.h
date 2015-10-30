#ifndef H_KATTISTIME_H
#define H_KATTISTIME_H
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

extern "C" {
#include <sys/types.h>
}

/*
 * This function has the same semantics as time(2) on Solaris 10,
 * except that it cannot fail.
 *
 * The following text is an excerpt of the relevant man-page:
 *
 *  DESCRIPTION
 *   The time() function returns the value  of  time  in  seconds
 *   since 00:00:00 UTC, January 1, 1970.
 *
 *   If tloc is non-zero, the return value is also stored in  the
 *   location  to which tloc points. If tloc points to an illegal
 *   address, time() fails and its actions are undefined.
 *
 *  RETURN VALUES
 *   Upon successful completion,  time()  returns  the  value  of
 *   time.  Otherwise, (time_t)-1 is returned and errno is set to
 *   indicate the error.
 *
 *
 */
time_t k_time(time_t *tloc);

/*
 * This function should only be called by the driver code
 */
void set_k_time(time_t t);

#endif /* H_KATTISTIME_H */
