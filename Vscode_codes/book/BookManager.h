#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include "../user/UserManager.h" 
#include "Book.h"
#include <vector>
#include <string>
#include <algorithm>
#include <cctype> 
using namespace std;

class BookManager {
private:
	UserManager &userManager;     // 引用 UserManager
    vector<Book> books;

public:
	BookManager(UserManager &um); // 构造函数
    void loadBooks(const string &filename);			//显示图书信息 
    void saveBooks(const string &filename);			//保存图书信息 
    void addBook(const Book &book);                // 添加图书
    void deleteBook(const string &title);          // 删除图书
    void updateBook(const string &title);          // 修改图书
	void interactiveAddBook();						// 管理员用户交互式添加图书
	
    void searchByTitle(const string &title);       // 按题名搜索
    void searchByAuthor(const string &author);     // 按作者搜索
    void searchByIsbn(const string &author);		//按图书ISBN搜索 
 	void displayAllBooks() const;    				// 显示所有图书
 	
 	void borrowBook(const string &title, const string &username);  // 借书
	void returnBook(const string &title, const string &username); // 还书
	void returnAllBooks(const string &username); // 一键归还用户的所有借阅图书
	
	vector<Book>& getBooks(); // 返回 books 的引用
    void displayBooks() const;
};

#endif

