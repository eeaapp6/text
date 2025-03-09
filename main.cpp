#include <iostream>
#include <unsupported/Eigen/FFT>
#include <Eigen/Dense>
#include "fft.h"
#include "ifft.h"

using namespace FFTLibrary;
using namespace IFFTLibrary;

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

    VectorXcd C(3);
    C << 1, 2, 3;
    std::cout << C << std::endl;
    VectorXcd C_ifft = ifft(C);
    std::cout << C_ifft << std::endl;
    VectorXcd C_ifft_4 = ifft(C,4);
    std::cout << C_ifft_4 << std::endl;

    MatrixXcd D(3,3);
    D << 1, 2, 3, 4, 5,6,7,8,9;
    std::cout << D << std::endl;
    MatrixXcd D_ifft_col = ifft(D,4,1);
    MatrixXcd D_ifft_row = ifft(D,4,2);
    std::cout << D_ifft_col << std::endl << std::endl;
    std::cout << D_ifft_row << std::endl;
    return 0;
}