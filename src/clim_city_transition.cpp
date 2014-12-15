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
#include "clim_city_transition.h"

using namespace std;

//------------------------------------------------------------------------------
clim_city_transition::clim_city_transition(const string &p_secteur_name,const string &p_name):
  m_action_name(p_name),
  m_secteur_name(p_secteur_name)
{
}

//------------------------------------------------------------------------------
string clim_city_transition::toString(void)const
{
  return "transition = \"" + m_secteur_name + "::" + m_action_name + "\"";
}

//------------------------------------------------------------------------------
const std::string & clim_city_transition::getActionName(void)const
{
  return m_action_name;
}

//------------------------------------------------------------------------------
const std::string & clim_city_transition::getSecteurName(void)const
{
  return m_secteur_name;
}

//EOF
