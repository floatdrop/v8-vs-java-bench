import static java.lang.System.out;

public class primes {

    public static int PRIMES = 5000;

	public static class Primes
	{
		public int prime_count;
		public int[] primes = new int[PRIMES];

		public int getPrimeCount () { return this.prime_count; }
		public int getPrime (int i) { return this.primes[i]; }
		public void addPrime (int p) { this.primes[this.prime_count++] = p; }

		public boolean isPrimeDivisible(int candidate) {
			for (int i = 1; i < this.prime_count; ++i) {
                if (this.primes[i] * this.primes[i] > candidate) return false;
				if ((candidate % this.primes[i]) == 0) return true;
			}
			return false;
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
        PRIMES = args.length > 0 ? Integer.parseInt(args[0]) : 5000;
		Primes p = new Primes();
		int c = 1;
		while (p.getPrimeCount() < PRIMES) {
			if (!p.isPrimeDivisible(c)) {
				p.addPrime(c);
			}
			c++;
		}
		out.println(p.getPrime(p.getPrimeCount() - 1));
	}

}
