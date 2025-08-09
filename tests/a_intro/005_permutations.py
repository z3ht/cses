from cses_test_runner import run_tests

TESTS = [
    ("1", "1"),
    ("5", "2 4 1 3 5"),
    ("6", "2 4 6 1 3 5"),
    ("3", "NO SOLUTION")
]

exit(run_tests(TESTS))