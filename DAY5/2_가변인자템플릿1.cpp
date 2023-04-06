// 7_가변인자템플릿1 - 225 page

// 가변인자 클래스 템플릿
template<typename ... Types> class tuple 
{
	// 핵심 : Types 안에 있는 타입을 꺼내서 사용하는 방법
};

int main()
{
	tuple<> t0;
	tuple<int> t1;
	tuple<int, double> t2;
	tuple<int, double, char> t3; // Types : int, double, char
}
