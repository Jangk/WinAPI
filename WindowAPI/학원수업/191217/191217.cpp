#include <iostream>
#include <tchar.h>

using namespace std;

void main()
{
	// ##1.문자 집합 (character set)

	// 1.SBCS (Single Byte Character Set)
	// 문자 하나당 1바이트로 처리한다.
	// 대표 예) 아스키코드

	//// 2.MBCS (Multi Byte Character Set)
	//// 문자 하나당 경우에 따라서 1바이트 혹은 2바이트로 처리한다.

	//char sz[5] = "한글";

	//cout << sizeof(sz) << endl;
	//cout << strlen(sz) << endl;


	// 3.WBCS (Wide Byte Character Set)
	// 문자 하나당 2바이트로 처리한다.
	// 대표 예) 유니코드

// 	//wchar_t a = 'A';
// 	cout << sizeof(a) << endl;

	/*wchar_t sz[3] = L"한글";

	cout << sizeof(sz) << endl;
	cout << wcslen(sz) << endl;*/

	//TCHAR

}