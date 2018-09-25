# CAD++
CAD plus plus is an includable code, (cadpp.h and cadpp.cpp), where namespaces and classes are provided in order to facilitate the managing of CAD files in different formats.

# Example
CAD++ is organized in the following way:
- Everything is contained in a big 'cadpp' namespace.
- You choose in which format and version you want to represent your model by navigating through namespaces.

So:

If you want to representate your model using de AutoCAD DXF format, in its revision 12, all you need to do is to instantiate the corresponding class:

    cadpp::dxf::r12::cad my_cad_model;

At this point, you are ready to start adding any information that can be represented in the DXF R12 format, like layers, line styles, lines, points, circles, arcs, solids, texts, dimensions, etc and its attributes. The following is an example of how to add a point to your model:

    // Create a circle
	cad::entities::circle circle1;
		circle1.layer = "MyLayer1";                  // On layer 'MyLayer1'
		circle1.ltype = "BYLAYER";                   // With line type defined 'by layer'
		circle1.color = constants::color::red;       // With red color
		circle1.xc = 3.96;                           // With given center coordinates
		circle1.yc = 5.25;
		circle1.zc = -2.3;
		circle1.r = 10.1;                            // And given radious

    // Remember to add it to the list container for circles
	my_cad_model.entities.circles.push_back(circle1);

Once you've added everything, just write it to a file!:

    my_cad_model.save("my_cad_model_file.dxf");
    
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
