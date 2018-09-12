#include "PID.h"
#include<limits>
#include<numeric>
#include<iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	p[0] = Kp;
	p[1] = Ki;
	p[2] = Kd;
	best_error = numeric_limits<double>::max();
	current_index = 2;//p
	initialized = true;
}

void PID::UpdateError(double cte) {
	if (step == 0) {
		prev_cte = cte;
	}
	p_error = cte;
	i_error += cte;
	d_error = cte - prev_cte;
	prev_cte = cte;
	step++;
}

double PID::TotalError() {
	return	-p[0] * p_error
			- p[1] * i_error
			- p[2] * d_error;
}

bool PID::isInitialized() {
	return initialized;
}
	 


