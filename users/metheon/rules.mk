# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
ifndef ENCODER_ENABLE
	ENCODER_ENABLE				=	no  	# Ensure encoders are disabled unless set to true in a specific keymap
endif

EXTRAKEY_ENABLE					=	yes 	# Enables audio control and System control
LEADER_ENABLE					=	yes 	# Enables the Leader Key feature
MOUSEKEY_ENABLE					=	yes 	# Enables usage of keyboard as mouse
LTO_ENABLE						=	yes		# Reduces compiled size of firmware
COMBO_ENABLE					=	yes		# Enables the usage of combos

SRC += metheon.c
SRC += encoders.c
SRC += process_records.c
SRC += leader.c
SRC += combos.c
SRC += which_os.c
SRC += window_tab.c

# Disable as many features as possible
BOOTMAGIC_ENABLE				=	no	    # Not required for CG_TOGG which is the only bootmagic feature I use
DYNAMIC_MACRO_ENABLE			=	no 		# Enables dynamic macros
TAP_DANCE_ENABLE				=	no		# Enables the tap dance feature
COMMAND_ENABLE					=	no 		# Commands for debug and configuration
AUDIO_ENABLE					=	no		# Enables any onboard speakers
KEY_LOCK_ENABLE					=	no
CONSOLE_ENABLE					=	no
VELOCIKEY_ENABLE				=	no
STENO_ENABLE					=	no
TERMINAL_ENABLE					=	no
GRAVE_ESC_ENABLE				=	no
SPACE_CADET_ENABLE				=	no
