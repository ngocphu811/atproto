/* Copyright (c) 2014 Ivan Grokhotkov. All rights reserved. 
 * This file is part of the atproto AT protocol library
 *
 * Redistribution and use is permitted according to the conditions of the
 * 3-clause BSD license to be found in the LICENSE file.
 */

#include "dce_common.h"
#include "dce_private.h"
#include "config_store.h"
#include "user_interface.h"

#define CONFIG_SECTOR 0

static config_t s_config;
static int s_config_loaded = 0;

void ICACHE_FLASH_ATTR config_read(config_t* config)
{
    load_user_param(CONFIG_SECTOR, 0, config, sizeof(config_t));
}

void ICACHE_FLASH_ATTR config_write(config_t* config)
{
    erase_user_param(CONFIG_SECTOR);
    save_user_param(CONFIG_SECTOR, 0, config, sizeof(config_t));
}

config_t* ICACHE_FLASH_ATTR config_get()
{
    if (!s_config_loaded)
    {
        config_read(&s_config);
        s_config_loaded = 1;
    }
    return &s_config;
}

void ICACHE_FLASH_ATTR config_save()
{
    config_write(&s_config);
    config_t tmp;
    config_read(&tmp);
    if (memcmp(&tmp, &s_config, sizeof(config_t)) != 0)
    {
        DCE_FAIL("config verify failed");
    }
}
