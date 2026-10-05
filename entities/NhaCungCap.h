#ifndef NHACUNGCAP_H
#define NHACUNGCAP_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "Entities.h"
#include "../utils/InputHelper.h"
using namespace std;

class NhaCungCap : public Entity{//Lop ke thua tu lop Entity
    private:
        string tenNCC;
        string quocGia;
        string soDienThoai;
    public:
        NhaCungCap(){}
        NhaCungCap(string id, string tenNCC,string quocGia,string soDienThoai){
            this->id = id;    
            this->tenNCC=tenNCC;
            this->quocGia=quocGia;
            this->soDienThoai=soDienThoai;
        }
    //Getter va Setter
        string getTenNCC(){
            return tenNCC;
        }
        void setTenNCC(string tenNCC){
            this->tenNCC=tenNCC;
        }
        string getQuocGia(){
            return quocGia; 
        }
        void setQuocGia(string quocGia) { 
            this->quocGia = quocGia; 
        }
        string getSoDienThoai(){ 
            return soDienThoai; 
        }
        void setSoDienThoai(string soDienThoai){ 
            this->soDienThoai = soDienThoai; 
        }
    //Nhap thong tin tu ban phim
        void input(bool isUpdating = false){
        //Neu la them moi isUpdating = false ->bat buoc nhap ma dinh danh
            if (!isUpdating) {
                id = InputHelper::getString("Nhap ma nha cung cap (vd: NCC01): ");
            }
            cout << "Nhap ten nha cung cap" << (isUpdating ? " (bo trong de giu nguyen): " : ": ");
            string tempTen;
            getline(cin, tempTen);
            if (!isUpdating || !tempTen.empty()) {
                if (!tempTen.empty()) tenNCC = tempTen;
            }   
            cout << "Nhap quoc gia" << (isUpdating ? " (bo trong de giu nguyen): " : ": ");
            string tempQG;
            getline(cin, tempQG);
            if (!isUpdating || !tempQG.empty()) {
                if (!tempQG.empty()) quocGia = tempQG;
            }
            cout << "Nhap so dien thoai" << (isUpdating ? " (bo trong de giu nguyen): " : ": ");
            string tempSDT;
            getline(cin, tempSDT);
            if (!isUpdating || !tempSDT.empty()) {
                if (!tempSDT.empty()) soDienThoai = tempSDT;
            }
        }
    // In thong tin ra console dang can cot
        void display(){
            cout << left << "| " << setw(10) << id 
                << "| " << setw(25) << tenNCC 
                << "| " << setw(15) << quocGia 
                << "| " << setw(15) << soDienThoai << "|\n";
        }
    //Gom thuoc tinh de luu file
        string toFileString(){
            return id + "|" + tenNCC + "|" + quocGia + "|" + soDienThoai;
        }
    //Doc mot dong text tu file va gan vao thuoc tinh
        void fromFileString(string line){
            stringstream ss(line);
            getline(ss, id, '|');
            getline(ss, tenNCC, '|');
            getline(ss, quocGia, '|');
            getline(ss, soDienThoai, '|');
        }
};
#endif // NHACUNGCAP_H
