#ifndef CLIM_CITY_SITUATION_H
#define CLIM_CITY_SITUATION_H

#include "FSM_situation.h"
#include "clim_city_context.h"
#include "sous_secteur_stats.h"

#include <set>
#include <map>

class action;

class clim_city_situation:public FSM_situation<clim_city_context>
{
 public:
  clim_city_situation(void);
  
  // Methods inherited from FSM_situation
  std::string toString(void)const;
  std::string getStringId(void)const;
  bool isFinal(void)const;
  bool less(const FSM_situation_if *p_object2)const;

  // Dedicated methods
  bool less(const clim_city_situation *p_situation)const;
  unsigned int getYear(void)const;
  unsigned int getBudgetPouvoirPublic(void)const;
  unsigned int getBudgetEntreprise(void)const;
  unsigned int getBudgetCitoyen(void)const;
  bool isActionApplied(const action * p_action)const;

  void incYear(void);
  void updateBudget(int p_cout_pouvoir_public,int p_cout_entreprise, int p_cout_citoyen);
  void setActionApplied(const action *p_action);
 private:
  unsigned int m_year;
  unsigned int m_budget_pouvoir_public;
  unsigned int m_budget_entreprise;
  unsigned int m_budget_citoyen;
  std::set<const action *> m_applied_actions;
  std::map<std::string,sous_secteur_stats> m_sous_secteur_stats;
}
;

#endif
