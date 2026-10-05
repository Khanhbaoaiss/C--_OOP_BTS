#include <iostream>
#include "menus/NhaCungCapMenu.h"
#include "utils/InputHelper.h"

using namespace std;

int main() {
    while (true) {
        cout << "\n========================================\n";
        cout << "      HE THONG QUAN LY TRAM BTS         \n";
        cout << "========================================\n";
        cout << "1. Quan ly Nha Cung Cap\n";
        cout << "2. Quan ly Tram BTS (sap co)\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "----------------------------------------\n";

        int choice = InputHelper::getInt("Nhap lua chon cua ban: ");

        switch (choice) {
            case 1:
                NhaCungCapMenu::show(); // Chuyển sang giao diện của Nhà cung cấp
                break;
            case 2:
                cout << ">> Tinh nang dang duoc thanh vien khac phat trien...\n";
                break;
            case 0:
                cout << ">> Tam biet!\n";
                return 0;
            default:
                cout << "[Loi] Lua chon khong hop le!\n";
                break;
        }
    }
    return 0;
}