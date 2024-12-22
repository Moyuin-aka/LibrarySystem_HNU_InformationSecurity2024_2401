#include "MenuManager.h"
#include "AdminMenu.h"
#include "ReaderMenu.h" 
#include <iostream>
using namespace std;

// 构造函数实现
MenuManager::MenuManager(AccountManager &am, BookManager &bm)
    : accountManager(am), bookManager(bm) {}
// 主菜单
void MenuManager::mainMenu() {
    bool exitMenu = false;
    do {
        int choice;
        cout << "===== 图书管理系统 =====" << endl;
        cout << "1. 登录" << endl;
        cout << "2. 注册" << endl;
        cout << "3. 退出系统" << endl;
        cout << "请选择（1-3）：";
        cin >> choice;

        switch (choice) {
        case 1: {
            int role = accountManager.login();
            if (role == 1) {
                AdminMenu adminMenu(accountManager, bookManager);
                adminMenu.adminMenu(); // 跳转管理员菜单
            } else if (role == 2) {
                ReaderMenu readerMenu(accountManager, bookManager);
                readerMenu.readerMenu(); // 跳转读者菜单
            }
            break;
        }
        case 2:
            accountManager.registerAccount();
            break;
        case 3:
            cout << "感谢使用系统，再见！" << endl;
            exitMenu = true; // 退出主菜单
            break;
        default:
            cout << "无效选择，请重试！" << endl;
            break;
        }
    } while (!exitMenu);
}


