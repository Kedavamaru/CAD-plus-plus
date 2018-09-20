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

namespace cadpp {
	using namespace std;

	namespace dxf {
		namespace r12 {
			using num = long;
			using dbl = double;
			using str = string;

			class cad {
			public:
				class header {
				public:
					const str acadver = "AC1009";
					struct insbase {
						dbl x = 0.0;
						dbl y = 0.0;
						dbl z = 0.0;
					} insbase;
				} header;
				class tables {
				public:
				} tables;
				class blocks {
				public:
				} blocks;
				class entities {
				public:
					struct point {
						str layer = "0";
						dbl x = 0.0;
						dbl y = 0.0;
						dbl z = 0.0;
					};
					struct line {
						str layer = "0";
						dbl thickness = 0;
						num colorindex = 0;

						dbl x1 = 0.0;
						dbl y1 = 0.0;
						dbl z1 = 0.0;

						dbl x2 = 0.0;
						dbl y2 = 0.0;
						dbl z2 = 0.0;
					};
					vector<point> points;
					vector<line> lines;
				} entities;
			public:
				cad();
				~cad();

				bool save(const string &filename);
				bool open(const string &filename);
			};
		}
		namespace Autocad2000 {}
	}
}
#endif // cadstream_h


/* * * * * * * * * * * * * * * * * *
 * Group Code types
 * * * * * * * * * * * * * * * * * *
 * [0   , 9   ] - string
 * [10  , 59  ] - double
 * [60  , 79  ] - int
 * [140 , 147 ] - double
 * [170 , 175 ] - int
 * [210 , 239 ] - double
 * [999 , 999 ] - string
 * [1000, 1009] - double
 * [1010, 1059] - int
 * [1060, 1079] - string
 * * * * * * * * * * * * * * * * * *
 * Constants
 * * * * * * * * * * * * * * * * * *
 * Pi float:  3.141592654f
 * Pi double: 3.141592653589793238
 * * * * * * * * * * * * * * * * * */