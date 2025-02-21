#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include "../user/UserManager.h"
#include <string>
#include <map>
using namespace std;

class AccountManager {
	private:
		UserManager &userManager; // ���� UserManager
		string currentUser;       // �洢��ǰ��¼�û����û���
		string adminSecondaryPassword; // �洢����Ա��������

	public:
		AccountManager(UserManager &um); // ���캯�������� UserManager
		int login();                    // ��¼����
		void registerAccount();         // ע�Ṧ��

		void setSecondaryPassword(const std::string &password);//���ù���Ա��������,��������һ��
		bool verifySecondaryPassword(const std::string &password) const;// ��֤��������
		void loadSecondaryPassword(const std::string &filename);//�����������
		void saveSecondaryPassword(const std::string &filename) const;//���ض�������

		void displayAllUsers();                            // �鿴�����û�
		void resetPassword(const string &username);        // �����û�����
		void deleteUser(const string &username);           // ɾ����ͨ�û�
		string getCurrentUser() const;   // ��ȡ��ǰ��¼�û�

		void viewAllReturnHistoryPaged() const ; // ����Ա�鿴���м�¼


		UserManager& getUserManager(); // ���� UserManager ������
};

#endif

