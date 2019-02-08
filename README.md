# OverOS
## Multi-platform C++ "overlaying" OS. 


### Features
OverOS, even though it is pretty basic in "stock" form, contains some great features:
- Ability to run commands from the \cmd directory, allowing for quick expansion.
- Simple, easy-to-modify source code for quick porting and improvements.
- Intuitive directory layouts to maximize ease-of-use.
- And more! 


### Important Notes
Since I have no actual clue how to write a proper "OS", this "OS" doesn't actually have the ability to "boot" on a bare-bones system so it requires a basic underlying OS (preferably Win32/64 or \*Nix based) to be run on top of. In the future I may write a basic kernel with it's own filesystem and executable management, but until then, this is basically a glorified shell and executable management system. 


### Built-in Commands
Currently, the "kernel" has some basic, but important, built-in commands:
- "help" ~ Prints list of built-in commands and other important info.
- "exitnow" ~ Cleans up OverOS and exits the kernel and bootloader.
- "clr" ~ Clears the screen/console.
- "sysver" ~ Prints the system's major, minor, and revision version.
- "listcmds" ~ Lists the files in the \cmd directory to allow the user to see which external commands are installed.

If the kernel is not told to run any of these, it will search for an executable in the \cmd directory with the name specified in the prompt and run it with the arguments specified in the prompt. If a suitable executable is not found, it will print an error. 


### Building OverOS
There is currently no effecient way to build OverOS just yet as I have no clue how to write makefiles at the moment. Once I learn, there should be an easy way to build it.
