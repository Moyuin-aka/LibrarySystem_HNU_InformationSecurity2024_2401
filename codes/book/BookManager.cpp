#include "BookManager.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// ����ͼ����Ϣ
void BookManager::loadBooks(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "�޷����ļ���" << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        string title, isbn, author, publisher;
        double price;

        // ʹ���ַ���������ÿһ��
        istringstream stream(line);

        getline(stream, title, '|'); // �� "|" ��Ϊ�ָ�����ȡͼ������
        getline(stream, isbn, '|'); // ��ȡ ISBN
        getline(stream, author, '|'); // ��ȡ����
        getline(stream, publisher, '|'); // ��ȡ������
        stream >> price; // ��ȡ�۸�

        books.emplace_back(title, isbn, author, publisher, price);
    }
    file.close();
}


// ɾ��ͼ��
void BookManager::deleteBook(const string &title) {
	auto it = remove_if(books.begin(), books.end(),
	[&title](const Book &book) {
		return book.title == title;
	});
	if (it != books.end()) {
		books.erase(it, books.end());
		cout << "ͼ�� \"" << title << "\" ��ɾ����" << endl;
	} else {
		cout << "δ�ҵ�����Ϊ \"" << title << "\" ��ͼ�顣" << endl;
	}
}

// �޸�ͼ����Ϣ
void BookManager::updateBook(const string &title) {
	for (auto &book : books) {
		if (book.title == title) {
			cout << "�������µ���������";
			cin.ignore();
			getline(cin, book.author);
			cout << "�������µĳ���������";
			getline(cin, book.publisher);
			cout << "�������µļ۸�";
			cin >> book.price;
			cout << "ͼ�� \"" << title << "\" �Ѹ��£�" << endl;
			return;
		}
	}
	cout << "δ�ҵ�����Ϊ \"" << title << "\" ��ͼ�顣" << endl;
}

// ����ͼ����Ϣ
void BookManager::saveBooks(const string &filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "�޷����ļ���" << filename << endl;
        return;
    }

    for (const auto &book : books) {
        file << book.title << "|" 
             << book.isbn << "|"
             << book.author << "|"
             << book.publisher << "|"
             << book.price << endl; // ʹ�� "|" ��Ϊ�ָ���
    }
    file.close();
}


// ���ͼ��
void BookManager::addBook(const Book &book) {
	books.push_back(book);
}

// ����ʽ���ͼ��
void BookManager::interactiveAddBook() {
	string title, author, publisher, isbn;
	double price;

	cout << "������ͼ��������";
	cin.ignore(); // ���������
	getline(cin, title);

	cout << "������ISBN��";
	getline(cin, isbn);

	cout << "��������������";
	getline(cin, author);

	cout << "���������������";
	getline(cin, publisher);

	cout << "������۸�";
	cin >> price;

	books.emplace_back(title, isbn, author, publisher, price);
	cout << "ͼ���ѳɹ���ӣ�" << endl;
}

// ��ʾ����ͼ��
void BookManager::displayAllBooks() const {
	if (books.empty()) {
		cout << "ͼ���Ϊ�ա�" << endl;
		return;
	}

	cout << "��ǰͼ����е�ͼ�飺" << endl;
	for (const auto &book : books) {
		book.display();
	}
}

// ��ʾͼ��
void BookManager::displayBooks() const {
	for (const auto &book : books) {
		book.display();
	}
}

// ����������
void BookManager::searchByTitle(const string &title) {
	for (const auto &book : books) {
		if (book.title == title) {
			book.display();
			return;
		}
	}
	cout << "δ�ҵ�����Ϊ \"" << title << "\" ��ͼ�顣" << endl;
}

// ����������
void BookManager::searchByAuthor(const string &author) {
	vector<Book> authorBooks;

	for (const auto &book : books) {
		if (book.author == author) {
			authorBooks.push_back(book);
		}
	}

	if (authorBooks.empty()) {
		cout << "δ�ҵ�����Ϊ \"" << author << "\" ��ͼ�顣" << endl;
		return;
	}
	// ���ֵ�������
	sort(authorBooks.begin(), authorBooks.end());

	cout << "���� \"" << author << "\" ��ͼ�����£�" << endl;
	for (const auto &book : authorBooks) {
		book.display();
	}
}

//��isbn����
	void BookManager::searchByIsbn(const string &isbn) {
		for (const auto &book : books) {
			if (book.isbn == isbn) {
				book.display();
				return;
			}
		}
		cout << "δ�ҵ�ISBNΪ \"" << isbn << "\" ��ͼ�顣" << endl;
	}

// ����
void BookManager::borrowBook(const string &title) {
	for (auto &book : books) {
		if (book.title == title) {
			if (book.isBorrowed) {
				cout << "ͼ�� \"" << title << "\" �ѱ������" << endl;
			} else {
				book.isBorrowed = true;
				cout << "���ѳɹ�����ͼ�� \"" << title << "\"��" << endl;
			}
			return;
		}
	}
	cout << "δ�ҵ�����Ϊ \"" << title << "\" ��ͼ�顣" << endl;
}

// ����
void BookManager::returnBook(const string &title) {
	for (auto &book : books) {
		if (book.title == title) {
			if (!book.isBorrowed) {
				cout << "ͼ�� \"" << title << "\" δ�����������黹��" << endl;
			} else {
				book.isBorrowed = false;
				cout << "���ѳɹ��黹ͼ�� \"" << title << "\"��" << endl;
			}
			return;
		}
	}
	cout << "δ�ҵ�����Ϊ \"" << title << "\" ��ͼ�顣" << endl;
}


