#ifndef FFT_H
#define FFT_H

#include <Eigen/Dense>
#include <unsupported/Eigen/FFT>
#include <stdexcept>

using namespace Eigen;

namespace FFTLibrary{

    // 没有指定长度
    VectorXcd fft(const VectorXcd &input){
      FFT<double> fft;
      VectorXcd output;
      fft.fwd(output,input);
      return output;
    }

    //指定长度n
    VectorXcd fft(const VectorXcd &input, int n){
      VectorXcd temp = VectorXcd :: Zero(n);
      temp.head(std::min(n,(int)input.size())) = input.head(std::min(n,(int)input.size()));
      FFT<double> fft;
      VectorXcd output;
      fft.fwd(output,temp);
      return output;
    }

    //指定长度n和维度dim
    MatrixXcd fft(const MatrixXd &input,int n,int dim){
        if(dim != 1 && dim != 2){
          throw std::invalid_argument("dim must be 1 or 2");
        }

        FFT<double> fft;
        MatrixXcd output;
        //按列处理
        if(dim == 1)
        {
            output.resize(n,input.cols());
            for(int col=0;col<input.cols();col++)
            {
              VectorXd column = input.col(col);
              VectorXd temp = VectorXd::Zero(n);
              temp.head(std::min(n,(int)column.size())) = column.head(std::min(n,(int)column.size()));

              VectorXcd fft_col;
              fft.fwd(fft_col,temp);
              output.col(col) = fft_col;
            }
        }
        //按行处理
        else
        {
          output.resize(input.rows(),n);
          for(int row=0;row<input.rows();row++)
          {
            VectorXd row1 = input.row(row);
            VectorXd temp = VectorXd::Zero(n);
            temp.head(std::min(n,(int)row1.size())) = row1.head(std::min(n,(int)row1.size()));
            VectorXcd fft_row;
            fft.fwd(fft_row,temp);
            output.row(row) = fft_row;
          }
        }
        return output;
    }
}

#endif //FFT_H
