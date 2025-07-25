#include <iostream>

using namespace std;

int main()
{
	// 주석 : 작성한 코드를 컴파일 단계에서 제외시키는 도구
	// - 테스트 코드 적용
	// - 코드에 대한 설명 및 자세한 내용을 기입하는 용도

	// 단일 주석 : 한 줄만 주석처리

	// /* */ 복수 주석 : 여러 줄은 한 번에 주석처리

	// cout << "hello world" << endl;

	/*cout << "hello world" << endl;
	cout << "hello world" << endl;
	cout << "hello world" << endl;
	cout << "hello world" << endl;*/

	// ctrl + k + c : 블럭 지정 후, 여러줄 주석 처리
	// ctrl + k + u : 블럭 지정 후, 여러줄 주석 해제

#pragma region 생략

	//cout << "hello world" << endl;

#pragma endregion			// 단락 나누기 용도

	cout << "hello jusin" << endl;


	return 0;
}