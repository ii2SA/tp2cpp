#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Date {
private:
    int jour;
    int mois;
    int annee;

public:
    Date(int _jour, int _mois, int _annee) : jour(_jour), mois(_mois), annee(_annee) {}

    int getJour() const {
        return jour;
    }

    int getMois() const {
        return mois;
    }

    int getAnnee() const {
        return annee;
    }

    string toString() const {
        return to_string(jour) + "/" + to_string(mois) + "/" + to_string(annee);
    }
};

class Chambre {
private:
    int numero;
    string type;
    bool disponible;

public:
    Chambre(int _numero, string _type) : numero(_numero), type(_type), disponible(true) {}

    int getNumero() const {
        return numero;
    }

    string getType() const {
        return type;
    }

    bool estDisponible() const {
        return disponible;
    }

    void reserver() {
        disponible = false;
    }

    void liberer() {
        disponible = true;
    }
};

class Client {
private:
    string nom;
    string adresse;

public:
    Client(string _nom, string _adresse) : nom(_nom), adresse(_adresse) {}

    string getNom() const {
        return nom;
    }

    string getAdresse() const {
        return adresse;
    }
};

class Reservation {
private:
    Chambre* chambre;
    Client* client;
    Date dateArrivee;
    Date dateDepart;

public:
    Reservation(Chambre* _chambre, Client* _client, Date _dateArrivee, Date _dateDepart)
        : chambre(_chambre), client(_client), dateArrivee(_dateArrivee), dateDepart(_dateDepart) {}

    Chambre* getChambre() const {
        return chambre;
    }

    Client* getClient() const {
        return client;
    }

    Date getDateArrivee() const {
        return dateArrivee;
    }

    Date getDateDepart() const {
        return dateDepart;
    }
};

class Hotel {
private:
    vector<Chambre*> chambres;
    vector<Client*> clients;
    vector<Reservation*> reservations;

public:
    void ajouterChambre(Chambre* chambre) {
        chambres.push_back(chambre);
    }

    void ajouterClient(Client* client) {
        clients.push_back(client);
    }

    void reserverChambre(Chambre* chambre, Client* client, Date dateArrivee, Date dateDepart) {
        Reservation* reservation = new Reservation(chambre, client, dateArrivee, dateDepart);
        reservations.push_back(reservation);
        chambre->reserver();
    }

    void libererChambre(Chambre* chambre) {
        for (auto it = reservations.begin(); it != reservations.end(); ++it) {
            if ((*it)->getChambre() == chambre) {
                reservations.erase(it);
                chambre->liberer();
                delete *it;
                break;
            }
        }
    }

    vector<Chambre*> getChambresDisponibles(Date dateArrivee, Date dateDepart) const {
        vector<Chambre*> disponibles;
        for (Chambre* chambre : chambres) {
            if (chambre->estDisponible()) {
                disponibles.push_back(chambre);
            } else {
                bool chambreDisponible = true;
                for (Reservation* reservation : reservations) {
                    if (reservation->getChambre() == chambre) {
                        if (reservation->getDateArrivee().getAnnee() <= dateDepart.getAnnee() &&
                            reservation->getDateDepart().getAnnee() >= dateArrivee.getAnnee()) {
                            if (reservation->getDateArrivee().getMois() <= dateDepart.getMois() &&
                                reservation->getDateDepart().getMois() >= dateArrivee.getMois()) {
                                if (reservation->getDateArrivee().getJour() <= dateDepart.getJour() &&
                                    reservation->getDateDepart().getJour() >= dateArrivee.getJour()) {
                                    chambreDisponible = false;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (chambreDisponible) {
                    disponibles.push_back(chambre);
                }
            }
        }
        return disponibles;
    }

    vector<Reservation*> getReservations() const {
        return reservations;
    }
};

int main() {
    Chambre chambre1(101, "Simple");
    Chambre chambre2(201Je m'excuse, il semble y avoir une erreur de frappe à la fin de la ligne de code précédente. Voici le code corrigé :

```cpp
    Chambre chambre1(101, "Simple");
    Chambre chambre2(201, "Double");

    Client client1("John Doe", "123 Main Street");
    Client client2("Jane Smith", "456 Elm Street");

    Date dateArrivee1(2024, 1, 20);
    Date dateDepart1(2024, 1, 25);
    Date dateArrivee2(2024, 2, 10);
    Date dateDepart2(2024, 2, 15);

    Hotel hotel;
    hotel.ajouterChambre(&chambre1);
    hotel.ajouterChambre(&chambre2);
    hotel.ajouterClient(&client1);
    hotel.ajouterClient(&client2);

    hotel.reserverChambre(&chambre1, &client1, dateArrivee1, dateDepart1);
    hotel.reserverChambre(&chambre2, &client2, dateArrivee2, dateDepart2);

    cout << "Chambres disponibles du 20/01/2024 au 25/01/2024 :" << endl;
    vector<Chambre*> chambresDisponibles = hotel.getChambresDisponibles(dateArrivee1, dateDepart1);
    for (Chambre* chambre : chambresDisponibles) {
        cout << "Chambre " << chambre->getNumero() << " (" << chambre->getType() << ")" << endl;
    }

    cout << endl;

    cout << "Liste des réservations :" << endl;
    vector<Reservation*> reservations = hotel.getReservations();
    for (Reservation* reservation : reservations) {
        cout << "Client : " << reservation->getClient()->getNom() << endl;
        cout << "Chambre : " << reservation->getChambre()->getNumero() << " (" << reservation->getChambre()->getType() << ")" << endl;
        cout << "Dates : " << reservation->getDateArrivee().toString() << " - " << reservation->getDateDepart().toString() << endl;
        cout << endl;
    }

    return 0;
}
