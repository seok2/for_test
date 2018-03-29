//
//					달력 출력 프로그램  a07CalPrint
//
//	임의의 연월 입력시 달력을 출력하는 프로그램은 별도 실습할 예정
//
#include <iostream>
#include <iomanip>
using namespace std;

void calender(int x, int y)
{
    int z;
    if(y==1)
    {
        cout << "\t";
    }
    else if(y==2)
    {
        cout << "\t\t";
    }
    else if(y==3)
    {
        cout << "\t\t\t";
    }
    else if(y==4)
    {
        cout << "\t\t\t\t";
    }
    else if(y==5)
    {
        cout << "\t\t\t\t\t";
    }

    else if(y==6)
    {
        cout << "\t\t\t\t\t\t";
    }
    for(z=1; z<=x; z++)
    {

        if((z+y)%7==1)
        {
            cout << endl;
        }
        cout << "\t" <<setw(3) << z;
    }
}

int main()
{
    int start_day; // 해당 월의 1일자 요일 값 저장(일요일 0  월요일 1  화요일 2 .... )
    int	month_date; // 해당 월의 날짜 수 저장
    int	day, date;  // 작업용 변수

//
// 문제 1.	1일이 수요일이고 월의 날짜 수가 31일인 달력 출력
//
    cout<<">> 문제 1. 1일이 수요일이고 월의 날짜 수가 31일인 달력\n\n";
    cout << "\t" << "sun" << "\t" << "mon" << "\t" << "tue" << "\t" << "wed" << "\t" << "thu" << "\t" << "fri" << "\t" << "sat" << endl;
    for(start_day=1; start_day<=31; start_day++)
    {
        if(start_day%7==5)
        {
            cout << endl;
        }
        else if(start_day==1)
        {
            cout << "\t\t\t";
        }
       cout << "\t" <<setw(3) << start_day;
    }

//
// 문제 2.	월의 날짜 수와 1일의 요일을 입력받아 달력 출력
//				월 : 1 - 12월
//				1일의 요일 : 일요일 0,  월요일 1,  화요일 2,  수요일 3,  ....
//

    cout<<"\n\n>> 문제 2. 날짜 수와 1일의 요일에 의한 달력\n" << endl;
    while(1)
    {
    cout << "Input day count(input 0 -> quit) : ";
    cin >> month_date;
        if(month_date==0)
        {
            break;
        }
    cout << "Input Want 1일 : ";
    cin >> date;
    cout << endl;

    if(date == 6)
    {
        cout << "\t\t\t\t\t\t";
    }
    else if(date == 5)
    {
        cout << "\t\t\t\t\t";
    }
    else if(date == 4)
    {
        cout << "\t\t\t\t";
    }
    else if(date == 3)
    {
        cout << "\t\t\t";
    }
    else if(date == 2)
    {
        cout << "\t\t";
    }
    else if(date == 1)
    {
        cout << "\t";
    }
    for(start_day=1; start_day<=month_date; start_day++)
    {
        if((start_day+date)%7==1)
        {
            cout << endl;
        }

        cout << "\t" <<setw(3) << start_day;
    }
    cout << endl;
  }

//
// 문제 3.	주요 논리부(달력 출력부) 함수화
//				함수화 부분 : 달력의 Heading 포함(변수 값 입력부 제외)
//
    cout<<"\n\n>> 문제 3. 문제 2의 달력 함수 처리\n";
    while(1)
    {
    cout << "input want day count(input 0 -> quit) : ";
    cin >> start_day;
    if(start_day==0)
    {
        cout<<"\n>> 작업이 종료되었습니다 !\n\n";
        break;
    }
    cout << "input day 0 ~ 6 : ";
    cin >> month_date;
    calender(start_day, month_date);
    cout << endl;
    }
}

