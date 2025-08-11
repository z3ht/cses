from cses_test_runner import run_tests

TESTS = [
    ("1", "0"),
    ("5", "1"),
    ("20", "4"),
    ("24", "4"),
    ("25", "6"),
    ("29", "6"),
    ("30", "7"),
    ("33", "7"),
]

exit(run_tests(TESTS))