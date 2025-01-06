#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include "Book.h"
#include <vector>
#include <string>
#include <algorithm>
#include <cctype> 
using namespace std;

class BookManager {
private:
    vector<Book> books;

public:
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
 	
 	void borrowBook(const string &title);  // ����
	void returnBook(const string &title); // ����

    void displayBooks() const;
};

#endif

