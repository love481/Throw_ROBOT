#pragma once
#ifndef _ROBO_INIT_H_
#define _ROBO_INIT_H_
#include"tim.h"
#include"motor.h"
#include"encoder.h"
#include"free_wheel.h"
//initilze all functions for their respective objects
void motorAllInitilize(void);
void encoderAllInitilize(void);
void freeWheelAllInitilize(void);
void robo_init(void);
#endif //!_ROBO_INIT_H_

