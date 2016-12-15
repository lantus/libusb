/*
 * Windows compat: POSIX compatibility wrapper
 * Copyright © 2012-2013 RealVNC Ltd.
 * Copyright © 2009-2010 Pete Batard <pete@akeo.ie>
 * With contributions from Michael Plante, Orin Eman et al.
 * Parts of poll implementation from libusb-win32, by Stephan Meyer et al.
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

#ifndef POLL_AMIGA_H
#define POLL_AMIGA_H

#define usbi_write write
#define usbi_read read
#define usbi_close close
#define usbi_poll poll

int usbi_pipe(int pipefd[2]);

 
#define MAX_FDS     256

#define POLLIN      0x0001    /* There is data to read */
#define POLLPRI     0x0002    /* There is urgent data to read */
#define POLLOUT     0x0004    /* Writing now will not block */
#define POLLERR     0x0008    /* Error condition */
#define POLLHUP     0x0010    /* Hung up */
#define POLLNVAL    0x0020    /* Invalid request: fd not open */

struct pollfd {
    int fd;           /* file descriptor */
    short events;     /* requested events */
    short revents;    /* returned events */
};

// access modes
enum rw_type {
	RW_NONE,
	RW_READ,
	RW_WRITE,
};

 

#endif
