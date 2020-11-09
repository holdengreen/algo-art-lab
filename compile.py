#!/usr/bin/python
import os
import sys
import subprocess

import colorful as cf

COMPILER = "clang++"

SRCS = [
        "main.cpp",
        "kernel/Kernel.cpp",
        "kernel/exportdata/ppm.cpp"
        ]

LIBS = [
    "dl"
]

FLAGS = [
    "g"
]

usages = [
        "./ (no options) Compile main program and kernel", #0
        "shader [frag or vert] [name (shaderfile excluding file extension)]", #1
]

messages = [
        "Please provide name of shaderfile" #0
]

def compile(srcs, flags, libs, outputfile):
    cmd = "{COMPILER} {flags} {srcs} -o {outputfile} {libs}".format(
        COMPILER=COMPILER,
        flags=' '.join(['-'+f for f in flags]),
        srcs=' '.join(srcs),
        outputfile=outputfile,
        libs=' '.join(["-l"+l for l in libs])
    )
    print(cmd)
    failed = os.system(cmd)
    if failed:
        print(cf.red("ERROR: " + cmd))


def shader(type, name): #compile a shader of type 'frag' or 'vert'
    compile(
        srcs=["shaders/{type}/{name}.cpp".format(type=type, name=name)],
        flags=["fPIC", 'g', 'shared'],
        libs=[],
        outputfile="shaders/binaries/{type}/{name}.so".format(type=type, name=name)
    )

if len(sys.argv) > 1:
    argv = sys.argv[1:]
    if argv[0] == "help":
        print("Options:")
        for option in usages:
            print( '\t' + option )

    elif argv[0] == "shader":
        argv = argv[1:]
        if len(argv) == 0:
            print("Too few shader arguments")
            print('\t' + usages[1])
            exit(1)
        elif argv[0] == "frag" or argv[0] == "vert":
            if len(argv) != 2:
                print(messages[1])
                exit(1)

            shader(argv[0], argv[1])

        else:
            print("Invalid shader type")
            print('\t' + usages[1])


else:
    compile(srcs=SRCS, flags=FLAGS, libs=LIBS, outputfile="algo-art-lab")
