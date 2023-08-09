#include "my.h"
#include "std_lib_facilities.h"

int main()
{   
    print_foo();
    print(99);
    //try calling each swap like this...
    int x = 7;
    int y = 9;
    swap_r(x, y);
    // The values were swapped so prints x: 9, y: 7
    cout << "value of x: " << x << "\n";
    cout << "value of y: " << y << "\n";
    // This is pointless, and will only work if we pass by value. 
    swap_v(7, 9); 
    // Not surprising. Not even a little.
    cout << "value of 7: " << 7 << "\n";
    // Pass by value and watch it not work.
    const int cx = 7;
    const int cy = 9;
    swap_v(cx, cy);
    // Prints 7 and then 9. 
    cout << "value of cx: " << cx << "\n";
    cout << "value of cy: " << cy << "\n";
    // What are we trying to accomplish here?
    swap_v(7.7, 9.9);
    double dx = 7.7;
    double dy = 9.9;
    // this won't work because they are doubles. 
    // I will create a function of the same name that works for doubles. 
    swap_r(dx, dy);
    swap_v(7.7, 9.9);
    // Prints 9.9 and then 7.7
    cout << "value of dx: " << dx << "\n";
    cout << "value of dy: " << dy << "\n";
    
    return 0;
}
