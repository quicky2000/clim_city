#ifndef CLIM_CITY_CONTEXT_H
#define CLIM_CITY_CONTEXT_H

#include "FSM_context.h"
#include "clim_city_transition.h"

class clim_city_context:public FSM_context<clim_city_transition>
{
 public:
  clim_city_context(void);
  clim_city_context(const clim_city_context & p_context);

  // Methods inherited from interface
  std::string toString(void)const;
  
  // Specific methods

 private:
}
;

#endif
