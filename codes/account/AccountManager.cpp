#include "AccountManager.h"
#include <iostream>
using namespace std;

// ���캯��
AccountManager::AccountManager(UserManager &um) : userManager(um) {}

// ��¼����
int AccountManager::login() {
    string username, password;
    cout << "�������û�����";
    cin >> username;
    cout << "���������룺";
    cin >> password;

    int role = userManager.login(username, password);
    if (role == 1) {
        cout << "��ӭ����Ա��¼��" << endl;
        currentUser = username; // ���µ�ǰ�û�
    } else if (role == 2) {
        cout << "��ӭ���ߵ�¼��" << endl;
        currentUser = username; // ���µ�ǰ�û�
    } else {
        cout << "��¼ʧ�ܣ������û��������룡" << endl;
        currentUser = ""; // ��յ�ǰ�û�
    }
    return role;
}

/*int AccountManager::login() {
    string username, password;
    cout << "�������û�����";
    cin >> username;
    cout << "���������룺";
    cin >> password;

    int role = userManager.login(username, password);
    if (role == 1) {
        cout << "��ӭ����Ա��¼��" << endl;
    } else if (role == 2) {
        cout << "��ӭ���ߵ�¼��" << endl;
    } else {
        cout << "��¼ʧ�ܣ������û��������룡" << endl;
    }
    return role;
}*/

// ע�Ṧ��
void AccountManager::registerAccount() {
    string username, password;
    cout << "���������û�����";
    cin >> username;
    cout << "�����������룺";
    cin >> password;

    userManager.registerUser(username, password, 2); // Ĭ��ע��Ϊ����
    cout << "ע��ɹ���" << endl;
}

// �鿴�����û�
void AccountManager::displayAllUsers() {
    cout << "===== ��ǰ�����û��б� =====" << endl;
    userManager.displayUsers(); // ���� UserManager ����ʾ����
}

//�����û�����
void AccountManager::resetPassword(const string &username) {
    string newPassword;
    cout << "�������û� \"" << username << "\" �������룺";
    cin >> newPassword;
    userManager.resetPassword(username, newPassword); // ���� UserManager ����
}

//ɾ����ͨ�û�
void AccountManager::deleteUser(const string &username) {
    userManager.deleteUser(username); // ���� UserManager ����
}

//��ȡ��ǰ��¼�û� 
string AccountManager::getCurrentUser() const {
    return currentUser;
}

//�ṩusermanager�����а� 
UserManager& AccountManager::getUserManager() {
    return userManager;
}




