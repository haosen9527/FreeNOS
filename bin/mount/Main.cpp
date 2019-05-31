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

#include <FreeNOS/System.h>
#include <FileSystemMount.h>
#include <Runtime.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char cmd[PAGESIZE];

int main(int argc, char **argv)
{
    refreshMounts(0);
    FileSystemMount *mounts = getMounts();

    // TODO: ask the kernel for the process table instead. With ARGV_ADDR copies.

    // Print header
    printf("PATH                 FILESYSTEM\r\n");

    // Print out
    for (Size i = 0; i < FILESYSTEM_MAXMOUNTS; i++)
    {
        if (mounts[i].path[0])
        {
            // Get the command
            VMCopy(mounts[i].procID, API::Read, (Address) cmd, ARGV_ADDR, PAGESIZE);
            printf("%20s %s\r\n", mounts[i].path, cmd);
        }
    }
    // Done
    return EXIT_SUCCESS;
}
