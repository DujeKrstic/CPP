#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student{
    protected:
        int id;
        std::string ime;
        std::string prezime;
        std::vector<int> ocjene;

    public:
        Student(int id, const std::string& ime, const std::string& prezime);

        void dodajOcjenu(int ocjena);
        double izracunajProsjek() const;

        int getId() const;
        std::string getIme() const;
        std::string getPrezime() const;

        void prikazi() const;
};

#endif