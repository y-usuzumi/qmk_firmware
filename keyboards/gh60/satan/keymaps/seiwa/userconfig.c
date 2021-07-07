#include "userconfig.h"
#include "utils.h"

user_config_t user_config;

void save_user_config(void) {
    eeconfig_update_user(user_config.raw);
    uprintf("I:CONF:SAVE\n");
}

void load_user_config(void) {
    // Read user config from EEPROM
    user_config.raw = eeconfig_read_user();
    set_default_layer(user_config.default_layer);
    uprintf("I:CONF:LOAD\n");
}
