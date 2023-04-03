// 18_if_init    50 page

int foo() { return 100; }

int main()
{
	int ret = foo();
	if (ret == 0)
	{
	}

	// C++17 부터 init if 도입됩니다.
	if (int ret2 = foo(); ret2 == 0)
	{
		// ret2 사용
	} //<== 여기서 ret2 파괴

	switch (int n = foo(); n)
	{
	case 1:break;
	}

	// while 도 될까요 ? => 안됩니다. for 문으로 하면 되기 때문에..!
	/*
	while (int cnt = 0; cnt < 10)
	{
		++cnt;
	}
	*/

}





