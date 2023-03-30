#include <chrono>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

using ck = chrono::high_resolution_clock;

void sieve1(int sz)
{
	vector<bool> isprime;

	isprime.push_back(false);
	for (int i=1; i<=sz; i++)
		isprime.push_back(true);

	for (int i=2; i<=sz/2; i++)
	{
		if (isprime[i])
		{
			for (int j=2*i; j<=sz; j+=i)
				isprime[j] = false;
		}
	}

	list<int> primes;
	for (int i=0; i<=sz; i++)
	{
		if (isprime[i])
			primes.push_back(i);
	}
	cout << primes.back() << endl;
}

void sieve2(int sz)
{
	vector<bool> isprime;

	isprime.push_back(false);
	for (int i=1; i<=sz; i++)
		isprime.push_back(true);

	auto p = next(begin(isprime),2);
	for (int i=2; i<=sz/2; i++,p++)
	{
		if (*p)
		{
			auto m = next(p,i);
			for (int j=i+i ; j<=sz; j+=i,advance(m,i))
				*m = false;
		}
	}

	list<int> primes;
	int i=0;
	for (auto f : isprime)
	{
		if (f)
			primes.push_back(i);
		i++;
	}
	cout << primes.back() << endl;
}

void sieve3(int sz)
{
	list<int> all;

	for (int i=2; i<=sz; i++)
		all.push_back(i);

#if 1
	for (auto p = begin(all); p != end(all); p++)
	{
		for (auto m = next(p); m != end(all); )
		{
			if (((*m)%(*p))==0)
				m = all.erase(m);
			else
				m++;
		}
	}
#else
	for (auto p = begin(all); p != end(all); p++)
	{
		auto last = remove_if(next(p),end(all),
								[p](int m) { return (m%(*p))==0;} );
		all.erase(last,end(all));
	}
#endif

	list<int> primes;
	primes.push_back(1);
	for (auto i : all)
		primes.push_back(i);

	cout << primes.back() << endl;
}

int main(int argc,char* argv[])
{
	int size = 123456;

	if (argc > 1)
		size = atoi(argv[1]);

	ck::time_point t0,t1;
	chrono::milliseconds elapsed;

	t0 = ck::now();
	sieve1(size);
	t1 = ck::now();
	elapsed = chrono::duration_cast<chrono::milliseconds>(t1-t0);
	cout << "Test 1: " << elapsed.count() << " ms" << endl;

	t0 = ck::now();
	sieve2(size);
	t1 = ck::now();
	elapsed = chrono::duration_cast<chrono::milliseconds>(t1-t0);
	cout << "Test 2: " << elapsed.count() << " ms" << endl;

	t0 = ck::now();
	sieve3(size);
	t1 = ck::now();
	elapsed = chrono::duration_cast<chrono::milliseconds>(t1-t0);
	cout << "Test 3: " << elapsed.count()
	 << " ms" << endl;

	return 0;
}
