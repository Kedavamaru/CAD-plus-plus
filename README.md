# CAD++
CAD plus plus is an includable code, (cadpp.h and cadpp.cpp), where namespaces and classes are provided in order to facilitate the managing of CAD files in different formats.

# Example
CAD++ is organized in the following way:
- Everything is contained in a big 'cadpp' namespace.
- You choose in which format and version you want to represent your model by navigating through namespaces.

So:

If you want to representate your model using de AutoCAD DXF format, in its revision 12, all you need to do is to instantiate the corresponding class:

    cadpp::dxf::r12::cad my_cad_model;

At this point, you are ready to start adding any information that can be represented in the DXF R12 format, like layers, line styles, lines, points, circles, arcs, solids, texts, dimensions, etc and its attributes.

Once you are ready, just write it to a file:

    my_cad_model.save();
    
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
   - Add support for the remaining entities on the DXF R12 specification.
   - Add support the STEP format specification.
   
The main objective is to cover the most used 2D and 3D CAD exchange formats.

# Want to contribute?
Of course! Your help is welcome

# Want to implement the code in your software?
Of course! If the GPL license doesn't fit your needs, I'm willing to provide you the code with another license for free, all I ask is a little author attribution. Just e-mail me.
