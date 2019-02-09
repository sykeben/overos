/*
 * kernel.cpp - OverOS kernel.
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

// Set up all the extra garbage.
using namespace std;
int _VMAJOR = 0; int _VMINOR = 1; int _VREVISION = 5;
bool _EXIT = false; int _EXITCODE = 0; bool _CLEARED = false;
const int _MAXIN = 255; char _INPUT[_MAXIN]; string _INPUTSTR;
string _CMDF; string _CMDFWIN; string _CMDRUN;

void clear_screen() {
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
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

const char _TERM = '\n'; // Terminator character (may need to be changed for your system).
#ifdef _WIN32 
	const string _LISTCMDS = "dir cmd /B /O:N";
#else
	const string _LISTCMDS = "ls cmd -x";
#endif

int main(int argc, char** argv) {
	// This is the "kernel" for overOS.
	// It really isn't a kernel, but whatever.
	
	// Prepare kernel enviroment.
	cout << "Kernel started, getting ready..." << _TERM;
	#ifdef _WIN32
		if (fexists(".\\os\\kautorun.exe")) system(".\\os\\kautorun");
	#else
		if (fexists("./os/kautorun")) system("./os/kautorun");
	#endif
	settitle("OverOS Shell");
	
	// Let the user know the kernel & shell are ready.
	clear_screen();
	cout << "[ OverOS " << _VMAJOR << '.' << _VMINOR << '.' << _VREVISION << " Shell ]" << _TERM;
	cout << "Run \"help\" for assistance." << _TERM;
	
	while (!_EXIT) {
		
		// Get user command input.
		if (_CLEARED) _CLEARED = false; else cout << _TERM;
		cout << "~> ";
		cin.getline(_INPUT, _MAXIN, _TERM);
		
		// Internal commands & externel executor.
		if (!strcmp(_INPUT, "help")) {
			// Help //
			cout << "Internal shell commands: help exitnow clr sysver listcmds" << _TERM;
			cout << "The prompt may also run executables from the \\cmd directory." << _TERM;
		} else if (!strcmp(_INPUT, "exitnow")) {
			// ExitNow //
			cout << "Exiting OverOS now..." << _TERM;
			_EXIT = true; _EXITCODE = 0;
		} else if (!strcmp(_INPUT, "clr")) {
			// Clr //
			clear_screen(); _CLEARED = true;
		} else if (!strcmp(_INPUT, "sysver")) {
			// SysVer //
			cout << "OverOS System Version " << _VMAJOR << '.' << _VMINOR << '.' << _VREVISION << _TERM;
		} else if (!strcmp(_INPUT, "listcmds")) {
			// ListCmds //
			cout << "Files in the \\cmd directory:" << _TERM;
			system(_LISTCMDS.c_str());
		} else {
			// Externel Executor //
			_INPUTSTR = _INPUT;
			#ifdef _WIN32
				_CMDF = ".\\cmd\\" + _INPUTSTR.substr(0, _INPUTSTR.find(' '));
				_CMDF += ".exe";
			#else
				_CMDF = "./cmd/" + _INPUTSTR.substr(0, _INPUTSTR.find(' '));
			#endif
			_CMDFWIN = _CMDF + ".exe";
			if (fexists(_CMDF) || fexists(_CMDFWIN)) {
				#ifdef _WIN32
					system((".\\cmd\\" + _INPUTSTR).c_str());
				#else
					system(("./cmd/" + _INPUTSTR).c_str());
				#endif
			} else {
				// Invalid Error //
				cout << "Error: Invalid command, " << _INPUT << "." << _TERM;
			}
		}
	}
	
	return _EXITCODE;
}
