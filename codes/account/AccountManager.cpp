#include "AccountManager.h"
#include <iostream>
using namespace std;

// 构造函数
AccountManager::AccountManager(UserManager &um) : userManager(um) {}

// 登录功能
int AccountManager::login() {
    string username, password;
    cout << "请输入用户名：";
    cin >> username;
    cout << "请输入密码：";
    cin >> password;

    int role = userManager.login(username, password);
    if (role == 1) {
        cout << "欢迎管理员登录！" << endl;
    } else if (role == 2) {
        cout << "欢迎读者登录！" << endl;
    } else {
        cout << "登录失败，请检查用户名和密码！" << endl;
    }
    return role;
}

// 注册功能
void AccountManager::registerAccount() {
    string username, password;
    cout << "请输入新用户名：";
    cin >> username;
    cout << "请输入新密码：";
    cin >> password;

    userManager.registerUser(username, password, 2); // 默认注册为读者
    cout << "注册成功！" << endl;
}

