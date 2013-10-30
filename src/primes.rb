

class Primes
    def initialize(c)
        @primes_count = 0
        @primes = Array.new(c)
    end

    attr_accessor :primes_count
    attr_accessor :primes

    def getPrime(i)
        return @primes[i]
    end

    def addPrime(i)
        @primes[@primes_count] = i
        @primes_count += 1
    end

    def isPrimeDivisible(candidate)
        for i in 1..(@primes_count - 1) 
            if (@primes[i] * @primes[i] > candidate)
                return false
            end
            if (candidate % @primes[i]) == 0
                return true
            end
        end
        return false
    end
end

if __FILE__ == $0
    primes = Integer(ARGV[0] || "5000")
    p = Primes.new(primes)
    c = 1
    while p.primes_count < primes do
        if not p.isPrimeDivisible(c)
            p.addPrime(c)
        end
        c += 1
    end
    print p.primes[-1]
end

