#ifndef NHACUNGCAPMENU_H
#define NHACUNGCAPMENU_H

#include <iostream>
#include "../entities/NhaCungCap.h"
#include "../repositories/Repository.h"
#include "../utils/InputHelper.h"

using namespace std;

class NhaCungCapMenu {
public:
    static void show() {
        // Khởi tạo Repository đọc/ghi dữ liệu từ file
        Repository<NhaCungCap> repoNCC("data/nha_cung_cap.txt");

        while (true) {
            cout << "\n========================================\n";
            cout << "       QUAN LY NHA CUNG CAP             \n";
            cout << "========================================\n";
            cout << "1. Hien thi danh sach nha cung cap\n";
            cout << "2. Them moi nha cung cap\n";
            cout << "3. Cap nhat thong tin nha cung cap\n";
            cout << "4. Xoa nha cung cap\n";
            cout << "0. Quay lai menu chinh\n";
            cout << "----------------------------------------\n";

            int choice = InputHelper::getInt("Nhap lua chon cua ban (0-4): ");

            switch (choice) {
                case 1:
                    cout << "\n--- DANH SACH NHA CUNG CAP ---\n";
                    repoNCC.displayAll();
                    break;
                case 2:
                    cout << "\n--- THEM NHA CUNG CAP MOI ---\n";
                    repoNCC.add();
                    break;
                case 3:
                    cout << "\n--- CAP NHAT NHA CUNG CAP ---\n";
                    repoNCC.update();
                    break;
                case 4:
                    cout << "\n--- XOA NHA CUNG CAP ---\n";
                    repoNCC.remove();
                    break;
                case 0:
                    cout << ">> Quay lai menu chinh...\n";
                    return; // Thoát khỏi hàm show(), quay về main
                default:
                    cout << "[Loi] Lua chon khong hop le!\n";
                    break;
            }
        }
    }
};

#endif // NHACUNGCAPMENU_H