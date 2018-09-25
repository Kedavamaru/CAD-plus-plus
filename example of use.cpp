#include "cadpp.h"

// cad abstraction following the dxf revision 12 especification
using namespace cadpp::dxf::r12;

int main() {
	cad mycad;

	// Create two line types
	cad::tables::ltype linetype1;
		linetype1.name = "Solid";
		linetype1.dscrp = "Solid line";
		linetype1.dashl = { 1.0 }; // "-"

	mycad.tables.ltypes.push_back(linetype1);

	cad::tables::ltype linetype2;
		linetype2.name = "Dashed";
		linetype2.dscrp = "Line dashed every 1 mm";
		linetype2.dashl = { 1.0, -1.0 }; // "- "

	mycad.tables.ltypes.push_back(linetype2);

	// Create two layers
	cad::tables::layer layer1;
		layer1.name = "MyLayer1";
		layer1.color = constants::color::blue;
		layer1.ltype = "Solid";
		
	mycad.tables.layers.push_back(layer1);

	cad::tables::layer layer2;
		layer2.name = "MyLayer2";
		layer2.color = constants::color::green;
		layer2.ltype = "Dashed";
		
	mycad.tables.layers.push_back(layer2);

	// Create a point
	cad::entities::point point1;
		point1.layer = "MyLayer1";
		point1.x = 28.5;
		point1.y = 0.46;
		point1.z = -2.8;

	mycad.entities.points.push_back(point1);

	// Create two lines
	cad::entities::line line1;
		line1.layer = "MyLayer1";
		line1.ltype = "BYLAYER";
		line1.color = constants::color::by_layer;
		line1.xi = -29.5;
		line1.yi = -1.46;
		line1.zi = -1.8;
		line1.xf = 39.5;
		line1.yf = 11.46;
		line1.zf = 9.8;

	mycad.entities.lines.push_back(line1);

	cad::entities::line line2;
		line2.layer = "MyLayer2";
		line2.ltype = "BYLAYER";
		line2.color = constants::color::by_layer;
		line2.xi = -29.5;
		line2.yi = 1.46;
		line2.zi = -1.8;
		line2.xf = -39.5;
		line2.yf = 11.46;
		line2.zf = -9.8;
		
	mycad.entities.lines.push_back(line2);

	// Create a circle
	cad::entities::circle circle1;
		circle1.layer = "MyLayer1";
		circle1.ltype = "BYLAYER";
		circle1.color = constants::color::by_layer;
		circle1.xc = 3.9;
		circle1.yc = 5.25;
		circle1.zc = -2.3;
		circle1.r = 10.1;

	mycad.entities.circles.push_back(circle1);

	// Create an arc
	cad::entities::arc arc1;
		arc1.layer = "MyLayer2";
		arc1.ltype = "BYLAYER";
		arc1.color = constants::color::by_layer;
		arc1.xc = -3.9;
		arc1.yc = -5.25;
		arc1.zc = 2.3;
		arc1.r = 10.1;
		arc1.angli = 45;
		arc1.anglf = 283.2;
		
	mycad.entities.arcs.push_back(arc1);

	bool is_all_ok = mycad.save("Example.dxf");

	// if (is_all_ok) Success!
}