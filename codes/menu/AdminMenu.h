#ifndef ADMINMENU_H
#define ADMINMENU_H

#include "../account/AccountManager.h"
#include "../book/BookManager.h"

class AdminMenu {
private:
    AccountManager &accountManager;
    BookManager &bookManager;
    

public:
    AdminMenu(AccountManager &am, BookManager &bm); // ���캯��
    void adminMenu(); // ����Ա�˵�
    void manageUsers(); // �û�������

};

#endif

