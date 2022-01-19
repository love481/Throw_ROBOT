#pragma once
#include <vector>
#include<iostream>
#include<math.h>
#ifndef _SMOOTHING_ALGORITHM_
#define _SMOOTHING_ALGORITHM_
// function based on the gradient descent method to smooth the descrete path with the help of tuning parameter
inline std::vector<std::vector<double>> smooth(std::vector<std::vector<double>>path,double weight_data=0.8,double weight_smooth=0.5,double tolerance=0.000001)
{
	std::vector<std::vector<double>> smoothPath(path.size(), std::vector<double>(2,0));
	for (int i = 0; i < path.size(); i++)
	{
		for (int j = 0; j < 2; j++)
			smoothPath[i][j] = path[i][j];
	}
	double change = tolerance;
	while (change >= tolerance)
	{   
		change = 0.0;
		for (int i = 1; i < path.size()-1; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				double aux = smoothPath[i][j];
				smoothPath[i][j] += weight_data * (path[i][j] - smoothPath[i][j]) + weight_smooth * (smoothPath[i - 1][j] + smoothPath[i+1][j] - 2 * smoothPath[i][j]);
				change += fabs(aux - smoothPath[i][j]);
			}
		}
	}
	return smoothPath;
}

#endif // !_SMOOTHING_ALGORITHM_

