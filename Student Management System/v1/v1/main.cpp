#include <iostream>
#include <string>
#include "StudentManager.h"
#include "DiplomiraniStudent.h"
#include "Test.h"

int main(){
    
    StudentManager manager;
    manager.ucitajIzDatoteke("students.txt");

    int izbor;

    do{
        std::cout << "\n======= IZBORNIK =======\n1. Dodaj studenta\n2. Prikazi sve\n3. Trazi po ID\n4. Spremi u datoteku\n5. Obrisi studenta pod ID-jem: \n6. Sortiraj po prosjeku\n7. Prikazi studente iznad zadanog prosjeka: \n8. Izvezi u .csv datoteku\n9. Testiraj program predefiniranim podacima\n10. Izlaz\n\nOdabir: ";
        
        std::cin >> izbor;

        switch (izbor) {

        case 1: {
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
            std::cin >> brojOcjena;

            for (int i = 0; i < brojOcjena; i++) {
                int ocjena;
                std::cout << "Ocjena #" << (i + 1) << ": ";
                std::cin >> ocjena;
                s->dodajOcjenu(ocjena);
            }

            manager.dodajStudenta(s);

            break;
        }
        

        case 2:{
            manager.prikaziSve();
            break;
        }

        case 3:{
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
        
            break;
        
        }
        
        case 4:{
            manager.spremiUDatoteku("students.txt");
            std::cout << "Podaci su spremljeni u datoteku students.txt\n";
			break;
        }

        case 5:{
            int id;
            std::cout << "Unesite ID studenta za brisanje: ";
            std::cin >> id;
            manager.obrisiStudentaPoId(id);
            break;
		}

        case 6: {
            std::cout << "Sortirati studente po prosjeku (0 = uzlazno, 1 = silazno): ";
			bool silazno;
            std::cin >> silazno;
            manager.sortirajPoProsjeku(silazno);
			std::cout << "Studenti su sortirani.\n";
            break;
        }

        case 7: {
            double prag;
            std::cout << "Unesite prag prosjeka: ";
            std::cin >> prag;
			manager.prikaziIznadProsjeka(prag);
            break;
        }

        case 8: {
            std::string nazivDatoteke;
            std::cout << "Uneiste naziv .csv datoteke (npr. studenti.csv): ";
            std::cin >> nazivDatoteke;
            manager.izveziUCsv(nazivDatoteke);
            break;
            
        }

        case 9:{
            dodajTestneStudente(manager);
            std::cout << "Sustav uspjesno testiran.\n";
            break;
		}

        case 10: {
            std::cout << "Izlaz iz programa.\n";
            break;
        }

        default:{
            std::cout << "Neispravan izbor. Molimo odaberite ponovno.\n";
			break;
            }
        }

    } while (izbor != 10);

    return 0;
}