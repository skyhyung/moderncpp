// 6_enable_if1.cpp
// 아래 코드는 C++11 부터 표준에서 제공됩니다.
template<bool, typename T = void > struct enable_if
{
	using type = T;
};
template<typename T> struct enable_if<false, T> 
{
	// 핵심 : type 이 없다
};
int main()
{
	// 아래 코드에서 각 변수의 타입은 ?
	enable_if<true, int>::type  n1; // int n1
	enable_if<true>::type       n2; // void n2 인데 void변수는 
								    // 안되므로 error
	enable_if<false, int>::type n3; // error. "::type" 이 없다
}
