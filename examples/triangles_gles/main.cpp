/**
 * Copyright (c) 2010-2015, Ranjith TV
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer
 *     in the documentation and/or other materials provided with the distribution.
 *   * Neither the name the Ranjith nor the names of its contributors may be used
       to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
#if defined(__SYMBIAN32__) || defined(SYMBIAN)
#if !defined(GLES)
#define GLES
#endif
#endif
#if defined(GLES)
#include <glut.h>
#else
#include <GL/glut.h>
#endif

#include <vector>
#include <math.h>

using namespace std;

GLfloat xRot = 0.0f;
GLfloat yRot = 0.0f;

int   scaleCount = 0;
int   scaleDir   = 1;

void display()
{
    glClearColor(1.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);
    glFrontFace(GL_CW);
    glPushMatrix();
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    
    int pivot = 1;
    
    std::vector<GLfloat> triangleColors;
    std::vector<GLfloat> trianglePaths;
    
    trianglePaths.push_back(0.0f);
    trianglePaths.push_back(0.0f);
    trianglePaths.push_back(75.0f);
    
    triangleColors.push_back(0.0f);
    triangleColors.push_back(1.0f);
    triangleColors.push_back(0.0f);
    triangleColors.push_back(1.0f);
    
    for (GLfloat angle = 0.0f; angle <= (2.0f * M_PI) + 1.0f; angle += M_PI/38.0f) {
        GLfloat x = 50.0f * sin(angle);
        GLfloat y = 50.0f * cos(angle);

        if (pivot % 2 == 0) {
            triangleColors.push_back(0.0f);
            triangleColors.push_back(1.0f);
            triangleColors.push_back(0.0f);
            triangleColors.push_back(1.0f);
        } else {
            triangleColors.push_back(1.0f);
            triangleColors.push_back(0.0f);
            triangleColors.push_back(0.0f);
            triangleColors.push_back(1.0f);
        }
        
        pivot++;
        trianglePaths.push_back(x);
        trianglePaths.push_back(y);
        trianglePaths.push_back(0.0f);
    }
    
    glVertexPointer(3, GL_FLOAT, 0, &trianglePaths[0]);
    glColorPointer(4, GL_FLOAT, 0, &triangleColors[0]);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glDrawArrays(GL_TRIANGLE_FAN, 0, trianglePaths.size() / 3);
    glDisableClientState(GL_VERTEX_ARRAY);
    glPopMatrix();
    
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    GLfloat nRange = 100.0f;
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    if (w <= h) {
#if defined(__SYMBIAN32__) || defined(SYMBIAN)
        glOrthof(-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange, nRange);
#else
        glOrtho(-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange, nRange);
#endif
    } else {
#if defined(__SYMBIAN32__) || defined(SYMBIAN)
        glOrthof(-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange, nRange);
#else
        glOrtho(-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange, nRange);
#endif
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void scale()
{
    float scaleUnit = 1.0f;

    if (scaleDir < 0) {
        if (scaleCount <= 0) {
            scaleCount = 0;
            scaleDir = scaleDir * -1;
        } else {                    
            scaleUnit = 1.0f / 0.8f;
            scaleCount--;
        }
    } else {
        if (scaleCount >= 10) {
            scaleCount = 10;
            scaleDir = scaleDir * -1;
        } else {                    
            scaleUnit = 0.8f;
            scaleCount++;
        }
    }
    glScalef(scaleUnit, scaleUnit, scaleUnit);
}

void timeout(int)
{
    if (xRot >= 360.0f) {
        xRot = 0.0f;
    }
    
    xRot += 5.0f;
    yRot = xRot;
    
    glutPostRedisplay();
    glutTimerFunc(20, timeout, 0);
}

void menu(int id)
{
    if (id == 1) {
        scale();
    } else if (id == 2) {
        exit(0);
    }
}

#if defined(__SYMBIAN32__) || defined(SYMBIAN)
GLDEF_C TInt E32Main()
{

    char * argv[] = {"triangle", "-renderer", "gles"};
    int    argc = sizeof(argv) / sizeof(argv[0]);
    
#else
int main(int argc, char ** argv)
{
#endif
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow(argv[0]);
    glutFullScreen();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(20, timeout, 0);
    
    glutCreateMenu(menu);
    glutAddMenuEntry("scale", 1);
    glutAddMenuEntry("exit", 2);
    glutAttachMenu(GLUT_LEFT_BUTTON);
    
    glutMainLoop();

    return 0;
}