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

#include "cadpp.h"

namespace cadpp {
	namespace dxf {
		namespace r12 {

			cad::cad() {}
			cad::~cad() {}

			bool cad::save(const string &filename) {
				ofstream file(filename);

				if (!file.good()) return false;

#define w(c, v) file << c << "\n" << v << "\n";
				w(0, "SECTION")
					w(2, "HEADER")
					w(9, "$ACADVER")
					w(1, header.acadver)
					w(9, "$INSBASE")
					w(10, header.insbase.x)
					w(20, header.insbase.y)
					w(30, header.insbase.z)
					w(0, "ENDSEC")

					w(0, "SECTION")
					w(2, "TABLES")
					w(0, "ENDSEC")

					w(0, "SECTION")
					w(2, "BLOCKS")
					w(0, "ENDSEC")

					w(0, "SECTION")
					w(2, "ENTITIES")
					for (unsigned int i = 0; i < entities.points.size(); ++i) {
						w(0, "POINT")
							w(8, entities.points[i].layer)
							w(10, entities.points[i].x)
							w(20, entities.points[i].y)
							w(30, entities.points[i].z)
					}

				for (unsigned int i = 0; i < entities.lines.size(); ++i) {
					w(0, "LINE")
						w(8, entities.lines[i].layer)
						w(10, entities.lines[i].thickness)
						w(10, entities.lines[i].colorindex)
						w(10, entities.lines[i].x1)
						w(20, entities.lines[i].y1)
						w(30, entities.lines[i].z1)
						w(30, entities.lines[i].x2)
						w(30, entities.lines[i].y2)
						w(30, entities.lines[i].z2)
				}
				w(0, "ENDSEC")

					w(0, "EOF")
#undef w
					file.close();
				return file.good();
			}
			bool cad::open(const string &filename) {
				return false;
			}
		}
	}
}