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
        string title, isbn, author, publisher, borrower;
        double price;
        bool isBorrowed;

        istringstream stream(line);

        getline(stream, title, '|');
        getline(stream, isbn, '|');
        getline(stream, author, '|');
        getline(stream, publisher, '|');
        stream >> price;
        stream.ignore(); // ���Էָ���
        stream >> isBorrowed;
        stream.ignore(); // ���Էָ���
        getline(stream, borrower);

        Book book(title, isbn, author, publisher, price);
        book.isBorrowed = isBorrowed;
        book.borrower = borrower;
        books.push_back(book);
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
		     << book.price << "|"
		     << book.isBorrowed << "|"
		     << book.borrower << endl; // �����������Ϣ
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

// ����������,֧��ģ������
void BookManager::searchByTitle(const string &titlePart) {
	vector<Book> matchedBooks;

	// ת������ؼ���ΪСд
	string lowerTitlePart = titlePart;
	transform(lowerTitlePart.begin(), lowerTitlePart.end(), lowerTitlePart.begin(), ::tolower);

	// ����ƥ���ͼ��
	for (const auto &book : books) {
		// ת������ΪСд
		string lowerTitle = book.title;
		transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);

		// ģ��ƥ��
		if (lowerTitle.find(lowerTitlePart) != string::npos) {
			matchedBooks.push_back(book);
		}
	}

	// ���û���ҵ�ƥ���ͼ��
	if (matchedBooks.empty()) {
		cout << "δ�ҵ����� \"" << titlePart << "\" ��ͼ�顣" << endl;
		return;
	}

	// ���ֵ�������
	sort(matchedBooks.begin(), matchedBooks.end(),
	[](const Book &a, const Book &b) {
		return a.title < b.title;
	});

	// ��ʾƥ���ͼ������
	cout << "�ҵ� " << matchedBooks.size() << " ��ͼ����� \"" << titlePart << "\"��" << endl;

	// ��ҳ��ʾ��ÿҳ�����ʾ 5 ��ͼ��
	const int booksPerPage = 5;
	int totalPages = (matchedBooks.size() + booksPerPage - 1) / booksPerPage;

	for (int page = 0; page < totalPages; ++page) {
		cout << "\n===== �� " << page + 1 << " ҳ���� " << totalPages << " ҳ =====" << endl;

		for (int i = page * booksPerPage; i < (page + 1) * booksPerPage && i < matchedBooks.size(); ++i) {
			matchedBooks[i].display(); // ���� Book ��� display ������ʾͼ����Ϣ
		}

		// ����������һҳ����ʾ�û��Ƿ����
		if (page < totalPages - 1) {
			char choice;
			cout << "�Ƿ�����鿴��һҳ��(y/n)��";
			cin >> choice;
			if (choice != 'y' && choice != 'Y') {
				break;
			}
		}
	}
}

// ����������,֧��ģ������
void BookManager::searchByAuthor(const string &author) {
	vector<Book> authorBooks;

	// �ռ������ߵ������鼮
	for (const auto &book : books) {
		if (book.author == author) {
			authorBooks.push_back(book);
		}
		// ֧�ֲ���ƥ������,Ҫ��Ҫ������
		if (book.author.find(author) != string::npos) {
			authorBooks.push_back(book);
		}
	}

	// ���δ�ҵ��κ��鼮
	if (authorBooks.empty()) {
		cout << "δ�ҵ�����Ϊ \"" << author << "\" ��ͼ�顣" << endl;
		return;
	}



	// ���������ֵ�������,������ĸ����,���Դ�Сд
	sort(authorBooks.begin(), authorBooks.end(),
	[](const Book &a, const Book &b) {
		string titleA = a.title, titleB = b.title;
		transform(titleA.begin(), titleA.end(), titleA.begin(), ::tolower);
		transform(titleB.begin(), titleB.end(), titleB.begin(), ::tolower);
		return titleA < titleB;
	});

	// ������
	cout << "���� \"" << author << "\" ��ͼ�����£�" << endl;
	for (const auto &book : authorBooks) {
		book.display(); // ���� Book ��� display ������ʾ��Ϣ
	}
}


//��isbn��ȷ����
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
void BookManager::borrowBook(const string &title, const string &username) {
	for (auto &book : books) {
		if (book.title == title) {
			if (book.isBorrowed) {
				cout << "ͼ�� \"" << title << "\" �ѱ��������ǰ������Ϊ��" << book.borrower << endl;
			} else {
				book.isBorrowed = true;
				book.borrower = username;
				cout << "�û� \"" << username << "\" �ѳɹ�����ͼ�� \"" << title << "\"��" << endl;
			}
			return;
		}
	}
	cout << "δ�ҵ�����Ϊ \"" << title << "\" ��ͼ�顣" << endl;
}


// ����
void BookManager::returnBook(const string &title, const string &username) {
	for (auto &book : books) {
		if (book.title == title) {
			if (!book.isBorrowed) {
				cout << "ͼ�� \"" << title << "\" δ�����������黹��" << endl;
			} else if (book.borrower != username) {
				cout << "�û� \"" << username << "\" ��Ȩ�黹ͼ�� \"" << title << "\"����ǰ������Ϊ��" << book.borrower << endl;
			} else {
				book.isBorrowed = false;
				book.borrower = "";
				cout << "�û� \"" << username << "\" �ѳɹ��黹ͼ�� \"" << title << "\"��" << endl;
			}
			return;
		}
	}
	cout << "δ�ҵ�����Ϊ \"" << title << "\" ��ͼ�顣" << endl;
}

//����books�����а��� 
vector<Book>& BookManager::getBooks() {
    return books;
}



