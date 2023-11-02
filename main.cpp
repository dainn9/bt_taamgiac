#include <iostream>
#include <math.h>
using namespace std;

int checkVT(int x, int y);
void Output_Vt(int ck);
void Output_TG(int ck);

class Point{
    float x = 0, y = 0;
    public:
        Point(){;}
        Point(int a, int b):x(a), y(b){}
        void setX(int a){x = a;}
        void setY(int b){y = b;}
        float getX() const {return x;}
        float getY()const {return y;}

        void Input();
        void Output();

        friend Point operator-(const Point& A, const Point& B);
        // tinh khoang cach
        double distance(const Point& B) const;
        friend double fdistance(const Point& A, const Point& B);
        // trung Point
        friend Point fmidPoint(const Point& A, const Point& B);
        Point midPoint(const Point& A) const;
        // Point doi xung qua goc toa do O, Ox, Oy
        Point symmetric_O() const;
        Point symmetric_Ox() const;
        Point symmetric_Oy() const;

        friend Point fsymmetric_O(const Point& A);
        friend Point fsymmetric_Ox(const Point& A);
        friend Point fsymmetric_Oy(const Point& A);

        // Kiem tra trung nhau
        bool check_overlap(const Point& A) const;
        // Kiem tra Point thuoc phan tu nao
        void Location();
};

int checkTG(const Point &A,const Point &B,const Point &C);

void Point::Input(){
    cout << "\nNhap toa do diem:\n";
    cin >> x >> y;
}

void Point::Output(){
    cout << "("<<x<<","<<y<<")\n";
}


void Point::Location(){
    cout << "Point ";
    this->Output();
    Output_Vt(checkVT(x, y));
}

Point operator-(const Point& A, const Point& B){
    return Point(A.x - B.x, A.y - B.y);
}

double Point::distance(const Point& B) const {
    return sqrt(pow(x-B.getX(), 2) + pow(y-B.getY(), 2));
}

double fdistance(const Point& A, const Point& B){
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y,2));
}

Point fmidPoint(const Point& A, const Point& B){
    Point C;
    C.setX((A.x + B.x) / 2);
    C.setY((A.y + B.y) / 2);
    return C;
}

Point Point::midPoint(const Point& A) const{
    Point C;
    C.setX((x + A.x) / 2);
    C.setY((y + A.y) / 2);
    return C;
}
Point Point::symmetric_O() const{
    Point C(0-x, 0-y);
    return C;
}

Point Point::symmetric_Ox() const{
    Point C(x, 0-y);
    return C;
}

Point Point::symmetric_Oy() const{
    Point C(0-x, y);
    return C;
}

Point fsymmetric_O(const Point& A){
    Point C(0-A.getX(), 0-A.getY());
    return C;
}
Point fsymmetric_Ox(const Point& A){
    Point C(A.getX(), 0-A.getY());
    return C;
}

Point fsymmetric_Oy(const Point& A){
    Point C(0-A.getX(), A.getY());
    return C;
}

bool Point::check_overlap(const Point& A) const{
    return (x == A.x && y == A.y);
}

class Triangle : public Point{
    Point A, B, C;
    public:
        Triangle(){;}
        Triangle (Point a, Point b, Point c) : A(a), B(b), C(c){}

        bool isTriangle() const;
        void distance_R() const;
        double perimeter() const;
        friend double fperimeter(const Point &a,const Point &b,const Point &c);
        // dien tich theo toa do 3 dinh
        double area() const;
        friend double farea(const Point &a,const Point &b,const Point &c);
        // nhap diem la thuoc tinh ke thua cua Point
        void Input_P();
        void Output_P();
        // nhap 3 diem thuoc tinh cua Triangle
        void Input_T();
        void Output_T();
        void checkT();

};

bool Triangle::isTriangle() const{
    double a = A.distance(B);
    double b = B.distance(C);
    double c = C.distance(A);

    if (a + b > c && a + c > b && c + b > a && a > 0 && b > 0 && c > 0)
        return true;
    return false;
}

void Triangle::distance_R() const{
    if (isTriangle() == false){
        cout << "Khong phai tam giac\n";
        return;
    } else {
        double a = A.distance(B);
        double b = B.distance(C);
        double c = C.distance(A);
        cout << "Do dai 3 canh tam giac:\n";
        cout << a << " " << b << " " << c << endl;
    }
}


double Triangle::perimeter() const{
    if (isTriangle() == false){
        cout << "Khong phai tam giac\n";
        return 0;
    } else 
        return A.distance(B) + B.distance(C) + C.distance(A);
}

double fperimeter(const Point &a,const Point &b,const Point &c){
    Triangle t(a,b,c);
    return t.perimeter();
}

double Triangle::area() const{
    if (isTriangle() == false){
        cout << "Khong phai tam giac\n";
        return 0;
    } else 
        return (1.0/2)*abs((B.getX() - A.getX())*(C.getY() - A.getY())-(C.getX() - A.getX())*(B.getY() - A.getY()));
}

double farea(const Point &a,const Point &b,const Point &c){
   Triangle t(a,b,c);
   return t.area();
}

void Triangle::Input_P(){
    Point::Input();
}
void Triangle::Output_P(){
    Point::Output();
}

void Triangle::Output_T(){
    cout << "Toa do 3 diem tam giac vua nhap:\n";
    A.Output(); B.Output(); C.Output();
}

void Triangle::Input_T(){
    cout << "\nNhap toa do 3 diem cua tam giac:\n";
    A.Input(); B.Input(); C.Input();
}

void Triangle::checkT(){
    if (isTriangle() == false){
        cout << "Khong phai tam giac\n";
        return;
    } else 
        Output_TG(checkTG(A, B, C));
    
}

int main(){
    Point a(2,3), b(4,3), c(3,5);
//    int i = checkTG(a, b, c);
//    Output_TG(i);
    // int n; cin >> n;
    // Triangle *t = new Triangle[n];
    // for (int i = 0; i < n; i++){
    //     t[i].Input_P();
    //     t[i].Output_P();
    // }

    // Triangle t;
    // t.Input_T();
    // t.Output_T();
    system("pause");
    return 0;
}

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
// Output vi tri goc phan tu
void Output_Vt(int ck){
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

int checkTG(const Point &A,const Point &B,const Point &C){
    double a = A.distance(B);
    double b = A.distance(C);
    double c = B.distance(C);
    if (a == b && a == c && b == c)
        return 3;
    else if ((a == b && a != c) || (b == c && b != a) || (a == c && a != b))
        return 2;
    else if ((pow(a,2) == pow(b,2)+pow(c,2)) || (pow(c,2) == pow(b,2)+pow(a,2)) || (pow(b,2) == pow(a,2)+pow(c,2)))
        return 4;
    else
        return 1;
}

void Output_TG(int ck){
    switch (ck)
    {
    case 1:
        cout <<"Tam giac thuong\n";
        break;
    case 2:
        cout <<"Tam giac can\n";
        break;
    case 3:
        cout <<"Tam giac deu\n";
        break;
    case 4:
        cout <<"Tam giac vuong\n";
        break;
    }
}