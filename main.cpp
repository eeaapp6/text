#include <iostream>
#include <unsupported/Eigen/FFT>
#include <Eigen/Dense>
#include "fft.h"

using namespace FFTLibrary;

int main(int argc, char** argv)
{
    VectorXd A(5);
    A << 1, 2, 3, 4, 5;
    std::cout << A << std::endl;
    VectorXcd A_fft = fft(A,6);
    std::cout << A_fft << std::endl;

    MatrixXd B(3,3);
    B << 1, 2, 3, 4, 5,6,7,8,9;
    std::cout << B << std::endl;
    MatrixXcd B_fft_col = fft(A,3,1);
    std::cout << B_fft_col << std::endl;
    return 0;
}