#include "UserManager.h"
#include <iostream>
#include <fstream>
using namespace std;

// 构造函数
UserManager::UserManager() {}

// 加载用户数据
void UserManager::loadUsers(const string &file) {
    ifstream inFile(file);
    if (!inFile.is_open()) return;

    string username, password;
    int role;
    while (inFile >> username >> password >> role) {
        users.emplace_back(username, password, role);
    }
    inFile.close();
}

// 保存用户数据
void UserManager::saveUsers(const string &file) {
    ofstream outFile(file);
    for (const auto &user : users) {
        outFile << user.username << " " << user.password << " " << user.role << endl;
    }
    outFile.close();
}

// 登录方法
int UserManager::login(const string &username, const string &password) {
    for (const auto &user : users) {
        if (user.username == username && user.password == password) {
            return user.role; // 返回用户角色（1: 管理员, 2: 读者）
        }
    }
    return 0; // 登录失败
}

// 注册用户
void UserManager::registerUser(const string &username, const string &password, int role) {
    users.emplace_back(username, password, role);
}

// 显示所有用户
void UserManager::displayUsers() {
    for (const auto &user : users) {
        user.display();
    }
}

