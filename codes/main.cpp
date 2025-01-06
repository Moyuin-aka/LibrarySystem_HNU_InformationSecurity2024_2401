#include <iostream>
#include "account/AccountManager.h"
#include "book/BookManager.h"
#include "menu/MenuManager.h"

using namespace std;

// ȫ�ֱ���
UserManager userManager;
BookManager bookManager(userManager);

int main() {
    // ��������
    userManager.loadUsers("users.txt");
    bookManager.loadBooks("books.txt");

    // ���� AccountManager �� MenuManager ʵ��
    AccountManager accountManager(userManager);
    MenuManager menuManager(accountManager, bookManager);

    // ��ʾ���˵�
    menuManager.mainMenu();

    // ��������
    userManager.saveUsers("users.txt");
    bookManager.saveBooks("books.txt");

    return 0;
}

