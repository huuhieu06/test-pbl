#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <sstream>

using namespace std;

struct Xe {
    string bienSo;
    string loaiXe;
    time_t thoiGianVao;
    time_t thoiGianRa;
    bool dangTrongBai;
};
vector<Xe> danhSachXe;

void luuVaoFile() {
    ofstream file("danh_sach_xe.txt");
    for (auto &xe : danhSachXe) {
        file << xe.bienSo << " " << xe.loaiXe << " " << xe.thoiGianVao << " " << xe.thoiGianRa << " " << xe.dangTrongBai << endl;
    }
    file.close();
}
void docTuFile() {
    ifstream file("danh_sach_xe.txt");
    danhSachXe.clear();
    Xe xe;
    while (file >> ws, getline(file, xe.bienSo), file >> xe.loaiXe >> xe.thoiGianVao >> xe.thoiGianRa >> xe.dangTrongBai) {
        danhSachXe.push_back(xe);
    }
    file.close();
}

void themXe() {
    Xe xe;
    cin.ignore();
    cout << "Nhập biển số xe: "; getline(cin, xe.bienSo);
    cout << "Nhập loại xe: "; cin >> xe.loaiXe;
    xe.thoiGianVao = time(nullptr);
    xe.dangTrongBai = true;
    xe.thoiGianRa = 0;
    danhSachXe.push_back(xe);
    luuVaoFile();
    cout << "Thêm xe thành công!\n";
}

void xeRa() {
    string bienSo;
    cin.ignore();
    cout << "Nhập biển số xe rời đi: "; getline(cin, bienSo);
    for (auto &xe : danhSachXe) {
        if (xe.bienSo == bienSo && xe.dangTrongBai) {
            xe.thoiGianRa = time(nullptr);
            xe.dangTrongBai = false;
            luuVaoFile();
            cout << "Xe đã rời bãi thành công!\n";
            return;
        }
    }
    cout << "Không tìm thấy xe hoặc xe đã rời bãi!\n";
}

void hienThiXe() {
    cout << "+---------------+---------------+---------------------+---------------------+------------+\n";
    cout << "| Biển số       | Loại xe       | Thời gian vào       | Thời gian ra        | Trong bãi  |\n";
    cout << "+---------------+---------------+---------------------+---------------------+------------+\n";
    
    for (auto &xe : danhSachXe) {
        stringstream ss;
        if (xe.thoiGianRa) {
            ss << put_time(localtime(&xe.thoiGianRa), "%Y-%m-%d %H:%M:%S");
        } else {
            ss << "-";
        }
        
        cout << "| " << left << setw(14) << xe.bienSo
             << "| " << setw(14) << xe.loaiXe
             << "| " << setw(20) << put_time(localtime(&xe.thoiGianVao), "%Y-%m-%d %H:%M:%S")
             << "| " << setw(20) << ss.str()
             << "| " << setw(10) << (xe.dangTrongBai ? "Có" : "Không") << "|\n";
    }
    
    cout << "+---------------+---------------+---------------------+---------------------+------------+\n";
}

int main() {
    docTuFile();
    int luaChon;
    while (true) {
        cout << "\n1. Thêm xe\n2. Xe rời bãi\n3. Hiển thị danh sách xe\n4. Thoát chương trình\nChọn một tùy chọn: ";
        cin >> luaChon;
        switch (luaChon) {
            case 1: themXe(); break;
            case 2: xeRa(); break;
            case 3: hienThiXe(); break;
            case 4: return 0;
            default: cout << "Tùy chọn không hợp lệ!\n";
        }
    }
}
