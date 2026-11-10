#pragma once
#include <vector>
#include <iostream>

double SarrusDet(const std::vector<double> mat);

class LinearSystem {
private:
    std::vector<double> A;   
    std::vector<double> b;
    //(i,j) entry of matrix is A[3*(i-1)+j-1], i,j = 1,2,3
    mutable std::vector<double> sol;
    
    std::vector<double> _replacedA(int j) const;  // Aj
public:
    LinearSystem(std::vector<double> A, std::vector<double> b):
    A(A), b(b) {} // Initializes member A from parameter A, member b from parameter b
    
    void solve() const;
    // Sets sol to solution of Ax=b if abs(det(A)) > 1e-10
    // and sets sol to empty vector otherwise
    void print() const;
    //Prints solution to the screen;
    //if sol is empty, then prints message to the
    //screen that there is no unique solution
};