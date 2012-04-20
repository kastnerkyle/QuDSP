import numpy as np
from scipy.weave import inline

#Inline code for center of mass tests
def centers_of_mass(data):
    dlen, dnum = np.shape(data)
    centers = np.zeros(dnum)
    np.asarray(np.shape(centers), dtype=np.float32)
    centers_of_mass = \
    """
    for (int i=0; i<dnum; i++) {
        float force = 0;
        float mass = 0;
        for (int j=0; j<dlen; j++) {
            force += data[dlen*i+j]*j;
            mass += data[dlen*i+j];
        }
        centers[i] = force/mass;
    }
    """
    inline(code=centers_of_mass,
           arg_names=['dnum', 'dlen', 'centers', 'data'],
           compiler='gcc')
    return centers
