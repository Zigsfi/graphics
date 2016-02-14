#ifndef CONE_H
#define CONE_H

#include "Shape.h"
#include <math.h>

class Cone : public Shape {
public:
	Cone() {};
	~Cone() {};

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

    void drawSides() {
        float r = 0.5f;
        for (int i = 0; i < m_segmentsX; i++) {
            for (float j = m_segmentsY; j >= 0; j--) {    
                float theta = i * (2 * PI / m_segmentsX); 
                float x =  (r * (j / m_segmentsY)) * cos(theta);
                float y = -(j / m_segmentsY - .5);
                float z =  (r * (j / m_segmentsY)) * sin(theta);
                
                float theta2 = (i + 1) * (2 * PI / m_segmentsX); 
                float x2 =  (r * (j / m_segmentsY)) * cos(theta2);
                float z2 =  (r * (j / m_segmentsY)) * sin(theta2);
            
                glVertex3f(x, y, z);
                glVertex3f(x2, y, z2);    
            }
        }    
    };

	void draw() {
        glBegin(GL_TRIANGLE_STRIP);
	    drawCircle(-0.5f);
        glEnd();

        glBegin(GL_TRIANGLE_STRIP);
        drawSides();
        glEnd();
    };

	void drawNormal() {
	};
};

#endif
