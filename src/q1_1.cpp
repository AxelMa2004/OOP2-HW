#include "point.h"
#include "questions.h"
#include <iostream>

using namespace std;


void q1_1()
{
    Shape::Point p1;
    cout << p1.x << '\n'; // 0
    std::cout << "----\n";
    
    Shape::Point p2(43);
    cout << p2.x << '\n'; // 43
    std::cout << "----\n";
    
    Shape::Point p3(p1);
    cout << p3.x << '\n'; // 0
    std::cout << "----\n";
    
    p3 = p2;
    cout << p3.x << '\n'; // 43
    std::cout << "----\n";
    
    Shape::Point p4 = Shape::Point(40);
    std::cout << "----\n";
    
    Shape::Point p5 = p2;
    std::cout << "----\n";
}