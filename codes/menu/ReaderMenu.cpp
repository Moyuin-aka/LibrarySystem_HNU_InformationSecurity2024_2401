#include "ReaderMenu.h"
#include <iostream>
using namespace std;

// ���캯��ʵ��
ReaderMenu::ReaderMenu(AccountManager &am, BookManager &bm)
	: accountManager(am), bookManager(bm) {}

// ���߲˵�
void ReaderMenu::readerMenu() {
	bool exitMenu = false;
	do {
		int choice;
		cout << "===== ���߲˵� =====" << endl;
		cout << "1. ����ͼ��" << endl;
		cout << "2. ����" << endl;
		cout << "3. ����" << endl;
		cout << "4. ��ʾ����ͼ��" << endl;
		cout << "5. ������һ���˵�" << endl;
		cout << "��ѡ��1-5����";
		cin >> choice;

		switch (choice) {
			case 1: {
				int searchChoice;
				cout << "1. ����������" << endl;
				cout << "2. ����������" << endl;
				cout << "3. ��ISBN����" << endl; // ����ѡ��
				cout << "4. ������һ���˵�" << endl; // ����ѡ��
				cout << "��ѡ��1-4����";
				cin >> searchChoice;
				if (searchChoice == 1) {
					string title;
					cout << "������������";
					cin.ignore();
					getline(cin, title);
					bookManager.searchByTitle(title);
				} else if (searchChoice == 2) {
					string author;
					cout << "��������������";
					cin.ignore();
					getline(cin, author);
					bookManager.searchByAuthor(author);
				} else if (searchChoice == 3) { // ��Ӱ�ISBN����
					string isbn;
					cout << "������ISBN��";
					cin.ignore();
					getline(cin, isbn);
					bookManager.searchByIsbn(isbn);
				} else if(searchChoice == 4) break;
				else {
					cout << "��Чѡ�������ԣ�" << endl;
				}
				break;
			}
			case 2: {
				string title;
				cout << "������Ҫ���ĵ�ͼ��������";
				cin.ignore();
				getline(cin, title);
				bookManager.borrowBook(title, accountManager.getCurrentUser()); // ���ݵ�ǰ�û���
				break;
			}
			case 3: {
				cout << "===== �黹ͼ�� =====" << endl;
				cout << "1. �黹����ͼ��" << endl;
				cout << "2. һ���黹����ͼ��" << endl; // ����ѡ��
				cout << "��ѡ��1-2����";

				int returnChoice;
				cin >> returnChoice;

				if (returnChoice == 1) {
					string title;
					cout << "������Ҫ�黹��ͼ��������";
					cin.ignore();
					getline(cin, title);
					bookManager.returnBook(title, accountManager.getCurrentUser()); // �黹����ͼ��
				} else if (returnChoice == 2) {
					bookManager.returnAllBooks(accountManager.getCurrentUser()); // ����һ���黹����
				} else {
					cout << "��Чѡ�������ԣ�" << endl;
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
				cout << "��Чѡ�������ԣ�" << endl;
				break;
		}
	} while (!exitMenu);
}

