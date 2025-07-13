#pragma once //Koristimo umjesto #ifndef, #define, #endif. 
				//Onemogucuje dvostruko ukljucivanje datoteke. 
#include "Student.h"
#include <vector>

class StudentManager {
private:
	std::vector<Student*> studenti; //omogucuje rad s baznim i izvedenim klasama

public:
	void dodajStudenta(Student* s);
	void prikaziSve() const;
	Student* pronadiPoId(int id);
	void spremiUDatoteku(const std::string& nazivDatoteke) const;
	void ucitajIzDatoteke(const std::string& nazivDatoteke);

	~StudentManager();

};