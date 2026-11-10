#pragma once

class Fraction{
private:
    int _nom;
    int _denom;
    
    int _gcd (int u, int v) const;
public:    
    Fraction();
    explicit Fraction(int nom);
    explicit Fraction(int nom, int denom);
    Fraction(const Fraction& other);
    Fraction& operator= (const Fraction& other);
    ~Fraction()=default;
    
    inline int getNom() const { return _nom; }    
    // Returns numerator
    inline int getDenom() const { return _denom; }  
    // Returns denominator
    void print() const;   // prints fraction to screen, format a/b
    void reduce();    
    // divide numerator and denominator by their gcd
    Fraction reciprocal() const;    
    // F.reciprocal returns reciprocal of F
    Fraction add(const Fraction &G) const;   
    // F.add(G) returns F+G
    Fraction mult(const Fraction& G) const;
};