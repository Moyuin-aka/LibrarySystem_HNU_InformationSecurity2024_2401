#include "ReaderMenu.h"
#include <iostream>
using namespace std;

// 构造函数实现
ReaderMenu::ReaderMenu(AccountManager &am, BookManager &bm)
	: accountManager(am), bookManager(bm) {}

// 读者菜单
void ReaderMenu::readerMenu() {
	bool exitMenu = false;
	do {
		int choice;
		cout << "===== 读者菜单 =====" << endl;
		cout << "1. 搜索图书" << endl;
		cout << "2. 借书" << endl;
		cout << "3. 还书" << endl;
		cout << "4. 显示所有图书" << endl;
		cout << "5. 返回上一级菜单" << endl;
		cout << "请选择（1-5）：";
		cin >> choice;

		switch (choice) {
			case 1: {
				int searchChoice;
				cout << "1. 按题名搜索" << endl;
				cout << "2. 按作者搜索" << endl;
				cout << "3. 按ISBN搜索" << endl; // 新增选项
				cout << "4. 返回上一级菜单" << endl; // 新增选项
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
					bookManager.searchByIsbn(isbn);
				} else if(searchChoice == 4) break;
				else {
					cout << "无效选择，请重试！" << endl;
				}
				break;
			}
			case 2: {
				string title;
				cout << "请输入要借阅的图书题名：";
				cin.ignore();
				getline(cin, title);
				bookManager.borrowBook(title, accountManager.getCurrentUser()); // 传递当前用户名
				break;
			}
			case 3: {
				cout << "===== 归还图书 =====" << endl;
				cout << "1. 归还单本图书" << endl;
				cout << "2. 一键归还所有图书" << endl; // 新增选项
				cout << "请选择（1-2）：";

				int returnChoice;
				cin >> returnChoice;

				if (returnChoice == 1) {
					string title;
					cout << "请输入要归还的图书题名：";
					cin.ignore();
					getline(cin, title);
					bookManager.returnBook(title, accountManager.getCurrentUser()); // 归还单本图书
				} else if (returnChoice == 2) {
					bookManager.returnAllBooks(accountManager.getCurrentUser()); // 调用一键归还功能
				} else {
					cout << "无效选择，请重试！" << endl;
				}
				break;
			}
			case 5: {
				exitMenu = true;
				break;
			}
			case 4: {
				bookManager.displayAllBooks();
				break;
			}
			default:
				cout << "无效选择，请重试！" << endl;
				break;
		}
	} while (!exitMenu);
}

