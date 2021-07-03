# project specific files
SRC += matrix.c
SRC += led_matrix.c
SRC += config_led.c

## chip/board settings
# - the next two should match the directories in
#   <chibios>/os/hal/ports/$(MCU_FAMILY)/$(MCU_SERIES)
MCU_FAMILY = SN32
MCU_SERIES = SN32F240B

# Linker script to use
# - it should exist either in <chibios>/os/common/ports/ARMCMx/compilers/GCC/ld/
#   or <this_dir>/ld/
MCU_LDSCRIPT = SN32F240B

# Startup code to use
#  - it should exist in <chibios>/os/common/startup/ARMCMx/compilers/GCC/mk/
MCU_STARTUP = sn32f24xb

# Board: it should exist either in <chibios>/os/hal/boards/
#  or <this_dir>/boards
BOARD = SN_SN32F240B

# Cortex version
MCU  = cortex-m0

# ARM version, CORTEX-M0/M1 are 6, CORTEX-M3/M4/M7 are 7
ARMV = 6

# BOOTLOADER = flash
SN32_BOOTLOADER_ADDRESS = 0x1FFF0301

OPT_DEFS = -O2

CFLAGS += -Wno-error=array-bounds -Wno-error=misleading-indentation -Wno-error

# Build Options
#   comment out to disable the options.
#
BACKLIGHT_ENABLE 		= no
MAGIC_ENABLE 			= yes
MAGIC_KEYCODE_ENABLE 	= yes
ENCODER_ENABLE 			= yes
BOOTMAGIC_ENABLE 		= full	# Virtual DIP switch configuration
MOUSEKEY_ENABLE 		= yes   # Mouse keys
EXTRAKEY_ENABLE 		= yes	# Audio control and System control
CONSOLE_ENABLE 			= no    # Console for debug
COMMAND_ENABLE 			= no    # Commands for debug and configuration
SLEEP_LED_ENABLE 		= no   	# Breathing sleep LED during USB suspend
NKRO_ENABLE 			= yes   # USB Nkey Rollover
AUDIO_ENABLE 			= no
RGBLIGHT_ENABLE 		= no
SERIAL_LINK_ENABLE 		= no
WAIT_FOR_USB 			= no
CUSTOM_MATRIX 			= yes

# Custom RGB matrix handling
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = custom
