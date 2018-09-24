#include "cadpp.h"

// cad abstraction following the dxf revision 12 especification
using namespace cadpp::dxf::r12;

int main() {
	cad mycad;

	// Create two line types
	cad::tables::ltype linetype1;
		linetype1.name = "Solid";
		linetype1.description = "Solid line";
		linetype1.dash_lengths = { 1.0 };

	cad::tables::ltype linetype2;
		linetype2.name = "Dashed";
		linetype2.description = "Line dashed every 1 mm";
		linetype2.dash_lengths = { 1.0, -1.0 }; // "- "

	mycad.tables.ltypes = { linetype1, linetype2 };

	// Create two layers
	cad::tables::layer layer1;
		layer1.name = "MyLayer1";
		layer1.color = color_blue;
		layer1.ltype = "Solid";

	cad::tables::layer layer2;
		layer2.name = "MyLayer2";
		layer2.color = color_red;
		layer2.ltype = "Dashed";

	mycad.tables.layers = { layer1, layer2 };

	// Create a point
	cad::entities::point point1;
		point1.layer = "MyLayer1";
		point1.x = 28.5;
		point1.y = 0.46;
		point1.z = -2.8;

	mycad.entities.points = { point1 };

	// Create two lines
	cad::entities::line line1;
		line1.layer = "MyLayer1";
		line1.color = color_by_layer;
		line1.thickness = 0.0;
		line1.x1 = -29.5;
		line1.y1 = -1.46;
		line1.z1 = -1.8;
		line1.x2 = 39.5;
		line1.y2 = 11.46;
		line1.z2 = 9.8;

	cad::entities::line line2;
		line2.layer = "MyLayer2";
		line2.color = color_by_layer;
		line2.thickness = 1.0;
		line2.x1 = -29.5;
		line2.y1 = 1.46;
		line2.z1 = -1.8;
		line2.x2 = -39.5;
		line2.y2 = 11.46;
		line2.z2 = -9.8;

	mycad.entities.lines = { line1, line2 };

	bool is_all_ok = mycad.save("Example.dxf");

	// if (is_all_ok) Success!
}