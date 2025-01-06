#include "Charts.h"
#include <iostream>
#include <algorithm>
using namespace std;

Charts::Charts(BookManager &bm, UserManager &um)
    : bookManager(bm), userManager(um) {}
    
//ͼ��������а� 
void Charts::displayTopBooks() {
    cout << "===== ͼ��������а�ǰʮ =====" << endl;

    // ��ȡ books ������
    vector<Book>& books = bookManager.getBooks();

    // ����һ����ʱ�������洢�鼮������Ĵ���
    vector<pair<string, int>> bookBorrowCounts;

    for (const auto &book : books) {
        if (book.isBorrowed || !book.borrower.empty()) { // �����Ĺ���ͼ��ż���
            int borrowCount = count_if(books.begin(), books.end(),
                                       [&book](const Book &b) { return b.title == book.title && !b.borrower.empty(); });
            bookBorrowCounts.emplace_back(book.title, borrowCount);
        }
    }

    // �����Ĵ�������
    sort(bookBorrowCounts.begin(), bookBorrowCounts.end(),
         [](const pair<string, int> &a, const pair<string, int> &b) { return b.second < a.second; });

    // ��ʾǰʮ
    for (size_t i = 0; i < bookBorrowCounts.size() && i < 10; ++i) {
        cout << i + 1 << ". " << bookBorrowCounts[i].first << " ���Ĵ���: " << bookBorrowCounts[i].second << endl;
    }
}


//���߽������а�,ʮ�Ѷ���!
void Charts::displayTopReaders() {
    cout << "===== ʮ�Ѷ������а� =====" << endl;

    // ��ȡ users ������
    vector<User>& users = userManager.getUsers();

    // ����һ����ʱ�������洢���߼�����Ĵ���
    vector<pair<string, int>> readerBorrowCounts;

    for (const auto &user : users) {
        int borrowCount = count_if(bookManager.getBooks().begin(), bookManager.getBooks().end(),
                                   [&user](const Book &b) { return b.borrower == user.username; });
        if (borrowCount > 0) { // ���Ĺ��鼮���û��ż���
            readerBorrowCounts.emplace_back(user.username, borrowCount);
        }
    }

    // �����Ĵ�������
    sort(readerBorrowCounts.begin(), readerBorrowCounts.end(),
         [](const pair<string, int> &a, const pair<string, int> &b) { return b.second < a.second; });

    // ��ʾǰʮ
    for (size_t i = 0; i < readerBorrowCounts.size() && i < 10; ++i) {
        cout << i + 1 << ". �û�: " << readerBorrowCounts[i].first << " ���Ĵ���: " << readerBorrowCounts[i].second << endl;
    }
}

 

