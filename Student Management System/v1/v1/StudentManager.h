#pragma once //Koristimo umjesto #ifndef, #define, #endif. 
				//Onemogu?uje dvostruko uklju?ivanje datoteke. 
#include "Student.h"
#include <vector>

class StudentManager {
private:
	std::vector<Student> studenti;

public:
	void dodajStudenta(const Student& s);
	void prikaziSve() const;
	Student* pronadiPoId(int id);
	void spremiUDatoteku(const std::string& nazivDatoteke) const;
	void ucitajIzDatoteke(const std::string& nazivDatoteke);

};