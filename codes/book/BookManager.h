#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include "Book.h"
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

class BookManager {
private:
    vector<Book> books;

public:
    void loadBooks(const string &filename);			//显示图书信息 
    void saveBooks(const string &filename);			//保存图书信息 
    void addBook(const Book &book);                // 添加图书
    void deleteBook(const string &title);          // 删除图书
    void updateBook(const string &title);          // 修改图书
	void interactiveAddBook();						// 管理员用户交互式添加图书
	
    void searchByTitle(const string &title);       // 按题名搜索
    void searchByAuthor(const string &author);     // 按作者搜索
 	void displayAllBooks() const;    				// 显示所有图书
 	
 	void borrowBook(const string &title);  // 借书
	void returnBook(const string &title); // 还书

    void displayBooks() const;
};

#endif

