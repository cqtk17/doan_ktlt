#include<iostream>
using namespace std;
#include<string>
#include<fstream>


// Sinh viên
struct sinhvien {
    int id;
    string hoTen;
    string gioiTinh;
    string ngaySinh;
    string idXaHoi;

    sinhvien(int _id,  string& _hoTen,  string& _gioiTinh,  string& _ngaySinh,  string& _idXaHoi)
        : id(_id), hoTen(_hoTen), gioiTinh(_gioiTinh), ngaySinh(_ngaySinh), idXaHoi(_idXaHoi) {}
    sinhvien() = default;
        void nhap() {
            cin.ignore();
            cout << "Nhap ho ten: ";
            getline(cin, hoTen);
            cout << "Gioi tinh: ";
            getline(cin, gioiTinh);
            cout << "Ngay sinh: ";
            getline(cin, ngaySinh);
            cout << "idxh: ";
            getline(cin, idXaHoi);
            cout << "Ma so: ";
            cin >> id;
            cin.ignore(); // Xóa bỏ ký tự newline sau khi nhập id
    }
        
};

struct Node {
    sinhvien data;
    Node* next;
};

struct list {
    Node* head;
    Node* tail;
};

void creatlist(list& l);
Node* creatnode(sinhvien& s);
void addnode(list& l, Node* node);

// bảng điểm
struct bangdiem {
    int id;
    string hoTen;
    float tk, ck, gk;
    bangdiem(int _id, string& _hoTen, float&_tk,float&_ck,float&_gk)
        : id(_id), hoTen(_hoTen), tk(_tk),ck(_ck),gk(_gk) {}
    bangdiem() = default;
    void nhapbangdiem(bangdiem& s) {
        cout << "Nhap id: ";
        cin >> s.id;
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, s.hoTen);
        cin.ignore();
        cout << "Nhap diem tong ket: ";
        cin >> s.tk;
        cout << "Nhap diem cuoi ki: ";
        cin >> s.ck;
        cout << "Nhap diem giua ki: ";
        cin >> s.gk;
    }
};
struct Nodebd {
    bangdiem data;
    Nodebd* next;
    Nodebd(bangdiem& s) : data(s), next(nullptr) {}
   
};

struct listbd {
    Nodebd* head;
    Nodebd* tail;
};
void creatlistbd(listbd& s);
Nodebd* creatnodebd(bangdiem& s);
void addnodebd(listbd& l, Nodebd* node);
// Khóa Học
struct KhoaHoc {
    int id;
    string tenKhoaHoc, tenGiaoVien, tenLop;
    int tinchi, slsv;
    string ngayHoc, buoiHoc;
    listbd dsd;
    list dshs;
    KhoaHoc(int& _id, string& _tenKhoaHoc, string& _tenLop, string& _tenGiaoVien, int _tinchi, int _slsv, string& _ngayHoc, string& _buoiHoc)
        : id(_id), tenKhoaHoc(_tenKhoaHoc), tenLop(_tenLop), tenGiaoVien(_tenGiaoVien), tinchi(_tinchi), slsv(_slsv), ngayHoc(_ngayHoc), buoiHoc(_buoiHoc) {
        creatlistbd(dsd);
        creatlist(dshs);
    }
    void themHocSinh(sinhvien& sv) {
        Node* v = creatnode(sv);
        addnode(dshs, v);
    }
    void themdiem(bangdiem& d) {
        Nodebd* v = creatnodebd(d);
        addnodebd(dsd, v);
    }
    KhoaHoc() = default;
    void nhapkh(KhoaHoc& s) {
        cout << "Nhap id: ";
        cin >> s.id;
        cin.ignore();
        cout << "Nhap ten Khoa hoc: \n";
        getline(cin, s.tenKhoaHoc);
        cin.ignore();
        cout << "Nhap ten lop: \n";
        cin >> s.tenLop;
        cin.ignore();
        cout << "Nhap ten giao vien: \n";
        getline(cin, s.tenGiaoVien);
        cin.ignore();
        cout << "Nhap so sinh vien toi da: \n";
        cin >> s.slsv;
        cout << "Nhap so tin chi: \n";
        cin >> s.tinchi;
        cout << "Nhap ngay hoc:\n";
        cin >> s.ngayHoc;
        cin.ignore();
        cout << "Nhap buoi hoc:\n";
        cin >> s.buoiHoc;
        cin.ignore();
    }
   

};
struct Nodekh {
    KhoaHoc data;
    Nodekh* next;
    Nodekh(KhoaHoc& s) : data(s), next(nullptr) {}
};
struct listkh {
    Nodekh* head;
    Nodekh* tail;
};
void creatlistkh(listkh& l);
Nodekh* creatnodekh(KhoaHoc& s);
void addnodekh(listkh& l, Nodekh* node);
// Lớp Học
struct LopHoc {
    string tenLop;
    list dssv;
    listkh dskh;
    LopHoc( string& _tenLop) : tenLop(_tenLop) {
        creatlist(dssv);
        creatlistkh(dskh);
    }
    void themHocSinh( sinhvien& sv) {
        Node* v = creatnode(sv);
        addnode(dssv, v);
    }
    void themKhoaHoc(KhoaHoc& kh) {
        Nodekh* k = creatnodekh(kh);
        addnodekh(dskh, k);
    }
    void hienThiDanhSachHocSinh() {
        cout << "Danh sach hoc sinh trong lop " << tenLop << ":\n";
        Node* temp = dssv.head;
        while (temp != nullptr) {
            cout << "ID: " << temp->data.id << ", Ho ten: " << temp->data.hoTen << ", Gioi tinh: " << temp->data.gioiTinh
                << ", Ngay sinh: " << temp->data.ngaySinh << ", ID xa hoi: " << temp->data.idXaHoi << "\n";
            temp = temp->next;
        }
    }
   
    void xemBangDiemTongKetHK() {
        cout << "Bang diem tong ket cua lop " << tenLop << " trong hoc ky:\n";
        Nodekh* khNode = dskh.head;
        while (khNode != nullptr) {
            cout << "Khoa hoc: " << khNode->data.tenKhoaHoc << endl;
            Nodebd* bdNode = khNode->data.dsd.head;
            while (bdNode != nullptr) {
                cout << "ID: " << bdNode->data.id << ", Ho ten: " << bdNode->data.hoTen
                    << ", Diem tong ket: " << bdNode->data.tk << endl;
                bdNode = bdNode->next;
            }
            khNode = khNode->next;
        }
    }
    void xemdiemcanhan( int id) {
        Nodekh* khNode = dskh.head;
        while (khNode != nullptr) {
            cout << "Khoa hoc: " << khNode->data.tenKhoaHoc << endl;
            Nodebd* bdNode = khNode->data.dsd.head;
            while (bdNode != nullptr) {
                if (bdNode->data.id == id) {
                    cout << "ID: " << bdNode->data.id << ", Ho ten: " << bdNode->data.hoTen
                        << ", Diem tong ket: " << bdNode->data.tk << endl;
                }
                bdNode = bdNode->next;
            }
            khNode = khNode->next;
            return;
        }
        cout << "Khong tim thay sinh vien\n";
    }
    void hienThiDanhSachKhoaHoc() {
        cout << "Danh sach khoa hoc cua lop " << tenLop << endl;
        Nodekh* temp = dskh.head;
        while (temp != nullptr) {
            cout << "ID: " << temp->data.id << ", Ten khoa hoc : " << temp->data.tenKhoaHoc << ", Ten Lop: " << temp->data.tenLop
                << ", Ten giao vien: " << temp->data.tenGiaoVien << ", So tin chi: " << temp->data.tinchi << ", So luong sinh vien toi da: " << temp->data.slsv
                << ", Ngay hoc: " << temp->data.ngayHoc << ", Buoi hoc: " << temp->data.buoiHoc << endl;
            temp = temp->next;
        }
    }
    void capNhatThongTinKhoaHoc(int id, int sl) {
        Nodekh* temp = dskh.head;
        while (temp != nullptr) {
            if (temp->data.id == id) {
                temp->data.slsv = sl;
                /*temp->data.ngayHoc = ngay;
                temp->data.buoiHoc = buoi;*/
                return;
            }
            temp = temp->next;\
        }
        cout << "Khong tim thay khóa học với ID " << id << endl;
    }
    void themHocVienVaoKhoaHoc(int id, sinhvien& sv) {
        Nodekh* temp = dskh.head;
        while (temp != nullptr) {
            if (temp->data.id == id) {
                Node* svNode = creatnode(sv);
                addnode(temp->data.dshs, svNode);
                return;
            }
            temp = temp->next;
        }
        cout << "Khong tim thay khóa học với ID " << id << endl;
    }
    void xoaHocVienKhoiKhoaHoc(int id, int studentId) {
        Nodekh* khNode = dskh.head;
        while (khNode != nullptr) {
            if (khNode->data.id == id) {
                Node* svNode = khNode->data.dshs.head;
                Node* prevNode = nullptr;
                while (svNode != nullptr) {
                    if (svNode->data.id == studentId) {
                        // Xóa sinh viên khỏi khóa học
                        if (prevNode == nullptr) {
                            // Xóa node đầu danh sách
                            khNode->data.dshs.head = svNode->next;
                        }
                        else {
                            // Xóa node ở vị trí khác
                            prevNode->next = svNode->next;
                        }
                        delete svNode;
                        cout << "Da xoa sinh vien co ID " << studentId << " ra khoi khoa hoc.\n";
                        return;
                    }
                    prevNode = svNode;
                    svNode = svNode->next;
                }
                cout << "Khong tim thay sinh vien co ID " << studentId << " trong khoa hoc.\n";
                return;
            }
            khNode = khNode->next;
        }
        cout << "Khong tim thay khoa hoc voi ID " << id << ".\n";
    }
    void xoaKhoaHoc(int id) {
        Nodekh* khNode = dskh.head;
        Nodekh* prevNode = nullptr;
        while (khNode != nullptr) {
            if (khNode->data.id == id) {
                // Xóa khóa học
                if (prevNode == nullptr) {
                    // Xóa node đầu danh sách
                    dskh.head = khNode->next;
                }
                else {
                    // Xóa node ở vị trí khác
                    prevNode->next = khNode->next;
                }
                delete khNode;
                cout << "Da xoa khoa hoc co ID " << id << ".\n";
                return;
            }
            prevNode = khNode;
            khNode = khNode->next;
        }
        cout << "Khong tim thay khoa hoc voi ID " << id << ".\n";
    }
    void capNhatKetQuaHocSinh(int id,float tk,float gk,float ck,  listkh& dskh) {
        Nodekh* khNode = dskh.head;
        while (khNode != nullptr) {
            Nodebd* bdNode = khNode->data.dsd.head;
            while (bdNode != nullptr) {
                if (bdNode->data.id == id) {
                    // Cập nhật kết quả của học sinh
                    bdNode->data.tk = tk;
                    bdNode->data.ck = ck;
                    bdNode->data.gk = gk;
                    cout << "Da cap nhat ket qua hoc sinh co ID " << id << " trong khoa hoc " << khNode->data.tenKhoaHoc << ".\n";
                    return;
                }
                bdNode = bdNode->next;
            }
            khNode = khNode->next;
        }
        cout << "Khong tim thay hoc sinh co ID " << id << " trong bang diem.\n";
    }
    void xemDanhSachSinhVienTrongKhoaHoc(int idKhoaHoc,  listkh& dskh) {
        Nodekh* temp = dskh.head;
        while (temp != nullptr) {
            if (temp->data.id == idKhoaHoc) {
                cout << "Danh sach sinh vien trong khoa hoc " << temp->data.tenKhoaHoc << ":\n";
                Node* svNode = temp->data.dshs.head;
                while (svNode != nullptr) {
                    cout << "ID: " << svNode->data.id << ", Ho ten: " << svNode->data.hoTen << endl;
                    svNode = svNode->next;
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Khong tim thay khoa hoc voi ID " << idKhoaHoc << endl;
    }
    void xemBangDiemKhoaHochk(int id, listkh& dskh) {
        Nodekh* khNode = dskh.head;
        while (khNode != nullptr) {
            if (khNode->data.id == id) {
                cout << "Bang diem cua khoa hoc " << khNode->data.tenKhoaHoc << ":\n";
                Nodebd* bdNode = khNode->data.dsd.head;
                while (bdNode != nullptr) {
                    cout << "ID: " << bdNode->data.id << ", Ho ten: " << bdNode->data.hoTen
                        << ", Diem tong ket: " << bdNode->data.tk
                        << ", Diem cuoi ki: " << bdNode->data.ck
                        << ", Diem giua ki: " << bdNode->data.gk << endl;
                    bdNode = bdNode->next;
                }
                return;
            }
            khNode = khNode->next;
        }
        cout << "Khong tim thay khoa hoc voi ID " << id << ".\n";
    }

};
struct Nodelh {
    LopHoc data;
    Nodelh* next;
    Nodelh( LopHoc& s) : data(s), next(nullptr) {}
};
struct listlh {
    Nodelh* head;
    Nodelh* tail;
};
Nodelh* creatnodelh(LopHoc& s);
void addnodelh(listlh& l, Nodelh* node);
void creatlistlh(listlh& s);
// Năm Học
struct NamHoc {
    string tenNamHoc;
    listlh dslh;

    NamHoc( string& _tenNamHoc) : tenNamHoc(_tenNamHoc) {
        creatlistlh(dslh);
    }

    void taoLopHoc( LopHoc& s) {
        LopHoc lopHoc(s);
        Nodelh* node = creatnodelh(s);
        node->data = lopHoc;
        addnodelh(dslh, node);
    }
    void themHocSinhVaoLop( string& tenLop,  sinhvien& sv) {
        Nodelh* temp = dslh.head;
        while (temp != nullptr) {
            if (temp->data.tenLop == tenLop) {
                temp->data.themHocSinh(sv);
                break;
            }
            temp = temp->next;
        }
    }

    void hienThiDanhSachLopHoc() {
        std::cout << "Danh sach cac lop trong nam hoc " << tenNamHoc << ":\n";
        Nodelh* temp = dslh.head;
        while (temp != nullptr) {
            std::cout << "Lop: " << temp->data.tenLop << "\n";
            temp = temp->next;
        }
    }

    void hienThiDanhSachHocSinhTrongLop(string& tenLop) {
        Nodelh* temp = dslh.head;
        while (temp != nullptr) {
            if (temp->data.tenLop == tenLop) {
                temp->data.hienThiDanhSachHocSinh();
                return;
            }
            temp = temp->next;
        }
        cout << "Khong tim thay lop " << tenLop << "\n";
    }
};
void nhapDanhSachHocSinhTuFile(string& tenFile, list& dssv);

// Học kì
struct HocKy {
    int namHoc;
    int hocKy;
    string ngayBatDau;
    string ngayKetThuc;
    listlh dslh;
    HocKy(int _namHoc, int _hocKy, string& _ngayBatDau, string& _ngayKetThuc)
        : namHoc(_namHoc), hocKy(_hocKy), ngayBatDau(_ngayBatDau), ngayKetThuc(_ngayKetThuc) {
        creatlistlh(dslh);
    }
    HocKy() = default;
    void taoLopHoc(string& s) {
        LopHoc lopHoc(s);
        Nodelh* node = creatnodelh(lopHoc);
        node->data = lopHoc;
        addnodelh(dslh, node);
    }

    void themHocSinhVaoLop(string& tenLop, sinhvien& sv) {
        Nodelh* temp = dslh.head;
        while (temp != nullptr) {
            if (temp->data.tenLop == tenLop) {
                temp->data.themHocSinh(sv);
                break;
            }
            temp = temp->next;
        }
        cout << "Khong tim thay lop " << tenLop << "\n";
    }

    void themKhoaHocVaoLop(string& tenLop,  KhoaHoc& khoaHoc) {
        Nodelh* temp = dslh.head;
        while (temp != nullptr) {
            if (temp->data.tenLop == tenLop) {
                temp->data.themKhoaHoc(khoaHoc);
                break;
            }
            temp = temp->next;
        }
        std::cout << "Khong tim thay lop " << tenLop << "\n";
    }

    void hienThiDanhSachLopHoc() {
        std::cout << "Danh sach lop hoc trong hoc ky " << hocKy << " nam hoc " << namHoc << ":\n";
        Nodelh* temp = dslh.head;
        while (temp != nullptr) {
            std::cout << "Lop: " << temp->data.tenLop << "\n";
            temp = temp->next;
        }
    }
    void xembangdiemkhoahoc(string& tenLop,int id) {
        Nodelh* temp = dslh.head;
        while (temp != nullptr) {
            if (temp->data.tenLop == tenLop) {
                temp->data.xemBangDiemKhoaHochk(id,temp->data.dskh);
                return;
            }
            temp = temp->next;
        }
        std::cout << "Khong tim thay lop " << tenLop << "\n";
    }
    void XemDiemCaNhan(string& tenLop, int id) {
        Nodelh* temp = dslh.head;
        while (temp != nullptr) {
            if (temp->data.tenLop == tenLop) {
                temp->data.xemdiemcanhan(id);
                return;
            }
            temp = temp->next;
        }
        std::cout << "Khong tim thay lop " << tenLop << "\n";
    }
    void capnhatbangdiem(string& tenLop, int id,float tk,float ck,float gk) {
        Nodelh* temp = dslh.head;
        while (temp != nullptr) {
            if (temp->data.tenLop == tenLop) {
                temp->data.capNhatKetQuaHocSinh(id,tk,gk,ck, temp->data.dskh);
                return;
            }
            temp = temp->next;
        }
        std::cout << "Khong tim thay lop " << tenLop << "\n";
    }
    void xembangdiemcalop(string& tenLop ) {
        Nodelh* temp = dslh.head;
        while (temp != nullptr) {
            if (temp->data.tenLop == tenLop) {
                temp->data.xemBangDiemTongKetHK();
                return;
            }
            temp = temp->next;
        }
        std::cout << "Khong tim thay lop " << tenLop << "\n";
    }

    void hienThiDanhSachHocSinhTrongLop(string& tenLop) {
        Nodelh* temp = dslh.head;
        while (temp != nullptr) {
            if (temp->data.tenLop == tenLop) {
                temp->data.hienThiDanhSachHocSinh();
                return;
            }
            temp = temp->next;
        }
        std::cout << "Khong tim thay lop " << tenLop << "\n";
    }

    void hienThiDanhSachKhoaHocTrongLop(string& tenLop) {
        Nodelh* temp = dslh.head;
        while (temp != nullptr) {
            if (temp->data.tenLop == tenLop) {
                temp->data.hienThiDanhSachKhoaHoc();
                return;
            }
            temp = temp->next;
        }
        cout << "Khong tim thay lop " << tenLop << endl;
    }
    void capnhatthongtinkhoahoc(string& tenLop,int id,int sl) {
        Nodelh* temp = dslh.head;
        while (temp != nullptr) {
            if (temp->data.tenLop == tenLop) {
                temp->data.capNhatThongTinKhoaHoc(id,sl);
                return;
            }
            temp = temp->next;
        }
        cout << "Khong tim thay lop " << tenLop << endl;
    }
    void themsinhvienvaokhoahoc(string& tenLop, int id, sinhvien& sv) {
        Nodelh* temp = dslh.head;
        while (temp != nullptr) {
            if (temp->data.tenLop == tenLop) {
                temp->data.themHocVienVaoKhoaHoc(id, sv);
                return;
            }
            temp = temp->next;
        }
        cout << "Khong tim thay lop " << tenLop << endl;
    }
    void xoasinhvienkhoikhoahoc(string& tenLop, int id, int idsv) {
        Nodelh* temp = dslh.head;
        while (temp != nullptr) {
            if (temp->data.tenLop == tenLop) {
                temp->data.xoaHocVienKhoiKhoaHoc(id,idsv);
                return;
            }
            temp = temp->next;
        }
        cout << "Khong tim thay lop " << tenLop << endl;
    }
    void xoaKhoaHoc(string& tenLop,int id) {
        Nodelh* temp = dslh.head;
        while (temp != nullptr) {
            if (temp->data.tenLop == tenLop) {
                temp->data.xoaKhoaHoc(id);
                return;
            }
            temp = temp->next;
        }
        cout << "Khong tim thay lop " << tenLop << endl;
    }
    void Xemdanhsachsinhvientrongkhoahoc(string& tenLop, int id) {
        Nodelh* temp = dslh.head;
        while (temp != nullptr) {
            if (temp->data.tenLop == tenLop) {
                temp->data.xemDanhSachSinhVienTrongKhoaHoc(id, temp->data.dskh);
                return;
            }
            temp = temp->next;
        }
        cout << "Khong tim thay lop " << tenLop << endl;
    }
};
struct Nodehk{
    HocKy data;
    Nodehk* next;
    Nodehk(HocKy& s) : data(s), next(nullptr) {}
};
struct listhk {
    Nodehk* head;
    Nodehk* tail;
};
void creatlisthk(listhk& l);
Nodehk* creatnodehk(HocKy& s);
void addnodehk(listhk& l, Nodehk* node);
void nhaphk(HocKy& s);
void nhapDanhSachKhoaHocTuFile(string& tenFile, listkh& dskh);
void nhapdanhsachlophoctufile(string& tenFile, listlh& dslh);
void nhapDanhSachhockyFile(string& tenFile, listhk& dshk);
void xuatdanhsachsinhvienrafile(string& tenFile, list& dssv);
void ghidulieubangdiemVaoFile(string& tenFile, bangdiem& sv);
void ghiDuLieuNamHocVaoFile(NamHoc& namHoc, string& tenFile);
void ghiDanhSachKhoaHocVaoFile(listkh& dskh, string& tenFile);
void ghiDanhSachSinhVienVaoFile(string& tenFile, list& dssv);
void luudanhsachlop(string& tenFile, string& s, string& v, listlh& dslh);
void luudanhsachkhoahoc(string& tenFile, listkh& dskh);
void luudanhsachsinhvien(string& tenFile, list& dssv);
void docBangDiemTuFile(string& fileName, listbd& dsbd);
 // Phần của cán bộ
struct canbo {
	string ten;
	int mk;
};
struct Nodecb {
	canbo data;
	Nodecb* next;
};

struct ds {
	Nodecb* head;
	Nodecb* tail; 
};
// các hàm lệnh của cán bộ
void creatlist1(ds& l);
Nodecb* creatnode1(canbo s);
bool  kiemtra(canbo v);
canbo find(ds l, string s);
ds hamdoc(string name);

void addnodecb(ds& l, Nodecb* node);
void doimk(ds& l, canbo v, string name);
void menu();
void menukh();
void menuhs();