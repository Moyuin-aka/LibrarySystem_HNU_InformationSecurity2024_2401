#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
public:
    string username;
    string password;
    int role; // 1: 管理员, 2: 读者
    int UserBorrow;//用户借阅次数 
     bool needsPasswordReset; // 是否需要重置密码

    User(string u, string p, int r);
    void display() const;
};

#endif

