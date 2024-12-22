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
            cout << "��ѡ��1-2����";
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
            } else {
                cout << "��Чѡ�������ԣ�" << endl;
            }
            break;
        }
        case 2: {
            string title;
            cout << "������Ҫ���ĵ�ͼ��������";
            cin.ignore();
            getline(cin, title);
            bookManager.borrowBook(title);
            break;
        }
        case 3: {
            string title;
            cout << "������Ҫ�黹��ͼ��������";
            cin.ignore();
            getline(cin, title);
            bookManager.returnBook(title);
            break;
        }
        case 5:{
            exitMenu = true;
            break;
        }
        case 4:{
			bookManager.displayAllBooks();
            break;
        }
        default:
            cout << "��Чѡ�������ԣ�" << endl;
            break;
        }
    } while (!exitMenu);
}

