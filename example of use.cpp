#include "cadpp.h"

// cad abstraction following the dxf revision 12 especification
using namespace cadpp::dxf::r12;

int main() {
	cad mycad;

	cad::entities::point point;
	point.layer = "0";
	point.x = 28.5;
	point.y = 0.46;
	point.z = -2.8;

	mycad.entities.points.push_back(point);

	cad::entities::line line;
	line.layer = "0";
	line.thickness = 1.2;
	line.colorindex = 1;
	line.x1 = 29.5;
	line.y1 = 1.46;
	line.z1 = -1.8;
	line.x2 = 39.5;
	line.y2 = 11.46;
	line.z2 = 9.8;

	mycad.entities.lines.push_back(line);

	bool is_all_ok = mycad.save("Example.dxf");

	// if (is_all_ok) Success!
}