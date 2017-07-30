#include <iostream>
#include<math.h>
double pi=3.14159265359;
float t1,t2,t3,t4,t5;
double t[5]={t1,t2,t3,t4,t5};
double a[5]={24,106,99.42,0,0};
double d[5]={10.7,0,0,10.7,74.7};
double alp[5]={-pi/2,0,0,pi/2,0};

double A12[4][4];
double A123[4][4];
double A1234[4][4];
double A12345[4][4];

void matrix_form(double A[][4],double B[][4],double C[][4],double D[][4],double E[][4]);
void display_matrix(double A[][4],double B[][4],double C[][4],double D[][4],double E[][4]);
void multiply(double A[][4],double B[][4],double C[][4],double D[][4],double E[][4]);


int main(int argc, const char * argv[]) {
    double A1[4][4]={};
    double A2[4][4]={};
    double A3[4][4]={};
    double A4[4][4]={};
    double A5[4][4]={};
    matrix_form(A1,A2,A3,A4,A5);
    
   
    
    multiply(A1,A2,A3,A4,A5);
    
    display_matrix(A1,A2,A3,A4,A5);
    return 0;
}

void matrix_form(double A[][4],double B[][4],double C[][4],double D[][4],double E[][4]){
   
    //ROW 1
    
    A[0][0]=cos(t[0]);
    B[0][0]=cos(t[1]);
    C[0][0]=cos(t[2]);
    D[0][0]=cos(t[3]);
    E[0][0]=cos(t[4]);
    
    A[0][1]=(-1)*cos(alp[0])*sin(t[0]);
    B[0][1]=(-1)*cos(alp[1])*sin(t[1]);
    C[0][1]=(-1)*cos(alp[2])*sin(t[2]);
    D[0][1]=(-1)*cos(alp[4])*sin(t[3]);
    E[0][1]=(-1)*cos(alp[4])*sin(t[4]);
    
    A[0][2]=sin(alp[0])*sin(t[0]);
    B[0][2]=sin(alp[1])*sin(t[1]);
    C[0][2]=sin(alp[2])*sin(t[2]);
    D[0][2]=sin(alp[3])*sin(t[3]);
    E[0][2]=sin(alp[4])*sin(t[4]);
    
  
    A[0][3]=a[0]*cos(t[0]);
    B[0][3]=a[1]*cos(t[1]);
    C[0][3]=a[2]*cos(t[2]);
    D[0][3]=a[3]*cos(t[3]);
    E[0][3]=a[4]*cos(t[4]);
    
    //ROW 2
    A[1][0]=sin(t[0]);
    B[1][0]=sin(t[1]);
    C[1][0]=sin(t[2]);
    D[1][0]=sin(t[3]);
    E[1][0]=sin(t[4]);
    
    A[1][1]=cos(alp[0])*cos(t[0]);
    B[1][1]=cos(alp[1])*cos(t[1]);
    C[1][1]=cos(alp[2])*cos(t[2]);
    D[1][1]=cos(alp[4])*cos(t[3]);
    E[1][1]=cos(alp[4])*cos(t[4]);
    
    
    A[1][2]=-1*sin(alp[0])*cos(t[0]);
    B[1][2]=-1*sin(alp[1])*cos(t[1]);
    C[1][2]=-1*sin(alp[2])*cos(t[2]);
    D[1][2]=-1*sin(alp[3])*cos(t[3]);
    E[1][2]=-1*sin(alp[4])*cos(t[4]);
    
    
    A[1][3]=a[0]*sin(t[0]);
    B[1][3]=a[1]*sin(t[1]);
    C[1][3]=a[2]*sin(t[2]);
    D[1][3]=a[3]*sin(t[3]);
    E[1][3]=a[4]*sin(t[4]);
    
    //ROW 3
    
    A[2][1]=sin(alp[0]);
    B[2][1]=sin(alp[1]);
    C[2][1]=sin(alp[2]);
    D[2][1]=sin(alp[3]);
    E[2][1]=sin(alp[4]);
    
    A[2][2]=cos(alp[0]);
    B[2][2]=cos(alp[1]);
    C[2][2]=cos(alp[2]);
    D[2][2]=cos(alp[3]);
    E[2][2]=cos(alp[4]);
    
    A[2][3]=d[0];
    B[2][3]=d[1];
    C[2][3]=d[2];
    D[2][3]=d[3];
    E[2][3]=d[4];
    
    A[2][0]=A[3][0]=A[3][1]=A[3][2]=0;
    B[2][0]=B[3][0]=B[3][1]=B[3][2]=0;
     C[2][0]=C[3][0]=C[3][1]=C[3][2]=0;
     D[2][0]=D[3][0]=D[3][1]=D[3][2]=0;
     E[2][0]=E[3][0]=E[3][1]=E[3][2]=0;
    
    A[3][3]=B[3][3]=C[3][3]=D[3][3]=E[3][3]=1;
    
   
}

void multiply(double A[][4],double B[][4],double C[][4],double D[][4],double E[][4]){
    
    
    double sum=0;
    for (int c = 0; c < 4; c++) {
        for (int d = 0; d < 4; d++) {
            for (int k = 0; k < 4; k++) {
                sum = sum + A[c][k]*B[k][d];
            }
            
            A12[c][d] = sum;
            sum = 0;
        }
}
    
    
    for (int c = 0; c < 4; c++) {
        for (int d = 0; d < 4; d++) {
            for (int k = 0; k < 4; k++) {
                sum = sum + A12[c][k]*C[k][d];
            }
            
            A123[c][d] = sum;
            sum = 0;
        }
    }
    
    
    for (int c = 0; c < 4; c++) {
        for (int d = 0; d < 4; d++) {
            for (int k = 0; k < 4; k++) {
                sum = sum + A123[c][k]*D[k][d];
            }
            
            A1234[c][d] = sum;
            sum = 0;
        }
    }
    
    
    for (int c = 0; c < 4; c++) {
        for (int d = 0; d < 4; d++) {
            for (int k = 0; k < 4; k++) {
                sum = sum + A1234[c][k]*E[k][d];
            }
            
            A12345[c][d] = sum;
            sum = 0;
        }
    }



    
   
}
    
    
void display_matrix(double A[][4],double B[][4],double C[][4],double D[][4],double E[][4]){
    
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            std::cout<<A[i][j];
            std::cout<<"       ";
            
            
        }
         std::cout<<"\n";
        
    }
    std::cout<<"\n";
    std::cout<<"\n";
    
    
   for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            
            std::cout<<B[i][j];
            std::cout<<"       ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
    std::cout<<"\n";
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            
            std::cout<<C[i][j];
            std::cout<<"       ";
        }
        std::cout<<"\n";
    }
std::cout<<"\n";
    std::cout<<"\n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            
            std::cout<<D[i][j];
            std::cout<<"       ";
        }
        std::cout<<"\n";
    }
std::cout<<"\n";
    std::cout<<"\n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            
            std::cout<<E[i][j];
            std::cout<<"       ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
    std::cout<<"\n";
    
    std::cout<<"A12";
    std::cout<<"\n";
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            std::cout<<A12[i][j];
            std::cout<<" ";
        }
        std::cout<<"\n";
    }
    
    
    std::cout<<"\n";
    
    std::cout<<"A123";
    std::cout<<"\n";
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            std::cout<<A123[i][j];
            std::cout<<" ";
        }
        std::cout<<"\n";
    }
    
    
    std::cout<<"\n";
    
    std::cout<<"A1234";
    std::cout<<"\n";
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            std::cout<<A1234[i][j];
            std::cout<<" ";
        }
        std::cout<<"\n";
    }
    
    
    std::cout<<"\n";
    
    std::cout<<"A12345";
    std::cout<<"\n";
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            std::cout<<A12345[i][j];
            std::cout<<" ";
        }
        std::cout<<"\n";
    }
    
}


void inverse_matrix(double a[][4]){
    double sum=0;
    double ai[4][4]={};
    ai[3][3]=1;
    for(int i =0;i<3;i++){
        for(int j=0;j<3;j++){
            ai[i][j]=a[j][i];
        }
    }
    
    for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
            sum=sum+ai[j][k]*a[k][3];
        }
        ai[j][3]=-1*sum;
    }
    
}


