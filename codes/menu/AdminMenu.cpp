#include "AdminMenu.h"
#include <iostream>
using namespace std;

// ���캯��ʵ��
AdminMenu::AdminMenu(AccountManager &am, BookManager &bm)
    : accountManager(am), bookManager(bm) {}

// ����Ա�˵�
void AdminMenu::adminMenu() {
    bool exitMenu = false;
    do {
        int choice;
        cout << "===== ����Ա�˵� =====" << endl;
        cout << "1. ���ͼ��" << endl;
        cout << "2. ɾ��ͼ��" << endl;
        cout << "3. �޸�ͼ����Ϣ" << endl;
        cout << "4. ����ͼ��" << endl;
        cout << "5. ��ʾ����ͼ��" << endl;
        cout << "6. ������һ���˵�" << endl;
        cout << "��ѡ��1-6����";
        cin >> choice;

        switch (choice) {
        case 1:
            bookManager.interactiveAddBook();
            break;
        case 2: {
            string title;
            cout << "������Ҫɾ����ͼ��������";
            cin.ignore();
            getline(cin, title);
            bookManager.deleteBook(title);
            break;
        }
        case 3: {
            string title;
            cout << "������Ҫ�޸ĵ�ͼ��������";
            cin.ignore();
            getline(cin, title);
            bookManager.updateBook(title);
            break;
        }
        case 4: {
            int searchChoice;
            cout << "1. ����������" << endl;
            cout << "2. ����������" << endl;
            cout << "3. ������һ���˵�" << endl;
            cout << "��ѡ��1-3����";
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
        case 5:
            bookManager.displayAllBooks();
            break;
        case 6:
            exitMenu = true;
            break;
        default:
            cout << "��Чѡ�������ԣ�" << endl;
            break;
        }
    } while (!exitMenu);
}

