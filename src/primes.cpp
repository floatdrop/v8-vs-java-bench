/** This code was at Google I/O 2012: 
Breaking the JavaScript Speed Limit with V8 
(http://www.youtube.com/watch?v=UJPdhx5zTaw) **/

#include <stdio.h>

class Primes {
	public:
		int getPrimeCount() const { return prime_count; }
		int getPrime(int i) const { return primes[i]; }
		void addPrime(int i) { primes[prime_count++] = i; }
		
		bool isPrimeDivisible(int candidate) {
			for (int i = 1; i < prime_count; ++i) {
				if ((candidate % primes[i]) == 0) return true;
			}
			return false;
		}
	private:
		volatile int prime_count;
		volatile int primes[5000];
};

int main() {
	Primes p;
	int c = 1;
	while (p.getPrimeCount() < 5000) {
		if (!p.isPrimeDivisible(c)) {
			p.addPrime(c);
		}
		c++;
	}
	printf("%d\n", p.getPrime(p.getPrimeCount() - 1));
}
