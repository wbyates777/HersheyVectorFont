Hershey Vector Font (http://paulbourke.net/dataformats/hershey/)

 Based on the Hershey character set

 It is sometimes necessary to have a simple set of characters made up of vectors, 
 the Hershey set of vectors is one of the standard descriptions in the public domain. 
 They were originally created by Dr. A. V. Hershey while working at the U. S. National Bureau of Standards.

 The font set consists of around 2000 characters, there are a number of font styles 
 and sizes as well as many special symbols.
 
 A string when written as Hershey characters using this class, i.e
 
 BHershey::write( buffer,  count, "Hello World" );
 
 results in a std::vector<float> buffer and a std::vector<int> count.  
 These can be rendered efficiently in OpenGL by:
 
 1) Write the buffer to OpenGL memory i.e
 
     glBufferData(GL_ARRAY_BUFFER, buffer.size() * sizeof(float), &buffer[0], GL_STATIC_DRAW);
    
 2) Extract the first index of each line strip
 
     std::vector<int> first.resize(count.size());
     int start = 0;
     for (int i = 0; i < first.size(); ++i) 
     { 
         first[i] = start;
         start += count[i];
     }
 3) Then render using
 
     glMultiDrawArrays(GL_LINE_STRIP, &first[0], &count[0],  count.size());
