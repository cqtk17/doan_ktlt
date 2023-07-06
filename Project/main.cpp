#include"Header.h"
int main() {
	int n, f = 1;
	while (f != 0) {
		do {
			cout << "Nhap lua chon:\n";
			cout << "1. Can bo\n";
			cout << "2. Sinh vien\n";
			cout << "3.Thoat khoi chuong trinh \n";
			cout << "         //////            \n";
			cin >> n;
		} while (n < 0 || n>3);

		switch (n) {
		case 1: {
			ds l1;
			l1 = hamdoc("danhsachcanbo.txt");
			string ten1;
			cout << "Nhap ten:\n ";
			cin.ignore();
			getline(cin, ten1);
			canbo v = find(l1, ten1);
			if (kiemtra(v) == false) {
				cout << "Mk sai\n";
			}
			else {
				cout << "Mk dung " << endl;
				int t = 1, lc;
				while (t != 0) {
					menu();
					do {
						cout << "Nhap lua chon \n";
						cin >> lc;
					} while (lc < 0);
					switch (lc) {
					case 0: {cout << "Ten: " << v.ten << endl;
						cout << "MK: " << v.mk << endl;
						break; }
					case 1:doimk(l1, v, "danhsachcanbo.txt"); break;
					case 2: {
						string s;
						cout << "Nhap nam hoc: ";
						cin.ignore();
						getline(cin, s);
						NamHoc namHoc{ s };
						int n; cout << "Nhap so lop muon tao: \n";
						cin >> n;
						string l[5];
						for (int i = 0; i < n; i++) {

							cout << "Nhap ten lop: " << i + 1 << endl;
							cin.ignore();
							getline(cin, l[i]);
							LopHoc lopHoc(l[i]);
							namHoc.taoLopHoc(lopHoc);
						}

						for (int i = 0; i < n; i++) {
							cout << "Nhap so hoc sinh cua lop " << l[i] << endl;
							int sl; cin >> sl;
							for (int j = 0; j < sl; j++) {
								sinhvien sv;
								cout << "sinh vien thu " << j + 1 << endl;
								sv.nhap();
								namHoc.themHocSinhVaoLop(l[i], sv);
							}
						}
						namHoc.hienThiDanhSachLopHoc();
						for (int i = 0; i < n; i++) {
							namHoc.hienThiDanhSachHocSinhTrongLop(l[i]);
						}
						string tenfile = "dulieunamhoc.txt";
						ghiDuLieuNamHocVaoFile(namHoc,tenfile);
						break;
						// còn thiếu đọc vào file
					}
					case 3: {cout << "Vui long nhap ten file\n";
						list dssv; 
						creatlist(dssv);
						cin.ignore();
						string s = {"danhsachsinhvien.txt"}; getline(cin, s);
						nhapDanhSachHocSinhTuFile(s, dssv);
						Node* temp = dssv.head;
						while (temp != nullptr) {
							cout << "ID: " << temp->data.id << ", Ho ten: " << temp->data.hoTen << ", Gioi tinh: " << temp->data.gioiTinh
								<< ", Ngay sinh: " << temp->data.ngaySinh << ", ID xa hoi: " << temp->data.idXaHoi << "\n";
							temp = temp->next;
						}
						break;
					}
					case 4: {
						listhk dshk;
						creatlisthk(dshk);
						cout << "Nhap ten file chua danh sach hoc ky: \n";
						string tenfile; cin.ignore(); getline(cin, tenfile);
						nhapDanhSachhockyFile(tenfile, dshk); cout << endl;
						int h = 1;
						while (h != 0) {
							int ch;
							do {
								menukh();
								cout << "Nhap lua chon: ";
								cin >> ch;
							} while (ch < 0 || ch>6);
							switch (ch) {
							case 1: {
								cout << "Nhap ten lop can xem khoa hoc: ";
								string kh; cin.ignore(); getline(cin, kh);
								Nodehk* temp = dshk.head;
								while (temp != nullptr) {
									temp->data.hienThiDanhSachKhoaHocTrongLop(kh);
									temp = temp->next;
								}
								break; }
							case 2: {
								
								KhoaHoc kh; 
								cout << "Nhap id khoa hoc can cap nhat:\n"; int id;
								 cin >>id;
								 cout << "Cap nhat so luong sinh vien\n"; int sl;
								 cin >> sl;
								 cout << "Nhap ten lop\n";
								 cin.ignore(); string ten;
								 getline(cin, ten);
								cout << "chon hoc ki: \n"; int hk;
								cin >> hk;
								Nodehk* temp = dshk.head;
								while (temp != nullptr) {
									if (temp->data.hocKy == hk) {
										temp->data.capnhatthongtinkhoahoc(ten, id, sl);
									
									}
									temp = temp->next;
								}
								Nodehk* node = dshk.head;
								while (node != nullptr) {
									Nodelh* tam = node->data.dslh.head;
									while (tam != nullptr) {
										string tenFile = "danhsachkhoahoc.txt";
										ghiDanhSachKhoaHocVaoFile(tam->data.dskh, tenFile);
										tam = tam->next;
									}
									node = node->next;
								}
								break;
							}
							case 3: {
								cout << "Nhap id sinh vien can them:";
								int id; cin >> id;
								cout << "Nhap thong tin sinh vien: ";
								cin.ignore();
								sinhvien sv; sv.nhap();
								cout << "Nhap ten lop cua lop hoc:";
								cin.ignore();
								string ten; getline(cin, ten);
								cout << "chon hoc ki: "; int hk;
								cin >> hk;
								Nodehk* temp = dshk.head;
								while (temp != nullptr) {
									if (temp->data.hocKy == hk) {
										temp->data.themsinhvienvaokhoahoc(ten, id, sv);
										
									}
									temp = temp->next;
								}
								Nodehk* node = dshk.head;
								while (node != nullptr) {
									Nodelh* tam = node->data.dslh.head;
									while (tam != nullptr) {
										string tenFile = "danhsachsinhvien.txt";
										ghiDanhSachSinhVienVaoFile(tenfile,tam->data.dssv);
										tam = tam->next;
									}
									node = node->next;
								}
								break;
							}
							case 4: {
								cout << "Nhap id khoa hoc can xoa sinh vien :";
								int id; cin >> id;
								cout << "Nhap id sinh vien: ";
								int idsv; cin >> idsv;
								cout << "Nhap ten lop cua lop hoc:";
								cin.ignore();
								string ten; getline(cin, ten);
								cout << "chon hoc ki: "; int hk;
								cin >> hk;
								Nodehk* temp = dshk.head;
								while (temp != nullptr) {
									if (temp->data.hocKy == hk) {
										temp->data.xoasinhvienkhoikhoahoc(ten, id, idsv);
										
									}
									temp = temp->next;
								}
								Nodehk* node = dshk.head;
								while (node != nullptr) {
									Nodelh* tam = node->data.dslh.head;
									while (tam != nullptr) {
										string tenFile = "danhsachsinhvien.txt";
										ghiDanhSachSinhVienVaoFile(tenfile, tam->data.dssv);
										tam = tam->next;
									}
									node = node->next;
								}
								break;
							}
							case 5: {
								cout << "Nhap id khoa hoc can xoa:";
								int id; cin >> id;
								cout << "Nhap ten lop cua lop hoc:";
								cin.ignore();
								string ten; getline(cin, ten);
								cout << "chon hoc ki: "; int hk;
								cin >> hk;
								Nodehk* temp = dshk.head;
								while (temp != nullptr) {
									if (temp->data.hocKy == hk) {
										temp->data.xoaKhoaHoc(ten, id);
										
									}
									temp = temp->next;
								}
								Nodehk* node = dshk.head;
								while (node != nullptr) {
									Nodelh* tam = node->data.dslh.head;
									while (tam != nullptr) {
										string tenFile = "danhsachkhoahoc.txt";
										ghiDanhSachKhoaHocVaoFile(tam->data.dskh, tenFile);
										tam = tam->next;
									}
									node = node->next;
								}
								break;
							}
							case 6:h = 0; break;
							}
						}
					}
					case 5:t = 0; break;
					}
				}
			}
			break;
		}
		case 2: {
			listhk dshk;
			creatlisthk(dshk);
			string tenfile="danhsachhocki.txt";
			std::ifstream file(tenfile);
			if (file.is_open()) {
				int nh, hk;
				string begin, end;
				while (file >> nh >> hk >> begin >> end) {
					HocKy hocki(nh, hk, begin, end);
					addnodehk(dshk, creatnodehk(hocki));
				}
				file.close();
			}
			else {
				cout << "thong tin chua duoc luu thanh cong " <<  "\n";
			}
			Nodehk* node = dshk.head;
			while (node != nullptr) {
				string lop= "danhsachlophoc.txt";
				string sv = "danhsachsinhvien.txt";
				string kh = "danhsachkhoahoc.txt";
				luudanhsachlop(lop, sv, kh,node->data.dslh);	
				node = node->next;
			}
			Nodehk* node1 = dshk.head;
			while (node1 != nullptr) {
				string lop = "danhsachlophoc.txt";
				string sv = "danhsachsinhvien.txt";
				string kh = "danhsachkhoahoc.txt";
				string bd = "danhsachdiem.txt";
				Nodelh* node2 = node1->data.dslh.head;
				while (node2 != nullptr) {
					Nodekh* node3 = node2->data.dskh.head;
					while (node3 != nullptr) {
						luudanhsachsinhvien(sv, node3->data.dshs);
						docBangDiemTuFile(bd, node3->data.dsd);
						node3 = node3->next;
					}
					node2 = node2->next;
				}
				node1 = node1->next;
			}

			int d = 1;
			while (d != 0) {
				int sl;
				do {
					menuhs();
					cout << "Nhap lua chon: ";
					cin >> sl;
				} while (sl < 0 || sl>11);
				switch (sl) {
				case 1: {
					cout << "chon hoc ki: "; int hk;
					cin >> hk;
					Nodehk* temp = dshk.head;
					while (temp != nullptr) {
						if (temp->data.hocKy == hk) {
							temp->data.hienThiDanhSachLopHoc();
							temp = temp->next;
						}
					}
					break;
				}
				case 2: {
					cout << "chon hoc ki: "; int hk;
					cin >> hk;
					cout << "Nhap ten lop cua lop hoc:";
					cin.ignore();
					string ten; getline(cin, ten);
					Nodehk* temp = dshk.head;
					while (temp != nullptr) {
						if (temp->data.hocKy == hk) {
							temp->data.hienThiDanhSachHocSinhTrongLop(ten);
							
						}
						temp = temp->next;
					}
					break;
				}
				case 3: {
					cout << "chon hoc ki: "; int hk;
					cin >> hk;
					cout << "Nhap ten lop cua lop hoc:";
					cin.ignore();
					string ten; getline(cin, ten);
					Nodehk* temp = dshk.head;
					while (temp != nullptr) {
						if (temp->data.hocKy == hk) {
							temp->data.hienThiDanhSachKhoaHocTrongLop(ten);
						}
						temp = temp->next;
					}
					break;
				}
				case 4: {
					cout << "chon hoc ki: "; int hk;
					cin >> hk;
					cout << "Nhap ten lop cua lop hoc:";
					cin.ignore();
					string ten; getline(cin, ten);
					cout << "Nhap id khoa hoc: \n";
					int id; cin >> id;
					Nodehk* temp = dshk.head;
					while (temp != nullptr) {
						if (temp->data.hocKy == hk) {
							temp->data.Xemdanhsachsinhvientrongkhoahoc(ten,id);
						}
						temp = temp->next;
					}
					break;
				}
				case 5: {
					cout << "Nhap ten file can in \n";
					string tenfile; cin.ignore(); getline(cin, tenfile);
					cout << "chon hoc ki: "; int hk;
					cin >> hk;
					cout << "Nhap ten lop cua lop hoc:";
					cin.ignore();
					string ten; getline(cin, ten);
					cout << "Nhap id khoa hoc: "; int id;
					cin >> id;
					Nodehk* node1 = dshk.head;
					while (node1 != nullptr) {
						if (node1->data.hocKy == hk) {
							Nodelh* node2 = node1->data.dslh.head;
							while (node2 != nullptr) {
								if (node2->data.tenLop == ten) {
									Nodekh* node3 = node2->data.dskh.head;
									while (node3 != nullptr) {
										if (node3->data.id == id) {
											xuatdanhsachsinhvienrafile(tenfile, node3->data.dshs);
										}
										node3 = node3->next;
									}
								}
								node2 = node2->next;
							}
						}
						node1 = node1->next;
					}
					/*Nodehk* temp = dshk.head;
					while (temp != nullptr) {
						if (temp->data.hocKy == hk) {
							Nodelh* node = temp->data.dslh.head;
							while (node != nullptr) {
								if (node->data.tenLop == ten) {
									xuatdanhsachsinhvienrafile(tenfile, node->data.dssv);
								}
								node = node->next;
							}
						}
						temp = temp->next;
					}*/
					break;
				}
				case 6: {
					listbd dsd;
					creatlistbd(dsd);
					cout << "Nhap so sinh vien: ";
					int n; cin >> n;
					for (int i = 0; i < n; i++) {
						cout << "Nhap bang diem sinh vien thu " << i + 1 << endl;
						bangdiem s;
						s.nhapbangdiem(s);
						addnodebd(dsd, creatnodebd(s));
					}
					cout << "Nhap ten file chua danh sach diem cua khoa hoc : \n";
					string tenfile; cin.ignore(); getline(cin, tenfile);
					Nodebd* node = dsd.head;
					while (node != nullptr) {
						ghidulieubangdiemVaoFile(tenfile, node->data);
						node = node->next;
					}
					break;
				}
				case 7: {
					cout << "chon hoc ki: "; int hk, id;
					cin >> hk;
					cout << "Nhap ten lop cua lop hoc:";
					cin.ignore();
					string ten; getline(cin, ten);
					cout << "Nhap id khoa hoc: ";
					cin >> id;
					Nodehk* temp = dshk.head;
					while (temp != nullptr) {
						if (temp->data.hocKy == hk) {
							temp->data.xembangdiemkhoahoc(ten,id);
						}
						temp = temp->next;
					}
					break;
				}
				case 8: {
					cout << "chon hoc ki: "; int hk, id; float tk, ck, gk;
					cin >> hk;
					cout << "Nhap ten lop cua lop hoc:";
					cin.ignore();
					string ten; getline(cin, ten);
					cout << "Nhap id hoc sinh: ";
					cin >> id;
					cout << "Nhap diem tong ket: "; cin >> tk;
					cout << "Nhap diem giua ki: "; cin >> gk;
					cout << "Nhap diem cuoi ki: "; cin >> ck;
					Nodehk* temp = dshk.head;
					while (temp != nullptr) {
						if (temp->data.hocKy == hk) {
							temp->data.capnhatbangdiem(ten, id,tk,gk,ck);
							temp = temp->next;
						}
					}
					break;
				}
				case 9: {
					cout << "chon hoc ki: "; int hk;
					cin >> hk;
					cout << "Nhap ten lop cua lop hoc:";
					cin.ignore();
					string ten; getline(cin, ten);
					Nodehk* temp = dshk.head;
					while (temp != nullptr) {
						if (temp->data.hocKy == hk) {
							temp->data.xembangdiemcalop(ten);
							temp = temp->next;
						}
					}
					break;
				}
				case 10: {
					cout << "chon hoc ki: "; int hk, id;
					cin >> hk;
					cout << "Nhap ten lop cua lop hoc:";
					cin.ignore();
					string ten; getline(cin, ten);
					cout << "Nhap ma so sinh vien: ";
					cin >> id;
					Nodehk* temp = dshk.head;
					while (temp != nullptr) {
						if (temp->data.hocKy == hk) {
							temp->data.XemDiemCaNhan(ten,id);
							temp = temp->next;
						}
					}
					break;
				}
				case 11:d = 0; break;
				}
			}
		}
		case 3:f = 0; break;
		}
	}
}
// Nhiệm vụ còn lại
// xuất thông tin ra lại các file
// tự động nhập thông tin tại nút chọn học sinh
// nhap bang diem trong khoa hoc