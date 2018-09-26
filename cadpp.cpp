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
			// Write a group code value to a file
			void cv(int code, num value, ofstream &file) { file << code << "\n" << value << "\n"; }
			void cv(int code, dbl value, ofstream &file) { file << code << "\n" << value << "\n"; }
			void cv(int code, str value, ofstream &file) { file << code << "\n" << value << "\n"; }

			cad::cad() {}
			cad::~cad() {}

			bool cad::save(const string &filename)
			{
				ofstream file(filename);

				if (!file.good()) return false;

				cv(0, "SECTION", file); {
					cv(2, "HEADER", file); {
						cv(9, "$ACADVER", file); {
							cv(1, "AC1009", file);
						}
						cv(9, "$INSBASE", file); {
							cv(10, header.insbase.x, file);
							cv(20, header.insbase.y, file);
							cv(30, header.insbase.z, file);
						}
						cv(9, "$EXTMIN", file); {
							cv(10, header.extmin.x, file);
							cv(20, header.extmin.y, file);
							cv(30, header.extmin.z, file);
						}
						cv(9, "$EXTMAX", file); {
							cv(10, header.extmax.x, file);
							cv(20, header.extmax.y, file);
							cv(30, header.extmax.z, file);
						}
					}
					cv(0, "ENDSEC", file);
				}
				cv(0, "SECTION", file); {
					cv(2, "TABLES", file); {
						cv(0, "TABLE", file); {
							cv(2, "LTYPE", file);
							cv(70, (num)tables.ltypes.size(), file);
							for (auto ltype : tables.ltypes)
							{
								cv(0, "LTYPE", file); {
									cv(2, ltype.name, file);
									cv(70, ltype.flags, file);
									cv(3, ltype.dscrp, file);
									cv(72, "65", file);
									cv(73, (num)ltype.dashl.size(), file);
									dbl tdshl = 0.0;
									for (auto dl : ltype.dashl)
									{
										tdshl = (dl > 0) ? tdshl + dl : tdshl - dl;
									}
									cv(40, tdshl, file);
									for (auto dl : ltype.dashl)
									{
										cv(49, dl, file);
									}
								}
							}
							cv(0, "ENDTAB", file);
						}
						cv(0, "TABLE", file); {
							cv(2, "LAYER", file);
							cv(70, (num)tables.layers.size(), file);
							for (auto layer : tables.layers)
							{
								cv(0, "LAYER", file); {
									cv(2, layer.name, file);
									cv(70, layer.flags, file);
									cv(62, layer.color, file);
									cv(6, layer.ltype, file);
								}
							}
							cv(0, "ENDTAB", file);
						}
						cv(0, "TABLE", file); {
							cv(2, "STYLE", file);
							cv(70, (num)tables.styles.size(), file);
							for (auto style : tables.styles)
							{
								cv(0, "STYLE", file);
								{
									cv(2, style.name, file);
									num flags = 4 * style.vrtcl;
									cv(70, flags, file);
									cv(40, style.h, file);
									cv(41, style.wdthf, file);
									cv(50, style.incln, file);
									num gflgs = style.mirry * 4 + style.mirrx * 2;
									cv(71, gflgs, file);
									cv(42, "1", file);
									cv(3, style.nfont, file);
									cv(4, style.bfont, file);
								}
							}
							cv(0, "ENDTAB", file);
						}
					}
					cv(0, "ENDSEC", file);
				}
				cv(0, "SECTION", file); {
					cv(2, "BLOCKS", file); {
					}
					cv(0, "ENDSEC", file);
				}
				cv(0, "SECTION", file); {
					cv(2, "ENTITIES", file); {
						for (auto point : entities.points)
						{
							cv(0, "POINT", file); {
								cv(8, point.layer, file);
								cv(10, point.x, file);
								cv(20, point.y, file);
								cv(30, point.z, file);
							}
						}
						for (auto line : entities.lines)
						{
							cv(0, "LINE", file); {
								cv(8, line.layer, file);
								cv(6, line.ltype, file);
								cv(62, line.color, file);
								cv(10, line.xi, file);
								cv(20, line.yi, file);
								cv(30, line.zi, file);
								cv(11, line.xf, file);
								cv(21, line.yf, file);
								cv(31, line.zf, file);
							}
						}
						for (auto circle : entities.circles)
						{
							cv(0, "CIRCLE", file); {
								cv(8, circle.layer, file);
								cv(6, circle.ltype, file);
								cv(62, circle.color, file);
								cv(10, circle.xc, file);
								cv(20, circle.yc, file);
								cv(30, circle.zc, file);
								cv(40, circle.r, file);
							}
						}
						for (auto arc : entities.arcs)
						{
							cv(0, "ARC", file); {
								cv(8, arc.layer, file);
								cv(6, arc.ltype, file);
								cv(62, arc.color, file);
								cv(10, arc.xc, file);
								cv(20, arc.yc, file);
								cv(30, arc.zc, file);
								cv(40, arc.r, file);
								cv(50, arc.angli, file);
								cv(51, arc.anglf, file);
							}
						}
						for (auto solid : entities.solids)
						{
							cv(0, "SOLID", file); {
								cv(8, solid.layer, file);
								cv(6, solid.ltype, file);
								cv(62, solid.color, file);
								cv(10, solid.x1, file);
								cv(20, solid.y1, file);
								cv(30, solid.z1, file);
								cv(11, solid.x2, file);
								cv(21, solid.y2, file);
								cv(31, solid.z2, file);
								cv(12, solid.x3, file);
								cv(22, solid.y3, file);
								cv(32, solid.z3, file);
								cv(13, solid.x4, file);
								cv(23, solid.y4, file);
								cv(33, solid.z4, file);
							}
						}
						for (auto text : entities.texts)
						{
							cv(0, "TEXT", file); {
								num gflgs;

								cv(8, text.layer, file);
								cv(6, text.ltype, file);
								cv(62, text.color, file);
								cv(10, text.ix, file);
								cv(20, text.iy, file);
								cv(30, text.iz, file);
								if (text.override_style)
								{
									cv(40, text.h, file);
								}
								else
								{
									cv(40, text.style.h, file);
								}
								cv(1, text.cntnt, file);
								cv(50, text.rotat, file);
								if (text.override_style)
								{
									cv(41, text.wdthf, file);
									cv(51, text.incln, file);
									gflgs = text.mirry * 4 + text.mirrx * 2;
								}
								else
								{
									cv(41, text.style.wdthf, file);
									cv(51, text.style.incln, file);
									gflgs = text.style.mirry * 4 + text.style.mirrx * 2;
								}
								cv(7, text.style.name, file);
								cv(71, gflgs, file);
								cv(72, text.jstfh, file);
								cv(73, text.jstfv, file);
								cv(11, text.ax, file);
								cv(21, text.ay, file);
								cv(31, text.az, file);
							}
						}
					}
					cv(0, "ENDSEC", file);
				}
				cv(0, "EOF", file);

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
