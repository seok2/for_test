//
//		자료 항목별 문자열 추출 프로그램   a07DataExtract
//
//      string 함수 : 쉽게 풀어쓴 C언어 Express 강의록 12장 참조
//
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    char		buff[]=
                "12345678:홍길동:충남 금산 추부 마전리:010-1234-1234:abcd@joongbu.ac.kr:";
    int numout = 0;
    int other = 0;
    int fronarray = 0;
    int backarray = 0;
    char name[5][80];
//
// 문제 1.	문자열 buff[]에 저장된 자료에서 구분자(:)로 분리된 각 항목의 자료를 추출,
//				추출한 자료와 buff[]에 남은 자료를 순서대로 출력
//				- 추출한 자료는 별도의 변수에 저장하여 문제 2에서 활용
//				- buff[] 자료는 추출한 부분을 제외하고 남은 부분만 재저장
//
    cout << ">> 원본 자료\n" << buff << endl;
    cout << "\n\n>> 문제 1. 항목별 자료 추출" << endl;

    while(true)
    {
        cout << numout+1 << "output : ";
        while(true)
        {
            if(buff[backarray] == ':')
            {
                name[numout][fronarray];
                backarray++;
                break;
            }
        name[numout][fronarray] = buff[backarray];
        cout << buff[backarray++];
        fronarray++;
        }

    other=backarray;

    if(buff[backarray]==NULL)
    {
        break;
    }

    cout << endl << "남은 자료 : ";
    while(buff[backarray] != NULL)
    {
        cout << buff[backarray++];
    }
    numout++;
    cout << endl << endl;
    backarray=other;
}


//
//
// 문제 2.	문제 1에서 추출된 자료를 일괄 출력
//
    cout << "\n\n>> 문제 2. 자료 추출 결과" << endl;
    cout << endl;
    cout << "HakBun : ";
    for(backarray = 0; backarray < 80; backarray++)
    {
        if(name[0][backarray] == NULL)
            break;
        cout << name[0][backarray];
    }
    cout << endl;

}
