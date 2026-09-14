#include "udf.h"
DEFINE_CG_MOTION(left1,dt,vel,omega,time,dtime)
{
	omega[2] = 1047.1975511;
}
DEFINE_CG_MOTION(right2,dt,vel,omega,time,dtime)
{
	omega[2] = -1047.1975511;
}