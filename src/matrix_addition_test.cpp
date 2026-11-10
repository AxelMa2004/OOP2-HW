#include "questions.h"
#include "matrix.h"
#include "timer.h"

#include <cstddef>
#include <random>
#include <stdexcept>


std::vector<double> random_vector(
    std::size_t size, double min_value = 0, double max_value = 100) {
    if (min_value > max_value) {
        throw std::invalid_argument("min_value must be <= max_value");
    }

    static thread_local std::mt19937 generator{std::random_device{}()};
    std::uniform_real_distribution<double> distribution(min_value, max_value);

    std::vector<double> values(size);
    for (double& value : values) {
        value = distribution(generator);
    }
    return values;
}

void run_matrix_addition_test(){
    // Generate 3 random vectors of size 100 * 100
    int m = 1000;
    int n = 1000;
    size_t N = m * n;
    std::vector<double> v1 = random_vector(N);
    std::vector<double> v2 = random_vector(N);
    std::vector<double> v3 = random_vector(N);
    
    // Construct 3 different matrix
    Matrix m1(m, n, v1);
    Matrix m2(m, n, v1);
    Matrix m3(m, n, v1);
    
    Matrix operator_adding_mat(m, n);
    Matrix function_adding_mat(m, n);
    
    {
        Timer tt("operator addition");
        operator_adding_mat = m1+m2+m3;
    }
    
    {
        Timer tt("function addition");
        function_adding_mat = triple_add(m1, m2, m3);
    }
    
    std::cout << "If identical: " << 
        ((operator_adding_mat==function_adding_mat)? "true": "false") << "\n";
    
}