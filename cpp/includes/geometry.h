//
// Created by Lei Ma on 10/28/17.
//

#ifndef CPP_GEOMETRY_H
#define CPP_GEOMETRY_H

class Array2D {
public:
    Array2D(int row, int col) {
        _arrayofarrays = new double*[row];
        for(int i = 0; i < row; ++i){
            _arrayofarrays[i] = new double[col];
        }

        dim[0] = row;
        dim[1] = col;
    }

    int* d(){
      return dim;
    }

    class Proxy {
    public:
        Proxy(double* _array) : _array(_array) { }

        int operator[](int index) {
            return _array[index];
        }
    private:
        double* _array;
    };

    Proxy operator[](int index) {
        return Proxy(_arrayofarrays[index]);
    }
   
   ~Array2D()
   {
      int rown = dim[0];
      int coln = dim[1];

      for (int i = 0; i != rown; ++i){
         delete[] _arrayofarrays[i];
      }

     delete[] _arrayofarrays;
   }

private:
    double** _arrayofarrays;
    int dim[2];
};



class WeightArray {
public:
   WeightArray(const int rown, const int coln) {
      double**elem;
      elem = new double*[rown];
      for(int i=0;i != rown; ++i){
         elem[i] = new double[coln];
      }

      int r = rown;
      int c = coln;

    } // Constructor
   //  double* operator[](const int rown)  // getter
   //  { 
   //     return elem[rown];
   //  }
   double** matrix(){
      return elem;
   }
   int row() { return r;}  // return size of the array of states
   int column() { return c;}  // return size of the array of states
   void init(const double iv = 0.0) // initialize the array to 0's
   {
      for(int i=0;i<r;i++) { // Might need long int when the array size gets huge!
         for(int j=0;j<c;j++) {
            elem[i][j] = iv;
         }
      }
   }
   
   ~WeightArray()
   {
      int rown = r;
      int coln = c;

      for (int i = 0; i != rown; ++i){
         delete[] elem[i];
      }

     delete[] elem;
   }
private:
   double** elem;
   int r;
   int c;
};





#endif //CPP_GEOMETRY_H
