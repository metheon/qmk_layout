# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
EXTRAKEY_ENABLE					=	yes 	# Enables audio control and System control
COMBO_ENABLE					=	yes		# Enables the usage of combos
KEY_OVERRIDE_ENABLE				=	yes		# Enables key overrides

//SRC += metheon.c

INTROSPECTION_KEYMAP_C = metheon.c # keymaps
SRC += features/oneshot.c
SRC += features/swapper.c

VPATH += keyboards/gboards

# Disable as many byte-costing features as possible
MOUSEKEY_ENABLE					=	no
BOOTMAGIC_ENABLE				=	no
GRAVE_ESC_ENABLE				=	no
POINTING_DEVICE_ENABLE			=	no
RAW_ENABLE						=	no
SPACE_CADET_ENABLE				=	no
UNICODE_ENABLE					=	no
