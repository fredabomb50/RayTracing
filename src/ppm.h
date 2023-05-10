#include <iostream>
using std::cout;

FILE* createPPM( const char* file_name, int x, int y, int color_depth );
void addToPPM( FILE* file, int r, int g, int b );


FILE* createPPM( const char* file_name, int x, int y, int color_depth )
{
    FILE* file = fopen(file_name, "w");
    fprintf(file, "P3\n%i %i\n%i\n", x, y, color_depth);


    return file;
}


void addToPPM( FILE* file, int r, int g, int b )
{
    if (file)
    {
        fprintf( file, "%i %i %i\n", r, g, b );
    }
    
}

void ppm_TEST( int color_depth )
{
    int x = 255;
    int y = 255;
    FILE* ppm_file = createPPM( "test.ppm", x, y, color_depth );

    for ( int j = y - 1; j >= 0; j-- )
    {
        for ( int i = 0; i < x; i++ )
        {
            addToPPM(ppm_file, j, i, x);
        }
    }

    fclose(ppm_file);
}