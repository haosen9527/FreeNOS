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

#include <FreeNOS/System.h>
#include "BubbleAllocator.h"

BubbleAllocator::BubbleAllocator(Address start, Size size)
{
    m_start   = (u8 *) start;
    m_current = (u8 *) start;
    m_size    = size;
}

Size BubbleAllocator::size()
{
    return m_size;
}

Size BubbleAllocator::available()
{
    return m_size - (m_current - m_start);
}

Allocator::Result BubbleAllocator::allocate(Size *sz, Address *addr, Size align)
{
    Size needed = aligned(*sz, MEMALIGN);

    // Do we still have enough room?
    if (m_current + needed < m_start + m_size)
    {
        m_current += needed;
        *addr = (Address) (m_current - needed);
        return Success;
    }
    // No more memory available
    return OutOfMemory;
}

Allocator::Result BubbleAllocator::release(Address addr)
{
    // BubbleAllocator never releases memory
    return InvalidAddress;
}
