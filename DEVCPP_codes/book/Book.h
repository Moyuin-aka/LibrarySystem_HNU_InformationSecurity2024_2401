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
    bool isBorrowed;   // 是否已借出
    string borrower;     // 借阅者用户名
    int borrowCount;     // 借阅次数


    Book(string t, string i, string a, string p, double pr);
    void display() const;
    
    bool operator<(const Book &other) const {
        return title < other.title;
    }
};

#endif

