#pragma once
#include <bits/stdc++.h>
using namespace std;

class Book {
private:
    string nameBook;
    string nameAuthor;
    int numberBook;
public:
    Book() {}
    Book(string nameBook, string nameAuthor, int numberBook): nameBook(nameBook), nameAuthor(nameAuthor), numberBook(numberBook) {}
   
    friend istream& operator >> (istream &in, Book &a) {
        cout << "--------------Enter A Book------------" << endl; 
        cout << "Name: "; getline(in, a.nameBook); cout << endl;
        cout << "Author: "; getline(in, a.nameAuthor); cout << endl;
        cout << "Number: "; in>> a.numberBook; cout << endl; in.ignore();
        return in;
    }

    friend ostream& operator << (ostream &out, Book a) {
        out << "=================================================" << endl;
        out << "Name Book: " << a.nameBook << endl;
        out << "Name Author: " << a.nameAuthor << endl;
        out << "Number Book: " << a.numberBook << endl;
        out << "=================================================" << endl;
        return out;
    }

    string getNameBook() {
        return nameBook;
    }
    string getNameAuthor() {
        return nameAuthor;
    }
    int getNumberBook() {
        return numberBook;
    }
    static int numOfTypeBooks(vector<Book> vb) {
        return vb.size();
    }
    static int totalNumOfBooks(vector<Book> vb) {
        long long count(0);
        for(int i(0); i<vb.size(); i++) {
            count+=vb[i].getNumberBook();
        }
        return count;
    }
};