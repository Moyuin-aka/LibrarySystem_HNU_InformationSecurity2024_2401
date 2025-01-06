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
        currentUser = username; // 更新当前用户
    } else if (role == 2) {
        cout << "欢迎读者登录！" << endl;
        currentUser = username; // 更新当前用户
    } else {
        cout << "登录失败，请检查用户名和密码！" << endl;
        currentUser = ""; // 清空当前用户
    }
    return role;
}

/*int AccountManager::login() {
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
}*/

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

// 查看所有用户
void AccountManager::displayAllUsers() {
    cout << "===== 当前所有用户列表 =====" << endl;
    userManager.displayUsers(); // 调用 UserManager 的显示方法
}

//重置用户密码
void AccountManager::resetPassword(const string &username) {
    string newPassword;
    cout << "请输入用户 \"" << username << "\" 的新密码：";
    cin >> newPassword;
    userManager.resetPassword(username, newPassword); // 调用 UserManager 方法
}

//删除普通用户
void AccountManager::deleteUser(const string &username) {
    userManager.deleteUser(username); // 调用 UserManager 方法
}

//获取当前登录用户 
string AccountManager::getCurrentUser() const {
    return currentUser;
}

//提供usermanager给排行榜 
UserManager& AccountManager::getUserManager() {
    return userManager;
}




