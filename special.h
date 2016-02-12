#ifndef CUBE_H
#define CUBE_H

#include "Shape.h"
#include "Algebra.h"
class Cube : public Shape {
public:
	Cube() : curX(0), curY(0) {};
	~Cube() {};
    void drawXYFace(Point p1, Point p2) {
        float x_inc = (p2[0] - p1[0]) / m_segmentsX;
        float y_inc = (p2[1] - p1[1]) / m_segmentsY;
        for (float x = p1[0]; x < p2[0]; x += x_inc) {
            for (float y = p1[1]; y < p2[1]; y += y_inc) {
                glVertex3f(x, y, p2[2]);
                glVertex3f(x, y + y_inc, p2[2]);
                glVertex3f(x + x_inc, y, p2[2]);
                glVertex3f(x + x_inc, y + y_inc, p2[2]);
            }
        }
    };
    void drawXZFace(Point p1, Point p2) {
        float x_inc = (p2[0] - p1[0]) / m_segmentsX;
        float z_inc = (p2[2] - p1[2]) / m_segmentsX;
        for (float x = p1[0]; x < p2[0]; x += x_inc) {
            for (float z = p1[2]; z < p2[2]; z += z_inc) {
                glVertex3f(x, p2[1], z);
                glVertex3f(x, p2[1], z+z_inc);
                glVertex3f(x + x_inc, p2[1], z);
                glVertex3f(x + x_inc, p2[1], z + z_inc);
            }
        }
    };
    void drawYZFace(Point p1, Point p2) {
        float y_inc = (p2[1] - p1[1]) / m_segmentsY;
        float z_inc = (p2[2] - p1[2]) / m_segmentsX;
        float y = p1[1];
        for (int i = 0; i < m_segmentsY; i++) {
            float z = p1[2];
            for (int j = 0; j < m_segmentsX; j++) {
                glVertex3f(p2[0], y, z);
                glVertex3f(p2[0], y, z + z_inc);
                glVertex3f(p2[0], y + y_inc, z);
                glVertex3f(p2[0], y + y_inc, z + z_inc);
                z += z_inc;
            }
            y += y_inc;
        }
    };

    void drawFace(Point p1, Point p2) {
        float x_inc = (p2[0] - p1[0]) / m_segmentsX;
        float y_inc = (p2[1] - p1[1]) / m_segmentsY;
        float z_inc = (p2[2] - p1[2]) / m_segmentsX;
        float x = p1[0];
        for (int i = 0; i < m_segmentsX; i++) {
            float y = p1[1];
            for (int j = 0; j < m_segmentsY; j++) {
                float z = p1[2];
                for (int k = 0; k < m_segmentsX; k++) {
                    glVertex3f(x, y, z);
                    glVertex3f(x, y + y_inc, z);
                    glVertex3f(x + x_inc, y, z);
                    glVertex3f(x + x_inc, y + y_inc, z);
                    z += z_inc;
                }
                y += y_inc;
            }
            x += x_inc;
        }
    }
    void draw() {
        if (curX != m_segmentsX || curY != m_segmentsY) {

        }
        glBegin(GL_TRIANGLE_STRIP);
        drawFace(Point(-0.5, -0.5, -0.5), Point(0.5, 0.5, -0.5));
        glEnd();
        glBegin(GL_TRIANGLE_STRIP);
        drawFace(Point(-0.5, -0.5, 0.5), Point(0.5, 0.5, 0.5));
        glEnd();

        glBegin(GL_TRIANGLE_STRIP);
        drawFace(Point(-0.5, -0.5, -0.5), Point(0.5, -0.5, 0.5));
        glEnd();
        glBegin(GL_TRIANGLE_STRIP);
        drawFace(Point(-0.5, 0.5, -0.5), Point(0.5, 0.5, 0.5));
        glEnd();

        glBegin(GL_TRIANGLE_STRIP);
        drawFace(Point(-0.5, -0.5, -0.5), Point(-0.5, 0.5, 0.5));
        glEnd();
        glBegin(GL_TRIANGLE_STRIP);
        drawFace(Point(0.5, -0.5, -0.5), Point(0.5, 0.5, 0.5));
        glEnd();
    };


    void drawNormal() {
    };
private:
    std::vector<Face> faces;
    int curX;
    int curY;
};

#endif
