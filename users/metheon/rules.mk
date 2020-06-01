# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
LINK_TIME_OPTIMIZATION_ENABLE	=	yes # Reduces compiled size of firmware
COMMAND_ENABLE					=	no 	# Commands for debug and configuration
AUDIO_ENABLE					=	no	# Enables any onboard speakers
MOUSEKEY_ENABLE					=	yes # Enables usage of keyboard as mouse

ifndef ENCODER_ENABLE
	ENCODER_ENABLE				=	no  # Enables usage of rotary encoders
endif

DYNAMIC_MACRO_ENABLE			=	yes # Enables dynamic macros
EXTRAKEY_ENABLE					=	yes # Enables audio control and System control
LEADER_ENABLE					=	yes # Enables the Leader Key feature
TAP_DANCE_ENABLE				=	yes # Enables the tap dance feature

SRC += encoders.c
SRC += tap_dance.c
SRC += process_records.c
SRC += leader.c
