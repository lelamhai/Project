#include "LoginData.h"
#include "LoadingData.h"

Student* logIn(PTRSTUDENT stdList1) {
    char user[15];
    char password[30];
    bool isUserCorrect;

    while (true) {
        isUserCorrect = false;
        cout << "Nhap tai khoan dang nhap: ";
        cin >> user;
        cout << "Nhap mat khau: ";
        cin >> password;

        if (strcmp(user, "GV") == 0) {
            if (strcmp(password, "GV") == 0) {
                cout << "Dang nhap thanh cong tai khoan Giao Vien" << endl;
                return NULL;
            }
            else {
                cout << "Mat khau khong dung, vui long nhap lai" << endl;
            }
        }

        else {
            for (PTRSTUDENT p = stdList1; p != NULL; p = p->next) {
                if (strcmp(user, p->info.studentCode) == 0) {
                    isUserCorrect = true;
                    if (strcmp(password, p->info.password) == 0) {
                        cout << "Dang nhap thanh cong!" << endl;
                        return &(p->info);
                    }
                    else {
                        cout << "Mat khau khong dung, vui long nhap lai" << endl;
                    }
                }
            }

            if (!isUserCorrect) {
                cout << "Tai khoan khong ton tai, vui long thu lai" << endl;
            }
        }
    }
}