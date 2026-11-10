#pragma once

#include <iostream>


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
        
        // Assignment Operator
        Point& operator = (const Point& other){
            _show_info("Assignment operator");
            
            if (this == &other){
                return *this;
            }
            this -> x = other.x;
            return *this;
        }
        
        
        
        
    private:
        void _show_info(const std::string& name){
            if (DEBUG) std::cout << name << " of Point is called" << std::endl;
        }
    
    };
}