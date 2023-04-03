#include <type_traits>
#include <iostream>

// C++98 enum.. 요소의 타입은 int 입니다. 변경할수 없습니다.
// enum  DAYOFWEEK { SUN = 0, MON = 1, TUE = 2 }; 

enum class DAYOFWEEK : char { SUN = 0, MON = 1, TUE = 2 };

int main()
{
	std::cout << typeid(std::underlying_type_t<DAYOFWEEK>).name()
		      << std::endl;
}




