#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define sigma 0.10
#define N 100000
#define dx 1
#define dy 1
#define v 5.0
float probabilidad(float *x,float *y,float *t,float xt, float yt);
float tiempo(int k, float *x, float *y,float xt,float yt);
float min(float a, float b);

int main(){
  /*Inicializo las listas con las posiciones de los laboratorios y los tiempos de llegada*/
  float *x;
  float *y;
  float *t;
  x=malloc(6.0*sizeof(float));
  y=malloc(6.0*sizeof(float));
  t=malloc(6.0*sizeof(float));
  x[0]=3.0;
  x[1]=4.0;
  x[2]=5.0;
  x[3]=3.0;
  x[4]=4.0;
  x[5]=5.0;
  y[0]=15.0;
  y[1]=15.0;
  y[2]=15.0;
  y[3]=16.0;
  y[4]=16.0;
  y[5]=16.0;
  t[0]=3.12;
  t[1]=2.98;
  t[2]=2.84;
  t[3]=3.26;
  t[4]=3.12;
  t[5]=2.98;
  /*Ahora definimos una posicion inicial tentativa*/
  srand48(time(NULL));
  float x0=(30.0*drand48())-15.0;
  float y0=30.0*drand48();
  printf("%f ",x0);
  printf("%f \n",y0);
  /*Inicializo las posiciones tentativas*/
  float xn;
  float yn;
  int i;
  float alpha;
  float u;
  /*Corro el for*/
  for(i=0;i<N;i++){
    xn= x0+(drand48()*dx*2.0)-dx;
    yn= y0+(drand48()*dy*2.0)-dy;
    alpha= min(1.0,exp(probabilidad(x,y,t,xn,yn)-probabilidad(x,y,t,x0,y0)));
    u=drand48();
    if(u<alpha){
      printf("%f ",xn);
      printf("%f \n",yn);
      x0 = xn;
      y0 =yn;
    }
    else{
      printf("%f ",x0);
      printf("%f \n",y0);

    }
    

  }
  
   
}

float probabilidad(float *x,float *y,float *t,float xt,float yt){
  float suma=0.0;
  int k;
  for(k=0;k<6;k++){
    suma+= pow(t[k]-tiempo(k,x,y,xt,yt),2.0);
  }
  suma = -1.0*suma;
  suma = suma/(sigma*sigma);

  return suma;
  
}

float tiempo(int k,float *x,float *y,float xt,float yt){
  float distancia;
  float distanciax;
  float distanciay;
 
  distanciax=pow(xt-x[k],2.0);
  distanciay=pow(yt-y[k],2.0);
  distancia=pow(distanciax+distanciay,0.5);
  return distancia/v;

}

float min(float a, float b){
  if(a<b){
    return a;
  }

  else{
    return b;
  }

}
