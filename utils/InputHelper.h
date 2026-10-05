#include <iostream>
#include <string>

using namespace std;

#ifndef INPUT_HELPER_H
#define INPUT_HELPER_H

class InputHelper {
public:
    // Nhap 1 chuoi khong duoc de trong
    static string getString(string prompt) {//Phuong thuc tinh -> ko can khoi tao doi tuong-> do ruom ra
        string val;
        while (true) {
            cout << prompt;
            getline(cin, val);
            if (!val.empty()) {
                return val;
            }
            cout << "[Loi] Du lieu khong duoc de trong! Vui long nhap lai.\n";
        }
    }

    // Nhap so nguyen an toan (chong nhap chu bi lap vo han)
    static int getInt(string prompt) {
        int val;
        while (true) {
            cout << prompt;
            if (cin >> val) {
                cin.ignore(1000, '\n');
                return val;
            }
            cout << "[Loi] Phai nhap so nguyen hop le! Vui long nhap lai.\n";
            cin.clear();
            cin.ignore(1000, '\n');   
        }
    }

    // Nhap so thuc an toan (dung cho toa do, gia cuoc, chieu cao anten...)
    static double getDouble(string prompt) {
        double val;
        while (true) {
            cout << prompt;
            if (cin >> val) {
                cin.ignore(1000, '\n');
                return val;
            }
            cout << "[Loi] Phai nhap so thuc hop le! Vui long nhap lai.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    // Xac nhan thao tac Co/Khong (phuc vu chuc nang Xoa: y/n theo de bai)
    static bool confirm(string prompt) {
        string ans;
        while (true) {
            cout << prompt << " (y/n): ";
            getline(cin, ans);
            if (ans == "y" || ans == "Y") return true;
            if (ans == "n" || ans == "N") return false;
            cout << "[Loi] Chi nhap 'y' (dong y) hoac 'n' (huy)!\n";
        }
    }
};

#endif // INPUT_HELPER_H