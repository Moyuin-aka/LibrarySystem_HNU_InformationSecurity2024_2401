#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include <string>
#include "User.h"

using namespace std;

class UserManager {
private:
    vector<User> users; // 用户列表

public:
    UserManager();                       // 构造函数
    void loadUsers(const string &file);  // 加载用户数据
    void saveUsers(const string &file);  // 保存用户数据
    int login(const string &username, const string &password); // 登录方法
    void registerUser(const string &username, const string &password, int role); // 注册用户
    void displayUsers();                 // 显示所有用户
};

#endif

