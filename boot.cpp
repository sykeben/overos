/*
 * boot.cpp
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

using namespace std;

void clear_screen() {
	#ifdef _WIN32
		system("cls");
	#else
		system ("clear");
	#endif
}

#ifdef _WIN32 
	const char _TERM = '\n';
#else
	const char _TERM = '\r';
#endif

int main(int argc, char** argv) {
	// This is a simple system loader, it boots the kernel.
	
	clear_screen();
	cout << "[ OverOS Boot ]" << _TERM;
	cout << "Starting the kernel..." << _TERM;
	
	system(".\\os\\kernel"); // Begin kernel execution.
	return 0;
}
