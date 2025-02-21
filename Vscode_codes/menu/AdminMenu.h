#ifndef ADMINMENU_H
#define ADMINMENU_H

#include "../account/AccountManager.h"
#include "../book/BookManager.h"
class AdminMenu {
private:
    AccountManager &accountManager;
    BookManager &bookManager;
    

public:
    AdminMenu(AccountManager &am, BookManager &bm); // 构造函数
    void adminMenu(); // 管理员菜单
    int getValidatedChoice(); 

};

#endif

