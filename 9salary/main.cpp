//
//					복잡한 수학적 계산 프로그램  a09SalaryCalc
//

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int		i, salary, salary_save, annual_salary, total_salary;	// 변수는 적절히 사용	가능
    float	salary_rate, inc_salary;								// 변수는 적절히 사용 가능
//
// 10년간 월급 증액 및 연봉을 계산하는 프로그램
//
//
    cout << "Input your 1month money (quit 0): ";
    cin >> salary;
    annual_salary = salary * 12;
    total_salary = annual_salary * 10;
    cout << "문제 1 : 10년간 월급액이 고정될 경우 10년간 봉급 총액 계산" << endl;
    cout << "money " << salary << "won" << endl;
    cout << "1year money " << annual_salary << "won, " << "10year money " << total_salary << "won" << endl;

    cout << "++ 1month money : ";
    cin >> inc_salary;

    total_salary = 0;
    total_salary = total_salary + (salary*12);

    salary_save = salary;

    annual_salary = salary;

    cout << "문제 2 : 월급이 매년 일정 %로 증액될 경우 매년 연봉 및 10년간 봉급 총액 계산" << endl;

    for(i=1; i<10; i++)
    {
        salary_save = salary_save + salary_save*(inc_salary/100);
        annual_salary = salary_save * 12;
        total_salary = total_salary + annual_salary;
        cout << i << "after " << "1month money " << salary_save << "won     1year money " << annual_salary << "won" << endl;
    }
//              월급의 증액분중 소숫점 이하는 절상(필요한 경우 함수 활용 권장)
//

    cout << "first money = " << salary << " and ++money rate = " << inc_salary << " then total money = " << total_salary << "won";

    cout<<"\n\n>> 작업이 종료되었습니다 !\n\n";
}
