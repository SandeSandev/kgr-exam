 #include<math.h>
#include <windows.h>  // For MS Windows
#include <GL/glut.h>  // GLUT, includes glu.h and gl.h


struct Point {
    GLint x;
    GLint y;
};

Point pC = {300, 250};
GLint radius = 150;

//GLint hRadius = 120;
GLint arrowRadius = 120;
//GLint sRadius = 140;

double arrowDegree = 0;

void draw_dda(Point p1, Point p2) {
    GLfloat dx = p2.x - p1.x;
    GLfloat dy = p2.y - p1.y;

    GLfloat x1 = p1.x;
    GLfloat y1 = p1.y;

    GLfloat step = 0;

    if(abs(dx) > abs(dy)) {
       step = abs(dx);
   } else {
        step = abs(dy);
  }

     GLfloat xInc = dx/step;
     GLfloat yInc = dy/step;

    for(float i = 1; i <= step; i++) {
        glVertex2i(x1, y1);
        x1 += xInc;
        y1 += yInc;
    }
}


void drawdigit( GLfloat x, GLfloat y)
{
 glClear( GL_COLOR_BUFFER_BIT);
 glColor3f(0.0, 1.0, 0.0);
 glBegin(GL_POINTS);

    for(float i = 1; i <= 30; i++)
    {

        glColor3f(0.0f, 0.0f, 0.0f);
        //glVertex3f(pC.x + i + radius, pC.y +  i + radius , 0.0);
        glVertex3f(x+i, y+i, 0.0);
        //glVertex3f(8.0, 6.0, 0.0);
       // glVertex3f(2.0, 6.0, 0.0);
     }
    glEnd();

 glFlush();
}


void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(1.0f);
    gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}

void draw_circle(Point pC, GLfloat radius) {
    GLfloat step = 1/radius;
    GLfloat x, y;

    for(GLfloat theta = 0; theta <= 360; theta += step) {


        x = pC.x + (radius * cos(theta));
        y = pC.y + (radius * sin(theta));

          if (theta == 90) {
            drawdigit(x,y);
        }
        glVertex2i(x, y);
    }
}




void display(void) {

    Point pHour;

    pHour.y = pC.y + (arrowRadius * sin(arrowDegree));
    pHour.x = pC.x + (arrowRadius * cos(arrowDegree));

   // pMinute.y = pC.y + (mRadius * sin(mDegree));
   // pMinute.x = pC.x + (mRadius * cos(mDegree));

 //   pSecond.y = pC.y + (sRadius * sin(sDegree));
    //pSecond.x = pC.x + (sRadius * cos(sDegree));

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 1.0);
    draw_circle(pC, radius);
    glColor3f(1.0, 0.0, 0.0);
    draw_dda(pC, pHour);

   // glColor3f(0.0, 1.0, 0.0);
    //draw_dda(pC, pMinute);

    //glColor3f(0.0, 0.0, 1.0);
    //draw_dda(pC, pSecond);
    glEnd();
    glFlush();

   // mDegree -= 0.001333333;
    // sDegree -= 0.08;
    arrowDegree -= 0.08;

}

void Timer(int value) {
    glutTimerFunc(330, Timer, 0);
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Square");
    glutDisplayFunc(display);
    init();
    Timer(0);
    glutMainLoop();

    return 0;
}
