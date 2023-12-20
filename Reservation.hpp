#include <iostream>
#include <string>
#include "Date.hpp"

class Reservation
{
protected:

    Date _dateDebutReservation;
    int _NbdeNuits;
    std::string _idHotel; 
    int _idChambre;
    std::string _idClient; 
    double _totalAmount;
    
public:
    Reservation();
    Reservation(Date dateDebutReservation, int NbdeNuits, std::string idHotel, int idChambre, std::string idClient, double totalAmount);

    ~Reservation();
};

