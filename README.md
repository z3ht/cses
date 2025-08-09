# CSES Problem Set (C++)

This is where I keep my C++ solutions to the [CSES Problem Set](https://cses.fi/problemset/), along with a CMake build setup and Python test scripts

---

## Build

```bash
./build.sh        # compile all problems into ./build/
```

* Each `.cpp` file in `problems/**` is compiled into a binary in `build/` with the same name.
* Example:

  * Source: `problems/a_intro/weird_algorithm.cpp`
  * Binary: `build/weird_algorithm`

---

## Test

Each problem has a Python test script that imports `cses_test_runner`, defines the test cases inline, and calls `run_tests()`.

Example:

```python
from cses_test_runner import run_tests

TESTS = [
    ("5\n3 2 5 1 7", "5")
]

exit(run_tests(TESTS))
```

* `TESTS` is a list of `(input_str, expected_output_str)` pairs.
* The script name corresponds to the binary in `build/`.
* For each test case, the runner passes `input_str` to the binary and compares its output to `expected_output_str`.

Run a test with:

```bash
python3 tests/<section>/<problem>.py
```

---

## CLion Run Configurations

The `.run/` directory has CLion run configuration templates that directly run the matching binary from `build/`. These let you run and debug problems inside CLion without typing commands manually. Duplicate a template, change the target binary name, and you’re ready to go. See the [CLion documentation](https://www.jetbrains.com/help/clion/run-debug-configuration.html) for details on creating or editing configurations.
