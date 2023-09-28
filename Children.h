#pragma once
#include "Person.h" 

class Children: public Person {
public:
    Children() {}
    Children(string name, int age, string add, vector<Book> vb) : Person(name, age, add, vb) {}
   
    // friend istream& operator >> (istream &in, Children &a) {
    //     cout << "--------------Enter A Child------------" << endl;
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
        return this->getVB().size()*5000;
    }


    void display() {
        cout << "Children!" << endl;
        Person::display();
    }
};