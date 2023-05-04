#include <iostream>


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
        for ( int k = 0; k < x; k++ )
        {
            float r, g, b;
            r = float(k) / float(x);
            g = float(j) / float(y);
            b = 0.3;

            
        }
    }
}