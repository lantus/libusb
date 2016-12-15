/*
 * poll_posix: poll compatibility wrapper for POSIX systems
 * Copyright © 2013 RealVNC Ltd.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#include <config.h>

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

#include "libusbi.h"



struct Library *TimerBase;

int usbi_pipe(int pipefd[2])
{	
	return 0; 
}

struct timezone __time_zone;
long __local_to_GMT;


int usbi_poll(struct pollfd *fds, unsigned int nfds, int timeout)
{
    return 0;
}


int gettimeofday(struct timeval *tp, struct timezone *tzp)
{
  if (tp) {
    GetSysTime(tp);
    tp->tv_sec += __local_to_GMT;
  }
  if (tzp) {
    /*
     * __time_zone is set up in the timerinit.c
     */
    *tzp = __time_zone;
  }

  return 0;
}
