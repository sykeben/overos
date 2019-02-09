# This is the makefile for OverOS.
CC = g++ -Wall -o
default: all

# Builds every single file, including optional ones.
all: base commands

# Only builds the bootloader and the kernel.
base: boot.cpp os/kernel.cpp
	$(CC) "boot" "boot.cpp"
	$(CC) "os/kernel" "os/kernel.cpp"

# Builds all the commands.
commands: cmd/hello.cpp
	$(CC) "cmd/hello" "cmd/hello.cpp"
