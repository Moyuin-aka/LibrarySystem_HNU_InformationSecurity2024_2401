#include "MenuManager.h"
#include "AdminMenu.h"
#include "ReaderMenu.h" 
#include <iostream>
using namespace std;

// ���캯��ʵ��
MenuManager::MenuManager(AccountManager &am, BookManager &bm)
    : accountManager(am), bookManager(bm) {}
// ���˵�
void MenuManager::mainMenu() {
    bool exitMenu = false;
    do {
        int choice;
        cout << "===== ͼ�����ϵͳ =====" << endl;
        cout << "1. ��¼" << endl;
        cout << "2. ע��" << endl;
        cout << "3. �˳�ϵͳ" << endl;
        cout << "��ѡ��1-3����";
        cin >> choice;

        switch (choice) {
        case 1: {
            int role = accountManager.login();
            if (role == 1) {
                AdminMenu adminMenu(accountManager, bookManager);
                adminMenu.adminMenu(); // ��ת����Ա�˵�
            } else if (role == 2) {
                ReaderMenu readerMenu(accountManager, bookManager);
                readerMenu.readerMenu(); // ��ת���߲˵�
            }
            break;
        }
        case 2:
            accountManager.registerAccount();
            break;
        case 3:
            cout << "��лʹ��ϵͳ���ټ���" << endl;
            exitMenu = true; // �˳����˵�
            break;
        default:
            cout << "��Чѡ�������ԣ�" << endl;
            break;
        }
    } while (!exitMenu);
}


