//
// Created by Lei Ma on 10/28/17.
// At this point this header file is not used.
// The classes here are not tested.
//

#ifndef CPP_GEOMETRY_H
#define CPP_GEOMETRY_H

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
