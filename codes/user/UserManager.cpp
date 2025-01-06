#include "UserManager.h"
#include <iostream>
#include <fstream>
#include <sstream> 
using namespace std;

// 构造函数
UserManager::UserManager() {}

// 加载用户数据
void UserManager::loadUsers(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "无法打开用户数据文件：" << filename << endl;
        return;
    }

    users.clear();
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string username, password;
        int role, borrowCount;
        getline(iss, username, '|');
        getline(iss, password, '|');
        iss >> role;
        iss.ignore();
        iss >> borrowCount; // 加载借阅次数
        users.emplace_back(username, password, role);
        users.back().UserBorrow = borrowCount;
    }
    file.close();
}


// 保存用户数据
void UserManager::saveUsers(const string &filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "无法保存用户数据到文件：" << filename << endl;
        return;
    }

    for (const auto &user : users) {
        file << user.username << "|"
             << user.password << "|"
             << user.role << "|"
             << user.UserBorrow << endl; // 保存借阅次数
    }
    file.close();
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

// 查找用户
User* UserManager::findUser(const string &username) {
    for (auto &user : users) {
        if (user.username == username) {
            return &user;
        }
    }
    return nullptr;
}


// 重置用户密码
void UserManager::resetPassword(const string &username) {
    User* user = findUser(username);
    if (user) {
        user->password = "123456"; // 重置为默认密码
        user->needsPasswordReset = true; // 标记为需要重置密码
        cout << "用户 " << username << " 的密码已重置为默认密码（123456）。" << endl;
    } else {
        cout << "用户 " << username << " 不存在！" << endl;
    }
}

// 登录验证
bool UserManager::validateLogin(const string &username, const string &password) {
    User* user = findUser(username);
    if (user && user->password == password) {
        return true;
    }
    return false;
}

// 检查是否需要重置密码
bool UserManager::needsPasswordReset(const string &username) {
    User* user = findUser(username);
    if (user) {
        return user->needsPasswordReset;
    }
    return false;
}

// 更新用户密码
void UserManager::updatePassword(const string &username, const string &newPassword) {
    User* user = findUser(username);
    if (user) {
        user->password = newPassword;
        user->needsPasswordReset = false; // 更新密码后取消重置标记
        cout << "用户 " << username << " 的密码已成功更新！" << endl;
    }
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

//增加用户借阅次数
void UserManager::incrementUserBorrow(const string &username) {
    for (auto &user : users) {
        if (user.username == username) {
            user.UserBorrow++; 
            return;
        }
    }
    cout << "警告：未找到用户 \"" << username << "\"，无法更新借阅次数。" << endl;
}

//users给排行榜 
vector<User>& UserManager::getUsers(){
    return users;
}



