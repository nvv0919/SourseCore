#include <bits/stdc++.h>

using namespace std;
class PHIEU;
class KHACHHANG
{
    char MAKH[10];
    char HOTEN[30];
    char NGAYBD[15];
    char NGAYKT[15];
public:
    void nhap();
    void xuat();
};
void KHACHHANG::nhap()
{
    cout<<"Nguoi lap: "; fflush(stdin);  cin.getline(MAKH, 10);
    cout<<"Ho ten   : "; fflush(stdin);  cin.getline(HOTEN, 30);
    cout<<"Tu ngay  : "; fflush(stdin);  cin.getline(NGAYBD, 15);
    cout<<"Den Ngay : "; fflush(stdin);  cin.getline(NGAYKT, 15);
}
void KHACHHANG::xuat()
{
    cout<<"Nguoi lap:   "<<MAKH<<"\t";     cout<<"Ho ten:   "<<HOTEN<<endl;
    cout<<"Tu ngay  :   "<<NGAYBD<<"\t";   cout<<"Den Ngay :    "<<NGAYKT<<endl;
}
class NHA
{
    char MAN[10];
    float DT;
    float GIA;
    char TT[20];
public:
    void nhap();
    void xuat();
    friend class PHIEU;
    friend void sapxep(PHIEU k);
    friend void sua(PHIEU k);
    friend void dem(PHIEU k);
};
void NHA::nhap()
{
    cout<<"Ma Can   : ";    fflush(stdin);  cin.getline(MAN, 10);
    cout<<"Dien tich: ";    cin>>DT;
    cout<<"Gia ban  : ";    cin>>GIA;
    cout<<"Tinh trang : ";  fflush(stdin); cin.getline(TT, 20);
}
void NHA::xuat()
{
    cout<<setw(10)<<MAN<<setw(30)<<DT<<setw(20)<<GIA<<setw(20)<<TT<<endl;
}
class PHIEU
{
    char MAP[10];
    char NGAYLAP[15];
    int n;
    KHACHHANG x;
    NHA *y;
public:
    void nhap();
    void xuat();
    friend void sapxep(PHIEU k);
    friend void sua(PHIEU k);
    friend void dem(PHIEU k);
};
void PHIEU::nhap()
{
    cout<<"Ma phieu : "; fflush(stdin); cin.getline(MAP, 10);
    cout<<"Ngay Lap : "; fflush(stdin); cin.getline(NGAYLAP, 15);
    x.nhap();
    cout<<"So can nha la n = ";
    cin>>n;
    y = new NHA[n];
    for(int i=0; i<n; i++)
        y[i].nhap();
}
void PHIEU::xuat()
{
    cout<<"TOA NHA MITE"<<endl;
    cout<<setw(30)<<"THONG KE TINH TRANG BAN"<<endl;
    cout<<"Ma phieu:    "<<MAP<<"\t";   cout<<"Ngay lap:    "<<NGAYLAP<<endl;
    x.xuat();
    cout<<setw(10)<<"Ma can"<<setw(30)<<"Dien tich"<<setw(20)<<"Gia Ban"<<setw(20)<<"Tinh Trang"<<endl;
    for(int i=0; i<n ; i++)
    {
		y[i].xuat();
    }
    float SUM=0;
    for(int i=0; i<n ; i++)
    {
        SUM+=y[i].GIA;
    }
    cout<<"\t"<<"Tong so can ho : "<<n<<".Tong gia ban: "<<SUM<<endl;
    cout<<setw(40)<<"TRUONG PHONG KD"<<setw(20)<<"NGUOI LAP"<<endl;
}
void sua(PHIEU k)
{
    for(int i=0; i<k.n; i++)
    if(strcmp(k.y[i].MAN, "C002")==0)
        k.y[i].GIA = 3400;
}
void sapxep(PHIEU k)
{
    float mid;
    for(int i=0; i<k.n; i++)
        for(int j=i+1; j<k.n; j++)
            if(k.y[i].GIA > k.y[j].GIA)
            {
                NHA mid = k.y[i];
                k.y[i]=k.y[j];
                k.y[j]=mid;
            }
}
void dem(PHIEU k)
{
    int dem=0;
    for(int i=0; i<k.n; i++)
    if(strcmp(k.y[i].TT, "da coc")==0)
        dem++;
    cout<<"So san da duoc coc la : "<<dem<<endl;
}
int main()
{
    PHIEU k;
    k.nhap();
    k.xuat();
    sua(k);
    sapxep(k);
    cout<<"Danh sach sau khi sap xep:"<<endl;
    k.xuat();
    dem(k);
}
