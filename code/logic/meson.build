dir = include_directories('.')

fossil_tofu_lib = library('fossil-tofu',
    files('doublylist.c', 'forwardlist.c', 'circularlist.c',
          'dqueue.c', 'tuple.c', 'pqueue.c', 'queue.c',
          'setof.c', 'stack.c', 'vector.c', 'tofu.c'),
    install: true,
    include_directories: dir)

fossil_tofu_dep = declare_dependency(
    link_with: [fossil_tofu_lib],
    include_directories: dir)
