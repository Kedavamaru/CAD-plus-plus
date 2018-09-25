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

To see an example please read "example_of_use.cpp" (https://github.com/Kedavamaru/CAD-plus-plus/blob/master/example%20of%20use.cpp)

      
# Current state of the library
Currently the library contains facilities for:
- Autocad DXF R12 especification
  - Points
  - Lines
  - Circles
  - Arcs
  - Texts
  - Solids
  
# Future work
More features will be added soon, the order of priority will be:
   - Add the remaining entities to the DXF R12 specification, (circles, arcs, texts, polylines, annotations, and others).
   - Write code to support the STEP format specification.
In this way, most used CAD 2D and CAD 3D exchange formats will be covered.

# Want to contribute?
Of course! Your help is welcome

# Want to implement the code in your software?
Of course! If the GPL license doesn't fit your needs, I'm willing to provide you the code with another license for free, all I ask is a little author attribution. E-mail me.
