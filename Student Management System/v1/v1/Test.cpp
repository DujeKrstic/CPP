#include "Test.h"
#include "DiplomiraniStudent.h"

void dodajTestneStudente(StudentManager& manager) {
	Student* s1 = new Student(23157078, "Duje", "Krstic");
	s1->dodajOcjenu(5);
	s1->dodajOcjenu(4);
	s1->dodajOcjenu(4);
	manager.dodajStudenta(s1);

	Student* s2 = new DiplomiraniStudent(23156900, "Dina", "Gladan", "Arduino Pet Feeder");
	s2->dodajOcjenu(5);
	s2->dodajOcjenu(5);
	s2->dodajOcjenu(4);
	manager.dodajStudenta(s2);

	Student* s3 = new Student(23156916, "Mate", "Gojsalic");
	s3->dodajOcjenu(3);
	s3->dodajOcjenu(2);
	s3->dodajOcjenu(2);
	manager.dodajStudenta(s3);
}