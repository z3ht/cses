import subprocess
import sys
from datetime import timedelta
from pathlib import Path
import time


PER_TEST_TIMEOUT = timedelta(seconds=1)

def format_multiline(text, prefix="      "):
    lines = text.split('\n')
    if len(lines) == 1:
        return text
    result = lines[0]
    for line in lines[1:]:
        result += '\n' + prefix + line
    return result

def run_tests(tests):
    problem_name = Path(sys.argv[0]).stem
    binary_path = Path.cwd() / "build" / problem_name

    if not binary_path.exists():
        print(f"Error: Could not find binary for {problem_name}")
        print(f"Expected location: {binary_path}")
        return len(tests)

    print(f"Testing {problem_name}")
    print(f"Binary: {binary_path}")
    print("-" * 50)

    passed = 0
    failed = 0

    for i, (input_str, expected) in enumerate(tests, 1):
        try:
            start = time.time()
            result = subprocess.run(
                [binary_path],
                input=input_str,
                capture_output=True,
                text=True,
                timeout=PER_TEST_TIMEOUT.total_seconds()
            )
            elapsed = time.time() - start
            actual = result.stdout.strip()

            if actual == expected.strip():
                print(f"  Test {i}: ✓ PASS ({elapsed:.3f}s)")
                passed += 1
            else:
                print(f"  Test {i}: ✗ FAIL")

                print("    Input: ", end="")
                print(format_multiline(input_str))

                print("    Expected: ", end="")
                print(format_multiline(expected.strip()))

                print("    Got: ", end="")
                print(format_multiline(actual))

                if result.stderr.strip():
                    print("    Stderr: ", end="")
                    print(format_multiline(result.stderr.strip()))

                failed += 1

        except subprocess.TimeoutExpired:
            print(f"  Test {i}: ✗ FAIL (timeout after {PER_TEST_TIMEOUT})")
            print("    Input: ", end="")
            print(format_multiline(input_str))
            failed += 1
        except Exception as e:
            print(f"  Test {i}: ✗ FAIL (error: {e})")
            print("    Input: ", end="")
            print(format_multiline(input_str))
            failed += 1

    print("-" * 50)
    if failed == 0:
        print(f"✓ All {passed} tests passed!")
    else:
        print(f"Summary: {passed} passed, {failed} failed")

    return failed