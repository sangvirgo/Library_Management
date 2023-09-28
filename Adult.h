#pragma once 
#include "Person.h"

class Adult:public Person {
public:
    Adult() {} 
    Adult(string name, int age, string add, vector<Book> vb) : Person(name, age, add, vb) {}

    // friend istream& operator >> (istream &in, Adult &a) {
    //     cout << "--------------Enter An Adult------------" << endl;
    //     cout << "Name: "; in >> a.getName(); cout << endl;
    //     cout << "Age: "; in >> a.getAge(); cout << endl;
    //     cout << "Address: "; in >> a.getAdd(); cout << endl;
    //     int n;
    //     cout << "Enter the number of books borrowed: "; in >> n;
    //     a.getVB().clear(); // Clear the vector before adding new books
    //     for (int i = 0; i < n; i++) {
    //         Book b;
    //         cin >> b;
    //         a.getVB().push_back(b);
    //     }
    //     return in;
    // }

    long moneyPay() {
        return this->getVB().size()*10000;
    }
    void display() {
        cout << "Adult!" << endl;
        Person::display();
    }
};  
