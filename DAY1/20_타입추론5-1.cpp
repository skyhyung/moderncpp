// 20_타입추론5-1
template<typename T>
void foo(T a, T b) { }

template<typename T>
void goo(T& a, T& b) { }

int main()
{
	foo("apple", "banana");
	goo("apple", "banana"); // error?? 왜 ?
}
