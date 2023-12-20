#include "Chambre.hpp"

Chambre::Chambre(int numberChambre, std::string typeChambre, double priceChambre)
{
     _numberChambre = numberChambre; 
     _typeChambre = typeChambre;
     _priceChambre = priceChambre;
}

Chambre::Chambre()
{
     _numberChambre = 0; 
     _typeChambre = "none";
     _priceChambre = 0.0;
}

Chambre::~Chambre()
{
}