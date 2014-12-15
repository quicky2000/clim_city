#ifndef SOUS_SECTEUR_STATS_H
#define SOUS_SECTEUR_STATS_H

class sous_secteur_stats
{
 public:
  sous_secteur_stats(void);
  sous_secteur_stats(const unsigned int p_nrj_produite,const double p_coef_ges_emis);
  sous_secteur_stats(const unsigned int p_nrj_electrecite_nucleaire,
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
		     const double p_tendanciel_autres_ges);

  unsigned int getConsoTotalElectrecite(void)const;
  unsigned int getConsoTotalChaleur(void)const;
  unsigned int getConsoTotalCarburant(void)const;
  
 private:
  //NRJ
  unsigned int m_nrj_electrecite_nucleaire;
  unsigned int m_nrj_carburants_renouvelables;
  unsigned int m_nrj_chaleur_renouvelable;
  unsigned int m_nrj_electricite_renouvelable;
  unsigned int m_nrj_carburants_fossibles;
  unsigned int m_nrj_chaleur_fossile;
  unsigned int m_nrj_electrecite_fossile;
  unsigned int m_nrj_produite;

  //coef to compute GES
  double m_coef_ges_autres;
  double m_coef_ges_electrecite_nucleaire;
  double m_coef_ges_carburants_renouvelables;
  double m_coef_ges_chaleur_renouvelable;
  double m_coef_ges_electrecite_renouvelable;
  double m_coef_ges_carburants_fossiles;
  double m_coef_ges_chaleur_fossile;
  double m_coef_ges_electrecite_fossile;
  double m_cof_ges_emis;

  // Tendanciels
  double m_tendanciel_electrecite;
  double m_tendanciel_carburant;
  double m_tendanciel_chaleur;
  double m_tendanciel_nrj_renouvelable;
  double m_tendanciel_autres_ges;
}
;
#endif
