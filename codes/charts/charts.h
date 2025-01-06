#ifndef CHARTS_H
#define CHARTS_H

#include "../book/BookManager.h"
#include "../user/UserManager.h"
#include <vector>
#include <string>
using namespace std;

class Charts {
private:
    BookManager &bookManager; // 引用图书管理器
    UserManager &userManager; // 引用用户管理器

public:
    Charts(BookManager &bm, UserManager &um); // 构造函数

    void displayTopBooks();   // 借阅排行榜前十
    void displayTopReaders(); // 十佳读者排行榜
};

#endif

