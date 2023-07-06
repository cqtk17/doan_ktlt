#include"Header.h"
// bảng điểm
void addnodebd(listbd& l, Nodebd* node) {
    if (l.head == nullptr) {
        l.head = node;
        l.tail = node;
        node->next = nullptr;
    }
    else {
        l.tail->next = node;
        l.tail = node;
        node->next = nullptr;
    }
}

void creatlistbd(listbd& s) {
    s.head = nullptr;
    s.tail = nullptr;
}
Nodebd* creatnodebd(bangdiem& s) {
    Nodebd* node = new Nodebd(s);
    node->next = nullptr;
    return node;
}
//Lớp Học
void addnodelh(listlh& l, Nodelh* node) {
    if (l.head == nullptr) {
        l.head = node;
        l.tail = node;
        node->next = nullptr;
    }
    else {
        l.tail->next = node;
        l.tail = node;
        node->next = nullptr;
    }
}

void creatlistlh(listlh& s) {
    s.head = nullptr;
    s.tail = nullptr;
}
Nodelh* creatnodelh(LopHoc& s) {
    Nodelh* node = new Nodelh(s);
    node->next = nullptr;
    return node;
}
// danh sách sinh viên
void creatlist(list& l) {
    l.head = nullptr;
    l.tail = nullptr;
}

Node* creatnode(sinhvien& s) {
    Node* node = new Node;
    node->data = s;
    node->next = nullptr;
    return node;
}

void addnode(list& l, Node* node) {
    if (l.head == nullptr) {
        l.head = node;
        l.tail = node;
        node->next = nullptr;
    }
    else {
        l.tail->next = node;
        l.tail = node;
        node->next = nullptr;
    }
}
void nhapDanhSachHocSinhTuFile(string& tenFile, list& dssv) {
    ifstream file(tenFile);
    if (file.is_open()) {
        string ht, ns, gt, idxh; int id;
        while (file >>id >> ht >>gt>>ns>>idxh) {
            sinhvien sv(id, ht, gt, ns, idxh);
            addnode(dssv, creatnode(sv));
      }
        file.close();
        cout << "Nhap danh sach hoc sinh tu file " << tenFile << " thanh cong.\n";
        cout << "   /////////////////      \n";
    }
    else {
        cout << "Khong the mo file " << tenFile << "\n";
    }
}
void luudanhsachsinhvien(string& tenFile, list& dssv) {
    std::ifstream file(tenFile);
    if (file.is_open()) {
        string ht, ns, gt, idxh; int id;
        while (file >>id>> ht >> gt >> ns >> idxh ) {
            sinhvien sv(id, ht, gt, ns, idxh);
            addnode(dssv, creatnode(sv));
        }
        file.close();
    }
    else {
        cout << "Khong the luu file " << tenFile << "\n";
    }
}
// danh sách khóa học
void creatlistkh(listkh& l) {
    l.head = nullptr;
    l.tail = nullptr;
}
Nodekh* creatnodekh(KhoaHoc& s) {
    Nodekh* node = new Nodekh(s);
    node->next = nullptr;
    return node;
}
void addnodekh(listkh& l, Nodekh* node) {
    if (l.head == nullptr) {
        l.head = node;
        l.tail = node;
        node->next = nullptr;
    }
    else {
        l.tail->next = node;
        l.tail = node;
        node->next = nullptr;
    }
}
// danh sách học kỳ
void creatlisthk(listhk& l) {
    l.head = nullptr;
    l.tail = nullptr;
}
Nodehk* creatnodehk(HocKy& s) {
    Nodehk* node = new Nodehk(s);
    node->next = nullptr;
    return node;
}
void addnodehk(listhk& l, Nodehk* node) {
    if (l.head == nullptr) {
        l.head = node;
        l.tail = node;
        node->next = nullptr;
    }
    else {
        l.tail->next = node;
        l.tail = node;
        node->next = nullptr;
    }
}
void nhaphk(HocKy& s) {
    cout << "Nhap nam hoc: ";
    cin >> s.namHoc;
    cout << "Nhap hoc ky: ";
    cin >> s.hocKy;
    cout << "Nhap ngay bat dau: ";
    cin >> s.ngayBatDau;
    cout << "Nhap ngay ket thuc: ";
    cin >> s.ngayKetThuc;
}
void nhapDanhSachKhoaHocTuFile(string& tenFile, listkh& dskh) {
    std::ifstream file(tenFile);
    if (file.is_open()) {
        string tengv, tenkh, tenl,ngayhoc,buoihoc; int id, slsv, tc;
        while (file >>id>>tenkh>>tenl>>tengv>>tc>>slsv>>ngayhoc>>buoihoc) {
            KhoaHoc kh(id,tenkh,tenl,tengv,tc,slsv,ngayhoc,buoihoc);
            addnodekh(dskh, creatnodekh(kh));
        }
        file.close();
        cout << "Nhap danh sach khoa hoc tu file " << tenFile << " thanh cong.\n";
        cout << "   /////////////////      \n";
    }
    else {
        cout << "Khong the mo file " << tenFile << "\n";
    }
}
 void docBangDiemTuFile( string& fileName, listbd& dsbd) {
    ifstream file(fileName);
    if (file.is_open()) {
        int id;
        string hoTen;
        float tk, ck, gk;
        while (file >> id >> hoTen >> tk >> ck >> gk) {
            bangdiem d(id, hoTen, tk, ck, gk);
            addnodebd(dsbd, creatnodebd(d));

        }
        file.close();
    }
    else {
        cout << "Khong the luu file.\n";
    }
}
void luudanhsachkhoahoc(string& tenFile, listkh& dskh) {
    std::ifstream file(tenFile);
    if (file.is_open()) {
        string tengv, tenkh, tenl, ngayhoc, buoihoc; int id, slsv, tc;
        while (file >> id >> tenkh >> tenl >> tengv >> tc >> slsv >> ngayhoc >> buoihoc) {
            KhoaHoc kh(id, tenkh, tenl, tengv, tc, slsv, ngayhoc, buoihoc);
            addnodekh(dskh, creatnodekh(kh));
        }
        file.close();
    }
    else {
        cout << "Khong the luu file " << tenFile << "\n";
    }
}
void nhapdanhsachlophoctufile(string& tenFile, listlh& dslh) {
    std::ifstream file(tenFile);
    if (file.is_open()) {
        string tenlop;
        while (file >> tenlop) {
            LopHoc lh(tenlop);
            addnodelh(dslh, creatnodelh(lh));
        }
        file.close();
        cout << "Nhap danh sach lop hoc tu file " << tenFile << " thanh cong.\n";
        cout << "   /////////////////      \n";
    }
    else {
        cout << "Khong the mo file " << tenFile << "\n";
    }
    Nodelh* node = dslh.head;
    while (node != nullptr) {
        string s;
        cout << "Nhap ten file chua du lieu hoc sinh lop " << node->data.tenLop << endl;
        getline(cin, s);
        nhapDanhSachHocSinhTuFile(s, node->data.dssv);
        string v;
        cout << "Nhap ten file chua du lieu khoa hoc  " << node->data.tenLop << endl;
        getline(cin, v);
        nhapDanhSachKhoaHocTuFile(v, node->data.dskh);
        cin.ignore();
        node = node->next;
    }
}
void luudanhsachlop(string& tenFile,string&s,string& v, listlh& dslh) {
    std::ifstream file(tenFile);
    if (file.is_open()) {
        string tenlop;
        while (file >> tenlop) {
            LopHoc lh(tenlop);
            addnodelh(dslh, creatnodelh(lh));
        }
        file.close();
    }
    else {
        cout << "Khong the luu  " << tenFile << "\n";
    }
    Nodelh* node = dslh.head;
    while (node != nullptr) {
        luudanhsachsinhvien(s, node->data.dssv);
        luudanhsachkhoahoc(v, node->data.dskh);
        node = node->next;
    }
}
void nhapDanhSachhockyFile(string& tenFile, listhk& dshk) {
    std::ifstream file(tenFile);
    if (file.is_open()) {
        int nh, hk;
        string begin, end;
        while (file>>nh>>hk>>begin>>end) {
            HocKy hocki(nh, hk, begin, end);
            addnodehk(dshk, creatnodehk(hocki));
        }
        file.close();
        cout << "Nhap danh sach hoc ki tu file " << tenFile << " thanh cong.\n";
        cout << "   /////////////////      \n";
    }
    else {
        cout << "Khong the mo file " << tenFile << "\n";
    }
    Nodehk* node = dshk.head;
    while (node != nullptr) {
        string s;
        cout << "Nhap ten file chua du lieu lop hoc cua hoc ky  " << node->data.hocKy << endl;
        getline(cin, s);
        nhapdanhsachlophoctufile(s, node->data.dslh);
        cin.ignore();
        node = node->next;
    }
}
void xuatdanhsachsinhvienrafile(string& tenFile, list& dssv) {
    ofstream file(tenFile);  
    if (file.is_open()) {
        Node* node = dssv.head;
        while (node != nullptr) {
            file << node->data.id << " " << node->data.hoTen << " " << node->data.gioiTinh << " " << node->data.ngaySinh << " " << node->data.idXaHoi << "\n";
            node = node->next;
    }
       
        file.close();  
        cout << " Xuat file thanh cong \n";
        cout << "   /////////////////      \n";
    }
    else {
        cout << "Khong the mo file.\n";
    }
}
void ghidulieubangdiemVaoFile( string& tenFile,  bangdiem& sv) {
    ofstream file(tenFile, ios::app); // Mở file để ghi dữ liệu (chế độ append)
    if (file.is_open()) {
        file << sv.id << " " << sv.hoTen << " " << sv.tk << " " << sv.ck << " " << sv.gk << endl;
        file.close(); // Đóng file sau khi ghi xong
        cout << "Ghi du lieu sinh vien vao file thanh cong.\n";
    }
    else {
        cout << "Khong the mo file " << tenFile << endl;
    }
}
void ghiDuLieuNamHocVaoFile(NamHoc& namHoc, string& tenFile) {
    ofstream file(tenFile);
    if (file.is_open()) {
        file << namHoc.tenNamHoc << endl; // Ghi thông tin tên năm học vào file
        Nodelh* temp = namHoc.dslh.head;
        while (temp != nullptr) {
            file << temp->data.tenLop << endl; // Ghi thông tin tên lớp vào file
            temp = temp->next;
        }
        file.close();
        cout << "Ghi du lieu nam hoc vao file " << tenFile << " thanh cong.\n";
    }
    else {
        cout << "Khong the mo file " << tenFile << "\n";
    }
}
void ghiDanhSachKhoaHocVaoFile(listkh& dskh, string& tenFile) {
    ofstream file(tenFile);
    if (file.is_open()) {
        Nodekh* temp = dskh.head;
        while (temp != nullptr) {
            file << temp->data.id << " " << temp->data.tenKhoaHoc << " " << temp->data.tenLop << " "
                << temp->data.tenGiaoVien << " " << temp->data.tinchi << " " << temp->data.slsv << " "
                << temp->data.ngayHoc << " " << temp->data.buoiHoc << endl;
            temp = temp->next;
        }
        file.close();
        cout << "Ghi danh sach khoa hoc vao file " << tenFile << " thanh cong.\n";
    }
    else {
        cout << "Khong the mo file " << tenFile << "\n";
    }
}
void ghiDanhSachSinhVienVaoFile( string& tenFile,  list& dssv) {
    ofstream file(tenFile);
    if (file.is_open()) {
        Node* temp = dssv.head;
        while (temp != nullptr) {
            file << temp->data.id << " "
                << temp->data.hoTen << " "
                << temp->data.gioiTinh << " "
                << temp->data.ngaySinh << " "
                << temp->data.idXaHoi << endl;
            temp = temp->next;
        }
        file.close();
        cout << "Ghi danh sach sinh vien vao file " << tenFile << " thanh cong.\n";
    }
    else {
        cout << "Khong the mo file " << tenFile << "\n";
    }
}


void menukh() {
    cout << "  //////////       \n";
    cout << "1.Xem danh sach\n";
    cout << "2.Cap nhat thong tin\n";
    cout << "3.Them mot sinh vien vao khoa hoc\n";
    cout << "4.Xoa mot sinh vien ra khoi khoa hoc\n";
    cout << "5.Xoa khoa hoc\n";
    cout << "6. Thoat\n";
    cout << "     ///////////////       \n";
}
void menuhs() {
    cout << "  //////////       \n";
    cout << "1.Xem danh sach cac lop\n";
    cout << "2.Xem danh sach hoc sinh lop\n";
    cout << "3.Xem danh sach cac khoa hoc\n";
    cout << "4.Xem danh sach hoc vien trong mot khoa hoc \n";
    cout << "5.Xuat danh sach hoc vien trong khoa hoc ra file\n";
    cout << "6.Nhap bang diem cua mot khoa hoc\n";
    cout << "7.xem bang diem cua mot khoa hoc\n";
    cout << "8.Cap nhat ket qua cua hoc sinh\n";
    cout << "9.Xem bang diem cua Lop\n";
    cout << "10.Xem bang diem cua chinh minh\n";
    cout << "11.Thoat\n";
    cout << "  //////////       \n";
}