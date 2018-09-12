#ifndef PID_H
#define PID_H
#include <vector>

class PID {
public:
  /*
  * Errors
  */
	double p_error;
	double i_error;
	double d_error;

  double dp[3] = {1,1,1};
  
  /*
  * Coefficients
  */ 
  double p[3] = {0,0,0};
  

  //Needed to calculate average CTE
  std::vector<int> cte_list;

  double best_error;
  double prev_cte;
  int step = 0;

  //current error parameter to optimize, p,i or d
  int current_index;

  //resume calculating error for the same error param, p, i or d
  bool resumeFromNestedElse = false;
  bool initialized = false;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  //returns true if pid is initialized
  bool isInitialized();
};

#endif /* PID_H */
