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

#ifndef __LIBTEST_EXTERNALTEST_H
#define __LIBTEST_EXTERNALTEST_H

#include "TestInstance.h"

class ExternalTest : public TestInstance
{
  public:

    ExternalTest(const char *name, int argc, char **argv);

    virtual TestResult run();

  private:

    int m_argc;
    char ** m_argv;

};

#endif /* __LIBTEST_EXTERNALTEST_H */
