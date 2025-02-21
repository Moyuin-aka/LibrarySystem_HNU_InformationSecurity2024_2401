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
	UserManager &userManager;     // ���� UserManager
    vector<Book> books;

public:
	BookManager(UserManager &um); // ���캯��
    void loadBooks(const string &filename);			//��ʾͼ����Ϣ 
    void saveBooks(const string &filename);			//����ͼ����Ϣ 
    void addBook(const Book &book);                // ���ͼ��
    void deleteBook(const string &title);          // ɾ��ͼ��
    void updateBook(const string &title);          // �޸�ͼ��
	void interactiveAddBook();						// ����Ա�û�����ʽ���ͼ��
	
    void searchByTitle(const string &title);       // ����������
    void searchByAuthor(const string &author);     // ����������
    void searchByIsbn(const string &author);		//��ͼ��ISBN���� 
 	void displayAllBooks() const;    				// ��ʾ����ͼ��
 	
 	void borrowBook(const string &title, const string &username);  // ����
	void returnBook(const string &title, const string &username); // ����
	void returnAllBooks(const string &username); // һ���黹�û������н���ͼ��
	
	vector<Book>& getBooks(); // ���� books ������
    void displayBooks() const;
};

#endif

