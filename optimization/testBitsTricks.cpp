#include <iostream>
#include <vector>

using namespace std;

int counterSetBits(int x)
{
	int count = 0;
	while (x)
	{
		x &= (x-1);
		count++;
	}
	return count;
}

int log2(int x)
{
	int res = 0;
	while (x >>=1)
		res++;
	return res;
}

// compile : g++ -std=c++11 testBitsTricks.cpp
int main()
{

  // Counter set bits
	{
		cout << "-> counterSetBits\n";
		cout << "counterSetBits(2) : " << counterSetBits(2) << endl;
    cout << "counterSetBits(10) : " << counterSetBits(10) << endl;
    cout << "counterSetBits(16) : " << counterSetBits(15) << endl;
	}

	// divide by 2
	{
		cout << "-> divide by 2 \n";
		int x = 10;
		x >>= 1;
		cout << "x >>= 1 : " << x << endl;
	}

	// multiplying by 2
	{
		cout << "-> multiplying by 2 \n";
		int x = 10;
		x <<= 1;
		cout << "x <<	= 1 : " << x << endl;
	}

	// swap 2 numbers
	{
		int a = 2;
		int b = 3;
		a ^= b;
		b ^= a;
		a ^= b;
		cout << "swap : " << a << " - " << b << endl;

	}

	// log2
	{
		cout << "-> log2 \n";
		int x = 4;
		cout << "log2(4) : " << log2(4) << endl;
	}

	// emplace_back better than push_back
	// 

	// odd even
  {
		cout << "-> odd even \n";
		int x = 4;
		if (x & 1)
      cout << "odd " << endl; // impair
		else
		  cout << "even " << endl; // pair
	}

}