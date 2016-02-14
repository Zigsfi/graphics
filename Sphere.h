#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

class Sphere : public Shape {
    public:
        Sphere() {};
        ~Sphere() {};

        void drawVert(float theta, float phi, bool normal) {
            float x = 0.5 * sin (phi) * cos(theta);
            float y = 0.5 * cos(phi);
            float z = 0.5 * sin(phi) * sin(theta);
            Point p(x, y, z);
            x = 0.6 * sin (phi) * cos(theta);
            y = 0.6 * cos(phi);
            z = 0.6 * sin(phi) * sin(theta);
            Point n(x, y, z);
            Vector v = n - p;
            v.normalize();
            glNormal3f(v[0], v[1], v[2]);
            v = v/10;
            n = p + v;
            
            if (normal) {
                glBegin(GL_LINES);
                glVertex3f(p[0], p[1], p[2]);
                glVertex3f(n[0], n[1], n[2]);
                glEnd();
            } else {
                glVertex3f(p[0], p[1], p[2]);
            }
        }
        void drawShape(bool normal) {
            if (!normal)
                glBegin(GL_TRIANGLES);
            for (int i = 0; i < m_segmentsX; i+=1) {
                for (int j = 0; j < m_segmentsY; j+=1) {
                    float theta = DEG_TO_RAD(i * (360.0f / m_segmentsX));
                    float phi = DEG_TO_RAD(j * (180.0f / m_segmentsY));
                    float theta2 = DEG_TO_RAD(((i + 1) % m_segmentsX) * (360.0f / m_segmentsX));
                    float phi2 = DEG_TO_RAD(((j + 1) ) * (180.0f / m_segmentsY));
                    drawVert(theta, phi, normal);
                    drawVert(theta2, phi, normal);
                    drawVert(theta, phi2, normal);

                    drawVert(theta2, phi, normal);
                    drawVert(theta, phi2, normal);
                    drawVert(theta2, phi2, normal);

                }
            } 
            if (!normal)
                glEnd();
        };

        void draw() {
            drawShape(false);
        }
        void drawNormal() {
            drawShape(true);
        };
};

#endif
