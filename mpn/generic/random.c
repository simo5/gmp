/* mpn_random -- Generate random numbers.

Copyright (C) 1996, 1997, 2000 Free Software Foundation, Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or (at your
option) any later version.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the GNU MP Library; see the file COPYING.LIB.  If not, write to
the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
MA 02111-1307, USA. */

#include "gmp.h"
#include "gmp-impl.h"
#include "urandom.h"

void
#if __STDC__
mpn_random (mp_ptr res_ptr, mp_size_t size)
#else
mpn_random (res_ptr, size)
     mp_ptr res_ptr;
     mp_size_t size;
#endif
{
  mp_size_t i;

  /* FIXME: Is size==0 supposed to be allowed? */
  ASSERT (size >= 0);

  for (i = 0; i < size; i++)
    res_ptr[i] = urandom ();

  /* Make sure the most significant limb is non-zero.  */
  while (res_ptr[size - 1] == 0)
    res_ptr[size - 1] = urandom ();
}
