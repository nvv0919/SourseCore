#include <bits/stdc++.h>

using namespace std;
class TUGIAC
{
    float a,b,c,d;
public:
    TUGIAC();
    TUGIAC(float x, float y, float z, float t);
    float operator++();
    TUGIAC operator+(TUGIAC y);
    friend istream& operator>>(istream& x, TUGIAC& y);
    friend ostream& operator<<(ostream& x, TUGIAC y);
    bool operator!();
};
TUGIAC::TUGIAC()
{
    a=b=c=d=0;
}
TUGIAC::TUGIAC(float x, float y, float z, float t)
{
    a = x;
    b = y;
    c = z;
    d = t;
}
TUGIAC TUGIAC::operator+(TUGIAC y)
{
    TUGIAC k;
    k.a=a + y.a;
    k.b=b + y.b;
    k.c=c + y.c;
    k.d=d + y.d;
    return k;
}
istream& operator>>(istream& x, TUGIAC& y)
{
    cout<<"a = ";   x>>y.a;
    cout<<"b = ";   x>>y.b;
    cout<<"c = ";   x>>y.c;
    cout<<"d = ";   x>>y.d;
    return x;
}
ostream& operator<<(ostream& x, TUGIAC y)
{
    x<<"a = "<<y.a<<endl;
    x<<"b = "<<y.b<<endl;
    x<<"c = "<<y.c<<endl;
    x<<"d = "<<y.d<<endl;
    return x;
}
float TUGIAC::operator++()
{
    return (a+b+c+d)/2;
}
bool TUGIAC::operator!()
{
    if(a == b && b == c && c == d)
        return true;
    return false;
}
int main()
{
    TUGIAC A,B;
    cout<<"Nhap thong tin tu giac A:"<<endl;
    cin>>A;
    cout<< "Nua chu vi cua tu giac A: "<<++A<<endl;
    cout<<"Nhap thong tin tu giac B:"<<endl;
    cin>>B;
    cout<< "Nua chu vi cua tu giac B: "<<++B<<endl;
    cout<<"Thong tin tu giac A:"<<endl;
    cout<<A;
    cout<<"Thong tin tu giac B:"<<endl;
    cout<<B;
    if(!A == true)
        cout<<"A la tu giac co 4 canh bang nhau"<<endl;
    else if(!B == true)
        cout<<"B la tu giac co 4 canh bang nhau"<<endl;
    else
        cout<<"Khong co tu giac co 4 canh bang nhau"<<endl;

    TUGIAC C = A + B;
    ofstream f("TUGIAC13.txt", ios::app);
    f<<"Thong tin tu giac A:"<<endl;
    f<<A;
    f<< "Nua chu vi cua tu giac A: "<<++A<<endl;
    f<<"Thong tin tu giac B:"<<endl;
    f<<B;
    f<<"Nua chu vi cua tu giac B: "<<++B<<endl;
    f<<"Thong tin tu giac C:"<<endl;
    f<<C;
    f<<"Nua chu vi cua tu giac C: "<<++C<<endl;
    if(!A == true)
        f<<"A la tu giac co 4 canh bang nhau"<<endl;
    else if(!B == true)
        f<<"B la tu giac co 4 canh bang nhau"<<endl;
    else
        f<<"Khong co tu giac co 4 canh bang nhau"<<endl;
    f.close();
    return 0;
}
