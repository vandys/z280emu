/*
 * sconsole.h - portable TCP socket serial port emulator
 *
 * Copyright (c) Michal Tomek 2018-2019 <mtdev79b@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307  USA.
 *
 */
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#define TCPIP_error WSAGetLastError()
#else
#include <stdint.h>
#define SOCKET int
#endif

// Base TCP port to connect to a virtual TTY device
#define BASE_PORT (10280)

// How many to emulate?
#define MAX_SOCKET_PORTS (2)

// Socket slots not currently open
#define INVALID_SOCKET (-1)

extern SOCKET listen_sockets[];
extern SOCKET client_sockets[];

// Return value for error
#define SOCKET_ERROR (-1)

extern int init_TCPIP(void);
extern void shutdown_TCPIP(void);

extern int init_socket_port(int port);
extern int open_socket_port(int port);
extern void shutdown_socket_ports(void);
extern int char_available_socket_port(int port);
extern int is_connected_socket_port(int port);
extern void tx_socket_port(int port, uint8_t data);
extern int rx_socket_port(int port);
