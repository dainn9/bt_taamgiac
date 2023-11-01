#include <iostream>
#include <math.h>
using namespace std;

int checkVT(int x, int y);
void xuat_Vt(int ck);


class Diem{
    float x = 0, y = 0;
    public:
        Diem(){;}
        Diem(int a, int b):x(a), y(b){}
        void setX(int a){x = a;}
        void setY(int b){y = b;}
        float getX() const {return x;}
        float getY()const {return y;}

        void nhap();
        void xuat();

        friend Diem operator-(const Diem& A, const Diem& B);
        // tinh khoang cach
        double kCach(const Diem& B);
        friend double fcvgb(const Diem& A, const Diem& B);
        // trung diem
        friend Diem ftrungDiem(const Diem& A, const Diem& B);
        Diem Tdiem(const Diem& A);
        // diem doi xung 
        Diem doiXung(const Diem& A);
        friend Diem Doixung(const Diem& A, const Diem& B);
        // Kiem tra trung nhau
        bool KTtrungnhau(const Diem& A);
        // Kiem tra diem thuoc phan tu nao
        void Vitri();



};

void Diem::nhap(){
    cin >> x >> y;
}

void Diem::xuat(){
    cout << "("<<x<<","<<y<<")";
}


void Diem::Vitri(){
    cout << "Diem ";
    this->xuat();
    xuat_Vt(checkVT(x, y));
}

Diem operator-(const Diem& A, const Diem& B){
    return Diem(A.x - B.x, A.y - B.y);
}

double Diem::kCach(const Diem& B){
    return sqrt(pow(x-B.x, 2) + pow(y-B.y, 2));
}

double Kcach(const Diem& A, const Diem& B)

Diem trungDiem(const Diem& A, const Diem& B);

Diem Tdiem(const Diem& A);
Diem doiXung(const Diem& A);
Diem Doixung(const Diem& A, const Diem& B)    
bool KTtrungnhau(const Diem& A){
    return (x == A.x && y == A.y);
}

int main(){
    
    Diem a;
    a.nhap();
    a.Vitri();

    system("pause");
    return 0;
}

// class TamGiac{
//     Diem A, B, C;
//     public:
//         TamGiac(){;}
//         TamGiac (Diem a, Diem b, Diem c) : A(a), B(b), C(c){}

//         double chuVi() {
//             return A.kCach(B) + B.kCach(C) + C.kCach(A);
//         }
//         // dien tich theo toa do 3 dinh
//         double dienTich(){
//             return abs((B.x - A.x)*(C.y - A.y)-(C.x - A.x)*(B.y - A.y));
//         }
//         // kiem tra co phai tam giac khong
//         bool checkTG(){
//              double a = A.kCach(B);
//             double b = B.kCach(C);
//             double c = C.kCach(A);

//             if (a + b > c && a + c > b && c + b > a && a > 0 && b > 0 && c > 0)
//                 return true;
//             return false;
//         }


// };


// class DanhSachTG{
//     int n;
//     Diem *p;
//     public:
//         DanhSachTG(){
//             n = 0;
//             p = nullptr;
//         }
//         DanhSachTG(int sl){
//             n = sl;
//             p = new Diem[n];
//         }
//         ~DanhSachTG(){
//             n = 0;
//             delete[] p;
//         }
//         double dienTich()
//         float 
//         void Nhap();

// };

int checkVT(int x, int y){
    if (x > 0 && y > 0)
        return 1;
    else if (x < 0 && y > 0)
        return 2;
    else if (x < 0 && y < 0)
        return 3;
    else if (x > 0 && y < 0)
        return 4;
    else if (x == 0 && y != 0)
        return 5;
    else if (x != 0 && y == 0)
        return 6;
    else return 0;
}
// xuat vi tri goc phan tu
void xuat_Vt(int ck){
    switch (ck)
    {
    case 1:
        cout << " thuoc goc phan tu thu I";
        break;
    case 2:
        cout << " thuoc goc phan tu thu II";
        break;
    case 3:
        cout << " thuoc goc phan tu thu III";
        break;
    case 4:
        cout << " thuoc goc phan tu thu IV";
        break;
    case 5:
        cout << " nam tren truc tung";
        break;
    case 6:
        cout << " nam tren truc hoanh";
        break;   
    default:
        cout <<" la goc toa do";
        break;
    }
}