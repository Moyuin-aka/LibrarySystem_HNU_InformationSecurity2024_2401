#include "ReaderMenu.h"
#include <iostream>
using namespace std;

// 构造函数实现
ReaderMenu::ReaderMenu(AccountManager &am, BookManager &bm, UserManager &um)
	: accountManager(am), bookManager(bm), userManager(um) {}

// 读者菜单
void ReaderMenu::readerMenu() {
	bool exitMenu = false;
	do {

		if (accountManager.getCurrentUser() != "admin" &&
		        userManager.needsPasswordReset(accountManager.getCurrentUser())) {
			cout << "===== 您的密码已被管理员重置，请立即修改密码！ =====" << endl;
			string newPassword;
			cout << "请输入新密码：";
			cin >> newPassword;
			userManager.updatePassword(accountManager.getCurrentUser(), newPassword);
			continue;
		}
		
		cout << "===== 读者菜单 =====" << endl;
		cout << "1. 搜索图书" << endl;
		cout << "2. 借书" << endl;
		cout << "3. 还书" << endl;
		cout << "4. 显示所有图书" << endl;
		cout << "5. 今日推荐" << endl;
		cout << "6. 返回上一级菜单" << endl;
		cout << "请选择（1-6）：";
		int choice = getValidatedChoice(); 

		switch (choice) {
			case 1: {
				
				cout << "1. 按题名搜索" << endl;
				cout << "2. 按作者搜索" << endl;
				cout << "3. 按ISBN搜索" << endl; // 新增选项
				cout << "4. 返回上一级菜单" << endl; // 新增选项
				cout << "请选择（1-4）：";
				
				int searchChoice = getValidatedChoice();
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

				int returnChoice = getValidatedChoice();
				

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
			case 6: {
				exitMenu = true;
				break;
			}
			case 5: {
				displayRecommendations();
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

//今日书单
void ReaderMenu::displayRecommendations() {
	cout << "===== 今日推荐书单 =====" << endl;

	vector<Book>& books = bookManager.getBooks();

	vector<pair<Book, int>> bookBorrowCounts;

	for (const auto &book : books) {
		if (book.borrowCount > 0) { // 仅推荐借阅次数大于 0 的书籍
			bookBorrowCounts.emplace_back(book, book.borrowCount);
		}
	}
	sort(bookBorrowCounts.begin(), bookBorrowCounts.end(),
	[](const pair<Book, int> &a, const pair<Book, int> &b) {
		if (a.second == b.second) {
			return a.first.title < b.first.title; // 按题名字典序排序
		}
		return a.second > b.second; // 按借阅次数排序（降序）
	});

	int count = 0;
	for (const auto &entry : bookBorrowCounts) {
		if (count >= 3) break; // 最多推荐 3 本
		cout << count + 1 << ". " << entry.first.title
		     << " (作者: " << entry.first.author
		     << ", 借阅次数: " << entry.second << ")" << endl;
		count++;
	}

	if (count == 0) {
		cout << "暂无热门图书推荐，请稍后再试！" << endl;
	}
}

int ReaderMenu::getValidatedChoice(){
    string input;
    int choice;

    while (true) {
        cin >> input;

        // 验证是否为数字
        bool isValidNumber = true;
        for (char c : input) {
            if (!isdigit(c)) {
                isValidNumber = false;
                break;
            }
        }

        if (!isValidNumber) {
            cout << "输入无效，请输入数字！" << endl;
            continue;
        }

        // 转换为整数
        choice = stoi(input);// 输入合法
        break;
    }

    return choice;
}
