/** This code was at Google I/O 2012: 
Breaking the JavaScript Speed Limit with V8 
(http://www.youtube.com/watch?v=UJPdhx5zTaw) **/

function Primes(c) {
	this.prime_count = 0;
	this.primes = new Array(c);
	this.getPrimeCount = function() { return this.prime_count; };
	this.getPrime = function(i) { return this.primes[i]; };
	this.addPrime = function(i) { this.primes[this.prime_count++] = i; };
	this.isPrimeDivisible = function(candidate) {
		for (var i = 1; i < this.prime_count; ++i) {
			if ((candidate % this.primes[i]) === 0) return true;
		}
		return false;
	};
}

function main(primes) {
	p = new Primes(primes);
	var c = 1;
	while (p.getPrimeCount() < primes) {
		if (!p.isPrimeDivisible(c)) {
			p.addPrime(c);
		}
		c++;
	}
	print(p.getPrime(p.getPrimeCount()-1));
}

main(arguments[0] || 5000);
