#include <iostream>
#include <string>

class Chambre
{
private:
    
    int _numberChambre; 
    std::string _typeChambre;
    double _priceChambre;

public:
    Chambre(int numberChambre, std::string typeChambre, double priceChambre);
    Chambre();
    ~Chambre();
};


