#ifndef CLIM_CITY_H
#define CLIM_CITY_H

#include "FSM.h"
#include "clim_city_situation.h"
#include "clim_city_transition.h"

#include <map>
#include <string>

class secteur;
class sous_secteur;
class action;

class clim_city:public FSM<clim_city_situation,clim_city_transition>
{
 public:
  clim_city(void);

  // Methods inherited from FSM
  void configure(void);
  string toString(void)const;
  void computeTransitionWeights(std::vector<FSM_weighted_transition_index_if*> &p_vector)const;

  //Dedicated methods
  static const std::map<std::pair<std::string,std::string>,const action*> & getActions(void);
  static const action * getAction(const std::string &p_secteur_name,const std::string & p_action_name);

 private:
  void addAction(const action *p_action);

  static std::map<std::pair<std::string,std::string>,const action*> m_actions;
}
;

#endif
