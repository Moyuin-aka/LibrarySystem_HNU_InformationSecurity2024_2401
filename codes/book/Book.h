#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>
using namespace std;

class Book {
public:
    string title;
    string isbn;
    string author;
    string publisher;
    double price;
    bool isBorrowed;   // �Ƿ��ѽ��
    string borrower;     // �������û���
    int borrowCount;     // ���Ĵ���


    Book(string t, string i, string a, string p, double pr);
    void display() const;
    
    bool operator<(const Book &other) const {
        return title < other.title;
    }
};

#endif

