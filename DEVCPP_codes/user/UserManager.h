#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include <string>
#include "User.h"

using namespace std;

class UserManager {
private:
    vector<User> users; // 用户列表

public:
    UserManager();                       // 构造函数
    void loadUsers(const string &file);  // 加载用户数据
    void saveUsers(const string &file);  // 保存用户数据
    int login(const string &username, const string &password); // 登录方法
    void registerUser(const string &username, const string &password, int role); // 注册用户
    void displayUsers();                 // 显示所有用户
    
    User* findUser(const string &username); // 查找用户
    bool needsPasswordReset(const string &username); // 检查是否需要重置密码
    void resetPassword(const string &username); //重置用户密码 
    void updatePassword(const string &username, const string &newPassword); // 更新密码
    bool validateLogin(const string &username, const string &password); // 登录验证
    
	void deleteUser(const string &username);//删除用户  
	void incrementUserBorrow(const string &username); // 增加用户借阅次数
	vector<User>& getUsers(); // 返回 user 的引用 
};

#endif
