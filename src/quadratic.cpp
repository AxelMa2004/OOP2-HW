#include "quadratic.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

QuadraticEquation::QuadraticEquation(): a(1.0), b(0.0), c(0.0), THRESHOLD(1e-10) {
    _check_a();
}
                        
QuadraticEquation::QuadraticEquation(double _a, double _b, double _c):
                    a(_a), b(_b), c(_c), THRESHOLD(1e-10) {
    _check_a();                        
}

QuadraticEquation::QuadraticEquation(double _a, double _b, double _c, double thres):
                    a(_a), b(_b), c(_c), THRESHOLD(thres) {
    _check_a();                       
}

QuadraticEquation::QuadraticEquation(const QuadraticEquation& other):
    a(other.a), b(other.b), c(other.c), THRESHOLD(other.THRESHOLD) {
    _check_a();
}

QuadraticEquation::~QuadraticEquation() {}
                    
double QuadraticEquation::_discriminant() const{
    return b*b - 4.0*a*c;
}

void QuadraticEquation::_check_a() const{
    if (a == 0.0){
        throw std::invalid_argument("a must be nonzero.");
    }
}

QuadraticEquation& QuadraticEquation::operator= (const QuadraticEquation& other){
    if (this == &other){
        return *this;
    }
    
    a = other.a;
    b = other.b;
    c = other.c;
    THRESHOLD = other.THRESHOLD;
    
    return *this;
}

void QuadraticEquation::solve() const{
    double discriminant = _discriminant();
    std::cout << "Equation: " << a << " x^2 + " << b << " x + " << c << "\n"; 
    if (discriminant < -THRESHOLD){
        std::cout << "No real solution..." << "\n";
    }
    else if(discriminant <= THRESHOLD){
        std::cout << "Unique solution: " << -b / (2*a) << "\n";
    }
    else{
        std::cout << "Solution 1: " << (-b+std::sqrt(discriminant)) / (2*a)  
                  << "; Solution 2: " << (-b-std::sqrt(discriminant)) / (2*a) 
                  << "\n";
    }
}
