#include "MenuManager.h"
#include "AdminMenu.h"
#include "ReaderMenu.h" 
#include <iostream>
#include <string>
using namespace std;

// ���캯��ʵ��
MenuManager::MenuManager(AccountManager &am, BookManager &bm, UserManager &mm)
    : accountManager(am), bookManager(bm), userManager(mm) {}
// ���˵�
void MenuManager::mainMenu() {
    bool exitMenu = false;
    do {
        cout << "===== ͼ�����ϵͳ =====" << endl;
        cout << "1. ��¼" << endl;
        cout << "2. ע��" << endl;
        cout << "3. �������а�" << endl; // �������а�ѡ��
        cout << "4. �˳�ϵͳ" << endl;
        cout << "��ѡ��1-4����";
        int choice = getValidatedChoice();

        switch (choice) {
        case 1: {
            int role = accountManager.login();
            if (role == 1) {
                AdminMenu adminMenu(accountManager, bookManager);
                adminMenu.adminMenu(); // ��ת����Ա�˵�
            } else if (role == 2) {
                ReaderMenu readerMenu(accountManager, bookManager, userManager);
                readerMenu.readerMenu(); // ��ת���߲˵�
            }
            break;
        }
        case 2:
            accountManager.registerAccount();
            break;
        case 3: {
            Charts charts(bookManager, accountManager.getUserManager());
            cout << "===== �������а� =====" << endl;
            cout << "1. ͼ��������а�" << endl;
            cout << "2. ʮ�Ѷ������а�" << endl;
            cout << "��ѡ��1-2����";

            int chartChoice;
            cin >> chartChoice;

            if (chartChoice == 1) {
                charts.displayTopBooks(); // ͼ��������а�
            } else if (chartChoice == 2) {
                charts.displayTopReaders(); // ʮ�Ѷ������а�
            } else {
                cout << "��Чѡ�������ԣ�" << endl;
            }
            break;
        }
        case 4:
            cout << "��лʹ��ϵͳ���ټ���" << endl;
            exitMenu = true; // �˳����˵�
            break;
        default:
            cout << "��Чѡ�������ԣ�" << endl;
            break;
        }
    } while (!exitMenu);
}

int MenuManager::getValidatedChoice(){
    string input;
    int choice;

    while (true) {
        cin >> input;

        // ��֤�Ƿ�Ϊ����
        bool isValidNumber = true;
        for (char c : input) {
            if (!isdigit(c)) {
                isValidNumber = false;
                break;
            }
        }

        if (!isValidNumber) {
            cout << "������Ч�����������֣�" << endl;
            cout << "����������: " ;
            continue;
        }

        // ת��Ϊ����
        choice = stoi(input);// ����Ϸ�
        break;
    }

    return choice;
}


