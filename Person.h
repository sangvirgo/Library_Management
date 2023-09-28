#pragma once
#include "Book.h"
#include <bits/stdc++.h>
using namespace std;

class Person {
private:
    string name;
    int age;
    string add;
    vector<Book> vb;
public:
    Person() {}
    Person(string name, int age, string add, vector<Book> vb) : name(name), age(age), add(add), vb(vb) {}
    
    friend istream& operator >> (istream &in, Person &a) {
        cout << "--------------Enter A Person------------" << endl;
        cout << "Name: "; getline(in, a.name); cout << endl;
        cout << "Age: ";  in >> a.age; cout << endl; in.ignore();
        cout << "Address: "; getline(in, a.add); cout << endl; 
        int n;
        cout << "Enter the number of books borrowed: "; in >> n; in.ignore();
        a.vb.clear(); // Clear the vector before adding new books
        for (int i = 0; i < n; i++) {
            Book b;
            cin >> b;
            a.vb.push_back(b);
        }
        return in;
    }
    // friend ostream& operator <<(ostream &out, Person& a) {
	// 	cout << "Name: " << a.name << endl;
	// 	cout << "Age: " << a.age << endl;
	// 	cout << "Add: " << a.add << endl;
	// 	cout << "List Book Borrowed:" << endl;
	// 	for (int i = 0; i < a.vb.size(); i++)
	// 	{
	// 		cout << a.vb[i];
	// 	}
	// 	cout << "Money Pay: " << a.moneyPay() << endl;
    // }

    virtual void display()
	{
        cout << "=================================================" << endl;
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Add: " << add << endl;
		cout << "List Book Borrowed:" << endl;
		for (int i = 0; i < vb.size(); i++)
		{
			cout << vb[i];
		}
		cout << "Money Pay: " << moneyPay() << endl;
        cout << "=================================================" << endl;
	}

    string getName() {
        return name;
    }
    int getAge() {
        return age;
    }
    string getAdd() {
        return add;
    }
    vector<Book> getVB() {
        return vb;
    }
    static int numOfPeople(vector<Person*> vp) {
        return vp.size();
    }
    void setName(string name) {
        this->name=name;
    }
    void setAge(int age) {
        this->age=age;
    }
    void setAdd(string add) {
        this->add=add;
    }
    void addBook(Book book) {
        vb.push_back(book);
    }
    virtual long moneyPay() =0;

    static void sortPersonAge(vector<Person*> &vt) {
        for(int i=0; i< vt.size()-1; i++) {
            int min=i;
            for(int j=i+1; j<vt.size(); j++) {
                if(vt[j]->age<vt[min]->age) {
                    min=j;
                }
            }
            swap(vt[i], vt[min]);
        }
    }
    static vector<int> getListAge(vector<Person*> vt) {
        vector<int> result;
        for(int i(0); i<vt.size(); i++) {
            auto it =find(result.begin(), result.end(), vt[i]->age);
            if (it==result.end())
            {
                result.push_back(vt[i]->age);
            }
        }
        return result;
    }

    static vector<Book> getMaxBookBorrowed(vector<Person*> vp, vector<Book> vb) {
        vector<int> cnt(vb.size(), 0);
        for(int i(0); i<vb.size(); i++) {
            for(int j(0); j<vp.size(); j++) {
                vector<Book> b(vp[j]->getVB());
                for(int k(0); k<b.size(); k++) {
                    if(vb[i].getNameBook()==b[k].getNameBook()) {
                        cnt[i]++;
                    }
                }
            }
        }
        int max=*max_element(cnt.begin(), cnt.end());
        vector<Book> result;
        for(int i(0); i<vb.size(); i++) {
            if(cnt[i]==max) {
                result.push_back(vb[i]);
            }
        }
        return result;
    } 


};
