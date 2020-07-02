#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

uint32_t count1;
uint32_t count2;

void countPrimes(uint32_t a, uint32_t b, uint32_t *primeCount) {
	uint32_t count = 0; uint32_t flag;
	for(uint32_t i= 2; i<= a/2; ++i){

	    if(a%i==0)
	    {
	    flag =1;
	    (*primeCount) = count;
                count++;
	    }
	}
	    ++a;




	}

int main() {
	// benchmark how long countPrimes takes for a single thread
	const uint32_t n = 100000000;
	countPrimes(1,  n, &count1);
  cout << count1 << '\n';


	// now benchmark with 2 threads
	thread t1( countPrimes, 1,  n/2, &count1);
	thread t2( countPrimes, n/2+1, n, &count2 );

	t1.join();
	t2.join();
	cout << count1 + count2 << '\n';
}
