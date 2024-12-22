#include "AdminMenu.h"
#include <iostream>
using namespace std;

// 构造函数实现
AdminMenu::AdminMenu(AccountManager &am, BookManager &bm)
    : accountManager(am), bookManager(bm) {}

// 管理员菜单
void AdminMenu::adminMenu() {
    bool exitMenu = false;
    do {
        int choice;
        cout << "===== 管理员菜单 =====" << endl;
        cout << "1. 添加图书" << endl;
        cout << "2. 删除图书" << endl;
        cout << "3. 修改图书信息" << endl;
        cout << "4. 搜索图书" << endl;
        cout << "5. 显示所有图书" << endl;
        cout << "6. 返回上一级菜单" << endl;
        cout << "请选择（1-6）：";
        cin >> choice;

        switch (choice) {
        case 1:
            bookManager.interactiveAddBook();
            break;
        case 2: {
            string title;
            cout << "请输入要删除的图书题名：";
            cin.ignore();
            getline(cin, title);
            bookManager.deleteBook(title);
            break;
        }
        case 3: {
            string title;
            cout << "请输入要修改的图书题名：";
            cin.ignore();
            getline(cin, title);
            bookManager.updateBook(title);
            break;
        }
        case 4: {
            int searchChoice;
            cout << "1. 按题名搜索" << endl;
            cout << "2. 按作者搜索" << endl;
            cout << "3. 返回上一级菜单" << endl;
            cout << "请选择（1-3）：";
            cin >> searchChoice;
            if (searchChoice == 1) {
                string title;
                cout << "请输入题名：";
                cin.ignore();
                getline(cin, title);
                bookManager.searchByTitle(title);
            } else if (searchChoice == 2) {
                string author;
                cout << "请输入作者名：";
                cin.ignore();
                getline(cin, author);
                bookManager.searchByAuthor(author);
            } else {
                cout << "无效选择，请重试！" << endl;
            }
            break;
        }
        case 5:
            bookManager.displayAllBooks();
            break;
        case 6:
            exitMenu = true;
            break;
        default:
            cout << "无效选择，请重试！" << endl;
            break;
        }
    } while (!exitMenu);
}

