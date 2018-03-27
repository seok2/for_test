//
//					달력 출력 프로그램  a07CalPrint
//
//	임의의 연월 입력시 달력을 출력하는 프로그램은 별도 실습할 예정
//
#include <iostream>
#include <iomanip>
using namespace std;
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
    cout<<"\n\n>> 문제 2. 날짜 수와 1일의 요일에 의한 달력\n";
    cout << "Input day count : ";
    cin >> month_date;
    cout << "Input Want 1일 : ";
    cin >> date;

    if(date ==6)
    {
        cout << "\t\t\t\t\t\t";
    }
    for(start_day=1; start_day<=month_date; start_day++)
    {
        if((start_day+date)%7==1)
        {
            cout << endl;
        }

        cout << "\t" <<setw(3) << start_day;
    }

//
// 문제 3.	주요 논리부(달력 출력부) 함수화
//				함수화 부분 : 달력의 Heading 포함(변수 값 입력부 제외)
//
last:
    cout<<"\n\n>> 문제 3. 문제 2의 달력 함수 처리\n";



    cout<<"\n>> 작업이 종료되었습니다 !\n\n";
}

