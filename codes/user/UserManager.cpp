#include "UserManager.h"
#include <iostream>
#include <fstream>
using namespace std;

// ���캯��
UserManager::UserManager() {}

// �����û�����
void UserManager::loadUsers(const string &file) {
    ifstream inFile(file);
    if (!inFile.is_open()) return;

    string username, password;
    int role;
    while (inFile >> username >> password >> role) {
        users.emplace_back(username, password, role);
    }
    inFile.close();
}

// �����û�����
void UserManager::saveUsers(const string &file) {
    ofstream outFile(file);
    for (const auto &user : users) {
        outFile << user.username << " " << user.password << " " << user.role << endl;
    }
    outFile.close();
}

// ��¼����
int UserManager::login(const string &username, const string &password) {
    for (const auto &user : users) {
        if (user.username == username && user.password == password) {
            return user.role; // �����û���ɫ��1: ����Ա, 2: ���ߣ�
        }
    }
    return 0; // ��¼ʧ��
}

// ע���û�
void UserManager::registerUser(const string &username, const string &password, int role) {
    users.emplace_back(username, password, role);
}

// ��ʾ�����û�
void UserManager::displayUsers() {
    for (const auto &user : users) {
        user.display();
    }
}

