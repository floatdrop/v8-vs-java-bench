var Benchmark = require('benchmark').Benchmark;
var spawn = require('child_process').spawn;
var suite = new Benchmark.Suite();

suite.add(
	createBench('c++', './target/primes', [])
);

suite.add(
	createBench('java', 'java', ['-cp', 'target', 'primes'])
);

suite.add(
	createBench('v8', './v8/out/native/d8', ['src/primes.js'])
);

suite.add(
	createBench('ruby', 'ruby', ['src/primes.rb'])
);

suite.add(
	createBench('python', 'python', ['src/primes.py'])
);

suite.on('cycle', function(event) {
	console.log('' + event.target);
});

suite.on('complete', function() {
    console.log('Fastest is ' + this.filter('fastest').pluck('name'));
});

suite.run();

function createBench(name, cmd, args) {
	return {
		name: name,
		defer: true,
		fn: function(deferred) {
			var process = spawn(cmd, args);

			process.on('close', function() {
				deferred.resolve();
			});
		}
	};
}
