#pragma once
#ifndef POLYNOMIAL_CURVE_H_
#define POLYNOMIAL_CURVE_H_
#include<vector>
#include<math.h>
#include<iostream>
#include"filters_algorithms/linalg.h"
#include"filters_algorithms/math_utils.h"
using namespace linalg;
using namespace linalg::aliases;
struct PolynomialCurve{
     std::vector<std::vector<float>> pathCoor;
};
int fact(int n){

    if(n==0)
     return 1;
    else return n*fact(n-1);
}
int comb(int n,int r)
{
 return fact(n)/(fact(n-r)*fact(r));
}
inline std::vector<float> bezier_eqn(std::vector<std::vector<float>>coor,float u)
{
 std::vector<float>coor_(3);//x,y,theta
coor_[0]=std::pow(1-u,3)*coor[0][0] + 3*std::pow(1-u,2)*u*coor[1][0]+3*(1-u)*std::pow(u,2)*coor[2][0]+std::pow(u,3)*coor[3][0];
coor_[1]=std::pow(1-u,3)*coor[0][1] + 3*std::pow(1-u,2)*u*coor[1][1]+3*(1-u)*std::pow(u,2)*coor[2][1]+std::pow(u,3)*coor[3][1];
float x_der=3*(1 - u)*2*(coor[1][0] - coor[0][0]) + 6*u*(1 - u)*(coor[2][0] - coor[1][0]) + 3*u*2 *(coor[3][0]-coor[2][0]);
float y_der=3*(1 - u)*2*(coor[1][1] - coor[0][1]) + 6*u*(1 - u)*(coor[2][1] - coor[1][1]) + 3*u*2 *(coor[3][1]-coor[2][1]);
coor_[2]=atan2(y_der,x_der);
return coor_;

}
inline std::vector<float> min_jerk(std::vector<float>pos,std::vector<float>vel,std::vector<float>accel,float T)
{    //x(t)=pos[0]+(pos[1]-pos[0])*(10(t/d)^3 -15(t/d)^4+6(t/d)^5) ,here d=T,t=time at which u find traj value
    std::vector<float>poly(6);
    poly[0]=pos[0];
    poly[1]=vel[0];
    poly[2]=accel[0]/2;
    vec<float,3>B;
    B[0]=pos[1]-poly[0]-poly[1]*T-poly[2]*T*T;
    B[1]=vel[1]-poly[1]-2*poly[2]*T;
    B[2]=accel[1]-2*poly[2];
    mat<float,3,3>A{{(float)std::pow(T,5),5*(float)std::pow(T,4),20*(float)std::pow(T,3)},
                   {(float)std::pow(T,4),4*(float)std::pow(T,3),12*(float)std::pow(T,2)},
                   {(float)std::pow(T,3),3*(float)std::pow(T,2),6*T}};
    vec<float,3>X;
    X=mul(inverse(A),B);
    poly[3]=X[2];
    poly[4]=X[1];
    poly[5]=X[0];
    return poly;


}
inline std::vector<float> min_accel(std::vector<float>pos,std::vector<float>vel,float T)
{
    std::vector<float>poly(4);
    vec<float,4>B;
    B[0]=pos[0];
    B[1]=pos[1];
    B[2]=vel[0];
    B[3]=vel[1];
    mat<float,4,4>A{{0,(float)std::pow(T,3),0,3*(float)std::pow(T,2)},
                   {0,(float)std::pow(T,2),0,2*T},
                   {0,T,1,1},
                   {1,1,0,0}};
    vec<float,4>X;
    X=mul(inverse(A),B);
    poly[0]=X[3];
    poly[1]=X[2];
    poly[2]=X[1];
    poly[3]=X[0];
    return poly;
}
//s being the function of time and coor is the initial pos and final pos
float lerp(std::vector<float> coor,std::vector<float>s,float t)
{
 return polynomial_val(s,t)*(coor[1]-coor[0])+coor[0];
}
#endif //  POLYNOMIAL_CURVE_H_
