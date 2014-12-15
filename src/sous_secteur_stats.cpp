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
#include "sous_secteur_stats.h"

sous_secteur_stats::sous_secteur_stats(void):
  //NRJ
  m_nrj_electrecite_nucleaire(0),
  m_nrj_carburants_renouvelables(0),
  m_nrj_chaleur_renouvelable(0),
  m_nrj_electricite_renouvelable(0),
  m_nrj_carburants_fossibles(0),
  m_nrj_chaleur_fossile(0),
  m_nrj_electrecite_fossile(0),
  m_nrj_produite(0),
  
//coef to compute GES
  m_coef_ges_autres(0),
  m_coef_ges_electrecite_nucleaire(0),
  m_coef_ges_carburants_renouvelables(0),
  m_coef_ges_chaleur_renouvelable(0),
  m_coef_ges_electrecite_renouvelable(0),
  m_coef_ges_carburants_fossiles(0),
  m_coef_ges_chaleur_fossile(0),
  m_coef_ges_electrecite_fossile(0),
  m_cof_ges_emis(0),
  
// Tendanciels
  m_tendanciel_electrecite(0),
  m_tendanciel_carburant(0),
  m_tendanciel_chaleur(0),
  m_tendanciel_nrj_renouvelable(0),
  m_tendanciel_autres_ges(0)
{
}

sous_secteur_stats::sous_secteur_stats(const unsigned int p_nrj_produite,const double p_coef_ges_emis):
  //NRJ
  m_nrj_electrecite_nucleaire(0),
  m_nrj_carburants_renouvelables(0),
  m_nrj_chaleur_renouvelable(0),
  m_nrj_electricite_renouvelable(0),
  m_nrj_carburants_fossibles(0),
  m_nrj_chaleur_fossile(0),
  m_nrj_electrecite_fossile(0),
  m_nrj_produite(p_nrj_produite),
  
//coef to compute GES
  m_coef_ges_autres(0),
  m_coef_ges_electrecite_nucleaire(0),
  m_coef_ges_carburants_renouvelables(0),
  m_coef_ges_chaleur_renouvelable(0),
  m_coef_ges_electrecite_renouvelable(0),
  m_coef_ges_carburants_fossiles(0),
  m_coef_ges_chaleur_fossile(0),
  m_coef_ges_electrecite_fossile(0),
  m_cof_ges_emis(p_coef_ges_emis),
  
// Tendanciels
  m_tendanciel_electrecite(0),
  m_tendanciel_carburant(0),
  m_tendanciel_chaleur(0),
  m_tendanciel_nrj_renouvelable(0),
  m_tendanciel_autres_ges(0)
{
}


sous_secteur_stats::sous_secteur_stats(const unsigned int p_nrj_electrecite_nucleaire,
				       const unsigned int p_nrj_carburants_renouvelables,
				       const unsigned int p_nrj_chaleur_renouvelable,
				       const unsigned int p_nrj_electricite_renouvelable,
				       const unsigned int p_nrj_carburants_fossibles,
				       const unsigned int p_nrj_chaleur_fossile,
				       const unsigned int p_nrj_electrecite_fossile,
				       const double p_coef_ges_autres,
				       const double p_coef_ges_electrecite_nucleaire,
				       const double p_coef_ges_carburants_renouvelables,
				       const double p_coef_ges_chaleur_renouvelable,
				       const double p_coef_ges_electrecite_renouvelable,
				       const double p_coef_ges_carburants_fossiles,
				       const double p_coef_ges_chaleur_fossile,
				       const double p_coef_ges_electrecite_fossile,
				       const double p_tendanciel_electrecite,
				       const double p_tendanciel_carburant,
				       const double p_tendanciel_chaleur,
				       const double p_tendanciel_nrj_renouvelable,
				       const double p_tendanciel_autres_ges):
  //NRJ
    m_nrj_electrecite_nucleaire(p_nrj_electrecite_nucleaire),
    m_nrj_carburants_renouvelables(p_nrj_carburants_renouvelables),
    m_nrj_chaleur_renouvelable(p_nrj_chaleur_renouvelable),
    m_nrj_electricite_renouvelable(p_nrj_electricite_renouvelable),
    m_nrj_carburants_fossibles(p_nrj_carburants_fossibles),
    m_nrj_chaleur_fossile(p_nrj_chaleur_fossile),
    m_nrj_electrecite_fossile(p_nrj_electrecite_fossile),
    m_nrj_produite(0),

  //coef to compute GES
    m_coef_ges_autres(p_coef_ges_autres),
    m_coef_ges_electrecite_nucleaire(p_coef_ges_electrecite_nucleaire),
    m_coef_ges_carburants_renouvelables(p_coef_ges_carburants_renouvelables),
    m_coef_ges_chaleur_renouvelable(p_coef_ges_chaleur_renouvelable),
    m_coef_ges_electrecite_renouvelable(p_coef_ges_electrecite_renouvelable),
    m_coef_ges_carburants_fossiles(p_coef_ges_carburants_fossiles),
    m_coef_ges_chaleur_fossile(p_coef_ges_chaleur_fossile),
    m_coef_ges_electrecite_fossile(p_coef_ges_electrecite_fossile),
    m_cof_ges_emis(0),

  // Tendanciels
    m_tendanciel_electrecite(p_tendanciel_electrecite),
    m_tendanciel_carburant(p_tendanciel_carburant),
    m_tendanciel_chaleur(p_tendanciel_chaleur),
    m_tendanciel_nrj_renouvelable(p_tendanciel_nrj_renouvelable),
    m_tendanciel_autres_ges(p_tendanciel_autres_ges)
{
}

unsigned int sous_secteur_stats::getConsoTotalElectrecite(void)const
{
   return m_nrj_electrecite_nucleaire + m_nrj_electricite_renouvelable + m_nrj_electrecite_fossile;

}
 
unsigned int sous_secteur_stats::getConsoTotalChaleur(void)const
{
   return m_nrj_chaleur_renouvelable + m_nrj_chaleur_fossile;
}

unsigned int sous_secteur_stats::getConsoTotalCarburant(void)const
{
   return m_nrj_carburants_renouvelables + m_nrj_carburants_fossibles;
}
  
//EOF
