#include "point.h"
#include "questions.h"
#include <iostream>

using namespace std;


void q1_1()
{
    // Default constructor. The next line prints 0.
    Shape::Point p1;
    cout << p1.x << '\n'; // 0
    std::cout << "----\n";
    
    // Input constructor. The next line prints 43.
    Shape::Point p2(43);
    cout << p2.x << '\n'; // 43
    std::cout << "----\n";
    
    // Copy constructor. The next line prints 0.
    Shape::Point p3(p1);
    cout << p3.x << '\n'; // 0
    std::cout << "----\n";
    
    // By-value assignment copies the parameter, assigns x, then destroys the parameter.
    // The reference version would print only the assignment message here.
    p3 = p2;
    cout << p3.x << '\n'; // 43
    std::cout << "----\n";
    
    // Input constructor only. C++17 guarantees copy elision here.
    Shape::Point p4 = Shape::Point(40);
    std::cout << "----\n";
    
    // Copy constructor. This declaration creates p5 from the existing p2.
    Shape::Point p5 = p2;
    std::cout << "----\n";
    // Destructors run for p5, p4, p3, p2 and p1, in that order.
}
