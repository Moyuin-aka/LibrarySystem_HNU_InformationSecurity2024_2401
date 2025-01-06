#ifndef CHARTS_H
#define CHARTS_H

#include "../book/BookManager.h"
#include "../user/UserManager.h"
#include <vector>
#include <string>
using namespace std;

class Charts {
private:
    BookManager &bookManager; // ����ͼ�������
    UserManager &userManager; // �����û�������

public:
    Charts(BookManager &bm, UserManager &um); // ���캯��

    void displayTopBooks();   // �������а�ǰʮ
    void displayTopReaders(); // ʮ�Ѷ������а�
};

#endif

