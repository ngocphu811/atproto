/* Copyright (c) 2014 Ivan Grokhotkov. All rights reserved. 
 * This file is part of the atproto AT protocol library
 *
 * Redistribution and use is permitted according to the conditions of the
 * 3-clause BSD license to be found in the LICENSE file.
 */

#ifndef __DCE_COMMON_H
#define __DCE_COMMON_H

#define VERSION_STRING "0.1"

#if defined(ESP_PLATFORM)
#include "ets_sys.h"
#include "os_type.h"
#include "osapi.h"
#include "mem.h"
#define SECTION_ATTR __attribute__((section(".irom0.text")))
#define malloc os_malloc
#define free os_free
#else
#include <string.h>
#include <stdlib.h>
#define SECTION_ATTR
#endif

#endif
