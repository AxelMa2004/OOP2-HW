#include "fraction.h"
#include <iostream>
#include <stdexcept>

Fraction::Fraction(): _nom(0), _denom(1) {}
Fraction::Fraction(int nom): _nom(nom), _denom(1) {}
Fraction::Fraction(int nom, int denom): _nom(nom), _denom(denom) {
    if (_denom==0){
        std::logic_error("The denominator is zero, invaild fraction.");
    }
}
Fraction::Fraction(const Fraction& other): _nom(other._nom), _denom(other._denom) {}
Fraction& Fraction::operator= (const Fraction& other){
    if (this == &other){
        return *this;
    }
    
    _nom = other._nom;
    _denom = other._denom;
    
    return *this;
}


int Fraction::_gcd (int u, int v) const {
    if (u<0) u=-u;
    if (v<0) v=-v;
    int r;
    while (v != 0){
        r = u%v;
        u=v;
        v=r;
    }
    return u;
}


void Fraction::print() const{
    std::cout << _nom << "/" << _denom << "\n";
}

void Fraction::reduce(){
    int gcd = _gcd(_nom, _denom);
    _nom /= gcd;
    _denom /= gcd;
}

Fraction Fraction::reciprocal() const{
    if (_nom==0){
        std::logic_error("The numerator is zero, reciprocal does not exist.");
    }
    return Fraction(_denom, _nom);
}

Fraction Fraction::add(const Fraction &G) const{
    int nom = _nom * G._denom + _denom * G._nom;
    int denom = _denom * G._denom;
    return Fraction(nom, denom);
}


Fraction Fraction::mult(const Fraction& G) const{
    int nom = _nom * G._nom;
    int denom = _denom * G._denom;
    return Fraction(nom, denom);
}

