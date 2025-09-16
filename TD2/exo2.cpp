////////////////////////////////////////////////////////////////////////////////
/// \file   exo2.cpp
/// \author 
////////////////////////////////////////////////////////////////////////////////


import std.cout
import std.cin

 
main
	Integer prix;
	Integer montant;
	cout << "Entrer prix : ";
		cin.read(prix);
	cout << "Entrer montant : ";
		cin.read(montant);
	
	Integer monnaie = montant - prix;
	Boolean montantPasSuffisant = montant < prix;
	
	cout << "Montant OK : " << boolalpha << (!montantPasSuffisant) << endOfLine
	<< "Monnaie rendue : " << endOfLine
	<< " - Billet(s) 100$..." << (monaie / 100) << endOfLine
	<< " - Billet(s) 20$...." << ((monaie mod 100) / 20) << endOfLine
	<< " - Billet(s) 10$...." << ((monaie mod 20) / 10) << endOfLine
	<< " - Billet(s) 5$....." << ((monaie mod 10) / 5) << endOfLine
	<< " - Piece(s) 1$......" << ((monaie mod 5) / 1) << endOfLine

