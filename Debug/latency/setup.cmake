###| CMake Kiibohd Controller Debug Module |###
#
# Written by Jacob Alexander in 2014-2017 for the Kiibohd Controller
#
# Released into the Public Domain
#
###


###
# Module C files
#

set ( Module_SRCS
	latency.c
)


###
# Compiler Family Compatibility
#
set ( ModuleCompatibility
	arm
	avr
	host
)

