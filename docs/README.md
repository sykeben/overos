### Features
OverOS, even though it is pretty basic in "stock" form, contains some great features:
- Ability to run commands from the `/cmd` directory, allowing for quick expansion.
- Simple, easy-to-modify source code for quick porting and improvements.
- Ability to run code before the kernel loads for setup of extra features.
- Intuitive directory layouts to maximize ease-of-use.
- And more! 


### Important Notes
Since I have no actual clue how to write a proper OS, this "OS" doesn't actually have the ability to "boot" on a bare-bones system so it requires a basic underlying OS (preferably Win32/64 or \*Nix based) to be run on top of. In the future I may write a basic kernel with it's own filesystem and executable management, but until then, this is basically a glorified shell and executable management system. 


### Built-in Commands
Currently, the "kernel" has some basic, but important, built-in commands:
- `help` ~ Prints list of built-in commands and other important info.
- `exitnow` ~ Cleans up OverOS and exits the kernel and bootloader.
- `clr` ~ Clears the screen/console.
- `sysver` ~ Prints the system's major, minor, and revision version.
- `listcmds` ~ Lists the files in the `/cmd` directory to allow the user to see which external commands are installed.

If the kernel is not told to run any of these, it will search for an executable in the `/cmd` directory with the name specified in the prompt and run it with the arguments specified in the prompt. If a suitable executable is not found, it will print an error. 


### Building OverOS
If you can use `make`, it is the easiest possible way to build OverOS. Avaliable targets are:
- `all` ~ Builds all executables, including optional ones.
- `base` ~ Only builds the bootloader, kernel, and other essential executables.
- `kautorun` ~ Builds the kernel autorun application, this may not be critical.
- `commands` ~ Builds all the commands in `/cmd`.

Otherwise, you can download [the latest release](https://github.com/sykeben/overos/releases/latest). 


### Running OverOS
It's incredebly easy to "boot" OverOS, simply execute `boot` after compiling. 


### Screenshot
![Screenshot](screenshot.png?raw=true) 

This screenshot is from  `v0.1.5` and may be outdated.
