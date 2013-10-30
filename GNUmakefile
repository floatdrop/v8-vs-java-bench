NODEJS ?= node
GCC ?= g++
JAVAC ?= javac

SRC_DIR := src
TARGET_DIR := target

NODE_MODULES := node_modules

.DEFAULT_GOAL := bench
.PHONY: bench build clean distclean

bench:: $(NODE_MODULES) build
	$(NODEJS) bench.js

build:: $(TARGET_DIR)/primes.class $(TARGET_DIR)/primes

$(TARGET_DIR)/primes.class:: $(TARGET_DIR) $(SRC_DIR)/primes.java
	$(JAVAC) $(SRC_DIR)/primes.java -d $(TARGET_DIR)

$(TARGET_DIR)/primes:: $(TARGET_DIR) $(SRC_DIR)/primes.cpp
	$(GCC) -O3 $(SRC_DIR)/primes.cpp -o $@

$(NODE_MODULES):: package.json
	npm install
	if [ -d $(NODE_MODULES) ]; then touch $(NODE_MODULES); else mkdir $(NODE_MODULES); fi

$(TARGET_DIR)::
	mkdir -p $(TARGET_DIR)

clean::
	rm -rf $(TARGET_DIR)

distclean:: clean
	rm -rf $(NODE_MODULES)
