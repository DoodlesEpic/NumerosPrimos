project('NumerosPrimos', 'c',
  version : '1.4',
  default_options : ['warning_level=everything'])

executable('NumerosPrimos',
           'src/main.c',
           include_directories: include_directories('include'),
           sources: ['src/main.c', 'src/bruteforce.c', 'src/eratostenes.c'],
           install : true)

