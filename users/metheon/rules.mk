# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
ifndef ENCODER_ENABLE
	ENCODER_ENABLE				=	no  	# Ensure encoders are disabled unless set to true in a specific keymap
endif

DYNAMIC_MACRO_ENABLE			=	yes 	# Enables dynamic macros
EXTRAKEY_ENABLE					=	yes 	# Enables audio control and System control
LEADER_ENABLE					=	yes 	# Enables the Leader Key feature
MOUSEKEY_ENABLE					=	yes 	# Enables usage of keyboard as mouse
BOOTMAGIC_ENABLE				=	full	# Used for toggling ctrl and gui
LTO_ENABLE						=	yes		# Reduces compiled size of firmware

SRC += metheon.c
SRC += encoders.c
SRC += process_records.c
SRC += leader.c

# Disable as many features as possible
TAP_DANCE_ENABLE				=	no		# Enables the tap dance feature
COMMAND_ENABLE					=	no 		# Commands for debug and configuration
AUDIO_ENABLE					=	no		# Enables any onboard speakers
KEY_LOCK_ENABLE					=	no
CONSOLE_ENABLE					=	no
VELOCIKEY_ENABLE				=	no
STENO_ENABLE					=	no
TERMINAL_ENABLE					=	no
GRAVE_ESC_ENABLE				=	no
MAGIC_ENABLE					=	no
SPACE_CADET_ENABLE				=	no
