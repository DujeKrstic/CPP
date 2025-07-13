#include "DiplomiraniStudent.h"
#include <iostream>

DiplomiraniStudent::DiplomiraniStudent(int id, const std::string& ime, const std::string& prezime, const std::string& tema) 
	: Student(id, ime, prezime), temaDiplomskog(tema){}

void DiplomiraniStudent::prikazi() const {
	Student::prikazi(); //ispisujemo osnovne podatke
	std::cout << "Tema diplomskog rada: " << temaDiplomskog << "\n";
}

