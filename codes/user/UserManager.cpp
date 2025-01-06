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

//�����û�����
void UserManager::resetPassword(const string &username, const string &newPassword) {
	for (auto &user : users) {
		if (user.username == username) {
			user.password = newPassword;
			cout << "�����ѳɹ����ã�" << endl;
			return;
		}
	}
	cout << "δ�ҵ��û���Ϊ \"" << username << "\" ���û���" << endl;
}

//ɾ���û�
void UserManager::deleteUser(const string &username) {
	for (auto it = users.begin(); it != users.end(); ++it) {
		if (it->username == username) {
			if (it->role == 1) {
				cout << "�޷�ɾ������Ա�û� \"" << username << "\"��" << endl;
				return;
			}
			cout<<"��ע��!ɾ�����޷��ָ�,��ȷ��ɾ����?(y/n)"<<endl;
			char checkOutDelete;
			cin>>checkOutDelete;
			if(checkOutDelete == 'y') {
				users.erase(it);
				cout << "�û� \"" << username << "\" �ѳɹ�ɾ����" << endl;
			} else {
				cout << "ȡ��ɾ���û� \"" << username << "\"��" << endl;
			}
			return;
		}
	}
	cout << "δ�ҵ��û���Ϊ \"" << username << "\" ���û���" << endl;
}

//users�����а� 
vector<User>& UserManager::getUsers(){
    return users;
}



