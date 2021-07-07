#[repr(C)]
#[derive(Clone, Copy)]
struct user_config_t_config {
    initialized: bool,
    emacs_mode: bool,
    default_layer: u8,
    last_default_layer: u8,
}

#[repr(C)]
pub union user_config_t {
    raw: u32,
    config: user_config_t_config
}
