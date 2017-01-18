#include <iostream>
#include <algorithm>

using namespace std;

void inverseMatrix(vector<vector<double>>& data, int dim) {
  vector<vector<double>> inverseMatrix(dim,vector<double>(2*dim));
  for(int i = 0; i < dim; i++) {
    for(int j = 0; j < 2*dim; j++) {
      if(j < dim) {
        inverseMatrix[i][j] = data[i][j];
      }
      else if(i == (j-dim)) {
        inverseMatrix[i][j] = 1.0;
      }
      else {
        inverseMatrix[i][j] = 0.0;
      }
    }
  }

  for(int i = 0; i < dim; i++){
    for(int j = 0; j < dim; j++){
      if(i!=j){
        double ratio = inverseMatrix[j][i]/inverseMatrix[i][i];
        for(int k = 0; k < 2*dim; k++){
          inverseMatrix[j][k] -= ratio * inverseMatrix[i][k];
        }
      }
    }
  }

  for(int i = 0; i < dim; i++){
    double a = inverseMatrix[i][i];
    for(int j = 0; j < 2*dim; j++){
      inverseMatrix[i][j] /= a;
    }
  }

  // Now copy the actual value into matrix
  for(int i = 0; i < dim; i++) {
    for(int j = 0; j < dim; j++) {
      data[i][j] = inverseMatrix[i][j+dim];
    }
  }
  return;
}


int main(){
  int dim;
  cout << "Please enter the dimension of square matrix : ";
  cin >> dim;
  vector<vector<double>> matrix(dim,vector<double>(dim));
  cout << "Please enter the matrix row wise : \n";
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
          double val;
          cin >> val;
          matrix[i][j] = val;
        }
    }
    inverseMatrix(matrix,dim);

    cout << "The inverse matrix is: \n";
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
          cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}
