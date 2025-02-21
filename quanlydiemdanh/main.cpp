#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struct để lưu thông tin học sinh
struct HocSinh {
    string ten;
    bool diemDanh; // true: đã điểm danh, false: chưa điểm danh
};

// Hàm hiển thị menu
void hienThiMenu() {
    cout << "\n===== QUAN LY DIEM DANH =====" << endl;
    cout << "1. Them hoc sinh" << endl;
    cout << "2. Diem danh" << endl;
    cout << "3. Hien thi danh sach diem danh" << endl;
    cout << "4. Thoat" << endl;
    cout << "Lua chon cua ban: ";
}

// Hàm thêm học sinh vào danh sách
void themHocSinh(vector<HocSinh>& danhSach) {
    HocSinh hs;
    cout << "Nhap ten hoc sinh: ";
    cin.ignore();
    getline(cin, hs.ten);
    hs.diemDanh = false;
    danhSach.push_back(hs);
    cout << "Da them hoc sinh: " << hs.ten << endl;
}

// Hàm điểm danh học sinh
void diemDanh(vector<HocSinh>& danhSach) {
    cout << "\nNhap ten hoc sinh de diem danh: ";
    string ten;
    cin.ignore();
    getline(cin, ten);

    bool timThay = false;
    for (auto& hs : danhSach) {
        if (hs.ten == ten) {
            hs.diemDanh = true;
            cout << "Da diem danh cho hoc sinh: " << ten << endl;
            timThay = true;
            break;
        }
    }

    if (!timThay) {
        cout << "Khong tim thay hoc sinh: " << ten << endl;
    }
}

// Hàm hiển thị danh sách điểm danh
void hienThiDanhSach(const vector<HocSinh>& danhSach) {
    cout << "\nDanh sach diem danh:" << endl;
    cout << "===========================" << endl;
    for (const auto& hs : danhSach) {
        cout << "Ten: " << hs.ten << " - Trang thai: "
             << (hs.diemDanh ? "Co mat" : "Vang mat") << endl;
    }
}

int main() {
    vector<HocSinh> danhSach;
    int luaChon;

    do {
        hienThiMenu();
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                themHocSinh(danhSach);
                break;
            case 2:
                diemDanh(danhSach);
                break;
            case 3:
                hienThiDanhSach(danhSach);
                break;
            case 4:
                cout << "Thoat chuong trinh!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
        }
    } while (luaChon != 4);

    return 0;
}

