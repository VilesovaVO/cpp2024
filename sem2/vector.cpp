#include <iostream>
#include <vector>
#include "library_vec.cpp"
int main() {
    std::vector<float> M = { 2, 4, 6, 12, 5 };
    std::cout << vec_dispersia(M) << std::endl;
    std::cout << vec_average(M) << std::endl;
    std::cout << vec_mediana(M) << std::endl;
    std::cout << vec_asd(M) << std::endl;
}