// 3_초기화12 - 0 번 복사해오세요
// C++98 초기화의 문제점 - 54 page
#include <complex>
#include <vector>

int main()
{
	// 문제점 1. 변수의 종류에 따라 초기화 방법이 다르다.
	// => {} 초기화로 해결
	int n1 = { 10 };
	int x[2] = { 1,2 };
	std::complex<double> c = { 1, 2 };

	// 2. 동적 할당한 배열을 초기화 할수 없다.
	// => {} 로 해결
	int* p = int[3] {1, 2, 3};

	// 3. 1,2,3,4,5 등으로 초기화된 STL 컨테이너를 만들수 없다.
	// => {} 로 해결
	std::vector<int> v1 = { 1,2,3,4,5 };
}
class Test
{
	// 4. 클래스 멤버로 있는 배열을 초기화 할수 없다.
	// => {}로 해결
	int x[3]{ 1,2,3 };
};
// 예전 문법

vector v1(10);
vector v2 = 10; // 1. 10사용해서 vector의 임시객체 생성후
				// 2. 임시객체를 복사 생성자로 v2에 복사
				// => 하지만 거의 모든 컴파일러는 최적화를 통해서
				//		임시객체 제거
				// => C++17 부터 문법적으로 임시객체 생성 안된다고 변경
				//    



