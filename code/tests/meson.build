if get_option('with_test').enabled()
    run_command(['python3', 'tools' / 'generate-runner.py'], check: true)

    test_src = ['unit_runner.c']
    test_cubes = [
        'arrayof', 'doublylist', 'forwardlist',
        'dqueue', 'mapof', 'pqueue', 'queue',
        'setof', 'stack', 'vector', 'tofu'
    ]

    foreach cube : test_cubes
        test_src += ['test_' + cube + '.c']
    endforeach

    pizza = executable('runner', test_src,
        include_directories: dir,
        dependencies: [
            dependency('fossil-test'),
            dependency('fossil-mock'),
            dependency('fossil-mark'),
            fossil_tofu_dep])

    test('Pizza Test Run', pizza)
endif