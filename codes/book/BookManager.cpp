#include "BookManager.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// 加载图书信息
void BookManager::loadBooks(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "无法打开文件：" << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        string title, isbn, author, publisher;
        double price;

        // 使用字符串流解析每一行
        istringstream stream(line);

        getline(stream, title, '|'); // 用 "|" 作为分隔符读取图书名称
        getline(stream, isbn, '|'); // 读取 ISBN
        getline(stream, author, '|'); // 读取作者
        getline(stream, publisher, '|'); // 读取出版社
        stream >> price; // 读取价格

        books.emplace_back(title, isbn, author, publisher, price);
    }
    file.close();
}


// 删除图书
void BookManager::deleteBook(const string &title) {
	auto it = remove_if(books.begin(), books.end(),
	[&title](const Book &book) {
		return book.title == title;
	});
	if (it != books.end()) {
		books.erase(it, books.end());
		cout << "图书 \"" << title << "\" 已删除！" << endl;
	} else {
		cout << "未找到题名为 \"" << title << "\" 的图书。" << endl;
	}
}

// 修改图书信息
void BookManager::updateBook(const string &title) {
	for (auto &book : books) {
		if (book.title == title) {
			cout << "请输入新的作者名：";
			cin.ignore();
			getline(cin, book.author);
			cout << "请输入新的出版社名：";
			getline(cin, book.publisher);
			cout << "请输入新的价格：";
			cin >> book.price;
			cout << "图书 \"" << title << "\" 已更新！" << endl;
			return;
		}
	}
	cout << "未找到题名为 \"" << title << "\" 的图书。" << endl;
}

// 保存图书信息
void BookManager::saveBooks(const string &filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "无法打开文件：" << filename << endl;
        return;
    }

    for (const auto &book : books) {
        file << book.title << "|" 
             << book.isbn << "|"
             << book.author << "|"
             << book.publisher << "|"
             << book.price << endl; // 使用 "|" 作为分隔符
    }
    file.close();
}


// 添加图书
void BookManager::addBook(const Book &book) {
	books.push_back(book);
}

// 交互式添加图书
void BookManager::interactiveAddBook() {
	string title, author, publisher, isbn;
	double price;

	cout << "请输入图书题名：";
	cin.ignore(); // 清除缓冲区
	getline(cin, title);

	cout << "请输入ISBN：";
	getline(cin, isbn);

	cout << "请输入作者名：";
	getline(cin, author);

	cout << "请输入出版社名：";
	getline(cin, publisher);

	cout << "请输入价格：";
	cin >> price;

	books.emplace_back(title, isbn, author, publisher, price);
	cout << "图书已成功添加！" << endl;
}

// 显示所有图书
void BookManager::displayAllBooks() const {
	if (books.empty()) {
		cout << "图书库为空。" << endl;
		return;
	}

	cout << "当前图书库中的图书：" << endl;
	for (const auto &book : books) {
		book.display();
	}
}

// 显示图书
void BookManager::displayBooks() const {
	for (const auto &book : books) {
		book.display();
	}
}

// 按题名搜索
void BookManager::searchByTitle(const string &title) {
	for (const auto &book : books) {
		if (book.title == title) {
			book.display();
			return;
		}
	}
	cout << "未找到题名为 \"" << title << "\" 的图书。" << endl;
}

// 按作者搜索
void BookManager::searchByAuthor(const string &author) {
	vector<Book> authorBooks;

	for (const auto &book : books) {
		if (book.author == author) {
			authorBooks.push_back(book);
		}
	}

	if (authorBooks.empty()) {
		cout << "未找到作者为 \"" << author << "\" 的图书。" << endl;
		return;
	}
	// 按字典序排序
	sort(authorBooks.begin(), authorBooks.end());

	cout << "作者 \"" << author << "\" 的图书如下：" << endl;
	for (const auto &book : authorBooks) {
		book.display();
	}
}

//按isbn搜索
	void BookManager::searchByIsbn(const string &isbn) {
		for (const auto &book : books) {
			if (book.isbn == isbn) {
				book.display();
				return;
			}
		}
		cout << "未找到ISBN为 \"" << isbn << "\" 的图书。" << endl;
	}

// 借书
void BookManager::borrowBook(const string &title) {
	for (auto &book : books) {
		if (book.title == title) {
			if (book.isBorrowed) {
				cout << "图书 \"" << title << "\" 已被借出！" << endl;
			} else {
				book.isBorrowed = true;
				cout << "您已成功借阅图书 \"" << title << "\"！" << endl;
			}
			return;
		}
	}
	cout << "未找到题名为 \"" << title << "\" 的图书。" << endl;
}

// 还书
void BookManager::returnBook(const string &title) {
	for (auto &book : books) {
		if (book.title == title) {
			if (!book.isBorrowed) {
				cout << "图书 \"" << title << "\" 未被借出，无需归还！" << endl;
			} else {
				book.isBorrowed = false;
				cout << "您已成功归还图书 \"" << title << "\"！" << endl;
			}
			return;
		}
	}
	cout << "未找到题名为 \"" << title << "\" 的图书。" << endl;
}


