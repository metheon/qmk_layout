# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
LINK_TIME_OPTIMIZATION_ENABLE	=	no	# Reduces compiled size of firmware
COMMAND_ENABLE					=	no 	# Commands for debug and configuration
AUDIO_ENABLE					=	no	# Enables any onboard speakers
MOUSEKEY_ENABLE					=	yes # Enables usage of keyboard as mouse
ENCODER_ENABLE					=	no  # Enables usage of rotary encoders
DYNAMIC_MACRO_ENABLE			=	yes # Enables dynamic macros
EXTRAKEY_ENABLE					=	yes # Enables audio control and System control
LEADER_ENABLE					=	no  # Enables the Leader Key feature
TAP_DANCE_ENABLE				=	yes # Enables the tap dance feature

SRC += metheon_encoders.c
SRC += metheon_tap_dance.c
