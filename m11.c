#include <stdio.h> 

double x1; 
double f1;
double der1; 

double h = 0.00001; 



double fun1(double h1); 
void derivative(); 


int main(){


    x1 = 2; 
    derivative(); 
    printf("%f",der1); 
    return 0; 

}


double fun1(double x11){

    f1 = (x11*x11);
    return f1; 
}



void derivative(){

    der1 = (fun1((x1+h))-fun1(x1))/h; 
    
}

