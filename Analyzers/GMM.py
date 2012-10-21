"""
PythonAnalyzers have access to the following global items
songpath = path of the song
wavdata = 1-D np.array of signed short values
channels = number of channels in wav
samplerate = samplerate of wav file in Hz
fftdata = 2-D np.array of complex doubles, where np.shape(fftdata) is a tuple that represents (fftlen, fftnum)
cepdata = 2-D np.array, like fftdata
psd = 2-D np.array, like fftdata
bfccdata = 2-D np.array, like fftdata
power calculated by log10(std::norm(complex_val))
Arrays are set as read-only... not much I can do to stop someone mucking with channels and samplerate
"""
import numpy as np
from sklearn import mixture
import os
import pickle

#Grab song name from filepath
songname = songpath.split("/")[-1].split(".mp3")[0]
fftlen, fftnum = np.shape(fftdata)
psdlen, psdnum = np.shape(psd)
ceplen, cepnum = np.shape(cepdata)
bfcclen, bfccnum = np.shape(bfccdata)

print songname
print len(wavdata)
print wavdata.flags
print channels
print samplerate

#Use GMM to fit data, will need to look at VBGMM and DPGMM as well
n_gauss = 10
g = mixture.GMM(n_components=n_gauss)
g.fit(bfccdata[:,:8])

#Store results in the results directory, as pickled object
songresults = "Results/"+"".join(songname.split(" "))
if not os.path.exists(songresults):
    os.popen("mkdir -p "+songresults)
f = open(songresults+'/DPGMM.pickle', 'w')
pickle.dump(g, f)
f.close()
