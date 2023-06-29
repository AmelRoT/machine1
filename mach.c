#include  <stdio.h>


    // y = kx -> k*{1,2,3,4,5,6} -> we want to predict 
    // y = {2,4,6,8,10,12,..} -> k = 2 



 double y [][2] = {{0,0}, {1,1.6}, {2,6.4},{3,14.4}, {4,25.6},{5,40},{6,57.6}};
//double y [][2] = {{0,0}, {1,6.6}, {2,11.4},{3,19.4}, {4,30.6},{5,45},{6,62.6},{7,83.4},{8,107.4}};

int i = 0; 
double d = 0; 
double k = 100; 
double sigma = 0; 
double C = 0.7; 


double cost(double k){

    double sigma = 0; 

    for(i = 0; i < 6; i++){
        d = k*(y[i][0]*y[i][0])-y[i][1];
      //  printf("d : %f \n", d); 
        sigma += d; 
    }

    return sigma; 
}


double dot(double k){

    double h = 1e-5; 
    return ((cost(k+h)-cost(k))/h);

}


int main(){

    
    for (int j = 0; j<50; j++){


        k = k - C*cost(k)/dot(k); 
        printf("K : %f \n" , k); 

    }


    return 0; 
}




git config --global user.email "<amelrambabovic@gmail.com>"
