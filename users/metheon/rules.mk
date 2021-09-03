# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
ifndef ENCODER_ENABLE
	ENCODER_ENABLE				=	no  	# Ensure encoders are disabled unless set to true in a specific keymap
endif

EXTRAKEY_ENABLE					=	yes 	# Enables audio control and System control
LTO_ENABLE						=	yes		# Reduces compiled size of firmware
COMBO_ENABLE					=	yes		# Enables the usage of combos
LEADER_ENABLE					=	yes  	# Enables the Leader Key feature

SRC += metheon.c
SRC += encoders.c
SRC += process_records.c
SRC += which_os.c
SRC += window_tab.c
SRC += caps_word.c
SRC += leader.c

VPATH += keyboards/gboards

# Disable as many features as possible
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