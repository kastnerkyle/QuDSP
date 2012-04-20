#!/usr/bin/python

"""
This file completely generates a Window.h file for a given integer argument.
Example usage:

./genWindow.py 1024

will generate a window.h file holding window values for a 1024 length Blackman
Harris window.
"""

import sys
import math 
import matplotlib.pyplot as plot

def window(f, fftlen): 
    a0 = 0.35876
    a1 = 0.48829
    a2 = 0.14128
    a3 = 0.01168
    pi = 3.14159

    def first_term(index):
        return a0
    def second_term(index):
        return a1*math.cos((2*math.pi*index)/(fftlen-1))
    def third_term(index):
        return a2*math.cos((4*math.pi*index)/(fftlen-1))
    def fourth_term(index):
        return a3*math.cos((6*math.pi*index)/(fftlen-1))
    def blackman(index):
        return first_term(index) - second_term(index) + third_term(index) - fourth_term(index)

    define = "#define WINDOWLEN "+str(fftlen)+"\n"
    data = "static const float window[WINDOWLEN] = {\n"
    hdr = "#ifndef _WINDOW_H_\n"+"#define _WINDOW_H_\n"+define+data
    f.write(hdr)
    map(lambda x: f.write(str(blackman(x))+",\n"), range(fftlen)[:-1])
    f.write(str(blackman(range(fftlen)[-1]))+"};\n")

if __name__=="__main__":
    fftlen = int(sys.argv[1])
    f = open('Window.h', 'w')
    window(f, fftlen)
    f.write("#endif")
    f.close()
