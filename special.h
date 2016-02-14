#ifndef SPECIAL_H
#define SPECIAL_H

#include "Shape.h"
#include "Algebra.h"
class Special : public Shape {
public:
	Special() {};
	~Special() {};
  
    void drawBases(float y) {
        for (float i = 0; i < m_segmentsX; i++) {
            for (float j = 0; j < m_segmentsY; j++) {
                float x  = (i / m_segmentsX) - 0.5f;
                float z  = (j / m_segmentsY) - 0.5f;
                float x2 = ((i + 0.5f) / m_segmentsX) - 0.5f;
                float z2 = ((j + 0.5f) / m_segmentsY) - 0.5f;

                glBegin(GL_TRIANGLE_STRIP);
                
                glVertex3f(x,  y, z);
                glVertex3f(x2, y, z);
                glVertex3f(x2, y, z2);
                glVertex3f(x,  y, z);
                glVertex3f(x,  y, z2);
                
                glEnd();
            }
        }
    };

    void drawColumns() { 
        for (float i = 0; i < m_segmentsX; i++) {
            for (float j = 0; j < m_segmentsY; j++) {
                float x  = (i / m_segmentsX) - 0.5f;
                float z  = (j / m_segmentsY) - 0.5f;
                float x2 = ((i + 0.5f) / m_segmentsX) - 0.5f;
                float z2 = ((j + 0.5f) / m_segmentsY) - 0.5f;

                glBegin(GL_TRIANGLE_STRIP);

                glVertex3f(x, -0.5f, z);
                glVertex3f(x2, -0.5f, z);
                glVertex3f(x2, 0.5f, z);
                glVertex3f(x, -0.5f, z);
                glVertex3f(x, 0.5f, z);

                glEnd();
                
                glBegin(GL_TRIANGLE_STRIP);

                glVertex3f(x2, -0.5f, z);
                glVertex3f(x2, -0.5f, z2);
                glVertex3f(x2, 0.5f, z2);
                glVertex3f(x2, -0.5f, z);
                glVertex3f(x2, 0.5f, z);

                glEnd();
                
                glBegin(GL_TRIANGLE_STRIP);

                glVertex3f(x, -0.5f, z2);
                glVertex3f(x2, -0.5f, z2);
                glVertex3f(x2, 0.5f, z2);
                glVertex3f(x, -0.5f, z2);
                glVertex3f(x, 0.5f, z2);

                glEnd();
 
                glBegin(GL_TRIANGLE_STRIP);

                glVertex3f(x, -0.5f, z);
                glVertex3f(x, -0.5f, z2);
                glVertex3f(x, 0.5f, z2);
                glVertex3f(x, -0.5f, z);
                glVertex3f(x, 0.5f, z);

                glEnd();
            }
        }
    };

    void drawDiagonals() {
         for (int i = 0; i < m_segmentsX; i++) {
            for (int j = 0; j < m_segmentsY; j++) {
                float x  = (((float)i + 0.5f) / m_segmentsX) - 0.5f;
                float z  = ((float)j / m_segmentsY) - 0.5f;
                float x2 = (((float)i + 1) / m_segmentsX) - 0.5f;
                float z2 = (((float)j + 0.5f) / m_segmentsY) - 0.5f;
                float y1, y2;
                if (j % 2 == 0) {
                    y1 = -0.5;
                    y2 =  0.5;
                } else {
                    y1 =  0.5;
                    y2 = -0.5;
                }
                if (i + 1 < m_segmentsX) {
                    glBegin(GL_TRIANGLE_STRIP);

                    glVertex3f(x, y1, z);
                    glVertex3f(x2, 0.0f, z);
                    glVertex3f(x2, y2, z);
                    glVertex3f(x, y1, z);
                    glVertex3f(x, 0.0f, z);

                    glEnd();
                    
                    glBegin(GL_TRIANGLE_STRIP);

                    glVertex3f(x, y1, z2);
                    glVertex3f(x2, 0.0f, z2);
                    glVertex3f(x2, y2, z2);
                    glVertex3f(x, y1, z2);
                    glVertex3f(x, 0.0f, z2);

                    glEnd();
                    
                    glBegin(GL_TRIANGLE_STRIP);

                    glVertex3f(x, y1, z);
                    glVertex3f(x, y1, z2);
                    glVertex3f(x2, 0.0f, z2);
                    glVertex3f(x, y1, z);
                    glVertex3f(x2, 0.0f, z);

                    glEnd();
                    
                    glBegin(GL_TRIANGLE_STRIP);

                    glVertex3f(x, 0.0f, z);
                    glVertex3f(x, 0.0f, z2);
                    glVertex3f(x2, y2, z2);
                    glVertex3f(x, 0.0f, z);
                    glVertex3f(x2, y2, z);

                    glEnd();
                }

                if (j + 1 < m_segmentsY) {
                    x  = ((float)i / m_segmentsX) - 0.5f;
                    z  = (((float)j + 0.5f) / m_segmentsY) - 0.5f;
                    x2 = (((float)i + 0.5f) / m_segmentsX) - 0.5f;
                    z2 = (((float)j + 1) / m_segmentsY) - 0.5f;
                    
                    if ((int)i % 2 == 0) {
                        y1 =  0.5;
                        y2 = -0.5;
                    } else {
                        y1 = -0.5;
                        y2 =  0.5;
                    }

                    glBegin(GL_TRIANGLE_STRIP);

                    glVertex3f(x, y1, z);
                    glVertex3f(x2, y1, z);
                    glVertex3f(x2, 0.0f, z2);
                    glVertex3f(x, y1, z);
                    glVertex3f(x, 0.0f, z2);

                    glEnd();
                    
                    glBegin(GL_TRIANGLE_STRIP);

                    glVertex3f(x, 0.0f, z);
                    glVertex3f(x2, 0.0f, z);
                    glVertex3f(x2, y2, z2);
                    glVertex3f(x, 0.0f, z);
                    glVertex3f(x, y2, z2);

                    glEnd();
                    
                    glBegin(GL_TRIANGLE_STRIP);

                    glVertex3f(x, y1, z);
                    glVertex3f(x, 0.0f, z);
                    glVertex3f(x, y2, z2);
                    glVertex3f(x, y1, z);
                    glVertex3f(x, 0.0f, z2);

                    glEnd();
                    
                    glBegin(GL_TRIANGLE_STRIP);

                    glVertex3f(x2, y1, z);
                    glVertex3f(x2, 0.0f, z);
                    glVertex3f(x2, y2, z2);
                    glVertex3f(x2, y1, z);
                    glVertex3f(x2, 0.0f, z2);

                    glEnd();
                }
            }
        } 
    };

    void draw() {
        drawBases(-0.5f);
        drawBases(0.5f);
        drawColumns();
        drawDiagonals();
    };

    void drawNormal() {
    };
private:
};

#endif
