/*
 * kernel.cpp
 * 
 * Copyright 2019 thatg <thatg@DESKTOP-RI4LHCA>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
int _VMAJOR = 0; int _VMINOR = 1; int _VREVISION = 3;

void clear_screen() {
	#ifdef _WIN32
		system("cls");
	#else
		system ("clear");
	#endif
}

void settitle(string titleMsg) {
	#ifdef WIN32
		string title = "title ";
		title += titleMsg.c_str();
	#else
		string title = "echo -en \"\\033]0;";
		title += titleMsg.c_str();
		title += "\\a\"";
	#endif
	system(title.c_str());
}

bool fexists(const string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

#ifdef _WIN32 
	const char _TERM = '\n';
	const string _LISTCMDS = "dir cmd /B /O:N";
#else
	const char _TERM = '\r';
	const string _LISTER = "ls -x";
#endif

int main(int argc, char** argv) {
	// This is the "kernel" for overOS.
	// It really isn't a kernel, but whatever.
	
	// Prepare kernel enviroment.
	cout << "Kernel started, getting ready..." << _TERM;
	settitle("OverOS Shell");
	int _MAXIN = 100; char _INPUT[_MAXIN];
	bool _EXIT = false; bool _CLEARED = false;
	string _INPUTSTR; string _CMDF; string _CMDFWIN;
	string _CMDRUN;
	
	// Let the user know the kernel & shell are ready.
	clear_screen();
	cout << "[ OverOS " << _VMAJOR << '.' << _VMINOR << '.' << _VREVISION << " Shell ]" << _TERM;
	cout << "Run \"help\" for assistance." << _TERM;
	
	while (!_EXIT) {
		
		// Get user command input.
		if (_CLEARED) {
			_CLEARED = false;
		} else {
			cout << _TERM;
		}
		cout << "~> ";
		cin.getline(_INPUT, _MAXIN, _TERM);
		
		// Internal commands.
		if (!strcmp(_INPUT, "help")) {
			cout << "Internal shell commands: help exitnow clr sysver listcmds" << _TERM;
			cout << "The prompt may also run executables from the \\cmd directory." << _TERM;
		} else if (!strcmp(_INPUT, "exitnow")) {
			cout << "Exiting OverOS now..." << _TERM;
			_EXIT = true;
		} else if (!strcmp(_INPUT, "clr")) {
			clear_screen(); _CLEARED = true;
		} else if (!strcmp(_INPUT, "sysver")) {
			cout << "OverOS System Version " << _VMAJOR << '.' << _VMINOR << '.' << _VREVISION << _TERM;
		} else if (!strcmp(_INPUT, "listcmds")) {
			cout << "Files in the \\cmd directory:" << _TERM;
			system(_LISTCMDS.c_str());
		} else {
			_INPUTSTR = _INPUT;
			_CMDF = ".\\cmd\\" + _INPUTSTR.substr(0, _INPUTSTR.find(' '));
			_CMDFWIN = _CMDF + ".exe";
			if (fexists(_CMDF) || fexists(_CMDFWIN)) {
				system((".\\cmd\\" + _INPUTSTR).c_str());
			} else {
				cout << "Error: Invalid command, " << _INPUT << "." << _TERM;
			}
		}
	}
	
	return 0;
}
