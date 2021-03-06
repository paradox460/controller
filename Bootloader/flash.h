/* Copyright (c) 2011,2012 Simon Schubert <2@0x2c.org>.
 * Modifications by Jacob Alexander 2014-2018 <haata@kiibohd.com>
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

#pragma once

#if defined(_sam_)
#include "flash_efc.h"
#endif

// ----- Defines -----

#if defined(_mk20dx128vlf5_) || defined(_mk20dx128vlh7_)
#define FLASH_SECTOR_SIZE 1024
#elif defined(_mk20dx256vlh7_)
#define FLASH_SECTOR_SIZE 2048
#elif defined(_mk22fx512avlh12_)
#define FLASH_SECTOR_SIZE 4096
#elif defined(_sam4s8_)
#define FLASH_SECTOR_SIZE 65536ul
#define LOCK_REGION_SIZE  8192
#define FLASH_PAGE_SIZE   512
#endif



// ----- Functions -----

__attribute__((section(".ramtext.ftfl_submit_cmd"), long_call))
int ftfl_submit_cmd(void);
int flash_prepare_flashing(void);
#if defined(_kinetis_)
int flash_program_sector(uintptr_t, size_t);
#elif defined(_sam_)
int flash_program_sector( uintptr_t addr, const void *data, size_t len );
#endif
int flash_program_longword(uintptr_t, uint8_t*);
void *flash_get_staging_area(uintptr_t, size_t);

