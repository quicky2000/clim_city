#ifndef SOUS_SECTEUR_H
#define SOUS_SECTEUR_H

#include <string>
#include <set>

class sous_secteur
{
 public:
  sous_secteur(const std::string &p_name);
  void add_action(const std::string &p_name);
  const std::string & getName(void)const;
 private:
  std::string m_name;
  std::set<std::string> m_actions;
}
;

#endif
