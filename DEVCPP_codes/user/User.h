#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
public:
    string username;
    string password;
    int role; // 1: ����Ա, 2: ����
    int UserBorrow;//�û����Ĵ��� 
     bool needsPasswordReset; // �Ƿ���Ҫ��������

    User(string u, string p, int r);
    void display() const;
};

#endif

