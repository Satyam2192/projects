#include <iostream>
#include <random>

using namespace std;

const int NUM_PARTICLES = 1000;

struct Particle {
    float x, y, z; // Position
    float vx, vy, vz; // Velocity
    float r, g, b; // Color
};

int main() {
    // Create an array of particles
    Particle particles[NUM_PARTICLES];

    // Initialize the particles with random positions, velocities, and colors
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> pos(-1.0, 1.0);
    uniform_real_distribution<float> vel(-0.1, 0.1);
    uniform_real_distribution<float> col(0.0, 1.0);
    for (int i = 0; i < NUM_PARTICLES; i++) {
        particles[i].x = pos(gen);
        particles[i].y = pos(gen);
        particles[i].z = pos(gen);
        particles[i].vx = vel(gen);
        particles[i].vy = vel(gen);
        particles[i].vz = vel(gen);
        particles[i].r = col(gen);
        particles[i].g = col(gen);
        particles[i].b = col(gen);
    }

    // Print the message and update the particle positions
    cout << "Happy New Year!" << endl;
    for (int i = 0; i < NUM_PARTICLES; i++) {
        particles[i].x += particles[i].vx;
        particles[i].y += particles[i].vy;
        particles[i].z += particles[i].vz;
    }

    return 0;
}
