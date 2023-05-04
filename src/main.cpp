//#include <iostream>
#include <vec3.h>

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
            // store as 0 - 1.0 range values
            float r, g, b;
            r = float(i) / float(x);
            g = float(j) / float(y);
            b = 0.3;

            // storing back as 0 - 255 values for logging
            int log_R, log_G, log_B;
            log_R = int(255.00 * r);
            log_G = int(255.00 * g);
            log_B = int(255.00 * b);

            cout << log_R << " " << log_G << " " << log_B << "\n";
        }
    }
}