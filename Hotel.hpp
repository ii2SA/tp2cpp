#include <iostream>
#include <string>

class Hotel
{
private:
    std::string _idHotel;
    std::string _nameHotel; 
    std::string _townHotel;
    std::vector _catalogueHotel;

public:
    Hotel();
    Hotel(std::string idHotel, std::string nameHotel, std::string townHotel, std::vector catalogueHotel);
    ~Hotel();
};

