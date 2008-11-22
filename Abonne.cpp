//*****************************************************************************
// Fichier: Abonne.cpp
// Classe: Abonne
//*****************************************************************************
// 20-11-08 Pierre-Alexandre VACHON Version Initiale
//*****************************************************************************
#include "Abonne.h"

using namespace std;
using namespace util;

namespace tp3{

//*****************************************************************************
// Sommaire: Constructeur de la classe Abonne
//
// Description: Le constructeur prend en arguments nom, telephone, adresse et
//				categorie pour construire un objet de la classe Abonne.
//
// Entrée: std::string& nom, std::string& telephone, std::string& adresse, 
//			std::string& categorie.
//
// Sortie: <nil>
//
// Notes: Le nom et l'adresse ne doivent pas etre vides et le telephone valide
//****************************************************************************
Abonne::Abonne(const std::string& nom, const std::string& telephone, 
			   const std::string& adresse, const std::string& categorie)
{
	PRECONDITION(!nom.empty());
	PRECONDITION(validerTelephone(telephone));
	PRECONDITION(!adresse.empty());
	//PRECONDITION(categorie == "Entreprise" || categorie == "Residence");

	m_nom = nom;
	m_telephone = telephone;
	m_adresse = adresse;
	m_categorie = categorie;

	INVARIANTS();
}

//*****************************************************************************
// Sommaire: Constructeur de copie de la classe Abonne
//
// Description: Le constructeur de copie prend en argument un objet deja 
//				existant de la classe Abonne et en construit un identique
//
// Entrée: Abonne& unAbonne
//
// Sortie: <nil>
//
// Notes: 
//****************************************************************************
Abonne::Abonne(const Abonne& abonne)
{
	PRECONDITION(!abonne.reqNom().empty());
	PRECONDITION(validerTelephone(abonne.reqTelephone()));
	PRECONDITION(!abonne.reqAdresse().empty());

	m_nom = abonne.reqNom();
	m_telephone = abonne.reqTelephone();
	m_adresse = abonne.reqAdresse();
	m_categorie = abonne.reqCategorie();

	INVARIANTS();
}

//*****************************************************************************
// Sommaire:		Assigne un numero de telephone a un objet Abonne.
//
// Description:		Cette fonction verifie si le numero est valide et s'il 
//					l'est, l'assigne a l'objet.
//
// Entrée:			Une string contenant un numero de telephone
//
// Sortie:			<nil>
//
// Note:			
//
//*****************************************************************************
void Abonne::asgTelephone(const std::string& telephone)
{
	PRECONDITION(validerTelephone(telephone));

	m_telephone = telephone;

	POSTCONDITION(validerTelephone(m_telephone));
}

//*****************************************************************************
// Sommaire:		Assigne une adresse a un objet Abonne.
//
// Description:		Cette fonction verifie si l'adresse est vide et sinon, 
//					l'assigne a l'objet.
//
// Entrée:			Une string contenant une adresse.
//
// Sortie:			<nil>
//
// Note:			
//
//*****************************************************************************
void Abonne::asgAdresse(const std::string& adresse)
{
	PRECONDITION(!adresse.empty());

	m_adresse = adresse;

	POSTCONDITION(!m_adresse.empty());
}

//*****************************************************************************
// Sommaire:      Verifie si tous les attributs de deux Abonnes sont identiques
//
// Description:   Compare tous les attributs pour savoir si deux abonnes sont identiques
//
// Entrée:        Un objet Abonne
//
// Sortie:        True si tous les attributs sont egaux, false sinon
//
// Note:
//
//*****************************************************************************
bool Abonne::operator==(const Abonne& unAbonne) const
{
	PRECONDITION(!unAbonne.reqNom().empty());
	PRECONDITION(validerTelephone(unAbonne.reqTelephone()));
	PRECONDITION(!unAbonne.reqAdresse().empty());
	PRECONDITION(!m_nom.empty());
	PRECONDITION(validerTelephone(m_telephone));
	PRECONDITION(!m_adresse.empty());

	if(m_nom == unAbonne.reqNom() 
		&& m_telephone == unAbonne.reqTelephone() 
		&& m_adresse == unAbonne.reqTelephone()
		&& m_categorie == unAbonne.reqCategorie())
		return true;
	else
		return false;
}

//*****************************************************************************
// Sommaire:    Permet d'inscrire sur 4 lignes la categorie, nom, adresse et
//				le telephone d'un abonne
//
// Description:   
//
// Entrée:        Une reference sur un objet ostream pour l'inscription
//
// Sortie:        <nil>
//
// Note:
//
//*****************************************************************************
void Abonne::serialise(std::ostream& os) const
{
	PRECONDITION(os != NULL);

	os << m_categorie << endl
		<< m_nom << endl
		<< m_telephone << endl
		<< m_adresse << endl;
}

//*****************************************************************************
// Sommaire:    Permet de lire sur 4 lignes la categorie, nom, adresse et
//				le telephone d'un abonne
//
// Description:   
//
// Entrée:        Une reference sur un objet istream pour la lecture
//
// Sortie:        <nil>
//
// Note:
//
//*****************************************************************************
void Abonne::deserialise(std::istream& is)
{
	char categorie[256];
	char nom[256];
	char telephone[256];
	char adresse[256];

	ASSERTION(is != NULL);

	is.getline(categorie, 255);
	is.getline(nom, 255);
	is.getline(telephone, 255);
	is.getline(adresse, 255);

	/* PAS CERTAIN DE S'IL FAUT ASSIGNER CES VALEURS A L'ABONNE COURANT OU PAS
	this->m_categorie = categorie;
	this->m_nom = nom;
	this->m_telephone = telephone;
	this->m_adresse = adresse;

	INVARIANTS();
	*/
}

//*****************************************************************************
// Sommaire:    Permet d'utiliser un objet Abonne avec une insertion de flux standard
//
// Description:   Fait appel a la methode serialise(std::istream& is)
//
// Entrée:        Une reference sur un objet ostream pour l'insertion et une
//					reference a un abonne valide
//
// Sortie:        Un objet ostream contenant le flux de l'abonne passe en entree
//
// Note:
//
//*****************************************************************************
std::ostream& operator<<(std::ostream& os, const Abonne& unAbonne)
{
	PRECONDITION(!unAbonne.reqNom().empty());
	PRECONDITION(validerTelephone(unAbonne.reqTelephone()));
	PRECONDITION(!unAbonne.reqAdresse().empty());
	PRECONDITION(os != NULL);

	unAbonne.serialise(os);

	return os;
}

std::istream& operator>>(std::istream& is, Abonne& unAbonne)
{
	PRECONDITION(is != NULL);

	unAbonne.deserialise(is);

	return is;
}
//*****************************************************************************
// Sommaire:      Defini les invariants pour la theorie du contrat
//
// Description:   Cette fonction se charge d'executer tous les tests sur les 
//				  invariants de la classe Abonne
//
// Entrée:        <nil>
//
// Sortie:        <nil>
//
// Note:
//
//*****************************************************************************
void Abonne::verifieInvariant() const
{
	INVARIANT(!m_nom.empty());
	INVARIANT(validerTelephone(m_telephone));
	INVARIANT(!m_adresse.empty());
	//INVARIANT(m_categorie == "Entreprise" || m_categorie == "Residence");
}
} //--- namespace tp3
