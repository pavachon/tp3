//*****************************************************************************
// Fichier: Entreprise.h
//
// Classe: Entreprise
//
// Sommaire: Classe implantant le concept d'entreprise.
//
// Description: La classe Entreprise permet d'implanter le concept d'entreprise.
// On y implante le type de données abstrait traditionnel avec
// les fonctionnalités courantes, soient ##############################
// Attributs: ############################
//
// Note: 
//*****************************************************************************
// 22-11-08 Pierre-Alexandre VACHON Version Initiale
//*****************************************************************************
#ifndef ENTREPRISE_H_DEJA_PRESENT
#define ENTREPRISE_H_DEJA_PRESENT

#include "Abonne.h"

namespace tp3{

class Entreprise :public Abonne{
public:
	// Constructeur
	Entreprise(const std::string& nom, 
		const std::string& telephone, 
		const std::string& adresse, 
		const std::string& siteWeb, 
		const std::string& telecopie, 
		const std::string& categorie = "Entreprise");
	Entreprise(std::istream& is);

	// Methodes de lecture
	std::string reqSiteWeb() const;
	std::string reqTelecopie() const;

	// Methodes virtuelles
	virtual Abonne* clone() const{return new Entreprise(*this);};
	//virtual std::string reqAbonneFormate() const;
	//virtual void serialise(std::ostream& os) const;
	//virtual void deserialise(std::istream& is); 

private:
	// Attributs
	std::string m_siteWeb;
	std::string m_telecopie;

	// Constructeur
	Entreprise() {};

	// Contrat Exception
	void verifieInvariant() const;

};//--- class Entreprise

//*****************************************************************************
// Sommaire: Retourne le site web de l'objet abonne courant
//
// Description: La méthode reqSiteWeb() permet de lire l'argument prive m_siteWeb
//				et le retourne. 
//
// Entrée: <nil>
//
// Sortie: Retourne un string contenant le site web de l'abonne courant.
//
// Notes:
//****************************************************************************
inline std::string Entreprise::reqSiteWeb() const
{
	return m_siteWeb;
}

//*****************************************************************************
// Sommaire: Retourne le numero de telecopie de l'objet abonne courant
//
// Description: La méthode reqNom() permet de lire l'argument prive m_telecopie
//				et le retourne. 
//
// Entrée: <nil>
//
// Sortie: Retourne un string contenant le numero de telecopie de l'abonne courant.
//
// Notes:
//****************************************************************************
inline std::string Entreprise::reqTelecopie() const
{
	return m_telecopie;
}
}//--- namespace tp3
#endif //--- ENTREPRISE_H_DEJA_INCLU