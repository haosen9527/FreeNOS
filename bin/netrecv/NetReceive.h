/*
 * Copyright (C) 2015 Niek Linnenbank
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __BIN_NETRECEIVE_H
#define __BIN_NETRECEIVE_H

#include <IPV4.h>
#include <Ethernet.h>
#include <POSIXApplication.h>

/**
 * Network receive application.
 */
class NetReceive : public POSIXApplication
{
  public:

    /**
     * Class constructor.
     */
    NetReceive(int argc, char **argv);

    /**
     * Class destructor.
     */
    virtual ~NetReceive();

    /**
     * Initialize the application.
     */
    virtual Result initialize();

    /**
     * Execute the application event loop.
     */
    virtual Result exec();

  private:

    Result receiveArp();
    Result receivePacket(u8 *packet, Size size);

    /** Socket */
    int m_socket;
};

#endif /* __BIN_NETRECEIVE_H */
