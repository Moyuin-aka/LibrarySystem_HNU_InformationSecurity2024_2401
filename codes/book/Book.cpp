#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(string t, string i, string a, string p, double pr)
    : title(t), isbn(i), author(a), publisher(p), price(pr) ,isBorrowed(false),borrower(""){}

// ��ʾͼ����Ϣ
void Book::display() const {
    cout << "����: " << title << ", ISBN: " << isbn << ", ����: " << author
         << ", ������: " << publisher << ", �۸�: " << price << (isBorrowed ? " [�ѽ��]" : " [�ɽ�]") ;
         if (isBorrowed) {
            cout << "��������: " << borrower;
        }
        cout<<endl;
}

