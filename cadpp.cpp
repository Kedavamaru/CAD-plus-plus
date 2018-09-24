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

namespace cadpp
{
	namespace dxf
	{
		namespace r12
		{
			cad::cad() {}
			cad::~cad() {}

			bool cad::save(const string &filename)
			{
				ofstream file(filename);

				if (!file.good()) return false;

				#define w(c, v) file << c << "\n" << v << "\n";
				w(0, "SECTION")
					w(2, "HEADER")
						w(9, "$ACADVER")
							w(1, "AC1009")
						w(9, "$INSBASE")
							w(10, header.insbase.x)
							w(20, header.insbase.y)
							w(30, header.insbase.z)
						w(9, "$EXTMIN")
							w(10, header.extmin.x)
							w(20, header.extmin.y)
							w(30, header.extmin.z)
						w(9, "$EXTMAX")
							w(10, header.extmax.x)
							w(20, header.extmax.y)
							w(30, header.extmax.z)
				w(0, "ENDSEC")

				w(0, "SECTION")
					w(2, "TABLES")
						w(0, "TABLE")
							w(2, "LTYPE")
							w(70, tables.ltypes.size())
								for (auto ltype : tables.ltypes)
								{
									w(0, "LTYPE")
										w(2, ltype.name)
										w(70, ltype.flags)
										w(3, ltype.description)
										w(72, "65")
										w(73, ltype.dash_lengths.size())
										w(40, ltype.total_dash_lengths())
										for (auto dashs_length : ltype.dash_lengths)
										{
											w(49, dashs_length)
										}
								}
						w(0, "ENDTAB")
						w(0, "TABLE")
							w(2, "LAYER")
							w(70, tables.layers.size())
								for (auto layer : tables.layers)
								{
									w(0, "LAYER")
										w(2, layer.name)
										w(70, layer.flags)
										w(62, layer.color)
										w(6, layer.ltype)
								}
						w(0, "ENDTAB")
						w(0, "TABLE")
							w(2, "STYLE")
							w(70, tables.styles.size())
								for (auto style : tables.styles)
								{
									w(0, "STYLE")
								}
						w(0, "ENDTAB")
				w(0, "ENDSEC")

				w(0, "SECTION")
					w(2, "BLOCKS")
				w(0, "ENDSEC")

				w(0, "SECTION")
					w(2, "ENTITIES")
					for (unsigned int i = 0; i < entities.points.size(); ++i)
					{
						w(0, "POINT")
							w(8, entities.points[i].layer)
							w(10, entities.points[i].x)
							w(20, entities.points[i].y)
							w(30, entities.points[i].z)
					}
					for (auto line : entities.lines)
					{
						w(0, "LINE")
							w(8, line.layer)
							w(39, line.thickness)
							w(62, line.color)
							w(10, line.x1)
							w(20, line.y1)
							w(30, line.z1)
							w(11, line.x2)
							w(21, line.y2)
							w(31, line.z2)
					}
				w(0, "ENDSEC")

				w(0, "EOF")
				#undef w

				file.close();
				return file.good();
			}
			bool cad::open(const string &filename)
			{
				return false;
			}
		}
	}
}