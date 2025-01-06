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
		cout << "6. 用户管理" << endl; // 新增选项
		cout << "7. 返回上一级菜单" << endl;
		cout << "请选择（1-7）：";
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
				cout << "3. 按ISBN搜索" << endl; // 新增选项
				cout << "4. 返回上一级菜单" << endl;
				cout << "请选择（1-4）：";
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
				} else if (searchChoice == 3) { // 添加按ISBN搜索
					string isbn;
					cout << "请输入ISBN：";
					cin.ignore();
					getline(cin, isbn);
					bookManager.searchByIsbn(isbn); // 调用新方法
				} else if(searchChoice == 4) break;

				else {
					cout << "无效选择，请重试！" << endl;
				}
				break;
			}
			case 5:
				bookManager.displayAllBooks();
				break;
			case 6:{
				bool exitUserMenu = false;
		    do {
		        int UserChoice;
		        cout << "===== 用户管理 =====" << endl;
		        cout << "1. 查看所有用户" << endl;
		        cout << "2. 重置用户密码" << endl;
		        cout << "3. 删除普通用户" << endl;
		        cout << "4. 返回上一级菜单" << endl;
		        cout << "请选择（1-4）：";
		        cin >> UserChoice;
		
		        switch (UserChoice) {
		        case 1:
		            accountManager.displayAllUsers(); // 调用显示所有用户功能
		            break;
		        case 2: {
		            string username;
		            cout << "请输入要重置密码的用户名：";
		            cin >> username;
		            accountManager.resetPassword(username); // 调用重置密码功能
		            break;
		        }
		        case 3: {
		            string username;
		            cout << "请输入要删除的用户名：";
		            cin >> username;
		            accountManager.deleteUser(username); // 调用删除用户功能
		            break;
		        }
		        case 4:
		            exitUserMenu = true;
		            break;
		        default:
		            cout << "无效选择，请重试！" << endl;
		            break;
		        	}
		    	} while (!exitUserMenu);
				break;
			}

			case 7:
				exitMenu = true;
				break;
			default:
				cout << "无效选择，请重试！" << endl;
				break;
		}
	} while (!exitMenu);
}

