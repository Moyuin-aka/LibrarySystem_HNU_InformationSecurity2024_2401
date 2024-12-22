#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include "../user/UserManager.h"
#include <string>
using namespace std;

class AccountManager {
private:
    UserManager &userManager; // 引用 UserManager

public:
    AccountManager(UserManager &um); // 构造函数，传入 UserManager
    int login();                    // 登录功能
    void registerAccount();         // 注册功能
};

#endif

