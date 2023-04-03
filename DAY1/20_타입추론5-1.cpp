// 20_타입추론5-1
template<typename T> void foo(T a,  T b) { }
template<typename T> void goo(T& a, T& b) { }
int main()
{
	// "apple"  타입 : const char[6]
	// "banana" 타입 : const char[7]
	
	goo("apple", "banana"); // error?? 왜 ?
						// 참조로 받으면 배열=> 배열로 전달
						// 같은 타입을 요구하는 데, "apple" 과 banaba는
						// 다른 타입(크기가 다르므로)

	foo("apple", "banana"); // 값타입이므로
							// const char[6] => const char* 로전달
							// const char[7] => const char* 로전달
}
