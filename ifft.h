#ifndef IFFT_H
#define IFFT_H

#include <Eigen/Dense>
#include <stdexcept>
#include <unsupported/Eigen/FFT>

using namespace Eigen;

namespace IFFTLibrary{

    VectorXcd ifft(const VectorXcd& input){
      FFT<double> fft;
      VectorXcd output;
      fft.inv(output,input);
      return output;
    }

    VectorXcd ifft(const VectorXcd & input,int n){
      VectorXcd temp = VectorXcd::Zero(n);
      temp.head(std::min(n,(int)input.size())) = input.head(std::min(n,(int)input.size()));
      FFT<double> fft;
      VectorXcd output;
      fft.inv(output,temp);
      return output;
    }

    MatrixXcd ifft(const MatrixXcd& input,int n,int dim){
      if(dim !=1 && dim !=2){
        throw std::invalid_argument("dim must be 1,2");
      }
      FFT<double> fft;
      MatrixXcd output;
      if(dim == 1)
      {
        output.resize(n,input.cols());
        for(int col=0;col<input.cols();col++){
          VectorXcd column = input.col(col);
          VectorXcd temp = VectorXcd::Zero(n);
          temp.head(std::min(n,(int)column.size())) = column.head(std::min(n,(int)column.size()));
          VectorXcd ifft_column;
          fft.inv(ifft_column,temp);
          output.col(col) = ifft_column;
        }
      }
      else
      {
        output.resize(input.rows(),n);
        for(int row=0;row<input.rows();row++){
          VectorXcd row1 = input.row(row);
          VectorXcd temp = VectorXcd::Zero(n);
          temp.head(std::min(n,(int)row1.size())) = row1.head(std::min(n,(int)row1.size()));
          VectorXcd ifft_row;
          fft.inv(ifft_row,temp);
          output.row(row) = ifft_row;
        }
      }
      return output;
    }
}

#endif //IFFT_H
