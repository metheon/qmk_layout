#undef KO
#define KO(name, mod, modded_key, new_key, layer) \
    const key_override_t name = ko_make_with_layers(mod, modded_key, new_key, (1 << layer));

#include "key_overrides.def"

#undef KO
#define KO(name, mod, modded_key, new_key, layer) \
    &name,

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
#include "key_overrides.def"
    NULL // Null terminate the array of overrides!
};