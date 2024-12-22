#ifndef READERMENU_H
#define READERMENU_H

#include "../account/AccountManager.h"
#include "../book/BookManager.h"

class ReaderMenu {
private:
    AccountManager &accountManager;
    BookManager &bookManager;

public:
    ReaderMenu(AccountManager &am, BookManager &bm); // ���캯��
    void readerMenu(); // ���߲˵�
};

#endif

