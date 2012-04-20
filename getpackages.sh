#!/bin/bash

PKGS="python-dev python-numpy python-scipy python-matplotlib python-scikits-learn python-pip libmpg123-dev libsndfile1-dev libfftw3-dev"

sudo apt-get install $PKGS
sudo pip install -U scikit-learn
sudo apt-get remove python-scikits-learn
