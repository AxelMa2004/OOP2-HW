#pragma once

#include <iostream>
#include <string>


namespace Shape{
    static bool DEBUG = true; 

    class Point{
    public:
        int x;
        
        // Constructors
        Point(): x(0) {
            _show_info("Default constructor");
        }
        
        explicit Point(int _x): x(_x) {
            _show_info("Input constructor");
        }
        
        Point(const Point& other): x(other.x) {
            _show_info("Copy constructor");
        }
        
        ~Point() {
            _show_info("Destructor");
        }
        
        // The reference version for comparison is operator=(const Point& other).
        // Question 1-1 also asks us to test a by-value parameter.
        Point& operator = (const Point other){
            _show_info("Assignment operator");
            this -> x = other.x;
            return *this;
        }
        
        
        
        
    private:
        void _show_info(const std::string& name){
            if (DEBUG) std::cout << name << " of Point is called" << std::endl;
        }
    
    };
}
