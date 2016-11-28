#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 1000000
#define da 100.0
#define db 100.0
#define dg 100.0
#define dd 100.0
#define sigma 1.0
float probabilidadx(float *x, float *y, float *xp,float at,float bt);
float probabilidady(float *x, float *y, float *yp,float gt,float dt);
float derivadax(int k,float *x, float *y, float at, float bt);
float derivaday(int k,float *x, float *y, float gt, float dt);
float min(float a, float b);


int main(){
  /*Lista con el tiempo, predadores, presas y derivadas*/
  float *t;
  float *x;
  float *y;
  float *xp;
  float *yp;
  t = malloc(96.0*sizeof(float));
  x = malloc(96.0*sizeof(float));
  y = malloc(96.0*sizeof(float));
  xp = malloc(95.0*sizeof(float));
  yp = malloc(95.0*sizeof(float));
  /*Toco cargar esto a mano*/
  t[0]=0.006;
  t[1]=0.018;
  t[2]=0.03;
  t[3]=0.058;
  t[4]=0.078;
  t[5]=0.08;
  t[6]=0.109;
  t[7]=0.117;
  t[8]=0.133;
  t[9]=0.141;
  t[10]=0.147;
  t[11]=0.157;
  t[12]=0.164;
  t[13]=0.181;
  t[14]=0.197;
  t[15]=0.209;
  t[16]=0.214;
  t[17]=0.225;
  t[18]=0.226;
  t[19]=0.227;
  t[20]=0.231;
  t[21]=0.251;
  t[22]=0.263;
  t[23]=0.268;
  t[24]=0.27;
  t[25]=0.293;
  t[26]=0.296;
  t[27]=0.297;
  t[28]=0.307;
  t[29]=0.309;
  t[30]=0.319;
  t[31]=0.321;
  t[32]=0.323;
  t[33]=0.327;
  t[34]=0.328;
  t[35]=0.371;
  t[36]=0.379;
  t[37]=0.38;
  t[38]=0.382;
  t[39]=0.389;
  t[40]=0.4;
  t[41]=0.417;
  t[42]=0.417;
  t[43]=0.424;
  t[44]=0.434;
  t[45]=0.435;
  t[46]=0.46;
  t[47]=0.464;
  t[48]=0.465;
  t[49]=0.477;
  t[50]=0.479;
  t[51]=0.484;
  t[52]=0.489;
  t[53]=0.501;
  t[54]=0.502;
  t[55]=0.506;
  t[56]=0.542;
  t[57]=0.554;
  t[58]=0.562;
  t[59]=0.566;
  t[60]=0.577;
  t[61]=0.605;
  t[62]=0.613;
  t[63]=0.621;
  t[64]=0.623;
  t[65]=0.642;
  t[66]=0.643;
  t[67]=0.65;
  t[68]=0.664;
  t[69]=0.666;
  t[70]=0.669;
  t[71]=0.678;
  t[72]=0.679;
  t[73]=0.682;
  t[74]=0.683;
  t[75]=0.684;
  t[76]=0.69;
  t[77]=0.691;
  t[78]=0.692;
  t[79]=0.694;
  t[80]=0.705;
  t[81]=0.706;
  t[82]=0.71;
  t[83]=0.711;
  t[84]=0.712;
  t[85]=0.718;
  t[86]=0.72;
  t[87]=0.731;
  t[88]=0.739;
  t[89]=0.748;
  t[90]=0.761;
  t[91]=0.772;
  t[92]=0.774;
  t[93]=0.791;
  t[94]=0.794;
  t[95]=0.799;
  x[0]=15.0;
  x[1]=11.0;
  x[2]=13.0;
  x[3]=16.0;
  x[4]=16.0;
  x[5]=22.0;
  x[6]=46.0;
  x[7]=49.0;
  x[8]=64.0;
  x[9]=67.0;
  x[10]=58.0;
  x[11]=49.0;
  x[12]=37.0;
  x[13]=17.0;
  x[14]=13.0;
  x[15]=13.0;
  x[16]=11.0;
  x[17]=13.0;
  x[18]=12.0;
  x[19]=13.0;
  x[20]=16.0;
  x[21]=17.0;
  x[22]=20.0;
  x[23]=26.0;
  x[24]=29.0;
  x[25]=41.0;
  x[26]=53.0;
  x[27]=49.0;
  x[28]=59.0;
  x[29]=60.0;
  x[30]=62.0;
  x[31]=66.0;
  x[32]=63.0;
  x[33]=65.0;
  x[34]=58.0;
  x[35]=12.0;
  x[36]=9.0;
  x[37]=8.0;
  x[38]=14.0;
  x[39]=10.0;
  x[40]=13.0;
  x[41]=18.0;
  x[42]=13.0;
  x[43]=15.0;
  x[44]=20.0;
  x[45]=20.0;
  x[46]=38.0;
  x[47]=34.0;
  x[48]=42.0;
  x[49]=50.0;
  x[50]=52.0;
  x[51]=56.0;
  x[52]=59.0;
  x[53]=63.0;
  x[54]=64.0;
  x[55]=62.0;
  x[56]=16.0;
  x[57]=12.0;
  x[58]=10.0;
  x[59]=14.0;
  x[60]=15.0;
  x[61]=15.0;
  x[62]=19.0;
  x[63]=24.0;
  x[64]=25.0;
  x[65]=35.0;
  x[66]=35.0;
  x[67]=41.0;
  x[68]=53.0;
  x[69]=57.0;
  x[70]=58.0;
  x[71]=63.0;
  x[72]=61.0;
  x[73]=64.0;
  x[74]=65.0;
  x[75]=62.0;
  x[76]=58.0;
  x[77]=53.0;
  x[78]=55.0;
  x[79]=52.0;
  x[80]=34.0;
  x[81]=32.0;
  x[82]=26.0;
  x[83]=24.0;
  x[84]=26.0;
  x[85]=20.0;
  x[86]=18.0;
  x[87]=13.0;
  x[88]=12.0;
  x[89]=12.0;
  x[90]=9.0;
  x[91]=15.0;
  x[92]=15.0;
  x[93]=18.0;
  x[94]=21.0;
  x[95]=24.0;
  y[0]=13.0;
  y[1]=9.0;
  y[2]=7.0;
  y[3]=3.0;
  y[4]=1.0;
  y[5]=1.0;
  y[6]=1.0;
  y[7]=2.0;
  y[8]=4.0;
  y[9]=6.0;
  y[10]=10.0;
  y[11]=13.0;
  y[12]=15.0;
  y[13]=13.0;
  y[14]=9.0;
  y[15]=7.0;
  y[16]=5.0;
  y[17]=4.0;
  y[18]=4.0;
  y[19]=4.0;
  y[20]=4.0;
  y[21]=2.0;
  y[22]=1.0;
  y[23]=2.0;
  y[24]=2.0;
  y[25]=2.0;
  y[26]=2.0;
  y[27]=2.0;
  y[28]=3.0;
  y[29]=3.0;
  y[30]=6.0;
  y[31]=7.0;
  y[32]=8.0;
  y[33]=9.0;
  y[34]=9.0;
  y[35]=11.0;
  y[36]=9.0;
  y[37]=9.0;
  y[38]=8.0;
  y[39]=6.0;
  y[40]=5.0;
  y[41]=3.0;
  y[42]=3.0;
  y[43]=2.0;
  y[44]=2.0;
  y[45]=2.0;
  y[46]=2.0;
  y[47]=0.0;
  y[48]=0.0;
  y[49]=2.0;
  y[50]=1.0;
  y[51]=3.0;
  y[52]=3.0;
  y[53]=7.0;
  y[54]=7.0;
  y[55]=9.0;
  y[56]=13.0;
  y[57]=9.0;
  y[58]=7.0;
  y[59]=7.0;
  y[60]=4.0;
  y[61]=2.0;
  y[62]=2.0;
  y[63]=2.0;
  y[64]=1.0;
  y[65]=1.0;
  y[66]=1.0;
  y[67]=2.0;
  y[68]=3.0;
  y[69]=3.0;
  y[70]=3.0;
  y[71]=5.0;
  y[72]=7.0;
  y[73]=7.0;
  y[74]=8.0;
  y[75]=9.0;
  y[76]=10.0;
  y[77]=12.0;
  y[78]=12.0;
  y[79]=12.0;
  y[80]=16.0;
  y[81]=17.0;
  y[82]=16.0;
  y[83]=15.0;
  y[84]=16.0;
  y[85]=14.0;
  y[86]=14.0;
  y[87]=11.0;
  y[88]=9.0;
  y[89]=6.0;
  y[90]=4.0;
  y[91]=3.0;
  y[92]=3.0;
  y[93]=1.0;
  y[94]=2.0;
  y[95]=1.0;
  /*Ahora lleno las derivadas*/
  int i;
  for(i=0;i<95;i++){
    xp[i]=(x[i+1]-x[i])/(t[i+1]-t[i]);
    yp[i]=(y[i+1]-y[i])/(t[i+1]-t[i]);

  }
  /*Ahora defino coeficientes iniciales*/
  srand48(time(NULL));
  float a0=(100.0*drand48())-50.0;
  float b0=(100.0*drand48())-50.0;
  float g0=(100.0*drand48())-50.0;
  float d0=(100.0*drand48())-50.0;
  printf("%f ",a0);
  printf("%f ",b0);
  printf("%f ",g0);
  printf("%f \n",d0);
  /*defino coeficientes tentativos*/
  float an;
  float bn;
  float gn;
  float dn;
  float alphax;
  float alphay;
  float ux;
  float uy;
  int w;
  
  /*corro el for*/
  for(w=0;w<N;w++){
    an=a0+(drand48()*da*2.0)-da;
    bn=b0+(drand48()*db*2.0)-db;
    gn=g0+(drand48()*dg*2.0)-dg;
    dn=d0+(drand48()*dd*2.0)-dd;
    alphax=min(1.0,exp(probabilidadx(x,y,xp,an,bn)-probabilidadx(x,y,xp,a0,b0)));
    alphay=min(1.0,exp(probabilidady(x,y,yp,gn,dn)-probabilidady(x,y,yp,g0,d0)));
    ux=drand48();
    uy=drand48();
    if(ux<alphax){
      printf("%f ",an);
      printf("%f ",bn);
      a0=an;
      b0=bn;
    }

    else{
      printf("%f ",a0);
      printf("%f ",b0);
    }
    if(uy<alphay){
      printf("%f ",gn);
      printf("%f \n",dn);
      g0=gn;
      d0=dn;
    }

    else{
      printf("%f ",g0);
      printf("%f \n",d0);
    }
    
  }

  return 0;
}

float probabilidadx(float *x, float *y, float *xp, float at, float bt){
  float suma=0.0;
  int k;
  for(k=0;k<95;k++){
    suma+= pow(xp[k]-derivadax(k,x,y,at,bt),2.0);
  }
  suma= -1.0*suma;
  suma= suma/(sigma*sigma);
  return suma;
}

float probabilidady(float *x, float *y, float *yp, float gt, float dt){
  float suma=0.0;
  int k;
  for(k=0;k<95;k++){
    suma+= pow(yp[k]-derivaday(k,x,y,gt,dt),2.0);
  }
  suma= -1.0*suma;
  suma= suma/(sigma*sigma);
  return suma;
}

float derivadax(int k,float *x, float *y, float at, float bt){
  float der= x[k]*(at-bt*y[k]);
  return der;
}

float derivaday(int k,float *x, float *y, float gt, float dt){
  float der= -y[k]*(gt-dt*x[k]);
  return der;
}

float min(float a, float b){
 if(a<b){
    return a;
  }

  else{
    return b;
  }
}
