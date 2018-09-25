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
#include <list>
#include <cmath>

namespace cadpp
{
	namespace dxf
	{
		namespace r12
		{
			using std::string;
			using std::list;
			using std::ofstream;

			using num = long long int;
			using dbl = long double;
			using str = string;

			namespace constants
			{
				// PI constant:
				//	float       f = std::acos(-1.0f);
				//	double      d = std::acos(-1.0 );
				//	long double l = std::acos(-1.0l);

				namespace color
				{
					// AutoCAD Color Index  (ACI)
					constexpr num red      =   1;
					constexpr num yellow   =   2;
					constexpr num green    =   3;
					constexpr num cyan     =   4;
					constexpr num blue     =   5;
					constexpr num pink     =   6;
					constexpr num mono     =   7; // Index 7 = (background_color != white)? white : black;
					constexpr num by_block =   0;
					constexpr num by_layer = 256;
				}
			}

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
					extmin  extmin ;
					extmax  extmax ;
				};
				class tables
				{
				public:
					class ltype
					{
					public:
						str name  = "continuous";
						str dscrp = "";
						num flags = 0;

						list<dbl> dashl;
					};
					class layer
					{
					public:
						str name  = "default";
						num flags = 0;
						num color = constants::color::mono;
						str ltype = "continuous";
					};
					class style
					{
					public:
					};
					class dimstyle
					{
					public:
						/*str name = "default";
						num flags = 0;
						str dimpost = "";
						str dimapost = "";
						str dimblk = "";
						str dimblk1 = "";
						str dimblk2 = "";
						num dimscale = 0;
						num dimasz = 0;
						num dimexo = 0;
						num dimdli = 0;
						num dimexe = 0;
						num dimmd = 0;
						num dimdle = 0;
						num dimtp = 0;
						num dimtm = 0;
						dbl dimtxt = 0;
						dbl dimcen = 0;
						dbl dimtsz = 0;
						dbl dimaltf = 0;
						dbl dimifac = 0;
						dbl dimtvp = 0;
						dbl dimtfac = 0;
						dbl dimgap = 0;
						num dimtol = 0;
						num dimlim = 0;
						num dimtih = 0;
						num dimtoh = 0;
						num dimsel = 0;
						num dimse2 = 0;
						num dimtad = 0;
						num dimzin = 0;
						num dimalt = 0;
						num dimaltd = 0;
						num dimtofl = 0;
						num dimsah = 0;
						num dimtix = 0;
						num dimsoxd = 0;
						num dimcird = 0;
						num dimcire = 0;
						num dimclrt = 0;*/
					};

					list<ltype>    ltypes    = { ltype()    };
					list<layer>    layers    = { layer()    };
					list<style>    styles    = {};
					list<dimstyle> dimstyles = {};
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
						dbl x     = 0.0;
						dbl y     = 0.0;
						dbl z     = 0.0;
					};
					class line
					{
					public:
						str layer = "default";
						str ltype = "BYLAYER";
						num color = constants::color::by_layer;
						dbl xi    = 0.0;
						dbl yi    = 0.0;
						dbl zi    = 0.0;
						dbl xf    = 0.0;
						dbl yf    = 0.0;
						dbl zf    = 0.0;
					};
					class circle
					{
					public:
						str layer = "default";
						str ltype = "BYLAYER";
						num color = constants::color::by_layer;
						dbl xc    = 0.0;
						dbl yc    = 0.0;
						dbl zc    = 0.0;
						dbl r     = 0.0;
					};
					class arc
					{
					public:
						str layer = "default";
						str ltype = "BYLAYER";
						num color = constants::color::by_layer;
						dbl xc    = 0.0;
						dbl yc    = 0.0;
						dbl zc    = 0.0;
						dbl r = 0.0;
						dbl angli = 0.0;
						dbl anglf = 0.0;
					};
					class solid
					{
					public:
						str layer = "default";
						str ltype = "BYLAYER";
						num color = constants::color::by_layer;
						dbl x1 = 0.0;
						dbl y1 = 0.0;
						dbl z1 = 0.0;
						dbl x2 = 0.0;
						dbl y2 = 0.0;
						dbl z2 = 0.0;
						dbl x3 = 0.0;
						dbl y3 = 0.0;
						dbl z3 = 0.0;
						dbl x4 = 0.0;
						dbl y4 = 0.0;
						dbl z4 = 0.0;
					};
					class text
					{
					public:
						str layer = "default";
						str ltype = "BYLAYER";
						num color = constants::color::by_layer;
						dbl ix    = 0.0;
						dbl iy    = 0.0;
						dbl iz    = 0.0;
						dbl h     = 1.0;
						str textv  = "";
						dbl rotat = 0.0;
						dbl incln = 0.0;
						str style = "default";
						num flags = 0;
						num jstfh = 1;
						num jstfv = 2;
						dbl ax    = 0.0;
						dbl ay    = 0.0;
						dbl az    = 0.0;
					};
					class dimension
					{
					public:
					};

					list<arc>       arcs;
					list<line>      lines;
					list<text>      texts;
					list<point>     points;
					list<solid>     solids;
					list<circle>    circles;
					list<dimension> dimensions;
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
	}
}
#endif // cadstream_h

