#include "User.h"
#include <iostream>
using namespace std;

// ���캯��
User::User(string u, string p, int r) : username(u), password(p), role(r) {}

// ��ʾ�û���Ϣ
void User::display() const {
    cout << "�˻�: " << username << ", ��ɫ: " << (role == 1 ? "����Ա" : "����") << endl;
}

