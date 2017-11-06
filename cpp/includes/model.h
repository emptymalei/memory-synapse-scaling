//
// Created by Lei Ma on 10/28/17.
//

#ifndef CPP_MODEL_H
#define CPP_MODEL_H

#include <cmath>
#include <vector>
#include "base.h"

namespace Model {

   double activity(double u, const double alpha, const double beta, const double epsilon) {
      return alpha / ( 1.0 + exp( beta * ( epsilon - u ) ) );
   }

   double dudt(double u, double frequency, double nbrs, double ext, const double tau, const double resistance){
      // nbrs = sum_excit - sum_inhit =  { f1+, f2+, f3+, f4+, ... } * { wi1+, wi2+, wi3+, wi4+, ... } - { f1-, f2-, f3- f4-, ... } * { wi1-, wi2-, wi3-, wi4-, ... } 
      

      return -u/tau + resistance * ( nbrs +  ext ) ;
   }

   double neighbours( vector<double> excfreq, vector<double> excw, vector<double> inhfreq, vector<double> inhw ){
      // excfreq = { f1+, f2+, f3+, f4+, ... } 
      // excw = { wi1+, wi2+, wi3+, wi4+, ... }
      // inhfreq = { f1-, f2-, f3- f4-, ... } 
      // inhw = { wi1-, wi2-, wi3-, wi4-, ... } 
      
      double excsum;
      double inhsum;

      int exclen =  excfreq.size();
      int inhlen = inhfreq.size();

      // std::cout << exclen << std::endl;
      // std::cout << excfreq[0] << std::endl;

      for(int i=0; i < exclen; i++ ){
         excsum = excfreq[i] * excw[i];
      }
      for(int i=0; i < inhlen; i++ ){
         excsum = inhfreq[i] * inhw[i];
      }

      return excsum + inhsum;

   }

   double external(double w, double freq, double bg) {
      return w * (freq + bg);
   }

   int neuronID(int geodim[2], int m, int n){
      return m* geodim[1] + n;
   }

   vector<double> nnActivity( Array2D* arr_ptr, int geodim[2], int i, int j ){
     
      int ip1 = ( geodim[0] + ( i + 1 )%geodim[0] )%geodim[0];
      int jp1 = ( geodim[1] + ( j + 1 )%geodim[1] )%geodim[1];
      int im1 = ( geodim[0] + ( i - 1 )%geodim[0] )%geodim[0];
      int jm1 = ( geodim[1] + ( j - 1 )%geodim[1] )%geodim[1];

      // double nn[1] = {(*arr_ptr)[0][0]};
      vector<double> nn = {};
      // vector<double> nn = { (*arr_ptr)[ip1][jp1], (*arr_ptr)[ip1][jm1], (*arr_ptr)[im1][jp1], (*arr_ptr)[im1][jm1] };
      for(int a : {ip1, im1} ) {
         for(int b : {jp1, jm1} ) {
            nn.push_back( (*arr_ptr)[a][b] );
         }
      }

      return nn;
   }

   vector<double> nnWeight( Array2D* w_ptr, int geodim[2], int i, int j ) {

      int ip1 = ( geodim[0] + ( i + 1 )%geodim[0] )%geodim[0];
      int jp1 = ( geodim[1] + ( j + 1 )%geodim[1] )%geodim[1];
      int im1 = ( geodim[0] + ( i - 1 )%geodim[0] )%geodim[0];
      int jm1 = ( geodim[1] + ( j - 1 )%geodim[1] )%geodim[1];

      int nid0 = neuronID(geodim, i, j);
      int nid[4] = { neuronID(geodim, ip1, jp1), neuronID(geodim, ip1, jm1), neuronID(geodim, im1, jp1), neuronID(geodim, im1, jm1) };

      vector<double> nn;

      for(int a =0; a < 4 ; a++ ) {
         nn.push_back( (*w_ptr)[nid0][nid[a]] );
      }
      
      return nn;
   
   }
   
   double dwEdt( double acti, double actj, double mu, double kappa, double actt) {
      return mu*  ( acti * actj); // + (actt - acti) * (Ewij)^2 / kappa );
   }


   vector<double> nnnActivity( Array2D* arr_ptr, int geodim[2], int i, int j ){
     
      int ip1 = ( geodim[0] + ( i + 1 )%geodim[0] )%geodim[0];
      int jp1 = ( geodim[1] + ( j + 1 )%geodim[1] )%geodim[1];
      int im1 = ( geodim[0] + ( i - 1 )%geodim[0] )%geodim[0];
      int jm1 = ( geodim[1] + ( j - 1 )%geodim[1] )%geodim[1];
      int ip2 = ( geodim[0] + ( i + 2 )%geodim[0] )%geodim[0];
      int jp2 = ( geodim[1] + ( j + 2 )%geodim[1] )%geodim[1];
      int im2 = ( geodim[0] + ( i - 2 )%geodim[0] )%geodim[0];
      int jm2 = ( geodim[1] + ( j - 2 )%geodim[1] )%geodim[1];

      // double nn[1] = {(*arr_ptr)[0][0]};
      vector<double> nn = {};
      // vector<double> nn = { (*arr_ptr)[ip1][jp1], (*arr_ptr)[ip1][jm1], (*arr_ptr)[im1][jp1], (*arr_ptr)[im1][jm1] };
      for(int a : {ip1, im1, ip2, im2} ) {
         for(int b : {jp1, jm1, jp2, jm2} ) {
            nn.push_back( (*arr_ptr)[a][b] );
         }
      }

      return nn;
   }

   vector<double> nnnWeight( Array2D* w_ptr, int geodim[2], int i, int j ) {


      int ip1 = ( geodim[0] + ( i + 1 )%geodim[0] )%geodim[0];
      int jp1 = ( geodim[1] + ( j + 1 )%geodim[1] )%geodim[1];
      int im1 = ( geodim[0] + ( i - 1 )%geodim[0] )%geodim[0];
      int jm1 = ( geodim[1] + ( j - 1 )%geodim[1] )%geodim[1];
      int ip2 = ( geodim[0] + ( i + 2 )%geodim[0] )%geodim[0];
      int jp2 = ( geodim[1] + ( j + 2 )%geodim[1] )%geodim[1];
      int im2 = ( geodim[0] + ( i - 2 )%geodim[0] )%geodim[0];
      int jm2 = ( geodim[1] + ( j - 2 )%geodim[1] )%geodim[1];

      int nid0 = neuronID(geodim, i, j);
      int nid[8] = { neuronID(geodim, ip1, jp1), neuronID(geodim, ip1, jm1), neuronID(geodim, im1, jp1), neuronID(geodim, im1, jm1), neuronID(geodim, ip2, jp2), neuronID(geodim, ip2, jm2), neuronID(geodim, im2, jp2), neuronID(geodim, im2, jm2) };

      vector<double> nn;

      for(int a =0; a < 8 ; a++ ) {
         nn.push_back( (*w_ptr)[nid0][nid[a]] );
      }
      
      return nn;
   
   }



}


#endif //CPP_MODEL_H
