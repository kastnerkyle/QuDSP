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
import pylab 

#Grab song name from filepath
songname = songpath.split("/")[-1].split(".mp3")[0]
fftlen, fftnum = np.shape(fftdata)
psdlen, psdnum = np.shape(psd)
ceplen, cepnum = np.shape(cepdata)
bfcclen, bfccnum = np.shape(bfccdata)

print "FFT stats are length: " + `fftlen` + ", num: " + `fftnum`
print "BFCC stats are length: " + `bfcclen` + ", num: " + `bfccnum`
pylab.imshow(bfccdata, interpolation="nearest", origin="upper")	
#pylab.imshow(psd[:50,::100], interpolation="nearest", origin="upper")
#pylab.imshow(psd[:50,::100], origin="upper")
pylab.colorbar()
pylab.show() 
