#include "linear_system.h"
#include <stdexcept>
#include <cmath>
#include <utility>

double SarrusDet(const std::vector<double>& mat){
    if (mat.size() != 9) throw std::invalid_argument("The size of mat should be 9, which means 3x3 matrix");

    double positive = mat[0] * mat[4] * mat[8] 
                        + mat[1] * mat[5] * mat[6] 
                        + mat[2] * mat[3] * mat[7];
    double negative = mat[2] * mat[4] * mat[6] 
                        + mat[0] * mat[5] * mat[7] 
                        + mat[1] * mat[3] * mat[8]; 
                            
             
    return positive - negative;
}


std::vector<double> LinearSystem::_replacedA(int j) const{
    std::vector<double> Aj = A;
    for (int i=0; i<3; ++i){
        Aj[3*i + j] = b[i];
    }
    return Aj;
}


void LinearSystem::solve() const{
    double detA = SarrusDet(A);
    if (std::abs(detA) <= 1e-10){
        sol.clear();
        return;
    }
    std::vector<double> result(3);
    for (size_t i=0; i<3; ++i){
        result[i] = SarrusDet(_replacedA(static_cast<int>(i))) / detA;
    }
    sol = std::move(result);
}


void LinearSystem::print() const{
    if (sol.empty()) std::cout << "No unique solution." << "\n";
    else std::cout << "(" << sol[0] << ", " << 
            sol[1] << ", " << sol[2] << ")\n";
}



