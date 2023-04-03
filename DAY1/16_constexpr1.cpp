// 16_constexpr1

// 상수의 종류
// 컴파일 시간 상수 : 컴파일러가 값을 알고 있는 상수
// 
// 실행  시간 상수 : 실행시간 결정된값을 변경할수 없는것
//				    컴파일러는 값을 모른다.
//					다른 언어는 "상수" 라고 부르기 보다는 
//					"읽기 전용, immutable" 이라고 합니다.

// 왜 구분 하나요 ?
// => 다양한 문법에서 "컴파일 시간상수"를 요구 합니다.
// => 배열 크기, 템플릿 인자등, static_assert 등

int main()
{
	int n = 10;
	const int c1 = 10; 
	const int c2 = n;  

	// 다음중 에러를 모두 고르세요
	int arr1[10]; // ok
	int arr2[n ]; // error
	int arr3[c1]; // ok
	int arr4[c2]; // error

}
