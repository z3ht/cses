from cses_test_runner import run_tests

TESTS = [
    ("1", "NO"),
    ("2", "NO"),
    ("3", "YES\n2\n1 2\n1\n3"),
    ("4", "YES\n2\n1 4\n2\n2 3"),
    ("5", "NO"),
    ("6", "NO"),
    ("7", "YES\n4\n1 4 2 7\n3\n5 3 6"),
]

exit(run_tests(TESTS))