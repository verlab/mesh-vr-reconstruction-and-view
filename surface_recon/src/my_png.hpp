//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%   This file is part of https://github.com/verlab/mesh-vr-reconstruction-and-view
//
//   mesh-vr-reconstruction-and-view is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
//   mesh-vr-reconstruction-and-view is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with mesh-vr-reconstruction-and-view.  If not, see <http://www.gnu.org/licenses/>.
//%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#ifndef MY_PNG
#define MY_PNG

#include <stdio.h>
#include <malloc.h>
#include <string>
#include <iostream>

#include <png.h>
#include <string.h>

using namespace std;

class my_png
{

	public:
	unsigned char* buffer;
	int width,height;

		my_png()
	{
		buffer = NULL;
		width = 0;
		height = 0;
	}

	my_png(int w, int h)
	{
		buffer = new unsigned char [w*h*3];
		width = w;
		height = h;

		memset(buffer,127,(w*h*3)*sizeof(unsigned char));
	}

	unsigned char& at(int r, int c, int ch);
	void write(string filename);

};

#endif