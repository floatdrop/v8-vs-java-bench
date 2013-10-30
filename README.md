## Requirements:
`sudo apt-get install make g++ nodejs npm openjdk-7-jdk ruby python`

## Benchmark:
`make`

## Results:
```bash
$ make bench 5000
c++ x 23.03 ops/sec ±1.81% (58 runs sampled)
java x 4.17 ops/sec ±1.17% (25 runs sampled)
v8 x 11.39 ops/sec ±0.77% (58 runs sampled)
ruby x 0.72 ops/sec ±9.83% (8 runs sampled)
python x 0.33 ops/sec ±0.57% (6 runs sampled)
```
