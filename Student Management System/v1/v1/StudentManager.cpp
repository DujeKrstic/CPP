#include "StudentManager.h"
#include <iostream>
#include <fstream>

StudentManager::~StudentManager() {
	for (Student* s : studenti) {
		delete s;
	}
}

void StudentManager::dodajStudenta(Student* s) {
	studenti.push_back(s);
}

void StudentManager::prikaziSve() const {
	for (const auto& s : studenti) {
		s->prikazi(); //koristimo virtualni prikaz
		std::cout << "---------------------------------\n";
	}
}

Student* StudentManager::pronadiPoId(int id) {
	for (auto& s : studenti) {
		if (s->getId() == id) {
			return s;
		}
	}
	return nullptr;
}

void StudentManager::spremiUDatoteku(const std::string& nazivDatoteke) const {
	std::ofstream out(nazivDatoteke);
	if (!out) {
		std::cerr << "Ne mogu otvoriti datoteku za pisanje.\n";
		return;
	}
	
	for (const auto& s : studenti) {
		out << s->getId() << ' ' << s->getIme() << ' ' << s->getPrezime() << ' ';
		out << s->izracunajProsjek() << ' ';
		//Spremi broj ocjena i svaku ocjenu

		const auto& ocjene = s->getOcjene();
		out << ocjene.size() << ' ';
		for (int o : ocjene) {
			out << o << ' ';
		}

		
		out << '\n';
	}
	
	out.close();
	std::cout << "Podaci spremljeni u " << nazivDatoteke << ".\n";
}

void StudentManager::ucitajIzDatoteke(const std::string& nazivDatoteke) {
	std::ifstream in(nazivDatoteke);
	if (!in) {
		std::cerr << "Ne mogu otvoriti datoteku za ?itanje.\n";
		return;
	}

	for (Student* s : studenti) delete s; //bri�i stare
	studenti.clear();

	int id, brojOcjena;
	std::string ime, prezime;
	double prosjek;
	while (in >> id >> ime >> prezime >> prosjek >> brojOcjena) {
		Student* s = new Student(id, ime, prezime);
		for (int i = 0; i < brojOcjena; ++i) {
			int ocjena;
			in >> ocjena;
			s->dodajOcjenu(ocjena);
		}
		studenti.push_back(s);
	}

	in.close();
	std::cout << "Podaci su u?itani iz " << nazivDatoteke << ".\n";
}