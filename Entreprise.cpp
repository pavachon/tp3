//*****************************************************************************
// Fichier: Entreprise.cpp
// Classe: Entreprise
//*****************************************************************************
// 20-11-08 Pierre-Alexandre VACHON Version Initiale
//*****************************************************************************
#include "Entreprise.h"

using namespace util;
using namespace std;

namespace tp3{


Entreprise::Entreprise(const std::string& nom, const std::string& telephone, 
	const std::string& adresse, const std::string& siteWeb, 
	const std::string& telecopie, const std::string& categorie):
	Abonne(nom, telephone, adresse, categorie)
{
	PRECONDITION(!siteWeb.empty());
	m_siteWeb = siteWeb;
	m_telecopie = telecopie;
	INVARIANTS();
}

Entreprise::Entreprise(std::istream &is)
{
	
}

void Entreprise::verifieInvariant() const
{
	INVARIANT(!m_siteWeb.empty());
}
}//--- namespace tp3