//*****************************************************************************
// Fichier:     ValidationFormat.h
//
// Description: Ce ficher contient des fonctions de validation de format ainsi
//              que des fonctions donnant le format valide.
//
// Note:
//
//*****************************************************************************
// 21-09-2002 Nicolas Richard & Yves Roy  Version initiale
// 03-10-2003 Marc Philippe Parent Version tp1
//*****************************************************************************
#ifndef VALIDATIONFORMAT_H_DEJA_INCLUS
#define VALIDATIONFORMAT_H_DEJA_INCLUS

#include <string>

namespace util
{
   
   std::string reqFormatTelephone  ();
   bool        validerTelephone    (const std::string& telephone);
   std::string reqFormatCodePostal ();
   bool        validerCodePostal   (const std::string& codePostal);

} // --- namespace util

#endif //VALIDATIONFORMAT_H_DEJA_INCLUS
