#pragma once
#ifndef MATH_UTILS_
#define MATH_UTILS_
#include<vector>
inline float polynomial_val(std::vector<float>poly,float x)
{
 float value=0;
 float x0=1;
 for(int i=0;i<poly.size();i++)
 {
   value+=x0*poly[i];
   x0*=x;
 }
 return value;
}
inline std::vector<float>polynomial_der(std::vector<float>poly)
{
 std::vector<float>der;
 for(int i=0;i<poly.size()-1;i++)
 {
     der.push_back((i+1)*poly[i+1]);
 }
 return der;

}
#endif // !MATH_UTILS_