#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include "../user/UserManager.h"
#include <string>
using namespace std;

class AccountManager {
	private:
		UserManager &userManager; // ���� UserManager

	public:
		AccountManager(UserManager &um); // ���캯�������� UserManager
		int login();                    // ��¼����
		void registerAccount();         // ע�Ṧ��
		void displayAllUsers();                            // �鿴�����û�
		void resetPassword(const string &username);        // �����û�����
		void deleteUser(const string &username);           // ɾ����ͨ�û�

};

#endif

