#ifndef CLIM_CITY_MOTOR_H
#define CLIM_CITY_MOTOR_H

#include "FSM_motor.h"
#include "clim_city_situation.h"
#include "clim_city_transition.h"

class clim_city_motor:public FSM_motor<clim_city_situation,clim_city_transition>
{
 public:
  clim_city_motor(void);

  // Methods inherited from FSM_motor
  std::string toString(void);
  clim_city_situation* run(clim_city_situation* p_situation, clim_city_transition *p_transition);
}
;

#endif
