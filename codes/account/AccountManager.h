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
};

#endif

