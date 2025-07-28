#include "StudentManager.h"
#include "DiplomiraniStudent.h"
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
		
		if(dynamic_cast<const DiplomiraniStudent*>(s)) {
			out << "D ";
		} else {
			out << "S ";
		}
		
		out << s->getId() << ' '
			<< s->getIme() << ' '
			<< s->getPrezime() << ' '
			<< s->izracunajProsjek() << ' ';
		//Spremi broj ocjena i svaku ocjenu

		const auto& ocjene = s->getOcjene();
		out << ocjene.size() << ' ';
		for (int o : ocjene) {
			out << o << ' ';
		}

		if(const auto* ds = dynamic_cast<const DiplomiraniStudent*>(s)) {
			out << ds->getTemaDiplomskog();
		} else {
			out << "N/A "; //ako nije diplomirani student, ispisi N/A
		}
		
		out << '\n';
	}
	
	out.close();
	std::cout << "Podaci spremljeni u " << nazivDatoteke << ".\n";
}

void StudentManager::ucitajIzDatoteke(const std::string& nazivDatoteke) {
	std::ifstream in(nazivDatoteke);
	if (!in) {
		std::cerr << "Ne mogu otvoriti datoteku za citanje.\n";
		return;
	}

	// Ocisti prethodne studente
	for (Student* s : studenti) delete s;
	studenti.clear();

	char tip;
	while (in >> tip) {
		int id, brojOcjena;
		std::string ime, prezime;
		double prosjek;
		in >> id >> ime >> prezime >> prosjek >> brojOcjena;

		std::vector<int> ocjene(brojOcjena);
		for (int i = 0; i < brojOcjena; ++i) {
			in >> ocjene[i];
		}

		Student* s = nullptr;

		if (tip == 'S') {
			s = new Student(id, ime, prezime);
		}
		else if (tip == 'D') {
			std::string tema;
			in.ignore(); // izbaci razmak
			std::getline(in, tema);
			s = new DiplomiraniStudent(id, ime, prezime, tema);
		}

		if (s) {
			for (int o : ocjene) {
				s->dodajOcjenu(o);
			}
			studenti.push_back(s);
		}
	}

	std::cout << "Podaci uspjesno ucitani iz " << nazivDatoteke << ".\n";
}

void StudentManager::sortirajPoProsjeku(bool silazno) {
	std::sort(studenti.begin(), studenti.end(), [silazno](Student* a, Student* b) {
		if (silazno) {
			return a->izracunajProsjek() > b->izracunajProsjek();
		} else {
			return a->izracunajProsjek() < b->izracunajProsjek();
		}
	});
}

void StudentManager::prikaziIznadProsjeka(double prag) const {
	int br = 0;
	std::cout << "Studenti s prosjekom iznad " << prag << ":\n";
	for (const Student* s : studenti) {
		if (s->izracunajProsjek() > prag) {
			s->prikazi();
			br++;
			std::cout << "---------------------------------\n";
		}
	}
	if(br == 0){
		std::cout << "Nema studenata s prosjekom iznad " << prag << ".\n";
	} else {
		std::cout << "Ukupno studenata iznad prosjeka: " << br << "\n";
	}
}

bool StudentManager::obrisiStudentaPoId(int id) {
	for (auto it = studenti.begin(); it != studenti.end(); ++it) {
		if ((*it)->getId() == id) {
			delete *it; // Oslobodi memoriju
			studenti.erase(it); // Ukloni iz vektora
			std::cout << "Student s ID " << id << " je obrisan.\n";
			return true;
		}
	}
	std::cout << "Student s ID " << id << " nije pronaden.\n";
	return false;
}

void StudentManager::izveziUCsv(const std::string& nazivDatoteke) const {
	std::ofstream out(nazivDatoteke);
	if (!out) {
		std::cerr << "Greska pri otvaranju CSV datoteke.\n";
		return;
	}

	out << "ID,Ime,Prezime,Tip,Prosjek,TemaDiplomskog\n";

	for (const Student* s : studenti) {
		out << s->getId() << ",";
		out << s->getIme() << ",";
		out << s->getPrezime() << ",";

		const DiplomiraniStudent* ds = dynamic_cast<const DiplomiraniStudent*>(s);
		if (ds) {
			out << "DiplomiraniStudent" << ",";
			out << ds->izracunajProsjek() << ",";
			out << "- " << ds->getTemaDiplomskog() << "\n";
		}
		else {
			out << "Student" << ",";
			out << s->izracunajProsjek() << ",";
			out << "-\n"; // Nema teme diplomskog
		}
	}
	std::cout << "Podaci uspjesno izvezeni u " << nazivDatoteke << ".\n";

}

void StudentManager::izveziStatistiku(const std::string& nazivDatoteke) const {
	std::ofstream out(nazivDatoteke);
	if (!out) {
		std::cerr << "Greska pri otvaranju datoteke za statistiku.\n";
		return;
	}

	int ukupno = studenti.size();
	int diplomiranih = 0;
	double ukupniProsjek = 0.0;
	double maxProsjek = -1.0, minProsjek = 6.0;

	for (const auto& s : studenti) {
		double p = s->izracunajProsjek();
		ukupniProsjek += p;

		if (p > maxProsjek) maxProsjek = p;
		if (p < minProsjek) minProsjek = p;

		// koristi dynamic_cast za provjeru tipa
		if (dynamic_cast<DiplomiraniStudent*>(s)) {
			diplomiranih++;
		}
	}

	double prosjek = (ukupno > 0) ? ukupniProsjek / ukupno : 0.0;

	out << "Ukupan broj studenata:," << ukupno << "\n";
	out << "Broj diplomiranih studenata:," << diplomiranih << "\n";
	out << "Prosjecna ocjena svih studenata:," << prosjek << "\n";
	out << "Najvisi prosjek:," << maxProsjek << "\n";
	out << "Najnizi prosjek:," << minProsjek << "\n";

	out.close();
	std::cout << "Statistika je uspjesno izvezena u: " << nazivDatoteke << "\n";
}
