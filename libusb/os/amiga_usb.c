/*
 * Windows CE backend for libusb 1.0
 * Copyright © 2011-2013 RealVNC Ltd.
 * Large portions taken from Windows backend, which is
 * Copyright © 2009-2010 Pete Batard <pbatard@gmail.com>
 * With contributions from Michael Plante, Orin Eman et al.
 * Parts of this code adapted from libusb-win32-v1 by Stephan Meyer
 * Major code testing contribution by Xiaofan Chen
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

#include <stdint.h>
#include <proto/poseidon.h> 
#include "libusbi.h"
#include "amiga_usb.h"

// Global variables
 
// Internal API functions
static int amiga_init(struct libusb_context *ctx)
{
 
	return 0;
}

static void amiga_exit(void)
{
 
}

static int amiga_get_device_list(
	struct libusb_context *ctx,
	struct discovered_devs **discdevs)
{
 
 
	return 0;
}

static int amiga_open(struct libusb_device_handle *handle)
{
	// Nothing to do to open devices as a handle to it has
	// been retrieved by amiga_get_device_list
	return LIBUSB_SUCCESS;
}

static void amiga_close(struct libusb_device_handle *handle)
{
	// Nothing to do as amiga_open does nothing.
}

static int amiga_get_device_descriptor(
	struct libusb_device *device,
	unsigned char *buffer, int *host_endian)
{
 
	return LIBUSB_SUCCESS;
}

static int amiga_get_active_config_descriptor(
	struct libusb_device *device,
	unsigned char *buffer, size_t len, int *host_endian)
{
 

	return 0;
}

static int amiga_get_config_descriptor(
	struct libusb_device *device,
	uint8_t config_index,
	unsigned char *buffer, size_t len, int *host_endian)
{
 

	return 0;
}

static int amiga_get_configuration(
	struct libusb_device_handle *handle,
	int *config)
{
 
	return LIBUSB_SUCCESS;
}

static int amiga_set_configuration(
	struct libusb_device_handle *handle,
	int config)
{
 

	return LIBUSB_SUCCESS;
}

static int amiga_claim_interface(
	struct libusb_device_handle *handle,
	int interface_number)
{
 

	return LIBUSB_SUCCESS;
}

static int amiga_release_interface(
	struct libusb_device_handle *handle,
	int interface_number)
{
 

	return LIBUSB_SUCCESS;
}

static int amiga_set_interface_altsetting(
	struct libusb_device_handle *handle,
	int interface_number, int altsetting)
{
 

	return LIBUSB_SUCCESS;
}

static int amiga_clear_halt(
	struct libusb_device_handle *handle,
	unsigned char endpoint)
{
 

	return LIBUSB_SUCCESS;
}

static int amiga_reset_device(
	struct libusb_device_handle *handle)
{
 

	return LIBUSB_SUCCESS;
}

static int amiga_kernel_driver_active(
	struct libusb_device_handle *handle,
	int interface_number)
{
 
	return 0;
}

static int amiga_detach_kernel_driver(
	struct libusb_device_handle *handle,
	int interface_number)
{
 
	return LIBUSB_SUCCESS;
}

static int amiga_attach_kernel_driver(
	struct libusb_device_handle *handle,
	int interface_number)
{
 
	return LIBUSB_SUCCESS;
}

static void amiga_destroy_device(struct libusb_device *dev)
{
 
}

static void amiga_clear_transfer_priv(struct usbi_transfer *itransfer)
{
 
}

static int amiga_cancel_transfer(struct usbi_transfer *itransfer)
{
 

	return LIBUSB_SUCCESS;
}

static int amiga_submit_control_or_bulk_transfer(struct usbi_transfer *itransfer)
{
 

	return LIBUSB_SUCCESS;
}

static int amiga_submit_iso_transfer(struct usbi_transfer *itransfer)
{
	return LIBUSB_ERROR_NOT_SUPPORTED;
}

static int amiga_submit_transfer(struct usbi_transfer *itransfer)
{
 
}

static void amiga_transfer_callback(
	struct usbi_transfer *itransfer,
	uint32_t io_result, uint32_t io_size)
{
 
}

static void amiga_handle_callback(
	struct usbi_transfer *itransfer,
	uint32_t io_result, uint32_t io_size)
{
 
}

static int amiga_handle_events(
	struct libusb_context *ctx,
	struct pollfd *fds, POLL_NFDS_TYPE nfds, int num_ready)
{
 

	return 0;
}

/*
 * Monotonic and real time functions
 */
static int amiga_clock_gettime(int clk_id, struct timespec *tp)
{
 
    return LIBUSB_SUCCESS;
 
}

const struct usbi_os_backend amiga_backend = {
	"Commodore Amiga",
	0,
	amiga_init,
	amiga_exit,

	amiga_get_device_list,
	NULL,				/* hotplug_poll */
	amiga_open,
	amiga_close,

	amiga_get_device_descriptor,
	amiga_get_active_config_descriptor,
	amiga_get_config_descriptor,
	NULL,				/* get_config_descriptor_by_value() */

	amiga_get_configuration,
	amiga_set_configuration,
	amiga_claim_interface,
	amiga_release_interface,

	amiga_set_interface_altsetting,
	amiga_clear_halt,
	amiga_reset_device,

	NULL,				/* alloc_streams */
	NULL,				/* free_streams */

	NULL,				/* dev_mem_alloc() */
	NULL,				/* dev_mem_free() */

	amiga_kernel_driver_active,
	amiga_detach_kernel_driver,
	amiga_attach_kernel_driver,

	amiga_destroy_device,

	amiga_submit_transfer,
	amiga_cancel_transfer,
	amiga_clear_transfer_priv,

	amiga_handle_events,
	NULL,				/* handle_transfer_completion() */

	amiga_clock_gettime,
	sizeof(struct amiga_device_priv),
	0,
	sizeof(struct amiga_transfer_priv),
};
