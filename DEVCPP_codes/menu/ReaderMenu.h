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
    ReaderMenu(AccountManager &am, BookManager &bm,UserManager &um); // ���캯��
    void displayRecommendations();// ��ʾ�����Ƽ��鵥,��֪���������... 
    void readerMenu(); // ���߲˵�
    int getValidatedChoice() ;//������֤ 
};
#endif

