# CAD++
CAD plus plus is an includable code, (cadpp.h and cadpp.cpp), where namespaces and classes are provided in order to facilitate the managing of CAD files in different formats.

# Example
CAD++ is organized in the following way:
- Everything is contained in a big 'cadpp' namespace.
- You choose in which format and version you want to represent your model by navigating through namespaces.

So:

If you want to representate your model using de AutoCAD DXF format, in its version (revision) 12, all you need to do is to instantiate the corresponding class:

  cadpp::dxf::r12::cad my_cad_model;

At this point, you are ready to start adding any information that can be represented in the DXF format revision 12, which include points, lines, circles, texts, etc.

In the following example a cad model containing a point and a line is created, and then written to a file:

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
      
# Current state of the library
Currently the library contains facilities for:
- Autocad DXF R12 especification
  - Points
  - Lines
  
# Future work
More features will be added soon, the order of priority will be:
   - Add the remaining entities to the DXF R12 specification, (circles, arcs, texts, polylines, annotations, and others).
   - Write code to support the STEP format specification.
In this way, most used CAD 2D and CAD 3D exchange formats will be covered.

# Want to contribute?
Of course! Your help is welcome

# Want to implement the code in your software?
Of course! If the GPL license doesn't fit your needs, I'm willing to provide you the code with another license for free, all I ask is a little author attribution. E-mail me.
