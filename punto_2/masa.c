#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define G 19.82548137
#define N 1000000
#define dm 0.001
#define da 0.01
#define sigma 1.0
float probabilidad(float *r, float *v,float mt, float at);
float velocidad(int k, float *r,float mt, float at);
float min(float a, float b);


int main(){
  /*Lista con las distancias y las velocidades al cuadrado*/
  float *r;
  float *v;
  r= malloc(8.0*sizeof(float));
  v=malloc(8.0*sizeof(float));
  r[0]=0.337486991;
  r[1]=0.722556134;
  r[2]=1.000984001;
  r[3]=1.379728791;
  r[4]=5.078374222;
  r[5]=9.396651033;
  r[6]=20.0956952;
  r[7]=30.02716987;
  v[0]=130.9922492;
  v[1]=54.9379593;
  v[2]=39.5608496;
  v[3]=31.10107728;
  v[4]=7.938687588;
  v[5]=4.269567859;
  v[6]=1.873652638;
  v[7]=1.318392471;
  /*Ahora defino una masa y un exponente inicial tentativo*/
  srand48(time(NULL));
  float m0=5.0*drand48();
  float a0= (4.0*drand48())-2.0;
  printf("%f ",30.0+log10(m0));
  printf("%f \n",a0);
  /*Inicializo la masa y exponente tentativo*/
  float mn;
  float an;
  int i;
  float alpha;
  float u;
  /*Corro el for*/
  for(i=0;i<N;i++){
    mn= m0+(drand48()*dm*2.0)-dm;
    an= a0+(drand48()*da*2.0)-da;
    alpha= min(1.0,exp(probabilidad(r,v,mn,an)-probabilidad(r,v,m0,a0)));
    u=drand48();
    if(u<alpha){
      printf("%f ",30.0+log10(mn));
      printf("%f \n",an);
      m0=mn;
      a0=an;
    }
    else{
      printf("%f ",30.0+log10(m0));
      printf("%f \n",a0);
    }

  }
  
  
  
  
  
  return 0;
}

float probabilidad(float *r,float *v, float mt, float at){
  float suma=0.0;
  int k;
  for(k=0;k<8;k++){
    suma+= pow(v[k]-velocidad(k,r,mt,at),2.0);
  }
  suma = -1.0*suma;
  suma = suma/(sigma*sigma);

  return suma;

}

float velocidad(int k,float *r,float mt,float at){
  float rapidez;
  rapidez= G*mt*pow(r[k],at);
  return rapidez;
   
}

float min(float a, float b){
  if(a<b){
    return a;
  }

  else{
    return b;
  }

}
