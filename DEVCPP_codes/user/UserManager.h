#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include <string>
#include "User.h"

using namespace std;

class UserManager {
private:
    vector<User> users; // �û��б�

public:
    UserManager();                       // ���캯��
    void loadUsers(const string &file);  // �����û�����
    void saveUsers(const string &file);  // �����û�����
    int login(const string &username, const string &password); // ��¼����
    void registerUser(const string &username, const string &password, int role); // ע���û�
    void displayUsers();                 // ��ʾ�����û�
    
    User* findUser(const string &username); // �����û�
    bool needsPasswordReset(const string &username); // ����Ƿ���Ҫ��������
    void resetPassword(const string &username); //�����û����� 
    void updatePassword(const string &username, const string &newPassword); // ��������
    bool validateLogin(const string &username, const string &password); // ��¼��֤
    
	void deleteUser(const string &username);//ɾ���û�  
	void incrementUserBorrow(const string &username); // �����û����Ĵ���
	vector<User>& getUsers(); // ���� user ������ 
};

#endif
