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
    MenuManager(AccountManager &am, BookManager &bm); // ���캯��
    void mainMenu();      // ���˵�
};

#endif

