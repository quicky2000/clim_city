#include "sous_secteur.h"

using namespace std;

sous_secteur::sous_secteur(const std::string &p_name):
  m_name(p_name)
{
}

void sous_secteur::add_action(const std::string &p_name)
{
  m_actions.insert(p_name);
}

const string & sous_secteur::getName(void)const
{
  return m_name;
}
