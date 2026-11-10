#pragma once


class QuadraticEquation{
// a x**2 + bx + c = 0
private:
    double a;
    double b;
    double c;
    
    double THRESHOLD;
    void _check_a() const;
    double _discriminant() const;
    
public:
    // Constructors, destructors and assignment operator
    QuadraticEquation();
    explicit QuadraticEquation(double _a, double _b, double _c);
    explicit QuadraticEquation(double _a, double _b, double _c, double thres);
    
    QuadraticEquation(const QuadraticEquation& other);
    ~QuadraticEquation();
    QuadraticEquation& operator= (const QuadraticEquation& other);
    
    // Member functions
    void solve() const;
    
};