dir = include_directories('.')

fossil_tofu_lib = library('fossil_tofu',
    files('dlist.c', 'flist.c', 'clist.c',
          'dqueue.c', 'pqueue.c', 'queue.c', 'cqueue.c',
          'setof.c', 'tuple.c', 'mapof.c',
          'stack.c', 'vector.c', 'tofu.c', 'algorithm.c'),
    install: true,
    include_directories: dir)

fossil_tofu_dep = declare_dependency(
    link_with: [fossil_tofu_lib],
    include_directories: dir)

meson.override_dependency('fossil-tofu', fossil_tofu_dep)