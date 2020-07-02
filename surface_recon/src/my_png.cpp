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

#include "my_png.hpp"

 unsigned char& my_png::at(int r, int c, int ch)
{
    if(r < height && c < width && r >=0 && c>=0)
        return buffer[width*r*3 + c*3 + ch];
    else
    {   
        cout<<"Error: image coords out of bounds"<<endl;
        cout<<"("<<r<<", "<<c<<")"<<endl;
        return buffer[0];
    }
}



void my_png::write(string filename)
{
    FILE *fp = NULL;
    png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    png_infop info_ptr = png_create_info_struct(png_ptr);
    png_bytep row = NULL;

    if (png_ptr == NULL) cout<< "Could not allocate png struct"<<endl;

    if (setjmp(png_jmpbuf(png_ptr)))
        cout<<"error in init_io"<<endl;
    
    fp = fopen(filename.c_str(), "wb");
    png_init_io(png_ptr, fp);


    // Write RGB header with 1 byte per channel (8 bits)
    png_set_IHDR(png_ptr, info_ptr, width, height,
            8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
            PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

    png_write_info(png_ptr, info_ptr);

    // (3 bytes per pixel - RGB)
    row = (png_bytep) malloc(3 * width * sizeof(png_byte));

    for (int y=0 ; y<height ; y++) 
    {
        for (int x=0 ; x<width ; x++) 
            for(int j=0; j<3; j++)
                row[x*3 + j] = buffer[y*width*3 + x*3 + j];
        
        png_write_row(png_ptr, row);

    }

    // End write
    png_write_end(png_ptr, NULL);

    if (fp != NULL) fclose(fp);
    if (info_ptr != NULL) png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);
    if (png_ptr != NULL) png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
    if (row != NULL) free(row);


}

