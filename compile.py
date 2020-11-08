#!/usr/bin/python

CFILES = [
        "main.cpp"
        #"Kernel.cpp"
        ]

LIBS = [
]

import os

os.system( "clang++ " + ' '.join(CFILES) + " -o algo-art-lab " + ''.join([" -l"+lib for lib in LIBS]) )
