/* BHershey 24/11/2022

 $$$$$$$$$$$$$$$$$$
 $   BHershey.h   $
 $$$$$$$$$$$$$$$$$$

 by W.B. Yates
 Copyright (c) W.B. Yates. All rights reserved.
 History:

 Hershey Vector Font (http://paulbourke.net/dataformats/hershey/)

 Based on the Hershey character set

 "It is sometimes necessary to have a simple set of characters made up of vectors, 
 the Hershey set of vectors is one of the standard descriptions in the public domain. 
 They were originally created by Dr. A. V. Hershey while working at the U. S. National Bureau of Standards.

 The font set consists of around 2000 characters, there are a number of font styles 
 and sizes as well as many special symbols.
 
 The structure is basically as follows: 
 each character consists of a number 1->4000 (not all used) in column 0:4, 
 the number of vertices in columns 5:7, 
 the left hand position in column 8, the right hand position in column 9, and 
 finally the vertices in single character pairs. 
 
 All coordinates are given relative to the ascii value of 'R'. 
 If the coordinate value is " R" that indicates a pen up operation.

 As an example consider the 8th symbol

     8  9MWOMOV RUMUV ROQUQ
 
 It has 9 coordinate pairs (this includes the left and right position).
 
 The left position is 'M' - 'R' = -5
 The right position is 'W' - 'R' = 5
 The first coordinate is "OM" = (-3,-5)
 The second coordinate is "OV" = (-3,4)
 Raise the pen " R"
 Move to "UM" = (3,-5)
 Draw to "UV" = (3,4)
 Raise the pen " R"
 Move to "OQ" = (-3,-1)
 Draw to "UQ" = (3,-1)
 Drawing this out on a piece of paper will reveal it represents an 'H'."
 
                    -----------------
 
 A string when written as Hershey characters using
 
 BHershey::write( buffer,  count, "Hello World" );
 
 results in a std::vector<float> buffer and a std::vector<int> count  
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

*/


#ifndef __BHERSHEY_H__
#define __BHERSHEY_H__


#include <string>
#include <vector>


class BHershey
{
public:

    enum Font 
    {
        Roman_Simplex, Roman_Duplex, Roman_Triplex, Roman_Plain, Roman_Complex, Roman_Complex_Small,
        Greek_Simplex, Greek_Plain, Greek_Complex, Greek_Complex_Small,
        Script_Simplex, Script_Complex,
        Italic_Triplex, Italic_Complex, Italic_Complex_Small, 
        Gothic_English_Triplex, Gothic_German_Triplex, Gothic_Italian_Triplex, Max_Font
    };
    
    BHershey( void )=default;
    ~BHershey( void )=default;

    static std::pair<float,float> 
    dimensions( const std::string& str, float font_size = 1.0, Font font = Roman_Duplex );
    
    static std::pair<float,float> 
    write( std::vector<float>& buffer, std::vector<int>& count, 
           const std::string& str, float font_size = 1.0, Font font = Roman_Duplex, 
           float x = 0.0, float y = 0.0, float z = 0.0 );
    
private:

    // magic Hershey font scaling
    static const double SFONTSCALE;
    
    // all 4000 Hershey codes (max height = 16);
    static const char * const m_hershey_codes[4000];
    static const short * const m_font[18];

    
    // fonts - ASCII mappings - index 0 -> ASCII 32 ('space') - 96 characters per font
    static const short m_roman_simplex[96];
    static const short m_roman_duplex[96];
    static const short m_roman_triplex[96];
    static const short m_roman_plain[96];
    static const short m_roman_complex[96];
    static const short m_roman_complex_small[96];

    static const short m_greek_simplex[96];
    static const short m_greek_plain[96];
    static const short m_greek_complex[96];
    static const short m_greek_complex_small[96];

    static const short m_script_simplex[96];
    static const short m_script_complex[96];
    
    static const short m_italic_triplex[96];
    static const short m_italic_complex[96];
    static const short m_italic_complex_small[96];

    static const short m_gothic_english_triplex[96];
    static const short m_gothic_german_triplex[96];
    static const short m_gothic_italian_triplex[96];

};

#endif


