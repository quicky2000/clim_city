#ifndef CLIM_CITY_TRANSITION_H
#define CLIM_CITY_TRANSITION_H

#include "FSM_transition_if.h"

class clim_city_transition:public FSM_transition_if
{
 public:
  clim_city_transition(const std::string &p_secteur_name,const std::string &p_action_name);

  // Methods inherited from interface
  std::string toString(void)const;
  
  // Specific methods
  const std::string & getActionName(void)const;
  const std::string & getSecteurName(void)const;

 private:
  std::string m_action_name;
  std::string m_secteur_name;
}
;

#endif
