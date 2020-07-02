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

#ifndef _HOLE_FILLING_
#define _HOLE_FILLING_

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polyhedron_3.h>
#include <CGAL/Polygon_mesh_processing/triangulate_hole.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <boost/foreach.hpp>


typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Polyhedron_3<K> P;
typedef P::Halfedge_handle H;
typedef P::Facet_handle F;
typedef P::Vertex_handle V;
typedef P::Point_3  Point3;


int fill_hole(std::string mesh_path, double max_perimeter);

#endif 
// HOLE_FILLING
