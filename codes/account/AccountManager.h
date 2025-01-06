#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include "../user/UserManager.h"
#include <string>
using namespace std;

class AccountManager {
	private:
		UserManager &userManager; // ���� UserManager
		string currentUser;       // �洢��ǰ��¼�û����û���

	public:
		AccountManager(UserManager &um); // ���캯�������� UserManager
		int login();                    // ��¼����
		void registerAccount();         // ע�Ṧ��
		void displayAllUsers();                            // �鿴�����û�
		void resetPassword(const string &username);        // �����û�����
		void deleteUser(const string &username);           // ɾ����ͨ�û�
		string getCurrentUser() const;   // ��ȡ��ǰ��¼�û�
		UserManager& getUserManager(); // ���� UserManager ������
};

#endif

