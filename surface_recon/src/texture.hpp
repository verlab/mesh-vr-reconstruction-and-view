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

#ifndef TEXTURE
#define TEXTURE

//#define DEBUG_TRUE

#include "my_png.hpp"
#include "surface_recon.hpp"
#include <math.h>
#include <Eigen/Dense>

struct uv_map
{
	double x,y;

	uv_map(){}
	uv_map(double _x, double _y)
	{x = _x; y = _y;}
};

struct face
{

	size_t v1, v2, v3;
	uv_map uv1, uv2, uv3;
	double area;

	face(size_t _v1, size_t _v2, size_t _v3)
	{
		v1 = _v1;
		v2 = _v2;
		v3 = _v3;

		uv1 = uv_map(0,0);
		uv2 = uv_map(0,0);
		uv3 = uv_map(0,0);
	}

};

struct vertex
{
	double x ,y ,z;

	vertex(double _x, double _y, double _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
};



class texture
{
		
	Tree& tree; //CGAL KD-tree to bake textures
	std::vector<Color>& colors;

	std::string output_path;
	my_png img;
	int texture_size;
	vector<vertex> vertices;
	vector<face> faces;
	vector<uv_map> uv_coords;
	size_t uv_idx;

	public:

		texture(Tree& tree, std::vector<Color>& colors, std::string output_path, int texture_size):tree(tree),colors(colors),output_path(output_path),texture_size(texture_size)
		{
			img = my_png(texture_size,texture_size); //initialize image for texture
			uv_idx=0;
			read_off("temp3.off");//("/media/sf_teste_SFM/lab_vale/our_model/pmvs_options.txt.ply_reconstructed.off");
		}

		void build_png();
		void draw_triangle_up(int x, int y, int t, unsigned char rgb[], int sep);
		void draw_triangle_down(int x, int y, int t, unsigned char rgb[], int sep);
		void draw_quad_and_parametrize(int x, int y, int t, int n);
		void save_obj();
		void read_off(string filename);
		double face_area(const face& f);
		bool sort_face_by_area(const face& f1, const face& f2);
		void idw_interpolation(double xyz[], unsigned char rgb[]);

};



#endif