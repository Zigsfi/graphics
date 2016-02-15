#ifndef CYLINDER_H
#define CYLINDER_H

#include "Shape.h"

class Cylinder : public Shape {
public:
	Cylinder() {};
	~Cylinder() {};

    void drawCircle(float y, bool normal){
        float r = 0.5f;
        for (int i = 0; i <= m_segmentsX; i++) {
            float theta = i * (2 * PI / m_segmentsX); 
            float x = r * cos(theta);
            float z = r * sin(theta);
            if (!normal) {
                glNormal3f(0, -1, 0);
                glVertex3f(x, y, z);
                glNormal3f(0, -1, 0);
                glVertex3f(0, y, 0);    
            } else {
                glBegin(GL_LINES);
                glVertex3f(x, y, z);
                glVertex3f(x, y + ((y > 0) ? 0.1f : -0.1f), z);
                glEnd();

                glBegin(GL_LINES);
                glVertex3f(0, y, 0);
                glVertex3f(0, y + ((y > 0) ? 0.1f : -0.1f), 0);
                glEnd();
            }
        } 
    };
    void drawCircle(float y){
        float r = 0.5f;
        for (int i = 0; i <= m_segmentsX; i++) {
            float theta = i * (2 * PI / m_segmentsX); 
            float x = r * cos(theta);
            float z = r * sin(theta);
            
            glVertex3f(x, y, z);
            glVertex3f(0, y, 0);    
        } 
    };

    void drawSides(bool normal) {
        float r = 0.5f;
        for (int i = 0; i < m_segmentsX; i++) {
            if (!normal)
                glBegin(GL_TRIANGLE_STRIP);
            for (float j = m_segmentsY; j >= 0; j--) {    
                float theta = i * (2 * PI / m_segmentsX); 
                float x =  r * cos(theta);
                float y = -(j / m_segmentsY - .5);
                float z =  r * sin(theta);
                float xN =  (r+1) * cos(theta);
                float yN = -(j / m_segmentsY - .5);
                float zN =  (r+1) * sin(theta);
                Vector v = Point(xN, yN, zN) - Point(x, y, z);
                v.normalize();
                
                if (!normal) {
                    glNormal3f(v[0], v[1], v[2]);
                    glVertex3f(x, y, z);
                } else {
                    v = v/10;
                    glBegin(GL_LINES);
                    glVertex3f(x, y, z);
                    glVertex3f(x + v[0], y + v[1], z + v[2]);
                    glEnd();
                }

                float theta2 = (i + 1) * (2 * PI / m_segmentsX); 
                float x2 = r * cos(theta2);
                float z2 = r * sin(theta2);
                xN =  (r+1) * cos(theta2);
                zN =  (r+1) * sin(theta2);
                v = Point(xN, yN, zN) - Point(x2, y, z2);
                v.normalize();
                if (!normal)
                    glVertex3f(x2, y, z2);    
            }
            if (!normal)
                glEnd();
        }    
    };

    void draw() {
        glBegin(GL_TRIANGLE_STRIP);
        drawCircle(-0.5f);
        glEnd();

        glBegin(GL_TRIANGLE_STRIP);
        drawCircle(0.5f);
        glEnd();

        drawSides(false);
    };

    void drawNormal() {
        drawCircle(-0.5f, true);
        drawCircle(0.5f, true);
        drawSides(true);
    };
};
#endif
