#include <iostream>
#include <numeric> //za accumulate
#include "Student.h"

//Konstruktor
Student::Student(int id, const std::string& ime, const std::string& prezime)
    : id(id), ime(ime), prezime(prezime){}

//Dodavanje ocjene
void Student::dodajOcjenu(int ocjena){
    ocjene.push_back(ocjena);
}

//Racunanje prosjeka
double Student::izracunajProsjek() const{
    if(ocjene.empty()) return 0.0;
    int zbroj = std::accumulate(ocjene.begin(), ocjene.end(), 0);
    return static_cast<double>(zbroj) / ocjene.size();
}

//Getteri
int Student::getId() const{
    return id;
}

std::string Student::getIme() const{
    return ime;
}

std::string Student::getPrezime() const{
    return prezime;
}

const std::vector<int>& Student::getOcjene() const {
    return ocjene;
}

//Ispis informacija
void Student::prikazi() const{
    std::cout<<"ID: "<<id<<", Ime: "<<ime<<", Prezime: "<<prezime<<".\n";
    std::cout<<"Ocjene: ";
    for(int o:ocjene) std::cout<<o<<" ";
    std::cout<<"\nProsjek: "<<izracunajProsjek()<<"\n";
}

