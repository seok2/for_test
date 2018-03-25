//
//		원 및 사각형의 면적 등을 계산하는 프로그램  a04CircleRect
//
#include <iostream>
#include <iomanip>
#include <cmath>
#define	PI  3.141592
using namespace std;

int oneline(int x)
{
    int jungop, jungdul;
    jungop = x*x;
    jungdul = (x+x)*2;
    cout << "\t" << "면적 : " << jungop << endl;
    cout << "\t" << "둘레 : " << jungdul << endl;
}

int twoline(int x, int y)
{
    int tjungop, tjungdul;
    tjungop = x*y;
    tjungdul = (x+y)*2;
    cout << "\t" << "면적 : " << tjungop << endl;
    cout << "\t" << "둘레 : " << tjungdul<< endl;
}

double circle(double x)
{
    double circmyun, circdul;
    circmyun = x * x * PI;
    circdul = 2 * PI * x;
    cout << "\t" << "면적 : " << circmyun << endl;
    cout << "\t" << "둘레 : " << circdul << endl;
}

double mixcal(double x, double y)
{
    double myun;
    myun = sqrt((double) x * y);
    cout << "\t" << "One Myun : " << myun << endl;
}

double mixcircle(double x, double y)
{
    double Mcir_radi, Dcri_radi;
    Mcir_radi = sqrt((double) x * y / PI);
    Dcri_radi = ((x+y)/ PI);
    cout << "\t" << "One Myun : " << Mcir_radi << endl;
    cout << "\t" << "One Myun : " << Dcri_radi << endl;
}

double OneCal(double x)
{
    double One_Pyo, One_Bupy, gong;
    gong = 4.0/3.0;
    One_Pyo = 4 * PI * x * x;
    One_Bupy = ( gong * PI * x * x * x);
    cout << "\t" << "OnePyo : " << One_Pyo << endl;
    cout << "\t" << "OneBupy : " << One_Bupy << endl;
}

int main()
{
    int line1, line2, radius;		// 사각형 및 원의 길이와 반지름 변수
    double ans;

// 공통사항	길이 또는 반지름의 입력 값(##)은 최대 2자리 정수로 가정
//					길이 또는 반지름의 단위는 cm로 간주

// 문제 1.	정사각형과 직사각형의 면적 및 둘레 계산
//				면적 및 둘레를 계산할 때 함수 사용(특히 함수 오버로딩을 추천)
//

    cout<<"\n>> 문제 1. 사각형의 면적 및 둘레 계산 " << endl;

    while(true)
    {
        cout << "\t" << "정사각형의 면적 및 둘레 계산(0->next~) : ";
        cin >> line1;
        if(line1==0)
        {
            break;
        }
        oneline(line1);

        cout << "\t" << "직사각형의 면적 및 둘레 계산(00->next~) : ";
        cin >> line1 >> line2;
        if(line1==0 && line2==0)
        {
            break;
        }
        twoline(line1, line2);

     }
// 문제 2. 원의 면적 및 둘레 계산
    cout<<"\n>> 문제 2. 원의 면적 및 들레 계산\n";

    while(true)
    {

        cout << "\t" << "원 반지름의 입력 값(0->next~) : ";
        cin >> ans;
        if(ans==0)
        {
            break;
        }
        circle(ans);
     }

// 문제 3.	사각형과 원의 면적 및 둘레 비교
//				주어진 직사각형과 동일한 면적의 정사각형의 한변의 길이 계산
//				주어진 직사각형과 동일한 면적의 원의 반지름 계산
//				주어진 직사각형과 동일한 둘레의 원의 반지름 계산
    cout<<"\n>> 문제 3. 사각형과 원의 면적 및 둘레 비교\n";

    while(1)
    {

    cout << "\t" << "직사각형과 동일한 면적의 정사각형의 한변의 길이(0 0->next~) : ";
    cin >> line1 >> line2;
    if(line1 == 0 && line2 == 0)
    {
        break;
    }
    mixcal(line1, line2);
    mixcircle(line1, line2);

    }

// 문제 4.	아래 공식과 문제 2의 함수를 활용하여 구의 표면적과 부피를 계산
//				구의 표면적 = 4*PI*r*r,   구의 부피 = 4/3*PI*r*r*r   (r은 반지름)
//				구의 표면적 계산시 원의 둘레 계산 함수 사용
//				구의 부피 계산시 원의 면적 계산 함수 사용
//
    cout<<"\n>> 문제 4. 구의 표면적 및 부피 계산\n";

    while(1)
    {
    cout << "\t" << ">> input Radius(0->next~) : ";
    cin >> ans;
    if(ans == 0)
    {
        break;
    }

    OneCal(ans);

    }
    cout<<"\n>> 작업이 완료되었습니다 !\n\n";

}
