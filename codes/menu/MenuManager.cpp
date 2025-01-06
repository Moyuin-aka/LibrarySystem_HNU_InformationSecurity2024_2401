#include "MenuManager.h"
#include "AdminMenu.h"
#include "ReaderMenu.h" 
#include <iostream>
#include <string>
using namespace std;

// 构造函数实现
MenuManager::MenuManager(AccountManager &am, BookManager &bm, UserManager &um)
    : accountManager(am), bookManager(bm), userManager(um) {}
// 主菜单
void MenuManager::mainMenu() {
    bool exitMenu = false;
    do {
        int choice;
        cout << "===== 图书管理系统 =====" << endl;
        cout << "1. 登录" << endl;
        cout << "2. 注册" << endl;
        cout << "3. 借阅排行榜" << endl; // 新增排行榜选项
        cout << "4. 退出系统" << endl;
        cout << "请选择（1-4）：";
        cin >> choice;

        switch (choice) {
        case 1: {
            int role = accountManager.login();
            if (role == 1) {
                AdminMenu adminMenu(accountManager, bookManager);
                adminMenu.adminMenu(); // 跳转管理员菜单
            } else if (role == 2) {
                ReaderMenu readerMenu(accountManager, bookManager, userManager);
                readerMenu.readerMenu(); // 跳转读者菜单
            }
            break;
        }
        case 2:
            accountManager.registerAccount();
            break;
        case 3: {
            Charts charts(bookManager, accountManager.getUserManager());
            cout << "===== 借阅排行榜 =====" << endl;
            cout << "1. 图书借阅排行榜" << endl;
            cout << "2. 十佳读者排行榜" << endl;
            cout << "请选择（1-2）：";

            int chartChoice;
            cin >> chartChoice;

            if (chartChoice == 1) {
                charts.displayTopBooks(); // 图书借阅排行榜
            } else if (chartChoice == 2) {
                charts.displayTopReaders(); // 十佳读者排行榜
            } else {
                cout << "无效选择，请重试！" << endl;
            }
            break;
        }
        case 4:
            cout << "感谢使用系统，再见！" << endl;
            exitMenu = true; // 退出主菜单
            break;
        default:
            cout << "无效选择，请重试！" << endl;
            break;
        }
    } while (!exitMenu);
}


