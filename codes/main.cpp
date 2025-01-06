#include <iostream>
#include "account/AccountManager.h"
#include "book/BookManager.h"
#include "menu/MenuManager.h"

using namespace std;

// ȫ�ֱ���
UserManager userManager;
BookManager bookManager(userManager);
AccountManager accountManager(userManager);

int main() {
    // ��������
    userManager.loadUsers("users.txt");
    bookManager.loadBooks("books.txt");
    accountManager.loadSecondaryPassword("admin_password.txt"); // ���ض�������

    // ���� AccountManager �� MenuManager ʵ��
    AccountManager accountManager(userManager);
    MenuManager menuManager(accountManager, bookManager, userManager);

    // ��ʾ���˵�
    menuManager.mainMenu();

    // ��������
    userManager.saveUsers("users.txt");
    bookManager.saveBooks("books.txt");
    accountManager.saveSecondaryPassword("admin_password.txt"); // �����������

    return 0;
}

