#include <iostream>
using std::cout;

FILE* createPPM( const char* file_name, int x, int y, int color_depth );
void saveToPPM( FILE* file, const char* text );


FILE* createPPM( const char* file_name, int x, int y, int color_depth )
{
    //cout << "P3\n" << x << " " << y << "\n255\n";
    FILE* file = fopen(file_name, "w");
    fprintf(file, "PPM\n%i %i\n%i", x, y, color_depth);


    return file;
}


void saveToPPM( FILE* file, const char* text )
{
    if (file)
    {
        fputs( text, file );
    }
    
}