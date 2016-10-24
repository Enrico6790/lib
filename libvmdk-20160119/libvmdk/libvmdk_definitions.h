/*
 * The internal definitions
 *
 * Copyright (C) 2009-2016, Joachim Metz <joachim.metz@gmail.com>
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

#if !defined( _LIBVMDK_INTERNAL_DEFINITIONS_H )
#define _LIBVMDK_INTERNAL_DEFINITIONS_H

#include <common.h>
#include <byte_stream.h>

#define LIBVMDK_ENDIAN_BIG					_BYTE_STREAM_ENDIAN_BIG
#define LIBVMDK_ENDIAN_LITTLE					_BYTE_STREAM_ENDIAN_LITTLE

/* Define HAVE_LOCAL_LIBVMDK for local use of libvmdk
 */
#if !defined( HAVE_LOCAL_LIBVMDK )
#include <libvmdk/definitions.h>

/* The definitions in <libvmdk/definitions.h> are copied here
 * for local use of libvmdk
 */
#else
#define LIBVMDK_VERSION						20160119

/* The libvmdk version string
 */
#define LIBVMDK_VERSION_STRING					"20160119"

/* The access flags definitions
 * bit 1        set to 1 for read access
 * bit 2        set to 1 for write access
 * bit 3-8      not used
 */
enum LIBVMDK_ACCESS_FLAGS
{
	LIBVMDK_ACCESS_FLAG_READ				= 0x01,
/* Reserved: not supported yet */
	LIBVMDK_ACCESS_FLAG_WRITE				= 0x02
};

/* The file access macros
 */
#define LIBVMDK_OPEN_READ					( LIBVMDK_ACCESS_FLAG_READ )
/* Reserved: not supported yet */
#define LIBVMDK_OPEN_WRITE					( LIBVMDK_ACCESS_FLAG_WRITE )
/* Reserved: not supported yet */
#define LIBVMDK_OPEN_READ_WRITE					( LIBVMDK_ACCESS_FLAG_READ | LIBVMDK_ACCESS_FLAG_WRITE )

/* The file types
 */
enum LIBVMDK_FILE_TYPES
{
	LIBVMDK_FILE_TYPE_COWD_SPARSE_DATA			= (uint8_t) 'c',
	LIBVMDK_FILE_TYPE_DESCRIPTOR_FILE			= (uint8_t) 'd',
	LIBVMDK_FILE_TYPE_RAW_DATA				= (uint8_t) 'r',
	LIBVMDK_FILE_TYPE_VMDK_SPARSE_DATA			= (uint8_t) 'v'
};

/* The (virtual) disk types
 */
enum LIBVMDK_DISK_TYPE
{
	LIBVMDK_DISK_TYPE_UNDEFINED,
	LIBVMDK_DISK_TYPE_2GB_EXTENT_FLAT,
	LIBVMDK_DISK_TYPE_2GB_EXTENT_SPARSE,
	LIBVMDK_DISK_TYPE_CUSTOM,
	LIBVMDK_DISK_TYPE_DEVICE,
	LIBVMDK_DISK_TYPE_DEVICE_PARITIONED,
	LIBVMDK_DISK_TYPE_MONOLITHIC_FLAT,
	LIBVMDK_DISK_TYPE_MONOLITHIC_SPARSE,
	LIBVMDK_DISK_TYPE_STREAM_OPTIMIZED,
	LIBVMDK_DISK_TYPE_VMFS_FLAT,
	LIBVMDK_DISK_TYPE_VMFS_FLAT_PRE_ALLOCATED,
	LIBVMDK_DISK_TYPE_VMFS_FLAT_ZEROED,
	LIBVMDK_DISK_TYPE_VMFS_RAW,
	LIBVMDK_DISK_TYPE_VMFS_RDM,
	LIBVMDK_DISK_TYPE_VMFS_RDMP,
	LIBVMDK_DISK_TYPE_VMFS_SPARSE,
	LIBVMDK_DISK_TYPE_VMFS_SPARSE_THIN
};

/* The compression methods
 */
enum LIBVMDK_COMPRESSION_METHODS
{
	LIBVMDK_COMPRESSION_METHOD_NONE				= 0,
	LIBVMDK_COMPRESSION_METHOD_DEFLATE			= 1
};

/* The extent access
 */
enum LIBVMDK_EXTENT_ACCESS
{
	LIBVMDK_EXTENT_ACCESS_NONE				= 1,
	LIBVMDK_EXTENT_ACCESS_READ				= 2,
	LIBVMDK_EXTENT_ACCESS_READ_WRITE			= 3,
};

/* The extent types
 */
enum LIBVMDK_EXTENT_TYPES
{
	LIBVMDK_EXTENT_TYPE_FLAT				= 1,
	LIBVMDK_EXTENT_TYPE_SPARSE				= 2,
	LIBVMDK_EXTENT_TYPE_VMFS_FLAT				= 3,
	LIBVMDK_EXTENT_TYPE_VMFS_SPARSE				= 4,
	LIBVMDK_EXTENT_TYPE_VMFS_RAW				= 5,
	LIBVMDK_EXTENT_TYPE_VMFS_RDM				= 6,
	LIBVMDK_EXTENT_TYPE_ZERO				= 7,
};

#endif

/* The flags
 */
enum LIBVMDK_FLAGS
{
	LIBVMDK_FLAG_NEW_LINE_DETECION_VALID			= 0x00000001,
	LIBVMDK_FLAG_USE_SECONDARY_GRAIN_DIRECTORY		= 0x00000002,

	LIBVMDK_FLAG_HAS_GRAIN_COMPRESSION			= 0x00010000,
	LIBVMDK_FLAG_HAS_DATA_MARKERS				= 0x00020000,
};

/* The markers
 */
enum LIBVMDK_MARKERS
{
	LIBVMDK_MARKER_END_OF_STREAM				= 0,
	LIBVMDK_MARKER_GRAIN_TABLE				= 1,
	LIBVMDK_MARKER_GRAIN_DIRECTORY				= 2,
	LIBVMDK_MARKER_FOOTER					= 3
};

/* The grain data range is sparse
 */
#define LIBVMDK_RANGE_FLAG_IS_SPARSE				LIBFDATA_RANGE_FLAG_IS_SPARSE

/* The grain data range is compressed
 */
#define LIBVMDK_RANGE_FLAG_IS_COMPRESSED			LIBFDATA_RANGE_FLAG_IS_COMPRESSED

/* The grain data range refers to a packed (unprocessed) grain
 */
#define LIBVMDK_RANGE_FLAG_IS_PACKED				LIBFDATA_RANGE_FLAG_USER_DEFINED_1

/* The grain data range is tainted (possibly corrupted)
 */
#define LIBVMDK_RANGE_FLAG_IS_TAINTED				LIBFDATA_RANGE_FLAG_USER_DEFINED_2

/* The grain data range is corrupted
 */
#define LIBVMDK_RANGE_FLAG_IS_CORRUPTED				LIBFDATA_RANGE_FLAG_USER_DEFINED_3

#define LIBVMDK_MAXIMUM_CACHE_ENTRIES_EXTENT_FILES		4
#define LIBVMDK_MAXIMUM_CACHE_ENTRIES_GRAIN_GROUPS		32
#define LIBVMDK_MAXIMUM_CACHE_ENTRIES_GRAINS			8

#endif

