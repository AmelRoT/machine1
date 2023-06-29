#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <math.h>

#define train_count (sizeof(train))/sizeof(train[0])

//#define train_count (sizeof(train)/sizeof(train[0])); 

float train[][2] =  {

    {0,0},
    {1,2},
    {2,4},
    {3,6},
    {4,8}

}; 


float rand_float(void){

    return (float) rand()/(float) RAND_MAX; 

}

float cost(float w){

    float result = 0; 
    for(size_t i = 0; i< train_count; i++){
        float x = train[i][0]; 
        float y = x*w; 
        float d = fabs(y - train[i][1]); 
        result = result + d*d; 
     //  printf("trained : %f , expected : %f \n ",y, train[i][1]); 
     printf("Result :  %f \n", result); 

    }
     
    //result = result/train_count; 
    return result; 

}


int main(){
    
    
   // srand(time(0)); 
    srand(69); 
    float w = rand_float()*100; 
    w = 20; 
    float epsi = 1e-5;

    printf("%f ", cost(w) ); 

    for (int i1 = 0;i1 < 2000 ; i1++){

        float deri = (cost(w+epsi)-cost(w))/epsi; 
        float rate = 0.0001; 
        w = w-rate*deri; 
    }
        printf("%f ", cost(w) ); 
        printf("%f", w); 

 //   printf("%zu\n", train_count);
 //   printf("%f \n", w); 
    return 0; 
   
}


//size_t for printing it we require %zu 