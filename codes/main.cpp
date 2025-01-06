#include <iostream>
#include "account/AccountManager.h"
#include "book/BookManager.h"
#include "menu/MenuManager.h"

using namespace std;

// 全局变量
UserManager userManager;
BookManager bookManager(userManager);

int main() {
    // 加载数据
    userManager.loadUsers("users.txt");
    bookManager.loadBooks("books.txt");

    // 创建 AccountManager 和 MenuManager 实例
    AccountManager accountManager(userManager);
    MenuManager menuManager(accountManager, bookManager);

    // 显示主菜单
    menuManager.mainMenu();

    // 保存数据
    userManager.saveUsers("users.txt");
    bookManager.saveBooks("books.txt");

    return 0;
}

