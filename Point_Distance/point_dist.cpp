#include <iostream>
#include <math.h>
using namespace std;

struct Point
{
    int x, y;  
};

class dayso
{
    public:
        int n;
        Point* pp = new Point;
        void nhap();
        float khoangcach(int i, int j);
};

void dayso::nhap()
{
    cout << "Num of points: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "Point " << i << ": ";
        cin >> pp[i].x >> pp[i].y;
    }
}

float dayso::khoangcach(int i, int j)
{
    return sqrt(pow(pp[i].x - pp[j].x, 2) + pow(pp[i].y - pp[j].y, 2));
}

ostream& operator<<(ostream& os, Point& p)
{
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

int main()
{
    dayso ds;
    ds.nhap();
    int n = ds.n;
    int iMax, jMax;
    float dMax = 0.0;
    for (int i = 1; i <= n - 1; ++i)
        for (int j = 1; j <= n; ++j)
        {
            float d = ds.khoangcach(i, j);
            if (d > dMax)
            {
                dMax = d;
                iMax = i;
                jMax = j;
            }
        }
    cout << "Max distance: " << dMax << endl;
    cout << "2 Points have max distance: " << ds.pp[iMax] << " " << ds.pp[jMax];
    return 0;
}
