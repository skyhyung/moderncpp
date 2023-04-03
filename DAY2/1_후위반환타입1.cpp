// github.com/codenuri/moderncpp 에서 DAY2.zip 받으시면 됩니다.
// 
// 1_후위반환타입1.cpp - 교재 73 page

// C/C++ 의 전통적인 함수 모양
/*
int square(int a)
{
	return a * a;
}
*/
// C++11 의 후위 반환 타입(suffix return type) 문법
auto square(int a) -> int
{
	return a * a;
}

int main()
{
	square(3);
}

