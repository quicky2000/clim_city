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
#include "clim_city_motor.h"

#include "clim_city.h"
#include "action.h"

//------------------------------------------------------------------------------
clim_city_motor::clim_city_motor(void)
{
}

//------------------------------------------------------------------------------
std::string clim_city_motor::toString(void)
{
  return "clim_city_motor";
}

//------------------------------------------------------------------------------
clim_city_situation* clim_city_motor::run(clim_city_situation* p_situation, clim_city_transition *p_transition)
{
  clim_city_situation *l_situation = new clim_city_situation(*p_situation);
  const action *l_action = clim_city::getAction(p_transition->getSecteurName(),p_transition->getActionName());

  l_situation->updateBudget(l_action->getCoutPouvoirPublic(),l_action->getCoutEntreprise(),l_action->getCoutCitoyen());

  if(p_transition->getSecteurName() == "general" && p_transition->getActionName() == "next year")
    {
      l_situation->incYear();
    }
  else
    {
      l_situation->setActionApplied(l_action);
    }

  return l_situation;
}

  //EOF
