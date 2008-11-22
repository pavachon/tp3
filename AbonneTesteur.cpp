//***************************************************************************
// Test unitaire de la classe : Abonne
//***************************************************************************

#include "Abonne.h"

#include "ContratException.h"
#include <iostream>

using namespace tp3;
using namespace std;


//*****************************************************************************
// Prototypes
//*****************************************************************************
void test_operatorTt_Tt__pPstd_SS_istreamR_tp3_SS_AbonneRPp_();
void test_operator_tT_tT_pPstd_SS_ostreamR_consttp3_SS_AbonneRPp_();
void test_tp3_SS_Abonne_SS_Abonne_pPconststd_SS_stringR_conststd_SS_stringR_conststd_SS_stringR_conststd_SS_stringRPp_();
void test_tp3_SS_Abonne_SS_Abonne_pPconsttp3_SS_AbonneRPp_();
void test_tp3_SS_Abonne_SS_asgAdresse_pPconststd_SS_stringRPp_();
void test_tp3_SS_Abonne_SS_asgTelephone_pPconststd_SS_stringRPp_();
void test_tp3_SS_Abonne_SS_deserialise_pPstd_SS_istreamRPp_();
void test_tp3_SS_Abonne_SS_operatorEE_pPconsttp3_SS_AbonneRPp_const();
void test_tp3_SS_Abonne_SS_reqAdresse_pPPp_const();
void test_tp3_SS_Abonne_SS_reqCategorie_pPPp_const();
void test_tp3_SS_Abonne_SS_reqNom_pPPp_const();
void test_tp3_SS_Abonne_SS_reqTelephone_pPPp_const();
void test_tp3_SS_Abonne_SS_serialise_pPstd_SS_ostreamRPp_const();



//*****************************************************************************
// Main du test
//*****************************************************************************
void main()
{
   try
   {
      test_operatorTt_Tt__pPstd_SS_istreamR_tp3_SS_AbonneRPp_();
      test_operator_tT_tT_pPstd_SS_ostreamR_consttp3_SS_AbonneRPp_();
      test_tp3_SS_Abonne_SS_Abonne_pPconststd_SS_stringR_conststd_SS_stringR_conststd_SS_stringR_conststd_SS_stringRPp_();
      test_tp3_SS_Abonne_SS_Abonne_pPconsttp3_SS_AbonneRPp_();
      test_tp3_SS_Abonne_SS_asgAdresse_pPconststd_SS_stringRPp_();
      test_tp3_SS_Abonne_SS_asgTelephone_pPconststd_SS_stringRPp_();
      test_tp3_SS_Abonne_SS_deserialise_pPstd_SS_istreamRPp_();
      test_tp3_SS_Abonne_SS_operatorEE_pPconsttp3_SS_AbonneRPp_const();
      test_tp3_SS_Abonne_SS_reqAdresse_pPPp_const();
      test_tp3_SS_Abonne_SS_reqCategorie_pPPp_const();
      test_tp3_SS_Abonne_SS_reqNom_pPPp_const();
      test_tp3_SS_Abonne_SS_reqTelephone_pPPp_const();
      test_tp3_SS_Abonne_SS_serialise_pPstd_SS_ostreamRPp_const();

      std::cout << "Test Abonne: Succes" << std::endl;

   }
   catch (ContratException& err)
   {
      std::cout << "Test Abonne: Echec" << std::endl;
      std::cout << err.reqTexteException() << std::endl;
   }

}



//*****************************************************************************
// Test de la methode: 
//    tp3::Abonne::Abonne(const std::string&,const std::string&,const std::string&,const std::string&)
//*****************************************************************************
void test_tp3_SS_Abonne_SS_Abonne_pPconststd_SS_stringR_conststd_SS_stringR_conststd_SS_stringR_conststd_SS_stringRPp_()
{
	//--- Cas valide
	{
		Abonne a("Peter", "(123) 123-1234", "1234 rue Frampton, Framptontown, Ontario, USA", "Residence");
	}

	//-- Cas invalides
	bool bCasLimite = false;
	try // Nom vide
	{
		Abonne a("", "(123) 123-1234", "1234 rue Frampton, Framptontown, Ontario, Canada", "Residence");
	}
	catch(ContratException&)
	{
		bCasLimite = true;
	}
	ASSERTION(bCasLimite);

	bCasLimite = false;
	try // Telephone invalide
	{
		Abonne a("Chuck", "1234567890", "4321 Berry Street, Berrytown, Ohio, USA", "Residence");
	}
	catch(ContratException&)
	{
		bCasLimite = true;
	}
	ASSERTION(bCasLimite);

	bCasLimite = false;
	try // Adresse vide
	{
		Abonne a("Chuck", "(123) 123-1234", "", "Residence");
	}
	catch(ContratException&)
	{
		bCasLimite = true;
	}
	ASSERTION(bCasLimite);

/*
	bCasLimite = false;
	try // categorie != residence || categorie != entreprise
	{
		Abonne a("Chuck", "(123) 123-1234", "4321 Berry Street, Berrytown, Ohio, USA", "Rocker");
	}
	catch(ContratException&)
	{
		bCasLimite = true;
	}
	ASSERTION(bCasLimite);
*/
}


//*****************************************************************************
// Test de la methode: 
//    tp3::Abonne::Abonne(const tp3::Abonne&)
//*****************************************************************************
void test_tp3_SS_Abonne_SS_Abonne_pPconsttp3_SS_AbonneRPp_()
{
	//--- Cas valide
	{
		Abonne a("Peter", "(123) 123-1234", "1234 rue Frampton, Framptontown, Ontario, USA", "Residence");
		Abonne b(a);
	}

	/*
	//--- Cas invalides
	bool bCasLimite = false;
	try // argument invalide
	{
		Abonne a("Peter", "(123) 123-1234", "1234 rue Frampton, Framptontown, Ontario, USA", "Residence");
		Abonne b(a);
	}*/
}


//*****************************************************************************
// Test de la methode: 
//    tp3::Abonne::asgTelephone(const std::string&)
//*****************************************************************************
void test_tp3_SS_Abonne_SS_asgTelephone_pPconststd_SS_stringRPp_()
{
	//--- Cas valide
	{
		Abonne a("Peter", "(123) 123-1234", "1234 rue Frampton, Framptontown, Ontario, USA", "Residence");
		a.asgTelephone("(321) 321-4321");
	}

	//--- Cas invalide
	bool bCasLimite = false;
	try // Numero au mauvais format
	{
		Abonne a("Peter", "(123) 123-1234", "1234 rue Frampton, Framptontown, Ontario, USA", "Residence");
		a.asgTelephone("1");
	}
	catch(ContratException&)
	{
		bCasLimite = true;
	}
	ASSERTION(bCasLimite);
}


//*****************************************************************************
// Test de la methode: 
//    tp3::Abonne::asgAdresse(const std::string&)
//*****************************************************************************
void test_tp3_SS_Abonne_SS_asgAdresse_pPconststd_SS_stringRPp_()
{
	//--- Cas valide
	{
		Abonne a("Peter", "(123) 123-1234", "1234 rue Frampton, Framptontown, Ontario, USA", "Residence");
		a.asgAdresse("1234 rue Peter, Petertown, Peterstate, Peterpays");
	}

	//--- Cas invalide
	bool bCasLimite = false;
	try // Adresse vide
	{
		Abonne a("Peter", "(123) 123-1234", "1234 rue Frampton, Framptontown, Ontario, USA", "Residence");
		a.asgAdresse("");
	}
	catch(ContratException&)
	{
		bCasLimite = true;
	}
	ASSERTION(bCasLimite);
}


//*****************************************************************************
// Test de la methode: 
//    tp3::Abonne::reqNom()const
//*****************************************************************************
void test_tp3_SS_Abonne_SS_reqNom_pPPp_const()
{
	//--- Cas valide
	{
		Abonne a("Chuck", "(123) 123-1234", "4321 Berry Street, Berrytown, Ohio, USA", "Residence");
		string x = a.reqNom();
		ASSERTION(x == "Chuck");
	}
}


//*****************************************************************************
// Test de la methode: 
//    tp3::Abonne::reqTelephone()const
//*****************************************************************************
void test_tp3_SS_Abonne_SS_reqTelephone_pPPp_const()
{
	//--- Cas valide
	{
		Abonne a("Chuck", "(123) 123-1234", "4321 Berry Street, Berrytown, Ohio, USA", "Residence");
		string x = a.reqTelephone();
		ASSERTION(x == "(123) 123-1234");
	}
}


//*****************************************************************************
// Test de la methode: 
//    tp3::Abonne::reqAdresse()const
//*****************************************************************************
void test_tp3_SS_Abonne_SS_reqAdresse_pPPp_const()
{
	//--- Cas valide
	{
		Abonne a("Chuck", "(123) 123-1234", "4321 Berry Street, Berrytown, Ohio, USA", "Residence");
		string x = a.reqAdresse();
		ASSERTION(x == "4321 Berry Street, Berrytown, Ohio, USA");
	}
}


//*****************************************************************************
// Test de la methode: 
//    tp3::Abonne::reqCategorie()const
//*****************************************************************************
void test_tp3_SS_Abonne_SS_reqCategorie_pPPp_const()
{
	//--- Cas valide
	{
		Abonne a("Chuck", "(123) 123-1234", "4321 Berry Street, Berrytown, Ohio, USA", "Residence");
		string x = a.reqCategorie();
		ASSERTION(x == "Residence");
	}
}


//*****************************************************************************
// Test de la methode: 
//    tp3::Abonne::serialise(std::ostream&)const
//*****************************************************************************
void test_tp3_SS_Abonne_SS_serialise_pPstd_SS_ostreamRPp_const()
{
	//--- Cas valide
	{
		Abonne b("Chuck", "(123) 123-1234", "1234 rue Frampton, Framptontown, Ontario, USA", "Residence");
		b.serialise(cout);
	}
}


//*****************************************************************************
// Test de la methode: 
//    tp3::Abonne::deserialise(std::istream&)
//*****************************************************************************
void test_tp3_SS_Abonne_SS_deserialise_pPstd_SS_istreamRPp_()
{

}


//*****************************************************************************
// Test de la methode: 
//    tp3::Abonne::operator ==(const tp3::Abonne&)const
//*****************************************************************************
void test_tp3_SS_Abonne_SS_operatorEE_pPconsttp3_SS_AbonneRPp_const()
{
	//--- Cas valides
	{
		// Les abonnes ne sont pas identiques dans tous les champs
		Abonne a("Peter", "(123) 123-1234", "1234 rue Frampton, Framptontown, Ontario, USA", "Residence");
		Abonne b("Chuck", "(123) 123-1234", "1234 rue Frampton, Framptontown, Ontario, USA", "Residence");
		a == b;
	}
	{
		// Tous les champs de a et b sont identiques
		Abonne a("Chuck", "(123) 123-1234", "1234 rue Frampton, Framptontown, Ontario, USA", "Residence");
		Abonne b("Chuck", "(123) 123-1234", "1234 rue Frampton, Framptontown, Ontario, USA", "Residence");
		a == b;
	}
}


//*****************************************************************************
// Test de la methode: 
//    operator <<(std::ostream&,const tp3::Abonne&)
//*****************************************************************************
void test_operator_tT_tT_pPstd_SS_ostreamR_consttp3_SS_AbonneRPp_()
{
	//--- Cas valide
	{
		Abonne b("Chuck", "(123) 123-1234", "1234 rue Frampton, Framptontown, Ontario, USA", "Residence");
		cout << b;
	}
}

//*****************************************************************************
// Test de la methode: 
//    operator >>(std::istream&,tp3::Abonne&)
//*****************************************************************************
void test_operatorTt_Tt__pPstd_SS_istreamR_tp3_SS_AbonneRPp_()
{

}

