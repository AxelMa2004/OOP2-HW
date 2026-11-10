#pragma once

#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
#include <ostream>
#include <stdexcept>
#include <string>

using namespace std;

class Matrix {
 private:
  int n;                   // number of rows
  int m;                   // number of columns
  vector<double> entries;  // entry in row i and column j
                           // is entries[(i-1)*m + j-1]
                           
  std::string _to_string() const;
  static std::size_t _entry_count(int rows, int columns);
 public:
  // constructors to support following creation.
  // Matrix A1(2, 2, {1, 2, 3, 4});

  
  /*
  ================
  Constructor
  ================
  */
  
  // Matrix A3;           // empty matrix of 0x0
  Matrix();  
  
  // Matrix A4(2, 2);     // matrix of 2x2 with all entries =0
  explicit Matrix(int _n, int _m);   
  
  // Matrix A5(2, 2, 1.); // matrix of 2x2 with all entries =1.
  explicit Matrix(int _n, int _m, double val);
  
  // vector<double> vd{1, 2, 3, 4};
  // Matrix A2(2, 2, vd);
  explicit Matrix(int _n, int _m, std::vector<double> vd);
 
  Matrix(const Matrix& B);  // Optional. vector already provides a deep copy.

  Matrix& operator=(const Matrix& B);  // Optional. Member-wise assignment is sufficient.

  ~Matrix();  // Optional. The vector member releases its own memory.

  inline int rows() const { return n; }                        // returns n
  inline int columns() const { return m; }                     // returns m
  inline double get_entry(int i, int j) const {
    if (i < 1 || i > n || j < 1 || j > m)
      throw std::out_of_range("Invalid matrix coordinates.");
    return entries[static_cast<std::size_t>(i - 1) * m + j - 1];
  }
  inline void set_entry(int i, int j, double x) {
    if (i < 1 || i > n || j < 1 || j > m)
      throw std::out_of_range("Invalid matrix coordinates.");
    entries[static_cast<std::size_t>(i - 1) * m + j - 1] = x;
  }
  
  void print() const;                      // prints matrix to the screen row-wise

  Matrix operator+(const Matrix& B) const;
  Matrix operator-(const Matrix& B) const;
  Matrix operator*(const Matrix& B) const;
  
  bool operator==(const Matrix& B) const;
  
  friend std::ostream& operator<<(std::ostream& oss, const Matrix& A);
  friend Matrix triple_add(const Matrix& m1, const Matrix& m2, const Matrix& m3);
};







