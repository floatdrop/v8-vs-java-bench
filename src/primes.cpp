/** This code was at Google I/O 2012: 
Breaking the JavaScript Speed Limit with V8 
(http://www.youtube.com/watch?v=UJPdhx5zTaw) **/

#include <stdio.h>
#include <stdlib.h>

class Primes {
	public:
        Primes(int size) {
            prime_count = 0;
            primes = new int[size];
        }
        ~Primes() {
            delete [] primes;
        }
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
        volatile int* primes;
};

int main(int argc, char *argv[]) {
    int primes = 5000;
    if (argc > 1)
        primes = atoi(argv[1]);
	Primes p(primes);
	int c = 1;
	while (p.getPrimeCount() < primes) {
		if (!p.isPrimeDivisible(c)) {
			p.addPrime(c);
		}
		c++;
	}
	printf("%d\n", p.getPrime(p.getPrimeCount() - 1));
}
