if get_option('with_test').enabled()
    run_command(['python3', 'tools' / 'generate-runner.py'], check: true)

    test_c = ['unit_runner.c']
    test_cases = [
        'tofu', # need new test cases for structures.
    ]

    foreach cases : test_cases
        test_c += ['cases' / 'test_' + cases + '.c']
    endforeach

    pizza = executable('runner', test_c,
        include_directories: dir,
        dependencies: [
            dependency('fossil-test'),
            fossil_tofu_dep])

    test('Pizza Test Run', pizza)
endif