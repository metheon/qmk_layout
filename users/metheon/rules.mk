# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
EXTRAKEY_ENABLE					=	yes 	# Enables audio control and System control
COMBO_ENABLE					=	yes		# Enables the usage of combos
KEY_OVERRIDE_ENABLE				=	yes		# Enables key overrides
ifndef LTO_ENABLE
	LTO_ENABLE					=	yes		# Reduces compiled size of firmware
endif

SRC += metheon.c
SRC += process_records.c
SRC += caps_word.c
SRC += oneshot.c

VPATH += keyboards/gboards

# Disable as many features as possible
ENCODER_ENABLE					=	no
LEADER_ENABLE					=	no
TAP_DANCE_ENABLE				=	no
MOUSEKEY_ENABLE					=	no
BOOTMAGIC_ENABLE				=	no
DYNAMIC_MACRO_ENABLE			=	no
COMMAND_ENABLE					=	no
AUDIO_ENABLE					=	no
KEY_LOCK_ENABLE					=	no
CONSOLE_ENABLE					=	no
VELOCIKEY_ENABLE				=	no
STENO_ENABLE					=	no
TERMINAL_ENABLE					=	no
GRAVE_ESC_ENABLE				=	no
SPACE_CADET_ENABLE				=	no
AUTO_SHIFT_ENABLE				=	no
POINTING_DEVICE_ENABLE			=	no
RAW_ENABLE						=	no
SEQUENCER_ENABLE				=	no
SWAP_HANDS_ENABLE				=	no
UNICODE_ENABLE					=	no
WPM_ENABLE						=	no
BACKLIGHT_ENABLE				=	no
LED_MATRIX_ENABLE				=	no
RGBLIGHT_ENABLE					=	no
RGB_MATRIX_ENABLE				=	no