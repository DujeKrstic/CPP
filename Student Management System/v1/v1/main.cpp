#include <iostream>
#include "StudentManager.h"

int main(){
    
    StudentManager manager;
    manager.ucitajIzDatoteke("students.txt");

    while (true) {
        std::cout << "\n1. Dodaj studenta\n2. Prikazi sve\n3. Trazi po ID\n4. Spremi u datoteku\n5. Izlaz\n\nOdabir: ";
        int izbor;
        std::cin >> izbor;

        if (izbor == 1) {
            int id;
            std::string ime, prezime;
            std::cout << "ID: "; std::cin >> id;
            std::cout << "Ime: "; std::cin >> ime;
            std::cout << "Prezime: "; std::cin >> prezime;

            Student s(id, ime, prezime);
            int brojOcjena;
            std::cout << "Unesite ukupan broj ocjena: ";
            std::cin >> brojOcjena;

            for (int i = 0; i < brojOcjena; i++) {
                int o;
                std::cout << "Ocjena #" << (i + 1) << ": ";
                std::cin >> o;
                s.dodajOcjenu(o);
            }

            manager.dodajStudenta(s);

        }

        else if (izbor == 2) {
            manager.prikaziSve();
        }

        else if (izbor == 3) {
            int id;
            std::cout << "Unesite ID: ";
            std::cin >> id;
            Student* s = manager.pronadiPoId(id);

            if (s) {
                s->prikazi();
            }
            else {
                std::cout << "Student nije pronaden.\n";
            }
        }

        else if(izbor == 4){
            manager.spremiUDatoteku("students.txt");
        }

        else if (izbor == 5) {
            break;
        }
        else {
            std::cout << "Neispravan izbor.\n";
        }
    }

    return 0;
}