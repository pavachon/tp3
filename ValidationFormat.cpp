//*****************************************************************************
// Fichier:     ValidationFormat.cpp
//*****************************************************************************
// 14-11-2008 Pierre-Aelxandre VACHON  Version initiale
//*****************************************************************************

#include "ValidationFormat.h"

using namespace std;

namespace util
{
//*****************************************************************************
// Sommaire:      Retourne le format valide d'un numéro de téléphone
//
// Description:   Cette fonction retourne le format valide d'un numéro de
//                téléphone canadien, où 9 correspond à un chiffre et
//                "()-" correspond directement à ces caractères.
//
// Entrée:        
//
// Sortie:        Retourne le format, i.e. (999) 999-9999
//
// Note:
//
//*****************************************************************************
std::string reqFormatTelephone()
{
	return "(999) 999-9999";
}

//*****************************************************************************
// Sommaire:      Verifie le format du numero de telephone en entree
//
// Description:   Cette fonction retourne un booleen confirmant ou infirmant la
//                validite du format du numero de telephone canadien en entree.
//
// Entrée:        Un numero de telephone dans une std::string
//
// Sortie:        Retourne true si le numero est valide, false sinon
//
// Note:
//
//*****************************************************************************
bool validerTelephone(const std::string& telephone)
{
	if(telephone.length() != 14)
		return false;
	if(telephone.find_first_not_of("0123456789- "))
		return false;
	if(telephone[0] != '(')
		return false;
	if(telephone[1] == '0')
		return false;
	if(telephone[4] != ')')
		return false;
	if(telephone[5] != ' ')
		return false;
	if(telephone[9] != '-')
		return false;
	else
		return true;
}

//*****************************************************************************
// Sommaire:      Retourne le format valide d'un code postal
//
// Description:   Cette fonction retourne le format valide d'un code postal
//                canadien, où X correspond à une lettre majuscule et 
//                9 correspond à un chiffre.
//
// Entrée:        
//
// Sortie:        Retourne le format, i.e. X9X 9X9
//
// Note:
//
//*****************************************************************************
std::string reqFormatCodePostal()
{
	return "X9X 9X9";
}

//*****************************************************************************
// Sommaire:      Verifie le format du code postal en entree
//
// Description:   Cette fonction retourne un booleen confirmant ou infirmant la
//                validite du format du code postal canadien en entree.
//
// Entrée:        Un code postal dans une std::string
//
// Sortie:        Retourne true si le code postal est valide, false sinon
//
// Note:
//
//*****************************************************************************
bool validerCodePostal(const std::string& codePostal)
{
	if(codePostal.length() != 7)
		return false;
	if(codePostal[0] < 'A' || codePostal[0] > 'Z')
		return false;
	if(codePostal[1] < '0' || codePostal[1] > '9')
		return false;
	if(codePostal[2] < 'A' || codePostal[2] > 'Z')
		return false;
	if(codePostal[3] != ' ')
		return false;
	if(codePostal[4] < '0' || codePostal[1] > '9')
		return false;
	if(codePostal[5] < 'A' || codePostal[2] > 'Z')
		return false;
	if(codePostal[6] < '0' || codePostal[1] > '9')
		return false;
	return true;
}
} // namespace util