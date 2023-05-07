#include <bits/stdc++.h>

using namespace std;
class GIANHANG;
class HANG
{
protected:
    char MAPT[10];
    char LOAI[10];
    int NAMSX;
    char HANGSX[20];
public:
    void nhap();
    void xuat();
};
void HANG::nhap()
{
    cout<<"Ma PT   : "; fflush(stdin);    cin.getline(MAPT, 10);
    cout<<"Loai    : "; fflush(stdin);    cin.getline(LOAI, 10);
    cout<<"Nam SX  : "; cin>>NAMSX;
    cout<<"HANG SX : "; fflush(stdin);  cin.getline(HANGSX, 20);
}
void HANG::xuat()
{
    cout<<setw(10)<<MAPT<<setw(10)<<LOAI<<setw(10)<<NAMSX<<setw(20)<<HANGSX;
}
class HOP : public HANG
{
    char KIEU[20];
    char CHATLIEU[20];
    float V;
    char GHICHU[20];
public:
    void nhap();
    void xuat();
    friend void sapxep(GIANHANG k);
};
void HOP::nhap()
{
    HANG::nhap();
    cout<<"Kieu dang : ";   fflush(stdin);  cin.getline(KIEU, 20);
    cout<<"Chat lieu : ";   fflush(stdin);  cin.getline(CHATLIEU, 20);
    cout<<"The tich  : ";   cin>>V;
    cout<<"Ghi chu   : ";   fflush(stdin);  cin.getline(GHICHU, 20);
}
void HOP::xuat()
{
    HANG::xuat();
    cout<<setw(20)<<KIEU<<setw(20)<<CHATLIEU<<setw(10)<<V<<setw(20)<<GHICHU<<endl;
}
class GIANHANG
{
    char MAGH[10];
    char TENGH[20];
    float S;
    HOP *x;
    int n;
public:
    void nhap();
    void xuat();
    friend void sua(GIANHANG &k);
    friend void sapxep(GIANHANG k);
};
void GIANHANG::nhap()
{
    cout<<"Ma gian hang  : ";   fflush(stdin);   cin.getline(MAGH, 10);
    cout<<"Ten gian hang : ";   fflush(stdin); cin.getline(TENGH, 20);
    cout<<"Nhap so mat hang n = ";  cin>>n;
    x=new HOP[n];
    for(int i=0; i<n; i++)
        x[i].nhap();
}
void GIANHANG::xuat()
{
    cout<<"Ma gian hang  : "<<MAGH<<endl;
    cout<<"Ten gian hang : "<<TENGH<<endl;
    cout<<setw(10)<<"MAPT"<<setw(10)<<"LOAI"<<setw(10)<<"NAMSX"<<setw(20)<<"HANGSX"<<setw(20)<<"KIEU DANG"<<setw(20)<<"CHAT LIEU"<<setw(10)<<"The tich"<<setw(20)<<"GHI CHU"<<endl;
    for(int i=0; i<n; i++)
        x[i].xuat();
}
void sua(GIANHANG &k)
{
    strcpy(k.TENGH, "DO NHUA");
}
void sapxep(GIANHANG k)
{
    float mid;
    for(int i=0; i<k.n; i++)
        for(int j=i+1; j<k.n; j++)
            if(k.x[i].V < k.x[j].V)
            {
                HOP mid = k.x[i];
                k.x[i]=k.x[j];
                k.x[j]=mid;
            }
}
int main()
{
    GIANHANG k;
    k.nhap();
    k.xuat();
    sua(k);
    sapxep(k);
    cout<<"Danh sach sau khi sap xep va sua :"<<endl;
    k.xuat();
}
