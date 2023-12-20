#include "Client.hpp"


Client::Client()
{
    _idClient = "none";
    _nameClient = "none"; 
    _surnameClient = "none";
}


Client::Client(std::string idClient, std::string nameClient, std::string surnameClient)
{
     _idClient = idClient;
     _nameClient = nameClient; 
     _surnameClient = surnameClient;
}

Client::~Client()
{
}
