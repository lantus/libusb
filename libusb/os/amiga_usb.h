/*
 * Windows CE backend for libusb 1.0
 * Copyright © 2011-2013 RealVNC Ltd.
 * Portions taken from Windows backend, which is
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
#pragma once


typedef struct amiga_device_priv {
	uint8_t	cfgvalue;		/* active config value */
	uint8_t	*raw_cfgdescr;		/* active config descriptor */
	struct libusb_device_descriptor	dev_descr;	/* usb device descriptor */
	char	*ugenpath;		/* name of the ugen(4) node */
	char	*phypath;		/* physical path */
} amiga_device_priv;

typedef	struct endpoint {
	int datafd;	/* data file */
	int statfd;	/* state file */
} amiga_ep_priv_t;

typedef struct amiga_device_handle_priv {
	uint8_t			altsetting[USB_MAXINTERFACES];	/* a interface's alt */
	uint8_t			config_index;
	amiga_ep_priv_t		eps[USB_MAXENDPOINTS];
	amiga_device_priv	*dpriv; /* device private */
} amiga_dev_handle_priv_t;

typedef	struct amiga_transfer_priv {	 
	struct libusb_transfer	*transfer;
} amiga_transfer_priv;
