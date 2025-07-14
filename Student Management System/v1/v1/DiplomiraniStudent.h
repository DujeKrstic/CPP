#pragma once

#include "Student.h"
#include <string>

class DiplomiraniStudent : public Student {

private:
	std::string temaDiplomskog;

public:
	DiplomiraniStudent(int id, const std::string& ime, const std::string& prezime, const std::string& tema);

	void prikazi() const override;

	std::string getTemaDiplomskog() const;
};