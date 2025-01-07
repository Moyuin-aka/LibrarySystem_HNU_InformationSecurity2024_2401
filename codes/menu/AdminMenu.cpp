#include "AdminMenu.h"
#include <iostream>
using namespace std;

// ���캯��ʵ��
AdminMenu::AdminMenu(AccountManager &am, BookManager &bm)
	: accountManager(am), bookManager(bm){}

// ����Ա�˵�
void AdminMenu::adminMenu() {
	bool exitMenu = false;
	do {
		cout << "===== ����Ա�˵� =====" << endl;
		cout << "1. ���ͼ��" << endl;
		cout << "2. ɾ��ͼ��" << endl;
		cout << "3. �޸�ͼ����Ϣ" << endl;
		cout << "4. ����ͼ��" << endl;
		cout << "5. ��ʾ����ͼ��" << endl;
		cout << "6. �鿴���й黹��¼" << endl; // ����ѡ��
		cout << "7. �û�����" << endl;
		cout << "8. ���ö�������" << endl;
		cout << "9. ������һ���˵�" << endl;
		cout << "��ѡ��1-9����";
		int choice = getValidatedChoice();

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
				cout << "1. ����������" << endl;
				cout << "2. ����������" << endl;
				cout << "3. ��ISBN����" << endl;
				cout << "4. ������һ���˵�" << endl;
				cout << "��ѡ��1-4����";
				
				int searchChoice =getValidatedChoice();
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
					bookManager.searchByIsbn(isbn); // �����·���
				} else if(searchChoice == 4) break;

				else {
					cout << "��Чѡ�������ԣ�" << endl;
				}
				break;
			}
			case 5:
				bookManager.displayAllBooks();
				break;
			case 6: {
				accountManager.viewAllReturnHistoryPaged(); // �����·���
				break;
			}
			case 7: {
				bool exitUserMenu = false;
				do {
					cout << "===== �û����� =====" << endl;
					cout << "1. �鿴�����û�" << endl;
					cout << "2. �����û�����" << endl;
					cout << "3. ɾ����ͨ�û�" << endl;
					cout << "4. ������һ���˵�" << endl;
					cout << "��ѡ��1-4����";
					int UserChoice =getValidatedChoice();

					switch (UserChoice) {
						case 1:
							accountManager.displayAllUsers(); // ������ʾ�����û�����
							break;
						case 2: {
							string username;
							cout << "������Ҫ����������û�����";
							cin >> username;
							accountManager.resetPassword(username); // �����������빦��
							break;
						}
						case 3: {
							string username;
							cout << "������Ҫɾ�����û�����";
							cin >> username;
							accountManager.deleteUser(username); // ����ɾ���û�����
							break;
						}
						case 4:
							exitUserMenu = true;
							break;
						default:
							cout << "��Чѡ�������ԣ�" << endl;
							break;
					}
				} while (!exitUserMenu);
				break;
			}
			case 8: {
				string password;
				cout << "������Ҫ���õĶ������룺";
				cin >> password;
				accountManager.setSecondaryPassword(password);
				break;
				break;
			}
			case 9:
				exitMenu = true;
				break;
			default:
				cout << "��Чѡ�������ԣ�" << endl;
				break;
		}
	} while (!exitMenu);
}

int AdminMenu::getValidatedChoice(){
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
            continue;
        }

        // ת��Ϊ����
        choice = stoi(input);// ����Ϸ�
        break;
    }

    return choice;
}

