#include <iostream>
using namespace std;
class circle
{
    float radius;

public:
    void set_radius(float rad)
    {
        radius = rad;
    }
    float get_area()
    {
        return 3.1416 * radius * radius;
    }
    float get_circumfrence()
    {
        return 3.1416 * radius;
    }
};
int main()
{
    circle circle1, circle2;
    circle1.set_radius(4);
    circle2.set_radius(2);
    cout << "area of circle 1 is  " << circle1.get_area() << endl;
    cout << "circumfrence of circle 1 is " << circle1.get_circumfrence() << endl;
    cout << "area of circle 2 is  " << circle2.get_area() << endl;
    cout << "circumfrence of circle 2 is " << circle2.get_circumfrence() << endl;

    return 0;
}
