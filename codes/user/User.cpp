#include "User.h"
#include <iostream>
using namespace std;

// 构造函数
User::User(string u, string p, int r) : username(u), password(p), role(r) {}

// 显示用户信息
void User::display() const {
    cout << "账户: " << username << ", 角色: " << (role == 1 ? "管理员" : "读者") << endl;
}

