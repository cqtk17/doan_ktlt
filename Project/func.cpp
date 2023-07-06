#include"Header.h"
void creatlist1(ds& l1) {
	l1.head = nullptr;
	l1.tail = nullptr;
}

Nodecb* creatnode1(canbo s) {
	Nodecb* node = new Nodecb;
	node->data = s;
	node->next = nullptr;
	return node;
}
bool  kiemtra(canbo v) {
	int  s;
	cout << "Nhap mk: \n ";
	cin >> s;
	if (s==v.mk) {// kiểm tra mk đúng hay không
		return true;
	}
	else {
		return false;
	}
}
canbo find(ds l,string s) {
	Nodecb* node = l.head;
	canbo v{};
	while (node != nullptr) {
		if (node->data.ten.compare( s)==0) {
			 v = node->data;
			break;
		}
		node = node->next;
	}
	return v;
}
ds hamdoc(string name) {
	ifstream f(name);
	ds l;
	creatlist1(l);
	if (f.is_open()) {
		string ten;
		int mk;
		while (f>>ten>>mk) {
			canbo cb;
			cb.ten = ten;
			cb.mk = mk;
			Nodecb* node = creatnode1(cb);
			addnodecb(l, node);
		}
		f.close();
		cout << "Mo file thanh cong\n";
	}
	else {
		cout << "Khong The mo file\n";
	}
	return l;
}
void addnodecb(ds& l, Nodecb* node) {
	if (l.head == nullptr) {
		l.head = node;
	}
	else {
		node->next = l.head;
		l.head = node;
	}
	
}
void doimk(ds& l,canbo v,string name) {
	int s;
	cout << "Nhap lai mk can doi \n";
	cin >> s;
	Nodecb* node = l.head;
	while (node != NULL) {
		if (node->data.ten.compare(v.ten)==0) {
			node->data.mk = s;
			break;
		}
		node = node->next;
	}
	ofstream f(name);
	if (f.is_open()) {
		Nodecb* temp = l.head;
		while (temp != nullptr) {
			f << temp->data.ten << " " << temp->data.mk << endl;
			temp = temp->next;
		}
		f.close();
		cout << "Doi mk thanh cong\n";
	}
	else {
		cout << "Khong The mo file\n";
	}
}

void menu() {
	cout << "           /////////////////           \n";
	cout << "0.Xem thong tin\n";
	cout << "1.Doi mk\n";
	cout << "2.Tao nam hoc, lop hoc, them hoc sinh\n";
	cout << "3.Nhap ds tu file\n";
	cout << "4.Tao hoc ki\n";
	cout << "5.Thoat\n";
	cout << "           ////////////////             \n";
}