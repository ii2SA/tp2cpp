#include <iostream>
#include <string>

class Client
{
private:
    
    std::string _idClient;
    std::string _nameClient; 
    std::string _surnameClient;

public:
    Client(std::string idClient, std::string nameClient, std::string surnameClient);
    Client();
    ~Client();
};

