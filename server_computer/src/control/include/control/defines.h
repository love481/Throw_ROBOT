#ifndef _DEFINES_H_
#define  _DEFINES_H_
#define PI (3.1415)
#define SAMPLE_TIME 10
#define bodyDiameter 0.690
#define interWheelDist 0.75
#define wheelDiameter 0.14
#define B_A             (0)
#define B_B             (1)
#define B_X             (2)
#define B_Y             (3)
#define B_LB            (4)
#define B_RB            (5)
#define B_START         (7)
#define B_BACK          (6)
#define B_XBOX          (8)
   
#define AXES_L_HX       (0)
#define AXES_L_HY       (1)
#define AXES_L_T        (2)
#define AXES_R_HX       (3)
#define AXES_R_HY       (4)
#define AXES_R_T        (5)
#define AXES_LEFT_RIGHT (6)
#define AXES_UP_DOWN    (7)
#include"math.h"
#include"stdio.h"
inline float normalizeAngle(float dx)
{
	if (dx >= 0)
		dx = fmodf(dx + (float)PI, 2 * (float)PI) - (float)PI;
	else
		dx = fmodf(dx - (float)PI, 2 * (float)PI) + (float)PI;
	return dx;
}
#endif //! _DEFINES_H_