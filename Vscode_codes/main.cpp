#include <iostream>
#include "account/AccountManager.h"
#include "book/BookManager.h"
#include "menu/MenuManager.h"
#include <windows.h>
using namespace std;

// 全局变量
UserManager userManager;
BookManager bookManager(userManager);
AccountManager accountManager(userManager);

int main() {
	system("chcp 65001");
    // 加载数据
    userManager.loadUsers("users.txt");
    bookManager.loadBooks("books.txt");
    accountManager.loadSecondaryPassword("admin_password.txt"); // 加载二级密码

    // 创建 AccountManager 和 MenuManager 实例
    AccountManager accountManager(userManager);
    MenuManager menuManager(accountManager, bookManager, userManager);

    // 显示主菜单
    menuManager.mainMenu();

    // 保存数据
    userManager.saveUsers("users.txt");
    bookManager.saveBooks("books.txt");
    accountManager.saveSecondaryPassword("admin_password.txt"); // 保存二级密码

    return 0;
}

