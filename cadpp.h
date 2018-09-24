/*
 *    Name: CAD++
 *    Abstract: C++ abstraction for managing CAD files in different formats.
 *
 *    Copyright (C) 2018  Kevin Amado  Kedavamaru@gmail.com
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef cadpp_h
#define cadpp_h

#include <fstream>
#include <string>
#include <vector>

namespace cadpp
{
	namespace dxf
	{
		namespace r12
		{
			using std::string;
			using std::vector;
			using std::ofstream;

			using num = long;
			using dbl = double;
			using str = string;

			// AutoCAD Index Colors (ACI)
			constexpr num color_red      =   1;
			constexpr num color_yellow   =   2;
			constexpr num color_green    =   3;
			constexpr num color_cyan     =   4;
			constexpr num color_blue     =   5;
			constexpr num color_pink     =   6;
			constexpr num color_default  =   7;
				// index 7 = black @ background_color white
				// index 7 = white @ background_color black
			constexpr num color_by_block =   0;
			constexpr num color_by_layer = 256;

			class cad
			{
			public:
				class header
				{
				public:
					class insbase
					{
					public:
						dbl x = 0.0;
						dbl y = 0.0;
						dbl z = 0.0;
					};
					class extmin
					{
					public:
						dbl x = 0.0;
						dbl y = 0.0;
						dbl z = 0.0;
					};
					class extmax
					{
					public:
						dbl x = 0.0;
						dbl y = 0.0;
						dbl z = 0.0;
					};

					insbase insbase;
					extmin extmin;
					extmax extmax;
				};
				class tables
				{
				public:
					class ltype
					{
					public:
						str name = "continuous";
						str description = "";
						num flags = 0;
						vector<dbl> dash_lengths;

						dbl total_dash_lengths() {
							dbl sum = 0;
							for (auto val : dash_lengths) sum += (val > 0)? val : -1.0 * val;
							return sum;
						}
					};
					class layer
					{
					public:
						str name = "default";
						num flags = 0;
						num color = color_default;
						str ltype = "continuous";
					};
					class style
					{
					public:
					};

					vector<style> styles;
					vector<ltype> ltypes = { ltype() };
					vector<layer> layers = { layer() };
				};
				class blocks
				{
				public:
				};
				class entities
				{
				public:
					class point
					{
					public:
						str layer = "default";
						dbl x = 0.0;
						dbl y = 0.0;
						dbl z = 0.0;
					};
					class line
					{
					public:
						str layer = "default";
						dbl thickness = 0;
						num color = color_by_layer;
						dbl x1 = 0.0;
						dbl y1 = 0.0;
						dbl z1 = 0.0;
						dbl x2 = 0.0;
						dbl y2 = 0.0;
						dbl z2 = 0.0;
					};
					vector<point> points;
					vector<line> lines;
				};

				cad();
				~cad();

				header header;
				tables tables;
				blocks blocks;
				entities entities;


				bool save(const string &filename);
				bool open(const string &filename);
			};
		}
		namespace Autocad_2000
		{
		}
	}
}
#endif // cadstream_h

