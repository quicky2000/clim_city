#ifndef ACTION_H
#define ACTION_H

#include <string>
#include <set>

class sous_secteur;

class action
{
 public:
  action(const std::string &p_name,const sous_secteur *p_sous_secteur,  int p_cout_pouvoir_public, int p_cout_entreprise, int p_cout_citoyen);
  void addDependancy(const std::string &p_action_name,const std::string &p_sous_secteur_name);
  const std::string & getName(void)const;
  const std::string & getSousSecteur(void)const;
  int getCoutPouvoirPublic(void)const;
  int getCoutEntreprise(void)const;
  int getCoutCitoyen(void)const;
 private:
  std::string m_name;
  int m_cout_pouvoir_public;
  int m_cout_entreprise;
  int m_cout_citoyen;
  std::string m_sous_secteur;
  std::set<std::pair<std::string,std::string> > m_dependancies;
}
;

#endif
