/*
 * Copyright (C) 2009 Niek Linnenbank
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

#ifndef __PCI_PCIREGISTER_H
#define __PCI_PCIREGISTER_H

#include <Types.h>
#include "File.h"
#include "FileMode.h"
#include "Directory.h"
#include "IOBuffer.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
 * @brief Represent a PCI configuration register as a File.
 *
 * This class reads out a register directly from the PCI
 * configuration space.
 *
 * @see PCIServer
 * @see File
 */
class PCIRegister : public File
{
    public:

	/**
	 * @brief Constructor function.
	 * @param bus PCI bus number.
	 * @param slot PCI slot on the bus.
	 * @param func PCI device function number.
	 * @param reg PCI configuration register to access.
	 * @param size The size of the register.
	 */
	PCIRegister(u16 bus, u16 slot, u16 func, u16 reg, Size size);

	/** 
         * @brief Read bytes from the file. 
	 *
         * @param buffer Output buffer. 
         * @param size Number of bytes to read, at maximum. 
         * @param offset Offset inside the file to start reading. 
         * @return Number of bytes read on success, Error on failure. 
	 *
	 * @see IOBuffer
	 * @see PCIServer.h
         */
        Error read(IOBuffer *buffer, Size size, Size offset);
	
    private:

	/** @brief PCI bus number. */
	u16 bus;
	
	/** @brief PCI slot number. */
	u16 slot;
	
	/** @brief PCI device function number. */
	u16 func;
    
	/** @brief PCI register for I/O. */
	u16 reg;
	
	/** @brief Size of the register in bytes. */
	Size size;
};

/**
 * @}
 */

#endif /* __PCI_PCIREGISTER_H */
