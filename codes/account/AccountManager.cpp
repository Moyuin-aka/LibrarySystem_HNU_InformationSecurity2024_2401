#include "AccountManager.h"
#include <iostream>
#include <fstream>
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

// ���ö������루��������һ�Σ�
void AccountManager::setSecondaryPassword(const string &password) {
    if (!adminSecondaryPassword.empty()) {
        cout << "�������������ã��޷��ٴ��޸ģ�" << endl;
        return;
    }
    adminSecondaryPassword = password;
    cout << "�����������óɹ��������Ʊ����������룡" << endl;
}

// ��֤��������
bool AccountManager::verifySecondaryPassword(const std::string &password) const {
	if (adminSecondaryPassword.empty()) {
		cout << "��δ���ö������룬�������ã�" << endl;
		return false;
	}
	return adminSecondaryPassword == password;
}

// ����������뵽�ļ�
void AccountManager::saveSecondaryPassword(const string &filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "�޷�����������뵽�ļ���" << filename << endl;
        return;
    }
    file << adminSecondaryPassword << endl;
    file.close();
}

// ���ļ����ض�������
void AccountManager::loadSecondaryPassword(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "�޷����ض��������ļ���" << filename << endl;
        return;
    }
    getline(file, adminSecondaryPassword);
    file.close();
}

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
	userManager.resetPassword(username); // ���� UserManager ����
}

//ɾ����ͨ�û�
void AccountManager::deleteUser(const string &username) {
	 string password;
    cout << "��������������Լ���������";
    cin >> password;

    if (!verifySecondaryPassword(password)) {
        cout << "����������֤ʧ�ܣ�������ȡ����" << endl;
        return;
    }
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




