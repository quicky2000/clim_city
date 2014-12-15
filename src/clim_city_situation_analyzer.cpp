/*    This file is part of clim_city
      Copyright (C) 2014  Julien Thevenon ( julien_thevenon at yahoo.fr )

      This program is free software: you can redistribute it and/or modify
      it under the terms of the GNU General Public License as published by
      the Free Software Foundation, either version 3 of the License, or
      (at your option) any later version.

      This program is distributed in the hope that it will be useful,
      but WITHOUT ANY WARRANTY; without even the implied warranty of
      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
      GNU General Public License for more details.

      You should have received a copy of the GNU General Public License
      along with this program.  If not, see <http://www.gnu.org/licenses/>
*/
#include "clim_city_situation_analyzer.h"

#include "clim_city.h"
#include "action.h"

//------------------------------------------------------------------------------
clim_city_situation_analyzer::clim_city_situation_analyzer(void)
{
}

//------------------------------------------------------------------------------
clim_city_situation_analyzer::~clim_city_situation_analyzer(void)
{
}

//------------------------------------------------------------------------------
string clim_city_situation_analyzer::toString(void)
{
  return "clim_city_situation_analyzer";
}

//------------------------------------------------------------------------------
vector<clim_city_transition*> clim_city_situation_analyzer::getTransitions(clim_city_situation* p_situation)
{
  vector<clim_city_transition*> l_transitions ;

  const map<pair<string,string>,const action*> &l_actions = clim_city::getActions();
  map<pair<string,string>,const action*>::const_iterator l_iter = l_actions.begin();
  map<pair<string,string>,const action*>::const_iterator l_iter_end = l_actions.end();
  while(l_iter != l_iter_end)
    {
      if( ((int)p_situation->getBudgetEntreprise()) >= l_iter->second->getCoutEntreprise() && ((int)p_situation->getBudgetCitoyen()) >= l_iter->second->getCoutCitoyen() && ((int)p_situation->getBudgetPouvoirPublic()) >= l_iter->second->getCoutPouvoirPublic() && !p_situation->isActionApplied(l_iter->second))
	{
	  l_transitions.push_back(new clim_city_transition(l_iter->second->getSousSecteur(),l_iter->second->getName()));
	}
      ++l_iter;
    }

  return l_transitions;
}

  //EOF
