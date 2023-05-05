//#include <iostream>
#include "vec3.h"

using std::cout;

int main()
{
    // declare file dimensions
    int x = 200;
    int y = 100;

    // declare file header
    cout << "P3\n" << x << " " << y << "\n255\n";

    for ( int j = y - 1; j >= 0; j-- )
    {
        for ( int i = 0; i < x; i++ )
        {
            vec3 color( (float(i) / float(x)), (float(j) / float(y)), 0.3 );

            // storing back as 0 - 255 values for logging
            int log_R, log_G, log_B;
            log_R = int(255.00 * color[0]);
            log_G = int(255.00 * color[1]);
            log_B = int(255.00 * color[2]);

            cout << log_R << " " << log_G << " " << log_B << "\n";
        }
    }
}