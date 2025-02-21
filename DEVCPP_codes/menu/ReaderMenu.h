#ifndef READERMENU_H
#define READERMENU_H

#include "../account/AccountManager.h"
#include "../book/BookManager.h"
#include "../user/UserManager.h"
#include "MenuManager.h"
class ReaderMenu {
private:
    AccountManager &accountManager;
    BookManager &bookManager;
    UserManager &userManager; 

public:
    ReaderMenu(AccountManager &am, BookManager &bm,UserManager &um); // 构造函数
    void displayRecommendations();// 显示今日推荐书单,不知道塞哪里好... 
    void readerMenu(); // 读者菜单
    int getValidatedChoice() ;//输入验证 
};
#endif

