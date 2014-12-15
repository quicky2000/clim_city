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
#include "clim_city_situation.h"

#include <sstream>
using namespace std;

string toString(unsigned int p_int)
{
  stringstream l_stream;
  l_stream << p_int;
  return l_stream.str();
}

//------------------------------------------------------------------------------
clim_city_situation::clim_city_situation(void):
  m_year(2008),
  m_budget_pouvoir_public(50),
  m_budget_entreprise(50),
  m_budget_citoyen(30)
{
  m_sous_secteur_stats.insert(map<string,sous_secteur_stats>::value_type("Habitat",	sous_secteur_stats()));



  this->setContext(new clim_city_context());
}

//------------------------------------------------------------------------------
string clim_city_situation::toString(void)const
{
  string l_result = string("----------------------------------\n") ;
  l_result += " Year : " + ::toString(m_year) + "\n" ;

  
  l_result += " Budget entreprise : " + ::toString(m_budget_entreprise) + "\n";
  l_result += " Budget pouvoir public : " + ::toString(m_budget_pouvoir_public) + "\n";
  l_result += " Budget citoyen : " + ::toString(m_budget_citoyen) + "\n";
  return l_result;
}

//------------------------------------------------------------------------------
string clim_city_situation::getStringId(void)const
{
  return "";
}

//------------------------------------------------------------------------------
bool clim_city_situation::isFinal(void)const
{
  return m_year == 2058;
}

//------------------------------------------------------------------------------
bool clim_city_situation::less(const FSM_situation_if *p_object2)const
{
  return this->less(dynamic_cast<const clim_city_situation*>(p_object2)); 
}

//------------------------------------------------------------------------------
unsigned int clim_city_situation::getYear(void)const
{
  return m_year;
}

//------------------------------------------------------------------------------
unsigned int clim_city_situation::getBudgetPouvoirPublic(void)const
{
  return m_budget_pouvoir_public;
}

//------------------------------------------------------------------------------
unsigned int clim_city_situation::getBudgetEntreprise(void)const
{
  return m_budget_entreprise;
}

//------------------------------------------------------------------------------
unsigned int clim_city_situation::getBudgetCitoyen(void)const
{
  return m_budget_citoyen;
}

//------------------------------------------------------------------------------
bool clim_city_situation::isActionApplied(const action * p_action)const
{
  return m_applied_actions.find(p_action) != m_applied_actions.end();
}

//------------------------------------------------------------------------------
void clim_city_situation::incYear(void)
{
  m_year++;
}

//------------------------------------------------------------------------------
void clim_city_situation::updateBudget(int p_cout_pouvoir_public,int p_cout_entreprise, int p_cout_citoyen)
{
  m_budget_pouvoir_public = m_budget_pouvoir_public - p_cout_pouvoir_public;
  m_budget_entreprise = m_budget_entreprise - p_cout_entreprise;
  m_budget_citoyen = m_budget_citoyen - p_cout_citoyen;
}

//------------------------------------------------------------------------------
void clim_city_situation::setActionApplied(const action *p_action)
{
  m_applied_actions.insert(p_action);
}

//------------------------------------------------------------------------------
bool clim_city_situation::less(const clim_city_situation *p_situation)const
{
  bool l_result = false;
  if(m_year < p_situation->m_year)
    {
      l_result = true;
    }
  else if (m_budget_pouvoir_public < p_situation->m_budget_pouvoir_public)
    {
      l_result = true;
    }
  else if (m_budget_entreprise < p_situation->m_budget_entreprise)
    {
      l_result = true;
    }
  else if (m_budget_citoyen < p_situation->m_budget_citoyen)
    {
      l_result = true;
    }

  return l_result;
}

//EOF
