#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(string t, string i, string a, string p, double pr)
    : title(t), isbn(i), author(a), publisher(p), price(pr) ,isBorrowed(false),borrower(""){}

// 显示图书信息
void Book::display() const {
    cout << "题名: " << title << ", ISBN: " << isbn << ", 作者: " << author
         << ", 出版社: " << publisher << ", 价格: " << price << (isBorrowed ? " [已借出]" : " [可借]") ;
         if (isBorrowed) {
            cout << "，借阅者: " << borrower;
        }
        cout<<endl;
}

