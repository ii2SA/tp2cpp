#include "Reservation.hpp"

Reservation::Reservation()
{
    Date D0(01, 01, 2023) // je chercherai comment pour la date courrante (aujourd'hui)
     _dateDebutReservation = D0;
     _NbdeNuits = 1;
     _idHotel = "none"; 
     _idChambre = 0;
     _idClient = "none"; 
     _totalAmount = 0.0;
}

//revoir mes imbrications de while et de if surtout les while car ils sont assez desordonnés
//il faudra aussi reflechir a utiliser une fonction verfier dans le constructeur qu'on aurait créer dans le hpp

Reservation::Reservation(Date dateDebutReservation, int NbdeNuits, std::string idHotel, int idChambre, std::string idClient, double totalAmount)
{
    while (_dateDebutReservation._year < 2024)
    {
        while (_dateDebutReservation._month < 0 || _dateDebutReservation._month > 12)
        {
            if (_dateDebutReservation._month == 2)
            {
                while (_dateDebutReservation._day > 28)
                {
                    std::cout << "Reservation ivalide : date incorrecte"<<std::endl;
                    std::cout << "veillez entrer une reservation avec une date valide";
                   // std::cin>>dateDebutReservation;  //new
                }
                
            }
            else if (_dateDebutReservation._month == 4 || _dateDebutReservation._month == 6 || _dateDebutReservation._month == 9 || _dateDebutReservation._month == 11)
            {
                while (_dateDebutReservation._day > 30)
                {
                    std::cout << "Reservation ivalide : date incorrecte"<<std::endl;
                    std::cout << "veillez entrer une reservation avec une date valide";
                   // std::cin>>dateDebutReservation;  //new
                }
            }
            else if (_dateDebutReservation._month == 1 || _dateDebutReservation._month == 3 || _dateDebutReservation._month == 5 || _dateDebutReservation._month == 7 || _dateDebutReservation._month == 8 || _dateDebutReservation._month == 10 || _dateDebutReservation._month == 12)
            {

            }
            
            while (_dateDebutReservation._day < 0 || _dateDebutReservation._day > )
            {
                /* code */
            }
            
        }
        
    }
    
     _dateDebutReservation = dateDebutReservation;
     _NbdeNuits = NbdeNuits;
     _idHotel = idChambre; 
     _idChambre = idChambre;
     _idClient = idClient; 
     _totalAmount = totalAmount;
}

Reservation::~Reservation()
{
}
