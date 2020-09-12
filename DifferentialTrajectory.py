import numpy as np
import astropy.constants as const
import matplotlib.pyplot as plt

class Projectile:               # \frac{d^{2} \overrightarrow{x} }{dt^{2}} = \widehat{x} \cdot  \frac{Gm}{\left| x \right|^{2}}
    def __init__(self, initial_x, initial_dx):   # initialise position and velocity
        self.x = initial_x
        self.dx = initial_dx

    def step_t(self, step_size):       # step through time
        self.dx += step_size * self.d2x()
        self.x += step_size * self.dx
        return self.x.copy()

    def d2x(self):    # returns value for second derivative of position
        magnitude = const.G.value * const.M_earth.value /( self.x[0]**2 + self.x[1]**2 )   # G*m/(r^2)
        direction = -self.x/( ( self.x[0]**2 + self.x[1]**2 )**0.5 )                     # unit vector towards origin, direction of gravitational force
        return magnitude * direction

projectile = Projectile(np.array([[0.0],[6378100.0]]), np.array([[6000.0],[6000.0]]))     # make a projectile at surface of earth with velocity (6000,6000)
step_size = 1     # smaller step size increases accuracy
coords = []   # records positions after each time step

stage1_steps = 2000
coords += [projectile.step_t(step_size) for j in range(stage1_steps)]      # projectile moves away from earth

projectile.dx += np.array([[500.0],[-3000.0]])        # adds velocity to projectile to allow orbit
stage2_steps = 20000
coords += [projectile.step_t(step_size) for j in range(stage2_steps)]    # projectile orbits earth


X, Y = [], []
for coord in coords:       # records values for x(t) and y(t) to plot
    X.append(coord[0])
    Y.append(coord[1])

earth = plt.Circle((0, 0), 6378100.0, color='b')    # draws earth as blue circle
fig, ax = plt.subplots()
ax.set_aspect(1)
ax.add_artist(earth)

plt.plot(X, Y, 'ro', label = 'Position')
plt.title('Position')
plt.show()
plt.close()
