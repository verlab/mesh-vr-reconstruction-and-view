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

#include <iostream>
#include <string>
#include <Eigen/Dense>
#include "surface_recon.hpp"

bool check_pca_threshold(std::vector<Point_3> pts, float threshold, int max); //compares ratio between largest and smallest eigenvalue
void rm_artifacts_mesh(std::string path, int k);
CPoint3 laplacian_smooth(std::vector<Point_3> pts);