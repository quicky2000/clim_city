#ifndef CLIM_CITY_SITUATION_ANALYZER
#define CLIM_CITY_SITUATION_ANALYZER

#include "FSM_situation_analyzer.h"
#include "clim_city_situation.h"
#include "clim_city_transition.h"

class clim_city_situation_analyzer: public FSM_situation_analyzer<clim_city_situation,clim_city_transition>
{
 public:
  // Constructors and Destructors
  clim_city_situation_analyzer(void);
  ~clim_city_situation_analyzer(void);

  // Methods inherited from FSM_situation_analyzer
  std::string toString(void);
  std::vector<clim_city_transition*> getTransitions(clim_city_situation* p_situation);

 private:

};
#endif /* CLIM_CITY_SITUATION_ANALYZER */
