#ifndef READERMENU_H
#define READERMENU_H

#include "../account/AccountManager.h"
#include "../book/BookManager.h"

class ReaderMenu {
private:
    AccountManager &accountManager;
    BookManager &bookManager;

public:
    ReaderMenu(AccountManager &am, BookManager &bm); // 构造函数
    void displayRecommendations();// 显示今日推荐书单,不知道塞哪里好... 
    void readerMenu(); // 读者菜单
};
    
   

#endif

