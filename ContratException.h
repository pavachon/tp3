//************************************************************************
// Fichier:     ContratException.h
//
// Classes:     ContratException, AssertionException, PreconditionException,
//              PostconditionException, InvariantException
//
// Sommaire:    Hiérarchie pour la gestion des erreurs de théorie du contrat
//
// Description: Ces classes constituent la hiérarchie pour la gestion de la
//              théorie du contrat.  Elle maintient les données nécessaires à
//              la sauvegarde des renseignements de l'erreur.  Cette classe et sa
//              hiérarchie sont intéressantes lors de l'utilisation des
//              exceptions.
//              <pre>
//              std::logic_error        Classe de base des exceptions logiques
//              ContratException:       Classe de base des exceptions de contrat.
//              AssertionException:     Classe de gestion des erreurs d'assertion.
//              PreconditionException:  Classe de gestion des erreurs de précondition.
//              PostconditionException: Classe de gestion des erreurs de postcondition.
//              InvariantException:     Classe de gestion des erreurs d'invariant.
//              </pre>
//
// Attributs:   std::string  m_expression: Le test logique qui a échoué.
//              std::string  m_fichier:    Le nom du fichier.
//              unsigned int m_ligne:      Le numéro de ligne
//
// Notes:  Cette hiérarchie de classe est inspiré du livre de Horstmann:
//         Mastering object oriented design in C++, 1995, Ref:12-2007257.
//         Voir la classe ChiError sur la disquette fournie avec le livre.
//************************************************************************
#ifndef CONTRATEXCEPTION_H_DEJA_INCLU
#define CONTRATEXCEPTION_H_DEJA_INCLU

#include <string>
#include <stdexcept>

class ContratException : public std::logic_error
{
public:
                 ContratException  (const char*, unsigned int, const char*, const char*);
   std::string   reqTexteException () const; 

private:
   std::string  m_expression;
   std::string  m_fichier;
   unsigned int m_ligne;
};

class AssertionException : public ContratException
{
public:
   AssertionException (const char*, unsigned int, const char*);
};

class PreconditionException : public ContratException
{
public:
   PreconditionException (const char*, unsigned int, const char*);
};

class PostconditionException : public ContratException
{
public:
   PostconditionException (const char*, unsigned int, const char*);
};

class InvariantException : public ContratException
{
public:
   InvariantException (const char*, unsigned int, const char*);
};

// --- Désactiver les warnings de Microsoft sur la longueur des symboles
#pragma warning(disable : 4786)

// --- Définition des macros de contrôle de la théorie du contrat

#if !defined(NDEBUG)
// --- Mode debug 

#  define INVARIANTS() \
      verifieInvariant()

#  define ASSERTION(f)     \
      if (!(f)) throw AssertionException(__FILE__,__LINE__, #f);
#  define PRECONDITION(f)  \
      if (!(f)) throw PreconditionException(__FILE__, __LINE__, #f);
#  define POSTCONDITION(f) \
      if (!(f)) throw PostconditionException(__FILE__, __LINE__, #f);
#  define INVARIANT(f)   \
      if (!(f)) throw InvariantException(__FILE__,__LINE__, #f);

// --- LE MODE RELEASE
#else

#  define PRECONDITION(f);
#  define POSTCONDITION(f);
#  define INVARIANTS();
#  define INVARIANT(f);
#  define ASSERTION(f);

#endif  // --- if !defined (NDEBUG)

#endif  // --- ifndef CONTRATEXCEPTION_H_DEJA_INCLU



