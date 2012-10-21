#! /usr/bin/python
import os
import sys
import pickle
from sklearn import mixture
import numpy as np

def read():
    to_open=[]
    if len(sys.argv) < 2:
        results_dir="../Results/"
        print "WARNING: Because no path argument was provided, all results in " + results_dir + " will be loaded!"
        #[:-1] is to strip the newline that comes back from os.popen...
        for folder in os.popen("ls "+results_dir):
            folder_path = results_dir+folder[:-1]
            for p_file in os.popen("ls "+folder_path):
                to_open.append(folder_path+"/"+p_file[:-1])
    else:
        if not os.path.exists(sys.argv[1]):
            raise Exception("No MM file found at " + sys.argv[1])
        to_open.append(sys.argv[1])
    
    results = {}
    for n in to_open:
        f = open(n)
        r = pickle.load(f)
        results[n] = r
    return results

def score(results_dict):
    print results_dict
    for k in results_dict.keys():
        r = results_dict[k]
        num_iter = 50
        samps = [ r.sample() for x in range(num_iter) ]
        #print samps
        print "Testing " + k
        for k2 in results_dict.keys():
            #if k2 == k:
            #   continue
            n = results_dict[k2]
            evaluated = [ n.eval(s) for s in samps ]
            mean = sum( [ x[0] for x in evaluated ] ) / len(evaluated)
            print mean
            print k2
            print "--------"

if __name__=="__main__":
    results = read()
    score(results)
