//*****************************************************************************
// Fichier:  ContratException.cpp
// Classe :  ContratException et h�ritiers
//************************************************************************
#include "ContratException.h"
#include <sstream>

using namespace std;

//*****************************************************************************
// Sommaire: Contructeur de la classe de base ContratException
//
// Description:
//    Le constructeur public <code>ContratException(...)</code>
//    initialise l'objet � partir des valeurs pass�es en argument.
//
// Entr�e:
//    const char*  fichP   : Fichier source dans lequel a eu lieu l'erreur
//    unsigned int ligne   : Ligne � laquelle a eu lieu l'erreur
//    const char*  msgP    : Message d�crivant l'erreur: Exception de precondition...
//    const char*  exprP   : Test logique qui a �chou�
//
// Sortie:
//
// Notes:
//
//*****************************************************************************
ContratException::ContratException(const char* fichP, unsigned int prmLigne,
                                   const char* exprP, const char* msgP)
: logic_error(msgP), m_expression(exprP), m_fichier(fichP), m_ligne(prmLigne)
{
}

//*****************************************************************************
// Sommaire:     Construit le texte complet reli� � l'exception de contrat.
//
// Description:  La m�thode publique <code>reqTexteException()</code> permet
//               d'obtenir un texte format� correspondant � l'exception.
//
// Entr�e:
//
// Sortie:       Retourne une string contenant le texte.
//
// Notes:
//
//*****************************************************************************
std::string ContratException::reqTexteException() const
{
   // ---  Pr�pare le message
   ostringstream os;
   os << "Message : " << what() << endl;
   os << "Fichier : " << m_fichier << endl;
   os << "Ligne   : " << m_ligne << endl;
   os << "Test    : " << m_expression << endl;

   return os.str();
}

//*****************************************************************************
// Sommaire: Contructeur de la classe AssertionException
//
// Description:
//    Le constructeur public <code>AssertionException(...)</code> initialise
//    sa classe de base ContratException. On n'a pas d'attribut local. Cette
//    classe est int�ressante pour son TYPE lors du traitement des exceptions.
//
// Entr�e:
//    const char*  fichP   : Fichier source dans lequel a eu lieu l'erreur
//    unsigned int ligne   : Ligne � laquelle a eu lieu l'erreur
//    const char*  exprP   : Test logique qui a �chou�
//
// Sortie:
//
// Notes:
//
//*****************************************************************************
AssertionException::AssertionException(const char* fichP, unsigned int prmLigne,
                                       const char* exprP)
: ContratException(fichP, prmLigne, exprP, "ERREUR D'ASSERTION")
{
}

//*****************************************************************************
// Sommaire: Contructeur de la classe PreconditionException
//
// Description:
//    Le constructeur public <code>PreconditionException(...)</code> initialise
//    sa classe de base ContratException. On n'a pas d'attribut local. Cette
//    classe est int�ressante pour son TYPE lors du traitement des exceptions.
//    La classe repr�sente le erreur de pr�condition dans la th�orie du contrat.
//
// Entr�e:
//    const char*  fichP   : Fichier source dans lequel a eu lieu l'erreur
//    unsigned int ligne   : Ligne � laquelle a eu lieu l'erreur
//    const char*  exprP   : Test logique qui a �chou�
//
// Sortie:
//
// Notes:
//
//*****************************************************************************
PreconditionException::PreconditionException(const char* fichP, unsigned int prmLigne,
                                             const char* exprP)
: ContratException(fichP, prmLigne, exprP, "ERREUR DE PRECONDITION")
{
}

//*****************************************************************************
// Sommaire: Contructeur de la classe PostconditionException
//
// Description:
//    Le constructeur public <code>PostconditionException(...)</code>
//    initialise sa classe de base ContratException.  On n'a pas d'attribut
//    local. Cette classe est int�ressante pour son TYPE lors du traitement des
//    exceptions. La classe repr�sente des erreurs de postcondition dans la
//    th�orie du contrat.
//
// Entr�e:
//    const char*  fichP   : Fichier source dans lequel a eu lieu l'erreur
//    unsigned int ligne   : Ligne � laquelle a eu lieu l'erreur
//    const char*  exprP   : Test logique qui a �chou�
//
// Sortie:
//
// Notes:
//
//*****************************************************************************
PostconditionException::PostconditionException(const char* fichP, unsigned int prmLigne,
                                               const char* exprP)
: ContratException(fichP, prmLigne, exprP, "ERREUR DE POSTCONDITION")
{
}

//*****************************************************************************
// Sommaire: Contructeur de la classe InvariantException
//
// Description:
//    Le constructeur public <code>InvariantException(...)</code> initialise
//    sa classe de base ContratException. On n'a pas d'attribut local. Cette
//    classe est int�ressante pour son TYPE lors du traitement des exceptions.
//    La classe repr�sente des erreurs d'invariant dans la th�orie du contrat.
//
// Entr�e:
//    const char*  fichP   : Fichier source dans lequel a eu lieu l'erreur
//    unsigned int ligne   : Ligne � laquelle a eu lieu l'erreur
//    const char*  exprP   : Test logique qui a �chou�
//
// Sortie:
//
// Notes:
//
//*****************************************************************************
InvariantException::InvariantException(const char* fichP, unsigned int prmLigne,
                                       const char* exprP)
: ContratException(fichP, prmLigne, exprP, "ERREUR D'INVARIANT")
{
}
