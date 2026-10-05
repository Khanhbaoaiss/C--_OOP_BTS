#ifndef ENTITIES_H
#define ENTITIES_H 

#include <iostream>
#include <string>
using namespace std;
//Day la base class hay lop truu tuong
class Entity{
    protected:
        string id;
    public:
        Entity(){}//Constructor
        Entity(string id){
            this -> id = id;//Constructor dung tham so trung voi thuoc tinh thi gan con tro this
        }
        virtual ~Entity(){}//Ham huy tranh ro ri bo nho khi cap phat dong bo nho Heap
        string getId(){//ham getter lay ve thuoc tinh id
            return id;
        }
        void setId(string id){
            this->id=id;
        }
        //Cac ham bat buoc lop con phai tu viet
        //Vi la lop truu tuong nen se chua cac phuong thuc thuan ao va ta khong the khoi tao doi tuong tu lop nay
        //Cac ham con se ghi de len phuong thuc thuan ao
        virtual void input(bool isUpdating = false)=0;//Ham nhap du lieu neu false la dang them moi true la dang sua du lieu
        virtual void display()=0;//Ham lay du lieu ben trong doi tuong in ra man hinh 
        virtual string toFileString() =0;//Ham dong goi du lieu tu gom cac thuoc tinh thanh 1 chuoi
        virtual void fromFileString(string line)=0;//Chuoi chua 1 dong van ban doc duoc tu file    
};
#endif