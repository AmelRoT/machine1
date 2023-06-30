#include  <stdio.h>
#include <math.h>

    // y = kx -> k*{1,2,3,4,5,6} -> we want to predict 
    // y = {2,4,6,8,10,12,..} -> k = 2 

double sigmoid(double x){

    return (1/(1+exp(-x))); 

}


 double y [][3] = {
    {0,0,0}, 
    {1,1,1}, 
    {0,1,1},
    {1,0,1}, 
    
    };


//double y [][2] = {{0,0}, {1,6.6}, {2,11.4},{3,19.4}, {4,30.6},{5,45},{6,62.6},{7,83.4},{8,107.4}};

int i = 0; 
double d = 0; 
double k1 = 0.5; 
double k2 = 0.5; 
double sigma = 0; 
double C = 0.7; 
double h1 = 10^-5; 
double b = 100;




double cost(double k1, double k2,double b){

    double sigma = 0; 

    for(i = 0; i < 4; i++){
        d = sigmoid((k1*y[i][0]+k2*y[i][1])+b)-y[i][2];
      //  printf("d : %f \n", d); 
        sigma += d*d;  // distance between them 
      //  printf("sigma : %f \n",d) ; 
    }

    return sigma; 
}


double dot1(double k1, double k2,double b){

   double  h = 10^-5; 
   return (cost((k1+h),k2,b)-cost(k1,k2,b))/h; 

}


double dot2(double k1, double k2,double b){

   double  h = 10^-5; 
   return ((cost(k1,(k2+h),b)-cost(k1,k2,b))/h); 

}


double dot3(double k1, double k2,double b){

   double  h = 10^-5; 
   return ((cost(k1,k2,(b+h))-cost(k1,k2,b))/h); 

}


int main(){

    //
    // tested values --> 
    //

    k1 = 25; 
    k2 = 10; 
    b = -1;

#if 0 
    for (int j1 = -10; j1<10; j1++){

        printf("Value : %f \n " , sigmoid(j1)); 
    }

    return 0; 
#endif 


    for (int j = 0; j<10000; j++){

        double a = k1; 
        k1 = k1 - C*dot1(k1,k2,b); 
        k2 = k2 - C*dot2(k1,k2,b); 
        b =  b -  C*dot3(k1,k2,b); 

        printf("b : %f \n" ,b); 
        printf("k1 : %f \n" , k1); 
        printf("k2 : %f \n" , k2); 
 
    }

    for (int j2 = 0; j2 < 4; j2++){

        printf("V : %f \n ",sigmoid((k1*y[j2][0]+k2*y[j2][1]+b))); 

    }

    return 0; 
}




// gcc mach2.c -o mach2 -lm

// lm is used for math functions 

// git config --global user.email "<amelrambabovic@gmail.com>"


// space -> password for keys
// git add .
// git commit -m "commit"
// git remote add origin git@github.com:AmelRoT/machine1.git
// git push -u origin main 