#pragma once
#include <iostream>
#include <stdexcept>


class Fraction{
private:
    int _nom;
    int _denom;
    
    inline int _gcd (int u, int v) const {
        if (u<0) u=-u;
        if (v<0) v=-v;
        int r;
        while (v != 0){
            r = u%v;
            u=v;
            v=r;
        }
        return u;
    };
    
public:    
    Fraction() : _nom(0), _denom(1) {};
    explicit Fraction(int nom) : _nom(nom), _denom(1) {}
    explicit Fraction(int nom, int denom): _nom(nom), _denom(denom) {
        if (_denom==0){
            throw std::logic_error("The denominator is zero, invaild fraction.");
        }
    }
    
    Fraction(const Fraction& other) : _nom(other._nom), _denom(other._denom) {};
    Fraction& operator= (const Fraction& other){
        if (this == &other){
            return *this;
        }
        
        _nom = other._nom;
        _denom = other._denom;
        
        return *this;
    }
    ~Fraction()=default;
    
    inline int getNom() const { return _nom; }    
    // Returns numerator
    inline int getDenom() const { return _denom; }  
    // Returns denominator
    void print() const {
        std::cout << _nom << "/" << _denom << "\n";
    }   // prints fraction to screen, format a/b
    
    void reduce(){
        int gcd = _gcd(_nom, _denom);
        _nom /= gcd;
        _denom /= gcd;
    }   
    
    // divide numerator and denominator by their gcd
    Fraction reciprocal() const {
        if (_nom==0){
            throw std::logic_error("The numerator is zero, reciprocal does not exist.");
        }
        Fraction res(_denom, _nom);
        res.reduce();
        return res;
    }    
    
    // F.reciprocal returns reciprocal of F
    Fraction add(const Fraction &G) const {
        int nom = _nom * G._denom + _denom * G._nom;
        int denom = _denom * G._denom;
        Fraction res(nom, denom);
        res.reduce();
        return res;
    }
    
    // F.add(G) returns F+G
    Fraction mult(const Fraction& G) const {
        int nom = _nom * G._nom;
        int denom = _denom * G._denom;
        Fraction res(nom, denom);
        res.reduce();
        return res;
    }
};