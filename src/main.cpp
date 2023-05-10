#include "header.h"
#include <iostream>
#include "ray.h"
using std::cout;


// ===============================================
//          FUNCTION DECLARATIONS
// ===============================================
vec3 color(const ray& r);
bool hit_sphere( const vec3& center, float radius, const ray& r);


// quadratic formula:
//  x = (-b ± √(b^2 - 4ac)) / (2a)


int main()
{
    // declare file dimensions
    int x = 200;
    int y = 100;

    // declare file header
    FILE* test_file = createPPM( "test.ppm", x, y, 255 );

    // declare viewport
    vec3 lower_left_corner(-2.0, -1.0, -1.0);

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

            addToPPM(test_file, log_R, log_G, log_B);
        }
    }

    // free resources
    fclose(test_file);
}


// ===============================================
//          FUNCTION DEFINITIONS
// ===============================================
   
/*Color lerp between 2 values; default is white and a light blue*/
vec3 color(const ray& r)
{
    // check to see if ray collides with theoretical sphere, and return that color instead
    if ( hit_sphere(vec3(0, 0, -1), 0.5, r) ) { return vec3(1, 0, 0); }


    vec3 unit_directon = unit_vector( r.direction() );
    float t = 0.5 * (unit_directon.y() + 1.0);

    // blended = (1.0 - t) * start_value + t * end_value, 
    return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}


// Generate a hypothetical sphere at center and of radius
bool hit_sphere( const vec3& center, float radius, const ray& r)
{
    vec3 oc = r.origin() - center;
    float a, b, c;
    a = dot(r.direction(), r.direction());
    b = 2.0 * dot(oc, r.direction());
    c = dot(oc, oc) - radius*radius;
    float discriminant = b*b - 4*a*c;

    return (discriminant > 0);
}