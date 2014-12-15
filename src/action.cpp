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
#include "action.h"
#include "sous_secteur.h"

using namespace std;

//------------------------------------------------------------------------------
action::action(const std::string &p_name, const sous_secteur *p_sous_secteur, int p_cout_pouvoir_public, int p_cout_entreprise, int p_cout_citoyen):
  m_name(p_name),
  m_cout_pouvoir_public(p_cout_pouvoir_public),
  m_cout_entreprise(p_cout_entreprise),
  m_cout_citoyen(p_cout_citoyen),
  m_sous_secteur(p_sous_secteur->getName())
{
}

//------------------------------------------------------------------------------
void action::addDependancy(const string &p_action_name, const string &p_sous_secteur_name)
{
  m_dependancies.insert(pair<string,string>(p_action_name,p_sous_secteur_name));
}

//------------------------------------------------------------------------------
const string & action::getName(void)const
{
  return m_name;
}

//------------------------------------------------------------------------------
const string & action::getSousSecteur(void)const
{
  return m_sous_secteur;
}

//------------------------------------------------------------------------------
int action::getCoutPouvoirPublic(void)const
{
  return m_cout_pouvoir_public;
}

//------------------------------------------------------------------------------
int action::getCoutEntreprise(void)const
{
  return m_cout_entreprise;
}

//------------------------------------------------------------------------------
int action::getCoutCitoyen(void)const
{
  return m_cout_citoyen;
}

//EOF
