/*
 * Error functions
 *
 * Copyright (C) 2008-2016, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <types.h>

#include "libcfile_error.h"
#include "libcfile_libcerror.h"

#if !defined( HAVE_LOCAL_LIBCFILE )

/* Free an error and its elements
 */
void libcfile_error_free(
      libcfile_error_t **error )
{
	libcerror_error_free(
	 (libcerror_error_t **) error );
}

/* Prints a descriptive string of the error to the stream
 * Returns the number of printed characters if successful or -1 on error
 */
int libcfile_error_fprint(
     libcfile_error_t *error,
     FILE *stream )
{
	return( libcerror_error_fprint(
	         (libcerror_error_t *) error,
	         stream ) );
}

/* Prints a descriptive string of the error to the string
 * The end-of-string character is not included in the return value
 * Returns the number of printed characters if successful or -1 on error
 */
int libcfile_error_sprint(
     libcfile_error_t *error,
     char *string,
     size_t size )
{
	return( libcerror_error_sprint(
	         (libcerror_error_t *) error,
	         string,
	         size ) );
}

/* Prints a backtrace of the error to the stream
 * Returns the number of printed characters if successful or -1 on error
 */
int libcfile_error_backtrace_fprint(
     libcfile_error_t *error,
      FILE *stream )
{
	return( libcerror_error_backtrace_fprint(
	         (libcerror_error_t *) error,
	         stream ) );
}

/* Prints a backtrace of the error to the string
 * The end-of-string character is not included in the return value
 * Returns the number of printed characters if successful or -1 on error
 */
int libcfile_error_backtrace_sprint(
     libcfile_error_t *error,
     char *string,
     size_t size )
{
	return( libcerror_error_backtrace_sprint(
	         (libcerror_error_t *) error,
	         string,
	         size ) );
}

#endif /* !defined( HAVE_LOCAL_LIBCFILE ) */
