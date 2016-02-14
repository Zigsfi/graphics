#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

class Sphere : public Shape {
    public:
        Sphere() {};
        ~Sphere() {};

        void drawVert(float theta, float phi) {
            float x = 0.5 * sin (phi) * cos(theta);
            float y = 0.5 * cos(phi);
            float z = 0.5 * sin(phi) * sin(theta);
            Point p(x, y, z);
            x = 0.6 * sin (phi) * cos(theta);
            y = 0.6 * cos(phi);
            z = 0.6 * sin(phi) * sin(theta);
            Point n(x, y, z);
            Vector v = p - n;
            v.normalize();
            glNormal3f(v[0], v[1], v[2]);
            glVertex3f(p[0], p[1], p[2]);
        }
        void draw() {
            glBegin(GL_TRIANGLES);
            for (int i = 0; i < m_segmentsX/2; i+=1) {
                for (int j = 0; j < m_segmentsY; j+=1) {
                    float theta = DEG_TO_RAD(i * (360.0f / m_segmentsX));
                    float phi = DEG_TO_RAD(j * (180.0f / m_segmentsY));
                    float theta2 = DEG_TO_RAD(((i + 1) % m_segmentsX) * (360.0f / m_segmentsX));
                    float phi2 = DEG_TO_RAD(((j + 1) ) * (180.0f / m_segmentsY));
                    drawVert(theta, phi);
                    drawVert(theta2, phi);
                    drawVert(theta, phi2);

                    drawVert(theta2, phi);
                    drawVert(theta, phi2);
                    drawVert(theta2, phi2);

                }
            }
            for (int i = m_segmentsX/2; i < m_segmentsX; i+=1) {
                for (int j = 0; j < m_segmentsY; j+=1) {
                    float theta = DEG_TO_RAD(i * (360.0f / m_segmentsX));
                    float phi = DEG_TO_RAD(j * (180.0f / m_segmentsY));
                    float theta2 = DEG_TO_RAD(((i + 1) % m_segmentsX) * (360.0f / m_segmentsX));
                    float phi2 = DEG_TO_RAD(((j + 1) ) * (180.0f / m_segmentsY));
                    drawVert(theta, phi);
                    drawVert(theta2, phi);
                    drawVert(theta, phi2);

                    drawVert(theta2, phi);
                    drawVert(theta, phi2);
                    drawVert(theta2, phi2);

                }
            }
            glEnd();
        };

        void drawNormal() {
        };
};

#endif
