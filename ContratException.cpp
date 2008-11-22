//*****************************************************************************
// Fichier:  ContratException.cpp
// Classe :  ContratException et héritiers
//************************************************************************
#include "ContratException.h"
#include <sstream>

using namespace std;

//*****************************************************************************
// Sommaire: Contructeur de la classe de base ContratException
//
// Description:
//    Le constructeur public <code>ContratException(...)</code>
//    initialise l'objet à partir des valeurs passées en argument.
//
// Entrée:
//    const char*  fichP   : Fichier source dans lequel a eu lieu l'erreur
//    unsigned int ligne   : Ligne à laquelle a eu lieu l'erreur
//    const char*  msgP    : Message décrivant l'erreur: Exception de precondition...
//    const char*  exprP   : Test logique qui a échoué
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
// Sommaire:     Construit le texte complet relié à l'exception de contrat.
//
// Description:  La méthode publique <code>reqTexteException()</code> permet
//               d'obtenir un texte formaté correspondant à l'exception.
//
// Entrée:
//
// Sortie:       Retourne une string contenant le texte.
//
// Notes:
//
//*****************************************************************************
std::string ContratException::reqTexteException() const
{
   // ---  Prépare le message
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
//    classe est intéressante pour son TYPE lors du traitement des exceptions.
//
// Entrée:
//    const char*  fichP   : Fichier source dans lequel a eu lieu l'erreur
//    unsigned int ligne   : Ligne à laquelle a eu lieu l'erreur
//    const char*  exprP   : Test logique qui a échoué
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
//    classe est intéressante pour son TYPE lors du traitement des exceptions.
//    La classe représente le erreur de précondition dans la théorie du contrat.
//
// Entrée:
//    const char*  fichP   : Fichier source dans lequel a eu lieu l'erreur
//    unsigned int ligne   : Ligne à laquelle a eu lieu l'erreur
//    const char*  exprP   : Test logique qui a échoué
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
//    local. Cette classe est intéressante pour son TYPE lors du traitement des
//    exceptions. La classe représente des erreurs de postcondition dans la
//    théorie du contrat.
//
// Entrée:
//    const char*  fichP   : Fichier source dans lequel a eu lieu l'erreur
//    unsigned int ligne   : Ligne à laquelle a eu lieu l'erreur
//    const char*  exprP   : Test logique qui a échoué
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
//    classe est intéressante pour son TYPE lors du traitement des exceptions.
//    La classe représente des erreurs d'invariant dans la théorie du contrat.
//
// Entrée:
//    const char*  fichP   : Fichier source dans lequel a eu lieu l'erreur
//    unsigned int ligne   : Ligne à laquelle a eu lieu l'erreur
//    const char*  exprP   : Test logique qui a échoué
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
