#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include "../user/UserManager.h"
#include <string>
#include <map>
using namespace std;

class AccountManager {
	private:
		UserManager &userManager; // 引用 UserManager
		string currentUser;       // 存储当前登录用户的用户名
		string adminSecondaryPassword; // 存储管理员二级密码

	public:
		AccountManager(UserManager &um); // 构造函数，传入 UserManager
		int login();                    // 登录功能
		void registerAccount();         // 注册功能

		void setSecondaryPassword(const std::string &password);//设置管理员二级密码,仅能设置一次
		bool verifySecondaryPassword(const std::string &password) const;// 验证二级密码
		void loadSecondaryPassword(const std::string &filename);//保存二级密码
		void saveSecondaryPassword(const std::string &filename) const;//加载二级密码

		void displayAllUsers();                            // 查看所有用户
		void resetPassword(const string &username);        // 重置用户密码
		void deleteUser(const string &username);           // 删除普通用户
		string getCurrentUser() const;   // 获取当前登录用户

		void viewAllReturnHistoryPaged() const ; // 管理员查看所有记录


		UserManager& getUserManager(); // 返回 UserManager 的引用
};

#endif

