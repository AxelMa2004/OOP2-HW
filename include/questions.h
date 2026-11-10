#pragma once
#include <string>
#include <iostream>

void q1_1();
void q1_2();
void run_fraction_test();
void run_linearsystem_test();
void run_digragh_test();
void run_matrix_test();
void run_matrix_addition_test();


inline void generate_title(const std::string& name){
    std::cout << "\n\n=================\n" << name << "\n=================\n";
}