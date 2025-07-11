#include <iostream>
#include "Student.h"

int main(){
    Student s1(1, "Duje", "Krstić");

    s1.dodajOcjenu(5);
    s1.dodajOcjenu(4);
    s1.dodajOcjenu(3);
    s1.dodajOcjenu(4);
    s1.dodajOcjenu(4);
    s1.dodajOcjenu(3);
    s1.dodajOcjenu(3);

    s1.prikazi();

    return 0;
}