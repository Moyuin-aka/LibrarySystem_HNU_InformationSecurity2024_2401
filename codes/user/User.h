#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
public:
    string username;
    string password;
    int role; // 1: 管理员, 2: 读者

    User(string u, string p, int r);
    void display() const;
};

#endif

