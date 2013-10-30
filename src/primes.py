import sys
primes = int(sys.argv[1] if len(sys.argv) > 1 else "5000")

class Primes:
    def __init__(self):
        self.prime_count = 0
        self.primes = [0]*primes

    def getPrimeCount(self):
        return self.prime_count

    def getPrime(self, i):
        return self.primes[i]

    def addPrime(self, i):
        self.primes[self.prime_count] = i
        self.prime_count += 1

    def isPrimeDivisible(self, candidate):
        for i in range(1, self.prime_count - 1):
            if (self.primes[i] * self.primes[i] > candidate):
                return False
            if (candidate % self.primes[i]) == 0:
                return True
        return False

p = Primes()
c = 1
while p.getPrimeCount() < primes:
    if not p.isPrimeDivisible(c):
        p.addPrime(c)
    c += 1

print(p.getPrime(p.getPrimeCount()-1))
