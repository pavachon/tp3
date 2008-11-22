//*****************************************************************************
// Fichier: Abonne.h
//
// Classe: Abonne
//
// Sommaire: Classe implantant le concept d'abonne.
//
// Description: La classe Abonne permet d'implanter le concept d'abonne general.
// On y implante le type de données abstrait traditionnel avec
// les fonctionnalités courantes, soient ##############################
// Attributs: ############################
//
// Note: 
//*****************************************************************************
// 20-11-08 Pierre-Alexandre VACHON Version Initiale
//*****************************************************************************
#ifndef ABONNE_H_DEJA_INCLU
#define ABONNE_H_DEJA_INCLU

#include "ContratException.h"
#include "ValidationFormat.h"

#include <iostream>
#include <string>

namespace tp3{

class Abonne{
	// Declarations d'amitie
	friend std::ostream& operator<<(std::ostream& os, const Abonne& unAbonne);
	friend std::istream& operator>>(std::istream& is, Abonne& unAbonne);

public:
	// Constructeurs
	Abonne(const std::string& nom,
		const std::string& telephone,
		const std::string& adresse, 
		const std::string& categorie);

	Abonne(const Abonne& abonne);

	// Destructeur virtuel
	~Abonne(){};

	// Methodes d'assignation
	void asgTelephone(const std::string& telephone);
	void asgAdresse(const std::string& adresse);

	// Methodes de lecture
	std::string reqNom() const;
	std::string reqTelephone() const;
	std::string reqAdresse() const;
	std::string reqCategorie() const;

	// Methodes virtuelles pures
	//virtual std::string reqAbonneFormate() const = 0;
	//virtual Abonne* clone() const = 0;

	// Methodes virtuelles
	virtual void serialise(std::ostream& os) const;
	virtual void deserialise(std::istream& is);

	// Operateurs surcharges
	bool operator==(const Abonne& unAbonne) const;

private:
	// Attributs
	std::string m_nom;
	std::string m_telephone;
	std::string m_adresse;
	std::string m_categorie;

	// Contrat Exception
	void verifieInvariant() const;

protected:
	Abonne(){};
}; //--- class Abonne


//*****************************************************************************
// Sommaire: Retourne le nom de l'objet abonne courant
//
// Description: La méthode reqNom() permet de lire l'argument prive m_nom et le
//				retourne. 
//
// Entrée: <nil>
//
// Sortie: Retourne un string contenant le nom de l'abonne courant.
//
// Notes:
//****************************************************************************
inline std::string Abonne::reqNom() const
{
	return m_nom;
}

//*****************************************************************************
// Sommaire: Retourne le telephone de l'objet abonne courant
//
// Description: La méthode reqTelephone() permet de lire l'argument prive 
//				m_telephone et le retourne. 
//
// Entrée: <nil>
//
// Sortie: Retourne un string contenant le telephone de l'abonne courant.
//
// Notes:
//****************************************************************************
inline std::string Abonne::reqTelephone() const
{
	return m_telephone;
}

//*****************************************************************************
// Sommaire: Retourne l'adresse de l'objet abonne courant
//
// Description: La méthode reqAdresse() permet de lire l'argument prive m_adresse
//				et le retourne. 
//
// Entrée: <nil>
//
// Sortie: Retourne un string contenant l'adresse de l'abonne courant.
//
// Notes:
//****************************************************************************
inline std::string Abonne::reqAdresse() const
{
	return m_adresse;
}

//*****************************************************************************
// Sommaire: Retourne la categorie de l'objet abonne courant
//
// Description: La méthode reqCategorie() permet de lire l'argument prive 
//				m_categorie et le retourne. 
//
// Entrée: <nil>
//
// Sortie: Retourne un string contenant la categorie de l'abonne courant.
//
// Notes:
//****************************************************************************
inline std::string Abonne::reqCategorie() const
{
	return m_categorie;
}


} //--- namespace tp3
#endif //--- ABONNE_H_DEJA_INCLU