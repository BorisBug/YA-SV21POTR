#!python

import os
import sys
from shutil import rmtree
from pathlib import Path, PurePath

build = 'build'
target = 'build'

if len(sys.argv) == 2:
    if sys.argv[1] == 'clean':
        target = 'clean'
    else:
        print("Bad argument!")
        exit(1)
elif len(sys.argv) > 2:
    print("Too arguments!")
    exit(1)

if target == 'clean':
    rmtree(build, True)  # rm -rf build
    exit(0)

if not os.path.isdir(build):
    os.mkdir(build)

root = Path('.')

sources = []
for file in root.rglob("*.c"):
    sources.append(str(file))

includes = []
for file in root.rglob("*.h"):
    includes.append('-I' + str(file.parent))
includes = ' '.join(list(set(includes)))

for sfile in sources:
    # E.g. build/test.o for test/test.c
    ofile = PurePath(build, PurePath(sfile).name[0:-2] + '.o')
    os.system("gcc -Wall -o {} -c {} {}".format(ofile, sfile, includes))
