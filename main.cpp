#include <iostream>
#include "Eigen/Dense"

using namespace Eigen;

int main()
{
    Eigen::VectorXd aa = Eigen::VectorXd::LinSpaced(3,1,3);
    std::cout<<aa<<std::endl;
    return 0;
}