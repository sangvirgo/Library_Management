#include "Person.h"
#include "Book.h"
#include "Children.h"
#include "Adult.h"
#include "bits/stdc++.h"

int main() {
    vector<Person*> people;  // Lưu trữ danh sách người mượn
    vector<Book> books;     // Lưu trữ danh sách sách

    while (true) {
        cout << "==== Library Management System Menu ====" << endl;
        cout << "0. Thoat" << endl;
        cout << "1. Them nguoi muon" << endl;
        cout << "2. Them sach" << endl;
        cout << "3. Hien thi danh sach nguoi muon" << endl;
        cout << "4. Hien thi danh sach sach" << endl;
        cout << "5. Hien thi danh sach do tuoi" << endl;
        cout << "6. Doc File Person" << endl;
        cout << "7. Doc File Book" << endl;
        cout << "8. Hien thi so sach co, tong so sach, so nguoi muon" << endl;
        cout << "9. Top 5 cuon sach duoc muon nhieu nhat" << endl;
        cout << "10. Sap xep nguoi theo do tuoi" << endl;
        cout << "=========================================" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int type;
                cout << "====Chon loai nguoi muon====" << endl;
                cout << "1. Nguoi lon" << endl;
                cout << "2. Tre em" << endl;
                cout << "Nhap loai nguoi muon: ";
                cin >> type;
                cin.ignore();
                Person* p=NULL;
                switch (type) {
                    case 1: {
                        p=new Adult;
                        break;
                    }
                    case 2: {
                        p=new Children;
                        break;
                    }
                    default: {
                        cout << "Lua chon khong hop le!!!!"<< endl;
                        continue;
                    }
                }
                cin >> *p;
                people.push_back(p);
                break;
            }
            case 2: {
                // Thêm sách vào danh sách
                Book book; cin.ignore(); 
                cin >> book;
                books.push_back(book);
                break;
            }
            case 3: {
                for(auto it: people) {
                    it->display();
                    cout << endl;
                }
                break;
            }
            case 4: {
                cout << "--------------List Books------------" << endl;
                for(auto it:books) {
                    cout << it;
                }
                break;
            }
            case 5: {
                vector<int> age=Person::getListAge(people);
                cout << "Age: ";
                for(auto it: age) {
                    cout << it<< ' '; 
                }
                cout << endl;
                break;
            }


            case 6: {
                ifstream filein;
                filein.open("Person.txt");
                if(!filein) {
                    cout << "Cannot open file!!!" << endl;
                    break;
                }
                
                string line;
                while(getline(filein, line)) {
                    int type;
                    stringstream ss(line);
                    ss>>type;
                    Person* p = nullptr;
                    switch (type) {
                        case 1: {
                            p=new Adult;
                            break;
                        }
                        case 2: {
                            p=new Children;
                            break;
                        }
                    }

                    if(p!=NULL) {
                        ss.ignore();
                        string name, add;
                        int age, numbooks;
                        getline(ss, name, ',');
                        ss>>age;
                        ss.ignore();
                        getline(ss, add, ',');
                        ss>>numbooks;
                        ss.ignore();

                        p->setName(name);
                        p->setAge(age);
                        p->setAdd(add);

                        for(int i(0); i<numbooks; i++) {
                            string bookName, author;
                            int bookcount;
                            getline(filein, bookName, ',');
                            getline(filein, author, ',');
                            filein>>bookcount;
                            filein.ignore();

                            Book book(bookName, author, bookcount);
                            p->addBook(book);
                        }
                        people.push_back(p);
                    }
                }
                filein.close();
                break;
            }

            case 7: {
                ifstream filein;
                filein.open("ListBook.txt");
                if(!filein) {
                    cout << "Cannot open file !!!!" << endl;
                    break;
                }

                string line;
                while(getline(filein, line)) {
                    stringstream ss(line);
                    string namebook, author;
                    int numbook;
                    getline(ss, namebook, ',');
                    getline(ss, author, ',');
                    ss>>numbook;
                    ss.ignore();
                    Book book(namebook, author, numbook);
                    books.push_back(book);
                }
                filein.close();
                break;
            }

            case 8: {
            cout << "=================================================" << endl;
            cout << "So sach: " << Book::numOfTypeBooks(books) << endl;
            cout << "Tong so luong sach: " << Book::totalNumOfBooks(books) << endl;
            cout << "Tong so nguoi nguon: " << Person::numOfPeople(people) << endl;
            cout << "=================================================" << endl;

                break;
            }

            case 9: {
                vector<Book> result=Person::getMaxBookBorrowed(people, books);
                cout << "========Top 5 cuon sach duoc muon nhieu nhat========" << endl;
                for(auto it:result) {
                    cout << it;
                }
                break;
            }

            case 10: {
                Person::sortPersonAge(people);
                break;
            }

            case 0: {
                // Thoát khỏi chương trình
                cout << "Thoat khoi chuong trinh" << endl;
                for(auto it:people) {
                    delete it;
                }
                return 0;
            }
            default: {
                cout << "Lua chon khong hop le vui long nhap lai!!!!!" << endl;
                break;
            }
        }
    }

    return 0;
}
