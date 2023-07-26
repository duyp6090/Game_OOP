#include<iostream>
#include<iomanip>
#include"mylib.h"

using namespace std;

int sl = 10;
void ve_tuong_tren();
void ve_tuong_duoi();
void ve_tuong_trai();
void ve_tuong_phai();
void ve_tuong();
void khoi_tao_ran(int toadox[], int toadoy[]);
void ve_ran(int toadox[], int toadoy[]);
void xu_li_ran(int toadox[], int toadoy[],int,int,int);
void xoa_du_lieu(int toadox[], int toadoy[]);
bool kiem_tra_tram_tuong(int, int);
bool kiem_tra_ran_tu_huy(int toadox[], int toadoy[], int, int);
void them(int a[], int );
void xoa(int a[], int );
void tao_qua(int&, int&,int a[],int b[]);
bool ran_de_qua(int toadox[], int toadoy[], int , int );
void tang_chieu_dai_ran(int toadox[], int toadoy[]);

int main() {
	srand(time(NULL));
	int xqua=11, yqua=3;
	int toadox[100], toadoy[100];
	ve_tuong();
	khoi_tao_ran(toadox, toadoy);
	ve_ran(toadox, toadoy);
	int x = 50, y = 13;// dinh hinh vi tri ran can di chuyen
	int check = 2;
	tao_qua(xqua, yqua,toadox,toadoy);
	while (true) {
		// 0: tram tren va di xuong duoi
		// 1:tram duoi va di len
		// 2: tram trai di qua phai
		//3: tram phai va di qua trai
		
		// ========dieu khien cua nguoi dung
		if (_kbhit()) {
			char kitu = _getch();
			if (kitu == -32) {
				kitu = _getch();
				if (kitu == 72) {
					//di len
					if(check!=0) check = 1;
				}
				else if (kitu == 80) {
					//di xuong
					if(check!=1) check = 0;
				}
				else if (kitu == 77) {
					// di phai
					if(check!=3) check = 2;
				}
				else if (kitu == 75) {
					// di trai
					if(check!=2) check = 3;
				}
			}
		}
		//=========thuc hien di chuyen=========
		if (check == 0) {
			y++;
		}
		else if (check == 1) {
			y--;
		}
		else if (check == 2) {
			x++;
		}
		else x--;
		xoa_du_lieu(toadox, toadoy);
		int ok = 0;
		if (x == xqua && y == yqua) {
			// sau khi an thi phai tao qua
			tao_qua(xqua, yqua,toadox,toadoy);
			ok = 1;
		}
		xu_li_ran(toadox, toadoy, x, y,ok);
		//================kiem tra game over hay khong==============
		if(kiem_tra_tram_tuong(x, y) || kiem_tra_ran_tu_huy(toadox, toadoy, x, y)) break;
		Sleep(300);
	}
	_getch();
	return 0;
}

void ve_tuong_tren() {
	int x = 10, y = 1;
	while (x < 100) {
		gotoXY(x, y);
		cout << "+";
		x++;
	}
}

void ve_tuong_duoi() {
	int x = 10, y = 26;
	while (x < 100) {
		gotoXY(x, y);
		cout << "+";
		x++;
	}
}

void ve_tuong_phai() {
	int x = 100, y = 1;
	while (y < 26) {
		gotoXY(x, y);
		cout << "+";
		y++;
	}
}

void ve_tuong_trai() {
	int x = 10, y = 1;
	while (y < 26) {
		gotoXY(x, y);
		cout << "+";
		y++;
	}
}

void ve_tuong() {
	SetColor(11);
	ve_tuong_tren();
	ve_tuong_duoi();
	ve_tuong_trai();
	ve_tuong_phai();
	SetColor(7);
}

void khoi_tao_ran(int toadox[], int toadoy[]) {
	int x = 50, y = 13;
	for (int i = 0; i < sl; i++) {
		toadox[i] = x;
		x--;
		toadoy[i] = y;
	}
}

void ve_ran(int toadox[],int toadoy[]) {
	for (int i = 0; i < sl; i++) {
		gotoXY(toadox[i], toadoy[i]);
		if (i == 0) cout << "0";
		else cout << "o";
	}
}

void them(int a[],int x) {
	for (int i = sl; i > 0; i--) {
		a[i] = a[i - 1];
	}
	a[0] = x;
	sl++;
}

void xoa(int a[],int vt) {
	for (int i = vt; i < sl; i++) {
		a[i] = a[i + 1]; 
	}
	sl--;
}

void xu_li_ran(int toadox[],int toadoy[],int x,int y,int ok) {
	// them toa do moi vao dau mang
	them(toadox, x);
	them(toadoy, y);
	// xoa toa do cuoi mang
	if (!ok) {
		xoa(toadox, sl - 1);
		xoa(toadoy, sl - 1);
	}
	ve_ran(toadox, toadoy);
}

void xoa_du_lieu(int toadox[], int toadoy[]) {
	for (int i = 0; i < sl; i++) {
		gotoXY(toadox[i], toadoy[i]);
		cout << " ";
	}
}

bool kiem_tra_tram_tuong(int x0,int y0) {
	if (x0 == 10 || x0 == 100 || y0 == 1 || y0 == 26) return true;
	return false;
}

bool kiem_tra_ran_tu_huy(int toadox[],int toadoy[],int x, int y) {
	for (int i = 1; i < sl; i++) {
		if (toadox[i] == x && toadoy[i] == y) return true;
	 }
	return false;
}

void tao_qua(int& xqua,int& yqua,int toadox[],int toadoy[]) {
	do {
		xqua = rand() % (89) + 11;
		yqua = rand() % (24) + 2;
	} while (ran_de_qua(toadox, toadoy, xqua, yqua)==true);
	int i = rand() % (15-1+1) + 1;
	SetColor(i);
	gotoXY(xqua, yqua);
	cout << "@";
	SetColor(7);
}

bool ran_de_qua(int toadox[], int toadoy[],int xqua,int yqua) {
	for (int i = 0; i < sl; i++) {
		if (xqua == toadox[i] && yqua == toadoy[i]) {
			return true;
		}
	}
	return false;
}

void tang_chieu_dai_ran(int toadox[], int toadoy[]) {
	int x1 = toadox[sl - 1];
	int y1 = toadoy[sl - 1];
	if (y1 - 1 > 1 && y1 - 1 != toadoy[sl - 2]) {
		y1--;
		them(toadox, x1);
		them(toadoy, y1);
	}
	else {
		y1++;
		them(toadox, x1);
		them(toadoy, y1);
	}
	//ve_ran(toadox, toadoy);
}