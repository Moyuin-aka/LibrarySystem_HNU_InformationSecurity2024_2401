#include "User.h"
#include <iostream>
using namespace std;

// ���캯��
User::User(string u, string p, int r) : username(u), password(p), role(r) ,UserBorrow(0) {}

// ��ʾ�û���Ϣ
void User::display() const {
	cout << "�˻�: " << username << ", ��ɫ: " << (role == 1 ? "����Ա" : "����") << " ,���Ĵ���: " << UserBorrow << endl;
}

