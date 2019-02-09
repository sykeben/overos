# [ Setup Stuff ]
CC = g++ -Wall -o
default: all

# Builds every single file, including optional ones.
all: start base kautorun commands done

# Alerts user to build execution.
start:
	$(info ***** BUILD START ****)

# Only builds the bootloader and the kernel.
base: boot.cpp os/kernel.cpp
	$(info -> Building the base...)
	$(CC) "boot" "boot.cpp"
	$(CC) "os/kernel" "os/kernel.cpp"
	
# Builds the kernel autorun application.
kautorun: os/kautorun.cpp
	$(info -> Building the kernel autorun application...)
	$(CC) "os/kautorun" "os/kautorun.cpp"

# Builds all the commands.
commands: cmd/hello.cpp
	$(info -> Building system commands...)
	$(CC) "cmd/hello" "cmd/hello.cpp"
	
# Alerts user to build completion.
done:
	$(info ***** BUILD COMPLETE *****)
