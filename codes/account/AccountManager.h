#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include "../user/UserManager.h"
#include <string>
using namespace std;

class AccountManager {
	private:
		UserManager &userManager; // 引用 UserManager
		string currentUser;       // 存储当前登录用户的用户名

	public:
		AccountManager(UserManager &um); // 构造函数，传入 UserManager
		int login();                    // 登录功能
		void registerAccount();         // 注册功能
		void displayAllUsers();                            // 查看所有用户
		void resetPassword(const string &username);        // 重置用户密码
		void deleteUser(const string &username);           // 删除普通用户
		string getCurrentUser() const;   // 获取当前登录用户
		UserManager& getUserManager(); // 返回 UserManager 的引用
};

#endif

