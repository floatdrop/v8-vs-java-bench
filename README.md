# Primes Benchmark

This is benchmark, inspired by [Google IO](http://www.youtube.com/watch?v=UJPdhx5zTaw) talk on V8 performance.

## Requirements:
`sudo apt-get install make g++ nodejs npm openjdk-7-jdk ruby python`

## Benchmark:
`make`

## Results:
```bash
$ make bench PRIMES=50
c++ x 218 ops/sec ±4.74% (76 runs sampled)
java x 3.85 ops/sec ±8.92% (25 runs sampled)
v8 x 54.04 ops/sec ±0.84% (86 runs sampled)
ruby x 31.18 ops/sec ±0.77% (76 runs sampled)
python x 45.37 ops/sec ±0.84% (74 runs sampled)
```

```bash
$ make bench PRIMES=500
c++ x 213 ops/sec ±0.95% (83 runs sampled)
java x 4.96 ops/sec ±1.45% (29 runs sampled)
v8 x 49.70 ops/sec ±0.76% (80 runs sampled)
ruby x 21.27 ops/sec ±1.01% (54 runs sampled)
python x 19.45 ops/sec ±1.05% (51 runs sampled)
```

```bash
$ make bench PRIMES=5000
c++ x 23.03 ops/sec ±1.81% (58 runs sampled)
java x 4.17 ops/sec ±1.17% (25 runs sampled)
v8 x 11.39 ops/sec ±0.77% (58 runs sampled)
ruby x 0.72 ops/sec ±9.83% (8 runs sampled)
python x 0.33 ops/sec ±0.57% (6 runs sampled)
```

```bash
$ make bench PRIMES=50000
c++ x 0.26 ops/sec ±0.33% (6 runs sampled)
java x 0.22 ops/sec ±4.14% (6 runs sampled)
v8 x 0.14 ops/sec ±2.53% (5 runs sampled)
ruby x 0.01 ops/sec ±4.08% (5 runs sampled)
python ???
```
