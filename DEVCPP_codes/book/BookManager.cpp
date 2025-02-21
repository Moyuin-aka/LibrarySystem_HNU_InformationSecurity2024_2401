#include "BookManager.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

BookManager::BookManager(UserManager &um) : userManager(um) {}
// 加载图书信息
void BookManager::loadBooks(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "无法打开文件：" << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        string title, isbn, author, publisher, borrower;
        double price;
        bool isBorrowed;
        int borrowCount;

        istringstream stream(line);

        getline(stream, title, '|');
        getline(stream, isbn, '|');
        getline(stream, author, '|');
        getline(stream, publisher, '|');
        stream >> price;
        stream.ignore();
        stream >> isBorrowed;
        stream.ignore();
        getline(stream, borrower, '|');
        stream >> borrowCount;

        Book book(title, isbn, author, publisher, price);
        book.isBorrowed = isBorrowed;
        book.borrower = borrower;
        book.borrowCount = borrowCount; // 恢复借阅次数
        books.push_back(book);
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
		     << book.price << "|"
		     << book.isBorrowed << "|"
		     << book.borrower << "|"
             << book.borrowCount << endl; // 保存借阅者信息
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

    const int booksPerPage = 5; // 每页显示的书籍数量
    int currentPage = 0;
    int totalPages = (books.size() + booksPerPage - 1) / booksPerPage; // 计算总页数

    while (true) {
        cout << "===== 图书库（页数 " << currentPage + 1 << " / " << totalPages << "） =====" << endl;

        // 显示当前页的书籍
        int startIdx = currentPage * booksPerPage;
        int endIdx = min((int)books.size(), startIdx + booksPerPage);
        for (int i = startIdx; i < endIdx; ++i) {
            cout << i + 1 << ". ";
            books[i].display(); // 假设 Book 类有 display() 方法
        }

        // 分页选项
        cout << "==============================" << endl;
        cout << "1: 上一页, 2: 下一页, q: 退出" << endl;
        cout << "请输入选项: ";
        char choice;
        cin >> choice;

        if (choice == '2' || choice == '2') {
            if (currentPage < totalPages - 1) {
                currentPage++;
            } else {
                cout << "已经是最后一页了！" << endl;
            }
        } else if (choice == '1' || choice == '1') {
            if (currentPage > 0) {
                currentPage--;
            } else {
                cout << "已经是第一页了！" << endl;
            }
        } else if (choice == 'q' || choice == 'Q') {
            cout << "已退出分页浏览！" << endl;
            break;
        } else {
            cout << "无效选项，请重试！" << endl;
        }
    }
}

// 显示图书
void BookManager::displayBooks() const {
	for (const auto &book : books) {
		book.display();
	}
}

// 按题名搜索,支持模糊搜索
void BookManager::searchByTitle(const string &titlePart) {
	vector<Book> matchedBooks;

	// 转换输入关键字为小写
	string lowerTitlePart = titlePart;
	transform(lowerTitlePart.begin(), lowerTitlePart.end(), lowerTitlePart.begin(), ::tolower);

	// 搜索匹配的图书
	for (const auto &book : books) {
		// 转换书名为小写
		string lowerTitle = book.title;
		transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);

		// 模糊匹配
		if (lowerTitle.find(lowerTitlePart) != string::npos) {
			matchedBooks.push_back(book);
		}
	}

	// 如果没有找到匹配的图书
	if (matchedBooks.empty()) {
		cout << "未找到包含 \"" << titlePart << "\" 的图书。" << endl;
		return;
	}

	// 按字典序排序
	sort(matchedBooks.begin(), matchedBooks.end(),
	[](const Book &a, const Book &b) {
		return a.title < b.title;
	});

	// 显示匹配的图书总数
	cout << "找到 " << matchedBooks.size() << " 本图书包含 \"" << titlePart << "\"：" << endl;

	// 分页显示，每页最多显示 5 本图书
	const int booksPerPage = 5;
	int totalPages = (matchedBooks.size() + booksPerPage - 1) / booksPerPage;

	for (int page = 0; page < totalPages; ++page) {
		cout << "\n===== 第 " << page + 1 << " 页，共 " << totalPages << " 页 =====" << endl;

		for (int i = page * booksPerPage; i < (page + 1) * booksPerPage && i < matchedBooks.size(); ++i) {
			matchedBooks[i].display(); // 调用 Book 类的 display 方法显示图书信息
		}

		// 如果不是最后一页，提示用户是否继续
		if (page < totalPages - 1) {
			char choice;
			cout << "是否继续查看下一页？(y/n)：";
			cin >> choice;
			if (choice != 'y' && choice != 'Y') {
				break;
			}
		}
	}
}

// 按作者搜索,支持模糊搜索
void BookManager::searchByAuthor(const string &author) {
	vector<Book> authorBooks;

	// 收集该作者的所有书籍
	for (const auto &book : books) {
		if (book.author == author) {
			authorBooks.push_back(book);
		}
		// 支持部分匹配搜索,要不要留下呢
		if (book.author.find(author) != string::npos) {
			authorBooks.push_back(book);
		}
	}

	// 如果未找到任何书籍
	if (authorBooks.empty()) {
		cout << "未找到作者为 \"" << author << "\" 的图书。" << endl;
		return;
	}



	// 按书名的字典序排序,根据字母排序,忽略大小写
	sort(authorBooks.begin(), authorBooks.end(),
	[](const Book &a, const Book &b) {
		string titleA = a.title, titleB = b.title;
		transform(titleA.begin(), titleA.end(), titleA.begin(), ::tolower);
		transform(titleB.begin(), titleB.end(), titleB.begin(), ::tolower);
		return titleA < titleB;
	});

	// 输出结果
	cout << "作者 \"" << author << "\" 的图书如下：" << endl;
	for (const auto &book : authorBooks) {
		book.display(); // 调用 Book 类的 display 方法显示信息
	}
}


//按isbn精确搜索
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
void BookManager::borrowBook(const string &title, const string &username) {
	for (auto &book : books) {
		if (book.title == title) {
			if (book.isBorrowed) {
				cout << "图书 \"" << title << "\" 已被借出，当前借阅者为：" << book.borrower << endl;
			} else {
				book.isBorrowed = true;
				book.borrower = username;
				book.borrowCount++; 
				userManager.incrementUserBorrow(username);

				cout << "用户 \"" << username << "\" 已成功借阅图书 \"" << title << "\"！" << endl;
			}
			return;
		}
	}
	cout << "未找到题名为 \"" << title << "\" 的图书。" << endl;
}


// 还书
void BookManager::returnBook(const string &title, const string &username) {
	for (auto &book : books) {
		if (book.title == title) {
			if (!book.isBorrowed) {
				cout << "图书 \"" << title << "\" 未被借出，无需归还！" << endl;
			} else if (book.borrower != username) {
				cout << "用户 \"" << username << "\" 无权归还图书 \"" << title << "\"！当前借阅者为：" << book.borrower << endl;
			} else {
				book.isBorrowed = false;
				book.borrower = "";
				cout << "用户 \"" << username << "\" 已成功归还图书 \"" << title << "\"！" << endl;
			}
			return;
		}
	}
	cout << "未找到题名为 \"" << title << "\" 的图书。" << endl;
}

//一键还书 
void BookManager::returnAllBooks(const string &username) {
    bool hasBooksToReturn = false; // 判断用户是否有需要归还的书
    vector<string> returnedBooks; // 存储归还的书籍记录

    char confirm;
    cout << "你确定要归还所有借阅的图书吗？(y/n)：";
    cin >> confirm;
    if (confirm != 'y' && confirm != 'Y') {
        cout << "已取消一键归还操作。" << endl;
        return;
    }

    for (auto &book : books) {
        if (book.borrower == username) { 
            book.isBorrowed = false;    
            book.borrower = "";        
            returnedBooks.push_back(book.title); // 保存归还记录
            hasBooksToReturn = true;
        }
    }

    if (!hasBooksToReturn) {
        cout << "用户 \"" << username << "\" 没有需要归还的图书。" << endl;
        return;
    }

    // 统计归还的书籍数量
    cout << "一键归还完成，共归还 " << returnedBooks.size() << " 本图书！" << endl;

    // 导出归还记录到文件
    ofstream outFile("return_history.txt", ios::app); 
    if (!outFile.is_open()) {
        cout << "无法保存归还记录到文件。" << endl;
        return;
    }

    outFile << "用户: " << username << " 的归还记录：" << endl;
    for (const auto &title : returnedBooks) {
        outFile << "- " << title << endl;
    }
    outFile << "总计归还: " << returnedBooks.size() << " 本图书。" << endl;
    outFile << "========================" << endl;
    outFile.close();

    //cout << "归还记录已成功保存到 return_history.txt。" << endl;
}


//返回books给排行榜用 
vector<Book>& BookManager::getBooks(){
    return books;
}



