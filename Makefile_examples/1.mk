# from Alex Fosdick's embedded-systems coursera, week 2, lecture 8
#------------------------------------------------------------------
# An example makefile using automated variables
#  	to build for multiple targets.
#
# Use: make [targets] [overrides]
#
# Targets:
#	<FILE>.o - Builds <FILE>.o object file
#	build - Builds and links all source files
#	all - same as build
#	clean - Removes all generated files
#
# Overrides:
#	CPU - ARM Cortex Architecture (cortex-m0plus, cortex-m4)
#	ARCH - ARM Architecture (arm, thumb)
#	SPECS - Specs file to give the linker (nosys.specs, nano.specs)
#
#-----------------------------------------------------------------------
include sources.mk

#Overrides
CPU = cortex-m0plus
ARCH = thumb
SPECS = nosys.specs

#Compile defines
CC = arm-non-eabi-gcc
LD = arm-none-eabi-ld
BASENAME \ demo
TARGET = $(BASENAME).out
LDFLAGS = -Wl,-Map=$(BASENAME).map
CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -Wall

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@

.PHONY: build
build: all
.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -rf $(OBJS) $(TARGET) $(BASENAME).map
