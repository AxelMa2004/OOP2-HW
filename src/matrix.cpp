#include "matrix.h"
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <sstream>

Matrix::Matrix(): n(0), m(0), entries(0) {}  
Matrix::Matrix(int _n, int _m): n(_n), m(_m), entries(n*m) {};
Matrix::Matrix(int _n, int _m, double val): n(_n), m(_m), entries(n*m, val) {};
Matrix::Matrix(int _n, int _m, std::vector<double> vd): n(_n), m(_m), entries(vd) {};
Matrix::Matrix(const Matrix& B) : n(B.n), m(B.m), entries(B.entries) {}

Matrix& Matrix::operator=(const Matrix& B){
    if (this == &B){
        return *this;
    }
    
    n = B.n;
    m = B.m;
    entries = B.entries;
    return *this;
}

Matrix::~Matrix() {}

 // prints matrix to the screen row-wise
std::string Matrix::_to_string() const{
    std::stringstream oss;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            oss << std::setw(10) << get_entry(i, j) << " ";
        }
        oss << "\n";
    }
    return oss.str();
}


void Matrix::print() const {
    std::cout << _to_string();
}


std::ostream& operator<<(std::ostream& oss, const Matrix& A){
    oss << A._to_string();
    return oss;
}



Matrix Matrix::operator+(const Matrix& B) const{
    if ((rows() != B.rows()) || (columns() != B.columns())){
        throw std::logic_error("Matrix dimensions must agree for addition.");
    }
    
    Matrix result(n, m);
    for (std::size_t i = 0; i < entries.size(); ++i){
        result.entries[i] = entries[i] + B.entries[i];
    }
                    
    return result;
}


Matrix Matrix::operator-(const Matrix& B) const{
    if ((rows() != B.rows()) || (columns() != B.columns())){
        throw std::logic_error("Matrix dimensions must agree for subtraction.");
    }
    
    Matrix result(n, m);
    for (std::size_t i = 0; i < entries.size(); ++i){
        result.entries[i] = entries[i] - B.entries[i];
    }
                    
    return result;
}


Matrix Matrix::operator*(const Matrix& B) const{
    if (columns() != B.rows()) {
        throw std::logic_error("Matrix dimensions do not match for multiplication.");
    }
    
    int p = B.columns();
    Matrix C(n, p, 0.0);
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= p; ++j) {
            double sum = 0.0;

            for (int k = 1; k <= m; ++k) {
                sum += get_entry(i, k) * B.get_entry(k, j);
            }
            C.set_entry(i, j, sum);
        }
    }
    return C;
    
}


bool Matrix::operator==(const Matrix& B) const{
    if ((rows() != B.rows()) || (columns() != B.columns())) {
        return false;
    }
    
    for (size_t k=0; k<entries.size(); ++k){
        if (std::abs(entries[k] - B.entries[k]) >= 1e-10) return false;
    }
    return true;
}

Matrix triple_add(const Matrix& m1, const Matrix& m2, const Matrix& m3){
    const auto rows = m1.rows();
    const auto cols = m1.columns();

    if (m2.rows() != rows || m2.columns() != cols ||
        m3.rows() != rows || m3.columns() != cols) {
        throw std::logic_error("All three matrices must have the same dimensions.");
    }
    
    Matrix result(rows, cols);
    for (std::size_t i = 0; i < m1.entries.size(); ++i) {
        result.entries[i] = m1.entries[i] + m2.entries[i] + m3.entries[i];
    }

    return result;
}