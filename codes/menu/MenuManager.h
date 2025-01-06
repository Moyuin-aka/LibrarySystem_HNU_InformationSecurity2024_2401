#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "../account/AccountManager.h"
#include "../book/BookManager.h"
#include "../charts/Charts.h"
#include "AdminMenu.h"
#include "ReaderMenu.h" 

class MenuManager {
private:
    AccountManager &accountManager;
    BookManager &bookManager;

public:
    MenuManager(AccountManager &am, BookManager &bm); // 构造函数
    void mainMenu();      // 主菜单
};

#endif

