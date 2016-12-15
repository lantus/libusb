/*
 * libusb synchronization on Microsoft Windows
 *
 * Copyright © 2010 Michael Plante <michael.plante@gmail.com>
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
 */

#include <config.h>
#include <errno.h>
 

#include "libusbi.h"

struct usbi_cond_perthread {
	struct list_head list;
	DWORD tid;
	APTR event;
};

int usbi_mutex_static_lock(usbi_mutex_static_t *mutex)
{
    ObtainSemaphore(mutex);
	return 0;
}

int usbi_mutex_static_unlock(usbi_mutex_static_t *mutex)
{
    ReleaseSemaphore(mutex);
	return 0;
}

int usbi_mutex_init(usbi_mutex_t *mutex)
{ 
    InitSemaphore(mutex);
	return 0;
}

int usbi_mutex_lock(usbi_mutex_t *mutex)
{
    ObtainSemaphore(mutex);
	return 0; // acquired (ToDo: check that abandoned is ok)
 
}

int usbi_mutex_unlock(usbi_mutex_t *mutex)
{
    ReleaseSemaphore(mutex);
	return 0;
 
}

int usbi_mutex_trylock(usbi_mutex_t *mutex)
{
     ObtainSemaphore(mutex);

     return 0;
}

int usbi_mutex_destroy(usbi_mutex_t *mutex)
{
    if (mutex)
    {
        free(mutex);
        mutex = NULL;
    };
    
	return 0;
}

int usbi_cond_init(usbi_cond_t *cond)
{
 
	return 0;
}

int usbi_cond_destroy(usbi_cond_t *cond)
{
 
	return 0;
}

int usbi_cond_broadcast(usbi_cond_t *cond)
{
	return 0;
}


int usbi_cond_wait(usbi_cond_t *cond, usbi_mutex_t *mutex)
{
	return 0;
}

int usbi_cond_timedwait(usbi_cond_t *cond,
	usbi_mutex_t *mutex, const struct timeval *tv)
{
 
	return 0;
}

int usbi_tls_key_create(usbi_tls_key_t *key)
{
 
    return 0;
}

void *usbi_tls_key_get(usbi_tls_key_t key)
{
	return 0;
}

int usbi_tls_key_set(usbi_tls_key_t key, void *value)
{
    return 0;    
}

int usbi_tls_key_delete(usbi_tls_key_t key)
{
    return 0;
}

int usbi_get_tid(void)
{
	return 0;
}
