//#include <iostream>
#include "ray.h"
using std::cout;


// Function declarations
vec3 color(const ray& r);


// QUICK NOTE LEADING TO THE ADDITION OF A SPHERE FOR RAY TRACING AGAINST:
//  x = (-b ± √(b^2 - 4ac)) / (2a)

int main()
{
    // declare file dimensions
    int x = 300;
    int y = 200;

    // declare file header
    cout << "P3\n" << x << " " << y << "\n255\n";

    // declare viewport
    vec3 lower_left_corner(-2.0, -1.0, -1.0);

    // 
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);

    // camera directional origin point
    vec3 origin(0.0, 0.0, 0.0);


    for ( int j = y - 1; j >= 0; j-- )
    {
        for ( int i = 0; i < x; i++ )
        {
            float u = float(i) / float(x);
            float v = float(j) / float(x);

            ray r( origin, lower_left_corner + u*horizontal + v*vertical );
            vec3 color_val = color(r);

            // storing back as 0 - 255 values for logging
            int log_R, log_G, log_B;
            log_R = int(255.99 * color_val[0]);
            log_G = int(255.99 * color_val[1]);
            log_B = int(255.99 * color_val[2]);

            cout << log_R << " " << log_G << " " << log_B << "\n";
        }
    }
}


// function definitions
   
/*Color lerp between 2 values; default is white and a light blue*/
vec3 color(const ray& r)
{
    vec3 unit_directon = unit_vector( r.direction() );

    float t = 0.5 * (unit_directon.y() + 1.0);

    // blended = (1.0 - t) * start_value + t * end_value, 
    return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}