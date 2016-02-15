#ifndef CUBE_H
#define CUBE_H

#include "Shape.h"
#include "Algebra.h"
class Cube : public Shape {
public:
	Cube() : curX(0), curY(0) {};
	~Cube() {};
    void drawXYFace(Point p1, Point p2, Vector v, bool normal) {
        float x_inc = (p2[0] - p1[0]) / m_segmentsX;
        float y_inc = (p2[1] - p1[1]) / m_segmentsY;
        float x = p1[0];
        for (int i = 0; i < m_segmentsX; i++) {
            float y = p1[1];
            for (int j = 0; j < m_segmentsY; j++) {
                if (!normal) {
                    glBegin(GL_TRIANGLE_STRIP);
                    glNormal3f(v[0], v[1], v[2]);
                    glVertex3f(x, y, p2[2]);
                    glNormal3f(v[0], v[1], v[2]);
                    glVertex3f(x, y + y_inc, p2[2]);
                    glNormal3f(v[0], v[1], v[2]);
                    glVertex3f(x + x_inc, y, p2[2]);
                    glNormal3f(v[0], v[1], v[2]);
                    glVertex3f(x + x_inc, y + y_inc, p2[2]);
                    glEnd();
                } else {
                    glBegin(GL_LINES);
                    glVertex3f(x, y, p2[2]);
                    glVertex3f(x + (v[0]/10), y + (v[1]/10), p2[2] + (v[2]/10));
                    glEnd();

                    glBegin(GL_LINES);
                    glVertex3f(x, y + y_inc, p2[2]);
                    glVertex3f(x + (v[0]/10), y + y_inc + (v[1]/10), p2[2] + (v[2]/10));
                    glEnd();

                    glBegin(GL_LINES);
                    glVertex3f(x + x_inc, y, p2[2]);
                    glVertex3f(x + x_inc + (v[0]/10), y + (v[1]/10), p2[2] + (v[2]/10));
                    glEnd();

                    glBegin(GL_LINES);
                    glVertex3f(x + x_inc, y + y_inc, p2[2]);
                    glVertex3f(x + x_inc + (v[0]/10), y + y_inc + (v[1]/10), p2[2] + (v[2]/10));
                    glEnd();
                }
                y += y_inc; 
            }
            x += x_inc;
        }
    };
    void drawXZFace(Point p1, Point p2, Vector v, bool normal) {
        float x_inc = (p2[0] - p1[0]) / m_segmentsX;
        float z_inc = (p2[2] - p1[2]) / m_segmentsX;
        float x = p1[0];
        Vector v2 = v/10;
        for (int i = 0; i < m_segmentsX; i++) {
            float z = p1[2];
            for (int j = 0; j < m_segmentsX; j++) {
                if (!normal) {
                    glBegin(GL_TRIANGLE_STRIP);
                    glNormal3f(v[0], v[1], v[2]);
                    glVertex3f(x, p2[1], z);
                    glNormal3f(v[0], v[1], v[2]);
                    glVertex3f(x, p2[1], z+z_inc);
                    glNormal3f(v[0], v[1], v[2]);
                    glVertex3f(x + x_inc, p2[1], z);
                    glNormal3f(v[0], v[1], v[2]);
                    glVertex3f(x + x_inc, p2[1], z + z_inc);
                    glEnd();
                } else {
                    glBegin(GL_LINES);
                    glVertex3f(x, p2[1], z);
                    glVertex3f(x + v2[0], p2[1] + v2[1], z + v2[2]);

                    glVertex3f(x, p2[1], z+z_inc);
                    glVertex3f(x + v2[0], p2[1] + v2[1], z+z_inc + v2[2]);
                    glVertex3f(x + x_inc, p2[1], z);
                    glVertex3f(x + x_inc + v2[0], p2[1] + v2[1], z + v2[2]);

                    glVertex3f(x + x_inc, p2[1], z + z_inc);
                    glVertex3f(x + x_inc + v2[0], p2[1] + v2[1], z + z_inc + v2[2]);
                    glEnd();

                }
                z += z_inc;
            }
            x += x_inc;
        }
    };
    void drawYZFace(Point p1, Point p2, Vector v, bool normal) {
        float y_inc = (p2[1] - p1[1]) / m_segmentsY;
        float z_inc = (p2[2] - p1[2]) / m_segmentsX;
        float y = p1[1];
        Vector v2 = v / 10;
        for (int i = 0; i < m_segmentsY; i++) {
            float z = p1[2];
            for (int j = 0; j < m_segmentsX; j++) {
                if(!normal) {
                    glBegin(GL_TRIANGLE_STRIP);
                    glNormal3f(v[0], v[1], v[2]);
                    glVertex3f(p2[0], y, z);
                    glNormal3f(v[0], v[1], v[2]);
                    glVertex3f(p2[0], y, z + z_inc);
                    glNormal3f(v[0], v[1], v[2]);
                    glVertex3f(p2[0], y + y_inc, z);
                    glNormal3f(v[0], v[1], v[2]);
                    glVertex3f(p2[0], y + y_inc, z + z_inc);
                    glEnd();
                } else {
                    glBegin(GL_LINES);
                    glVertex3f(p2[0], y, z);
                    glVertex3f(p2[0] + v2[0], y + v2[1], z + v2[2]);

                    glVertex3f(p2[0], y, z + z_inc);
                    glVertex3f(p2[0] + v2[0], y + v2[1], z + z_inc + v2[2]);

                    glVertex3f(p2[0], y + y_inc, z);
                    glVertex3f(p2[0] + v2[0], y + y_inc + v2[1], z + v2[2]);

                    glVertex3f(p2[0], y + y_inc, z + z_inc);
                    glVertex3f(p2[0] + v2[0], y + y_inc + v2[1], z + z_inc + v2[2]);
                    glEnd();
                }
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
        drawXYFace(Point(-0.5, -0.5, -0.5), Point(0.5, 0.5, -0.5),
                Vector(0, 0, -1), false
                );
        drawXYFace(Point(-0.5, -0.5, 0.5), Point(0.5, 0.5, 0.5),
                Vector(0, 0, 1), false
                );

        drawXZFace(Point(-0.5, -0.5, -0.5), Point(0.5, -0.5, 0.5),
                Vector(0, -1, 0), false
                );
        drawXZFace(Point(-0.5, 0.5, -0.5), Point(0.5, 0.5, 0.5),
                Vector(0, -1, 0), false
                );

        drawYZFace(Point(-0.5, -0.5, -0.5), Point(-0.5, 0.5, 0.5),
                Vector(-1, 0, 0), false);
        drawYZFace(Point(0.5, -0.5, -0.5), Point(0.5, 0.5, 0.5),
                Vector(1, 0, 0), false);
    };


    void drawNormal() {
        drawXYFace(Point(-0.5, -0.5, -0.5), Point(0.5, 0.5, -0.5),
                Vector(0, 0, -1), true
                );
        drawXYFace(Point(-0.5, -0.5, 0.5), Point(0.5, 0.5, 0.5),
                Vector(0, 0, 1), true
                );
        drawXYFace(Point(-0.5, -0.5, 0.5), Point(0.5, 0.5, 0.5),
                Vector(0, 0, 1), true
                );

        drawXZFace(Point(-0.5, -0.5, -0.5), Point(0.5, -0.5, 0.5),
                Vector(0, -1, 0), true
                );
        drawYZFace(Point(-0.5, -0.5, -0.5), Point(-0.5, 0.5, 0.5),
                Vector(-1, 0, 0), true);
        drawYZFace(Point(0.5, -0.5, -0.5), Point(0.5, 0.5, 0.5),
                Vector(1, 0, 0), true);
    };
private:
    std::vector<Face> faces;
    int curX;
    int curY;
};

#endif
