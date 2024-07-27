dir = include_directories('.')

fossil_tofu_lib = library('fossil-tofu',
    files('arrayof.c', 'doublylist.c', 'forwardlist.c',
          'dqueue.c', 'mapof.c', 'pqueue.c', 'queue.c',
          'setof.c', 'stack.c', 'vector.c', 'tofu.c'),
    install: true,
    include_directories: dir)

fossil_tofu_dep = declare_dependency(
    link_with: [fossil_tofu_lib],
    include_directories: dir)
