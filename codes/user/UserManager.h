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
};

#endif

