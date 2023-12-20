#include "Hotel.hpp"

Hotel::Hotel()
{
     _idHotel = "none";
     _nameHotel = "none";
     _townHotel = "none";
     _catalogueHotel;
}

Hotel::Hotel(std::string idHotel, std::string nameHotel, std::string townHotel, std::vector catalogueHotel)
{
     _idHotel = idHotel;
     _nameHotel = nameHotel; 
     _townHotel = townHotel;
     _catalogueHotel = catalogueHotel;
}

Hotel::~Hotel()
{

}
