Hershey Vector Font (http://paulbourke.net/dataformats/hershey/)

 Based on the Hershey character set

 It is sometimes necessary to have a simple set of characters made up of vectors, 
 the Hershey set of vectors is one of the standard descriptions in the public domain. 
 They were originally created by Dr. A. V. Hershey while working at the U. S. National Bureau of Standards.

 The font set consists of around 2000 characters, there are a number of font styles 
 and sizes as well as many special symbols.
 
 A string when written as Hershey characters using this class, i.e
 
 BHershey::write( buffer,  count, "Hello World" );
 
 results in a std::vector<float> buffer and a std::vector<int> count  
 These can be rendered efficiently in OpenGL (see code comments for details).
