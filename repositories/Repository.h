#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../utils/InputHelper.h"

using namespace std;

template <class T>
class Repository {
    private:
       vector<T> items;
        string filePath;
    public:
    // Constructor: Nhan duong dan file va tu dong doc du lieu len vector
        Repository(string path) : filePath(path) {
            loadFromFile();
        }
    // Destructor: Tu dong luu du lieu xuong file khi ket thuc chuong trinh
        ~Repository() {
            saveToFile();
        }
    // 1. Doc file bang ifstream
    void loadFromFile() {
        items.clear();
        ifstream file(filePath);
        if (!file.is_open()) return;

        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                T item;
                item.fromFileString(line);
                items.push_back(item);
            }
        }
        file.close();
    }

    // 2. Ghi toan bo danh sach vao file bang ofstream
    void saveToFile() {
        ofstream file(filePath);
        if (!file.is_open()) {
            cout << "[Loi] Khong the mo file de ghi: " << filePath << "\n";
            return;
        }
        for (size_t i = 0; i < items.size(); ++i) {
            file << items[i].toFileString() << "\n";
        }
        file.close();
    }

    // 3. Tim vi tri (index) theo ID (tra ve -1 neu khong tim thay)
    int findIndexById(const string& id) {
        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i].getId() == id) {
                return (int)i;
            }
        }
        return -1;
    }

    // 4. Them moi (kiem tra trung khoa chinh ID)
    void add() {
        T item;
        while (true) {
            item.input(false);
            if (findIndexById(item.getId()) != -1) {
                cout << "[Loi] Ma '" << item.getId() << "' da ton tai tren he thong! Vui long nhap lai.\n";
            } else {
                break;
            }
        }
        items.push_back(item);
        saveToFile();
        cout << ">> Them moi thanh cong!\n";
    }

    // 5. Hien thi toan bo danh sach
    void displayAll() {
        if (items.empty()) {
            cout << ">> Danh sach hien dang trong!\n";
            return;
        }
        cout << string(70, '-') << "\n";
        for (size_t i = 0; i < items.size(); ++i) {
            items[i].display();
        }
        cout << string(70, '-') << "\n";
        cout << "Tong so ban ghi: " << items.size() << "\n";
    }

    // 6. Cap nhat thong tin theo ID
    void update() {
        string id = InputHelper::getString("Nhap ma can cap nhat: ");
        int idx = findIndexById(id);
        if (idx == -1) {
            cout << "[Loi] Khong tim thay ma: " << id << "\n";
            return;
        }
        cout << "--- Nhap thong tin moi (Nhan Enter neu muon giu nguyen) ---\n";
        items[idx].input(true);
        saveToFile();
        cout << ">> Cap nhat thanh cong!\n";
    }

    // 7. Xoa ban ghi theo ID (co xac nhan y/n)
    void remove() {
        string id = InputHelper::getString("Nhap ma can xoa: ");
        int idx = findIndexById(id);
        if (idx == -1) {
            cout << "[Loi] Khong tim thay ma: " << id << "\n";
            return;
        }
        if (InputHelper::confirm("Ban co chac chan muon xoa ban ghi nay?")) {
            items.erase(items.begin() + idx);
            saveToFile();
            cout << ">> Xoa thanh cong!\n";
        } else {
            cout << ">> Da huy thao tac xoa.\n";
        }
    }

    // Getter lay vector neu can xu ly logic ben ngoai
    vector<T>& getAll() {
        return items;
    }
};
#endif // REPOSITORY_H