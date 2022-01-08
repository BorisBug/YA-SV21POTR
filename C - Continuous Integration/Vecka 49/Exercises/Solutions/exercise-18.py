#!python

import re
import os
import sys
from shutil import rmtree
from pathlib import Path, PurePath

BUILD = 'bin'

if len(sys.argv) == 2:
    if sys.argv[1] == 'clean':
        rmtree(BUILD, True)
        exit(0)
    else:
        print("Bad argument")
        exit(1)
elif len(sys.argv) > 2:
    print("Too arguments")
    exit(1)

if not os.path.isdir(BUILD):
    os.mkdir(BUILD)

root = Path('.')

sources = [str(x) for x in root.rglob("*.c")]

includes = [x for x in root.rglob("*.h")]
includes = list(set([str(x.parent) for x in includes]))
includes = ' '.join(['-I' + x for x in includes])

prep_files = []

for sfile in sources:
    ofile = os.path.splitext(sfile)[0]
    ofile = ofile.replace("/", "_").replace("\\", "_")
    ifile = PurePath(BUILD, ofile + '.i')
    ofile = PurePath(BUILD, ofile + '.o')
    os.system("gcc -Wall -MMD -E -o {} {} {}".format(ifile, sfile, includes))
    try:
        with open(ifile) as f:
            try:
                # Search for source files that implemented the main fuction
                if None != re.search("int\s+[\n]*\s*main\s*[\n]*\(", f.read()):
                    prep_files.append(str(ifile))
            except:
                print("Failed to read {}".format(str(ifile)))
    except:
        print("Failed to open {}".format(str(ifile)))

    os.system("gcc -Wall -o {} -c {} {}".format(ofile, sfile, includes))


for value in prep_files:
    file = os.path.splitext(value)[0] + '.d'
    try:
        with open(file) as f:
            try:
                ofiles = []
                deps = f.read().split(": ")[1].strip()
                deps = deps.replace('\\\n', '').split()
                for v in deps:
                    v = os.path.splitext(v)[0] + '.o'
                    v = v.replace("/", "_")
                    v = v.replace("\\", "_")
                    v = PurePath(BUILD, v)
                    if os.path.isfile(v):
                        ofiles.append(v)
            except:
                print("Failed to read {}".format(file))

            ofiles = ' '.join([str(x) for x in ofiles])
            file = PurePath(BUILD, os.path.splitext(PurePath(file).stem)[0])
            os.system("gcc -Wall {} -o {}".format(ofiles, file))
    except:
        print("Failed to open {}".format(file))

for file in Path(BUILD).glob("*"):
    file = str(file)
    if file[-2:] in ['.d', '.i', '.o']:
        os.remove(file)
    else:
        print("\n*** Run {} ***\n".format(file))
        os.system(file)
