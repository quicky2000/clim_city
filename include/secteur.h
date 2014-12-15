#ifndef SECTEUR_H
#define SECTEUR_H

#include <string>
#include <set>

class secteur
{
 public:
  secteur(const std::string &p_name);
  void add_sub_sector(const std::string &p_name);

 private:
  std::string m_name;
  std::set<std::string> m_subsectors;
}
;

#endif
