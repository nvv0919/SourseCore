#include <bits/stdc++.h>

using namespace std;

class VECTO
{
    float x,y,z;
public:
    VECTO();
    VECTO(float a, float b, float c);
    friend istream& operator>>(istream& k, VECTO& h);
    friend ostream& operator<<(ostream& k, VECTO h);
    bool operator-(VECTO a);
    float operator!();
};
VECTO::VECTO()
{
    x = y = z = 0;
}
VECTO::VECTO(float a, float b, float c)
{
    x = a;
    y = b;
    z = c;
}
istream& operator>>(istream& k, VECTO& h)
{
    cout<<"Nhap x = ";  k>>h.x;
    cout<<"Nhap y = ";  k>>h.y;
    cout<<"Nhap z = ";  k>>h.z;
    return k;
}
ostream& operator<<(ostream& k, VECTO h)
{
    k<<"("<<h.x<<","<<h.y<<","<<h.z<<")";
    return k;
}
bool VECTO::operator-(VECTO a)
{
    if(x == a.x && y == a.y && z == a.z)
        return true;
    return false;
}
float VECTO::operator!()
{
    float max = x;
    if(max <= y)
    {
        max = y;
    }
    if(max <= z)
    {
        max = z;
    }
    return max;
}
int main()
{
    VECTO A,B;

    cout<<"Nhap vecto A :"<<endl;       cin>>A;
    cout<<"Vecto A  : "<<A<<endl;
    cout << "Gia tri lon nhat trong 3 thuoc tinh cua Vector A : "<<!A<<endl;

    cout<<"Nhap vecto B :"<<endl;       cin>>B;
    cout<<"Vecto B  : "<<B<<endl;
    cout << "Gia tri lon nhat trong 3 thuoc tinh cua Vector B : "<<!B<<endl;

    if((A-B) == true)
        cout<<"Toan bo cac thuoc tinh bang nhau"<<endl;
    else
        cout<<"Khong phai toan bo thuoc tinh bang nhau"<<endl;

    ofstream f("VECTO.txt", ios::out);
    f<<"Vecto A:"<<A<<endl;
    f<<"Gia tri lon nhat cua Vector A: "<<!A<<endl;
    f<<"Vecto B:"<<B<<endl;
    f<<"Gia tri lon nhat cua Vector B: "<<!B<<endl;
    if((A-B) == true)
        f<<"Toan bo cac thuoc tinh bang nhau"<<endl;
    else
        f<<"Khong phai toan bo thuoc tinh bang nhau"<<endl;
    f.close();

    return 0;
}
