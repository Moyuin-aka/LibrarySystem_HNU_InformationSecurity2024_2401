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

//重置用户密码
void UserManager::resetPassword(const string &username, const string &newPassword) {
	for (auto &user : users) {
		if (user.username == username) {
			user.password = newPassword;
			cout << "密码已成功重置！" << endl;
			return;
		}
	}
	cout << "未找到用户名为 \"" << username << "\" 的用户。" << endl;
}

//删除用户
void UserManager::deleteUser(const string &username) {
	for (auto it = users.begin(); it != users.end(); ++it) {
		if (it->username == username) {
			if (it->role == 1) {
				cout << "无法删除管理员用户 \"" << username << "\"！" << endl;
				return;
			}
			cout<<"请注意!删除后无法恢复,你确定删除吗?(y/n)"<<endl;
			char checkOutDelete;
			cin>>checkOutDelete;
			if(checkOutDelete == 'y') {
				users.erase(it);
				cout << "用户 \"" << username << "\" 已成功删除！" << endl;
			} else {
				cout << "取消删除用户 \"" << username << "\"！" << endl;
			}
			return;
		}
	}
	cout << "未找到用户名为 \"" << username << "\" 的用户。" << endl;
}

//users给排行榜 
vector<User>& UserManager::getUsers(){
    return users;
}



