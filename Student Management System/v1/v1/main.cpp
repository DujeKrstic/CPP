#include <iostream>
#include <string>
#include "StudentManager.h"
#include "DiplomiraniStudent.h"

int main(){
    
    StudentManager manager;
    manager.ucitajIzDatoteke("students.txt");

    while (true) {
        std::cout << "\n======= IZBORNIK =======\n1. Dodaj studenta\n2. Prikazi sve\n3. Trazi po ID\n4. Spremi u datoteku\n5. Izlaz\n\nOdabir: ";
        int izbor;
        std::cin >> izbor;

        if (izbor == 1) {

            int tip;
            do {
                std::cout << "1. Dodaj obicnog studenta\n2. Dodaj diplomiranog studenta\nOdabir:\t";
                std::cin >> tip;
            } while (tip != 1 && tip != 2);
            


            int id;
            std::string ime, prezime;
            std::cout << "ID: "; std::cin >> id;
            std::cout << "Ime: "; std::cin >> ime;
            std::cout << "Prezime: "; std::cin >> prezime;

            Student* s = nullptr;
            
            if (tip == 1) {
                s = new Student(id, ime, prezime);
            }
            else if (tip == 2) {
                std::string tema;
                std::cout << "Unesi temu diplomskog rada: ";
                std::cin.ignore(); //zanemari \n iz prethodnog unosa
                std::getline(std::cin, tema);
                
                s = new DiplomiraniStudent(id, ime, prezime, tema);
            }
            

            //Unos ocjena
            int brojOcjena;
            std::cout << "Koliko ocjena ima student:\t";
            std::cin>>brojOcjena;

            for (int i = 0; i < brojOcjena; i++) {
                int ocjena;
                std::cout << "Ocjena #" << (i + 1) << ": ";
                std::cin >> ocjena;
                s->dodajOcjenu(ocjena);
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