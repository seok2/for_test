//
//		나머지 연산자 응용 프로그램(시간 변환 프로그램)  a06TimeCalc
//
#include <iostream>
#include <iomanip>
using namespace std;

#define SEC_PER_MINUTE 60	// 1분 = 60초

int main()
{
    int input;												// 초 단위 입력 값
    int second, minute, hour, day, year, namuji;	// 초, 분, 시간, 일, 연을 표현하는 변수

//
// 문제 :	초 단위 시간을 입력받아 분 -> 시간 -> 일 -> 월 -> 연을 계산하여
//				XXXXX초는 A년 B월 C일 D시간 E분 F초 입니다와 같이 출력
//				각 단위 값이 0인 경우 출력 생략하고 1년은 365일로 고정

    cout<<"\n>> 초단위의 시간을 입력하시요( 2147483647초 이하, 종료 <= 0 ) ? ";
    cin >> input;
    cout << input << "초 = " << input << "초" << endl;

    cout<<"\n>> 초단위의 시간을 입력하시요( 2147483647초 이하, 종료 <= 0 ) ? ";
    cin >> input;
    minute = (input / 60);
    cout << input << "초 = " << minute << "bun" << endl;

    cout<<"\n>> 초단위의 시간을 입력하시요( 2147483647초 이하, 종료 <= 0 ) ? ";
    cin >> input;
    hour = input /3600 ;
    cout << input << "초 = " << hour << "hour" << endl;

    cout<<"\n>> 초단위의 시간을 입력하시요( 2147483647초 이하, 종료 <= 0 ) ? ";
    cin >> input;
    day = input / 24 / 3600 ;
    cout << input << "초 = " << day << "day" << endl;

    cout<<"\n>> 초단위의 시간을 입력하시요( 2147483647초 이하, 종료 <= 0 ) ? ";
    cin >> input;
    day = input / 24 / 3600;
    namuji = input % 60;
    cout << input << "초 = " << day << "day" << namuji <<endl;

    cout<<"\n>> 초단위의 시간을 입력하시요( 2147483647초 이하, 종료 <= 0 ) ? ";
    cin >> input;
    day = input / 24 / 3600;
    namuji = input % 60;
    cout << input << "초 = " << day << "day" << namuji <<endl;

    cout<<"\n>> 초단위의 시간을 입력하시요( 2147483647초 이하, 종료 <= 0 ) ? ";
    cin >> input;
    year = input / (365 * 24 * 60 * 60);
    day = (input % (365 * 24 * 60 * 60)) / (24 * 60 * 60);
    hour = ((input % (365 * 24 * 60 * 60)) % (24 * 60 * 60)) / (60 * 60);
    minute = (((input % (365 * 24 * 60 * 60)) % (24 * 60 * 60)) % (60 * 60) / 60);
    second = (((input % (365 * 24 * 60 * 60)) % (24 * 60 * 60)) % (60 * 60) % 60);

    cout << input << "초 = " << year << "year " << day << "il " << minute << "bun " << second << "cho " <<endl;
    cout<<"\n>> 작업이 완료되었습니다 !\n\n";

}
