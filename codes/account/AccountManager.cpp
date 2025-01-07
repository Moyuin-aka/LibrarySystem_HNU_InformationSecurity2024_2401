#include "AccountManager.h"
#include <iostream>
#include <fstream>
using namespace std;

// ���캯��
AccountManager::AccountManager(UserManager &um) : userManager(um),adminSecondaryPassword("") {
loadSecondaryPassword("admin_password.txt"); // ����ʱ�Զ����ض��������ļ�}
}

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
        cout << "���������ļ�δ�ҵ���ϵͳ���������С���ȷ���ڹ���Ա�˵��г�ʼ���������룡" << endl; // // �ṩһ����ȫ��ʾ������ѡ����Ի��ʼ������
        return;
    }

    string loadedPassword;
    getline(file, loadedPassword); // ���ļ���ȡ����
    if (!loadedPassword.empty()) {
        adminSecondaryPassword = loadedPassword;
    }
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

// ����Ա�鿴���й黹��¼
void AccountManager::viewAllReturnHistoryPaged() const {
        ifstream inFile("return_history.txt");
    if (!inFile.is_open()) {
        cout << "�޷��򿪹黹��¼�ļ���" << endl;
        return;
    }
    string line;
    string currentUser;
    vector<string> returnedBooks; // �洢��ǰ�û��Ĺ黹�鼮
    map<string, vector<string>> userHistory; // �洢�����û��Ĺ黹��¼
    while (getline(inFile, line)) {
        if (line.rfind("�û�: ", 0) == 0) { // ������Ƿ��� "�û�: " ��ͷ
            if (!currentUser.empty() && !returnedBooks.empty()) {// �����ǰ���Ѽ�¼���û�����洢��黹��¼
                userHistory[currentUser] = returnedBooks;
                returnedBooks.clear(); 
            }
            // ��ȡ�û���
            size_t startPos = line.find("�û�: ") + 4;
            size_t endPos = line.find(" �Ĺ黹��¼:");
            currentUser = line.substr(startPos, endPos - startPos);
        }
        else if (line.rfind("- ", 0) == 0) {
            string bookTitle = line.substr(2); // ȥ�� "- " ǰ׺
            returnedBooks.push_back(bookTitle);
        }
        else if (line.rfind("=============================", 0) == 0) {// ������Ƿ��� "=============================" ��ͷ
            if (!currentUser.empty() && !returnedBooks.empty()) {
                userHistory[currentUser] = returnedBooks;
                returnedBooks.clear(); // ��ռ�¼��׼����һλ�û�
            }
        }
    }
    if (!currentUser.empty() && !returnedBooks.empty()) { // �������һ���û�����Ϊ�ļ�ĩβû�зָ�����
        userHistory[currentUser] = returnedBooks;
    }

    // ��ʾ�����û��Ĺ黹��¼
    for (const auto &entry : userHistory) {
        cout << "�û�: " << entry.first << " �Ĺ黹��¼:" << endl;
        for (const auto &book : entry.second) {
            cout << "- " << book << endl;
        }
        cout << "�ܼƹ黹: " << entry.second.size() << " ��ͼ�顣" << endl;
        cout << "=============================" << endl;
    }

    inFile.close();
}


//��ȡ��ǰ��¼�û�
string AccountManager::getCurrentUser() const {
	return currentUser;
}

//�ṩusermanager�����а�
UserManager& AccountManager::getUserManager() {
	return userManager;
}




