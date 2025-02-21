#include "Charts.h"
#include <iostream>
#include <algorithm>
using namespace std;

Charts::Charts(BookManager &bm, UserManager &um)
    : bookManager(bm), userManager(um) {}
    
//图书借阅排行榜 
void Charts::displayTopBooks() {
    cout << "===== 图书借阅排行榜前十 =====" << endl;

    // 获取 books 的引用
    vector<Book>& books = bookManager.getBooks();

    // 创建一个临时容器，存储书籍及其借阅次数
    vector<pair<string, int>> bookBorrowCounts;

    for (const auto &book : books) {
        if (book.borrowCount > 0) { // 仅统计借阅次数大于 0 的书籍
            bookBorrowCounts.emplace_back(book.title, book.borrowCount);
        }
    }

    // 按借阅次数排序
    sort(bookBorrowCounts.begin(), bookBorrowCounts.end(),
         [](const pair<string, int> &a, const pair<string, int> &b) { return a.second > b.second; });

    // 显示前十
    for (size_t i = 0; i < bookBorrowCounts.size() && i < 10; ++i) {
        cout << i + 1 << ". " << bookBorrowCounts[i].first << " 借阅次数: " << bookBorrowCounts[i].second << endl;
    }
}



//读者借阅排行榜,十佳读者!
void Charts::displayTopReaders() {
    cout << "===== 十佳读者排行榜 =====" << endl;

    // 获取 users 的引用
    vector<User>& users = userManager.getUsers();

    // 创建一个临时容器，存储读者及其借阅次数
    vector<pair<string, int>> readerBorrowCounts;

    for (const auto &user : users) {
        if (user.UserBorrow > 0) { // 借阅过书籍的用户才计入
            readerBorrowCounts.emplace_back(user.username, user.UserBorrow);
        }
    }

    // 按借阅次数排序（降序）
    sort(readerBorrowCounts.begin(), readerBorrowCounts.end(),
         [](const pair<string, int> &a, const pair<string, int> &b) { return a.second > b.second; });

    // 显示前十
    for (size_t i = 0; i < readerBorrowCounts.size() && i < 10; ++i) {
        cout << i + 1 << ". 用户: " << readerBorrowCounts[i].first << " 借阅次数: " << readerBorrowCounts[i].second << endl;
    }

    if (readerBorrowCounts.empty()) {
        cout << "暂无用户上榜！" << endl;
    }
}