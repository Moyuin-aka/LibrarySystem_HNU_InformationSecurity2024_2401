#include "AccountManager.h"
#include <iostream>
#include <fstream>
using namespace std;

// 构造函数
AccountManager::AccountManager(UserManager &um) : userManager(um),adminSecondaryPassword("") {
loadSecondaryPassword("admin_password.txt"); // 构造时自动加载二级密码文件}
}

// 登录功能
int AccountManager::login() {
	string username, password;
	cout << "请输入用户名：";
	cin >> username;
	cout << "请输入密码：";
	cin >> password;

	int role = userManager.login(username, password);
	if (role == 1) {
		cout << "欢迎管理员登录！" << endl;
		currentUser = username; // 更新当前用户
	} else if (role == 2) {
		cout << "欢迎读者登录！" << endl;
		currentUser = username; // 更新当前用户
	} else {
		cout << "登录失败，请检查用户名和密码！" << endl;
		currentUser = ""; // 清空当前用户
	}
	return role;
}

// 设置二级密码（仅可设置一次）
void AccountManager::setSecondaryPassword(const string &password) {
    if (!adminSecondaryPassword.empty()) {
        cout << "二级密码已设置，无法再次修改！" << endl;
        return;
    }
    adminSecondaryPassword = password;
    cout << "二级密码设置成功！请妥善保存您的密码！" << endl;
}

// 验证二级密码
bool AccountManager::verifySecondaryPassword(const std::string &password) const {
	if (adminSecondaryPassword.empty()) {
		cout << "尚未设置二级密码，请先设置！" << endl;
		return false;
	}
	return adminSecondaryPassword == password;
}

// 保存二级密码到文件
void AccountManager::saveSecondaryPassword(const string &filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "无法保存二级密码到文件：" << filename << endl;
        return;
    }

    file << adminSecondaryPassword << endl;
    file.close();
}

// 从文件加载二级密码
void AccountManager::loadSecondaryPassword(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "无法加载二级密码文件：" << filename << endl;
        cout << "二级密码文件未找到，系统将继续运行。请确保在管理员菜单中初始化二级密码！" << endl; // // 提供一个安全提示，可以选择忽略或初始化密码
        return;
    }

    string loadedPassword;
    getline(file, loadedPassword); // 从文件读取密码
    if (!loadedPassword.empty()) {
        adminSecondaryPassword = loadedPassword;
    }
    file.close();
}


// 注册功能
void AccountManager::registerAccount() {
	string username, password;
	cout << "请输入新用户名：";
	cin >> username;
	cout << "请输入新密码：";
	cin >> password;

	userManager.registerUser(username, password, 2); // 默认注册为读者
	cout << "注册成功！" << endl;
}

// 查看所有用户
void AccountManager::displayAllUsers() {
	cout << "===== 当前所有用户列表 =====" << endl;
	userManager.displayUsers(); // 调用 UserManager 的显示方法
}

//重置用户密码
void AccountManager::resetPassword(const string &username) {
	userManager.resetPassword(username); // 调用 UserManager 方法
}

//删除普通用户
void AccountManager::deleteUser(const string &username) {
	 string password;
    cout << "请输入二级密码以继续操作：";
    cin >> password;

    if (!verifySecondaryPassword(password)) {
        cout << "二级密码验证失败，操作已取消！" << endl;
        return;
    }
	userManager.deleteUser(username); // 调用 UserManager 方法
}

// 管理员查看所有归还记录
void AccountManager::viewAllReturnHistoryPaged() const {
        ifstream inFile("return_history.txt");
    if (!inFile.is_open()) {
        cout << "无法打开归还记录文件！" << endl;
        return;
    }
    string line;
    string currentUser;
    vector<string> returnedBooks; // 存储当前用户的归还书籍
    map<string, vector<string>> userHistory; // 存储所有用户的归还记录
    while (getline(inFile, line)) {
        if (line.rfind("用户: ", 0) == 0) { // 检查行是否以 "用户: " 开头
            if (!currentUser.empty() && !returnedBooks.empty()) {// 如果当前有已记录的用户，则存储其归还记录
                userHistory[currentUser] = returnedBooks;
                returnedBooks.clear(); 
            }
            // 提取用户名
            size_t startPos = line.find("用户: ") + 4;
            size_t endPos = line.find(" 的归还记录:");
            currentUser = line.substr(startPos, endPos - startPos);
        }
        else if (line.rfind("- ", 0) == 0) {
            string bookTitle = line.substr(2); // 去掉 "- " 前缀
            returnedBooks.push_back(bookTitle);
        }
        else if (line.rfind("=============================", 0) == 0) {// 检查行是否以 "=============================" 开头
            if (!currentUser.empty() && !returnedBooks.empty()) {
                userHistory[currentUser] = returnedBooks;
                returnedBooks.clear(); // 清空记录，准备下一位用户
            }
        }
    }
    if (!currentUser.empty() && !returnedBooks.empty()) { // 处理最后一个用户（因为文件末尾没有分隔符）
        userHistory[currentUser] = returnedBooks;
    }

    // 显示所有用户的归还记录
    for (const auto &entry : userHistory) {
        cout << "用户: " << entry.first << " 的归还记录:" << endl;
        for (const auto &book : entry.second) {
            cout << "- " << book << endl;
        }
        cout << "总计归还: " << entry.second.size() << " 本图书。" << endl;
        cout << "=============================" << endl;
    }

    inFile.close();
}


//获取当前登录用户
string AccountManager::getCurrentUser() const {
	return currentUser;
}

//提供usermanager给排行榜
UserManager& AccountManager::getUserManager() {
	return userManager;
}




