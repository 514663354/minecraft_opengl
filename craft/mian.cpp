/**
* @file main.c
* @author zf
* @date 2017/11/26
* @detail ��������openglȥ����minecraft
* @TODO �������ɣ��ܼ���minecraft�Ĳ��ʰ���������Ư�����⣬�ƻ����飬����״̬�ļ�¼
*/
#define  _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<map>
#include<string>
#include"Crawler.h"
//#include "visualBall.h"
#include "CubeManager.h"
#include "LightMaterial.h"
#include"Man.h"
#include"Chunk.h"
#include"coll_dete.h"
#include"Camera.h"
#include"Skybox.h"

using namespace std;
////����
#define DELAY 12
#define NUM_OF_LINE 32
#define BLOCK_SIZE 1
#define PI 3.1415926535898
#define MAX_CHAR 128


Chunk chunk_test;
Camera camera;
CSkyBox skybox;
///
float near_sight = 0.1f;
float far_sight = 100;
int scr_w;
int scr_h;
extern float curPos[3];

vector<Point> torch_arr;




//����������
bool left_forward = true;
bool right_forward = false;
bool look_from_left = true;


//��Դ̫��
GLfloat s_angle = 0.0f;
GLfloat LightPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };        //��Դλ��

GLfloat ambient = 0.2f;
GLfloat LightAmbient[] = { ambient, ambient, ambient, 1.0f };        //������
GLfloat diffuse = 0.2f;
GLfloat LightDiffuse[] = { diffuse, 0, 0, 1.0f };        //������
GLfloat specular = 0.2f;
GLfloat LightSpecular[] = { specular, 0.6f, 0.6f, 1.0f };    //���淴��

															 //���ϲ���
GLfloat matEmissionR, matEmissionG, matEmissionB;
GLfloat MatEmission[] = { matEmissionR, matEmissionG, matEmissionB, 1.0f };
GLfloat matAmbientR, matAmbientG, matAmbientB;
GLfloat MatAmbient[] = { matAmbientR, matAmbientG, matAmbientB, 1.0f };
GLfloat matDiffuseR, matDiffuseG, matDiffuseB;
GLfloat MatDiffuse[] = { matDiffuseR, matDiffuseG, matDiffuseB, 1.0f };
GLfloat matSpecularR, matSpecularG, matSpecularB;
GLfloat MatSpecular[] = { matSpecularR, matSpecularG, matSpecularB, 1.0f };
GLfloat MatShininess;
//���ڴ�С
int WindowWidth = 1200;
int WindowHeight = 800;
CubeManager cube_mgr = CubeManager();
LightMaterial lightMaterial;
vector<Crawler> crawler_arr;
// ����
Man man;
////////


/**
* @brief ���ÿ�����
*/
void setCrawler() 
{
	for (auto &itr : crawler_arr)
	{
		itr.createCrawler();
	}
}

/**
* @brief ���û�Ѻ���
*/
void setTorch()
{
	for (auto itr : torch_arr)
	{
		lightMaterial.setTorch(itr.x, itr.y, itr.z);
	}
}

void floor() 
{
	glColor3f(1.0f, 1.0f, 1.0f);
	cube_mgr.createAllCube();
	glBindTexture(GL_TEXTURE_2D, 0);
}



/**
* @brief ��ʾ����
*/
void display() 
{

	lightMaterial.setBackGround();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_BLEND);
	lightMaterial.setLight();
	//TODO  ��������������
	skybox.CreateSkyBox(man.x, man.y, man.z, 1.0, 0.5, 1.0);

	glDisable(GL_BLEND);
	lightMaterial.setMaterial(2);
	
	floor();
	lightMaterial.setMaterial(0);
	man.refresh();
	lightMaterial.setMaterial(1);
	setCrawler();
	setTorch();
	//glColor3f(1.0f, 0.0f, 0.0f);
	//glRasterPos2f(0.0f, 0.0f);
	//drawString("Hello, World!");
	glutSwapBuffers();
	camera.setting_view_person(man);
}

/**
* @brief openglһЩ��ʼ״̬���趨
*/
void init() 
{
	///����Ϊ��ƽ����ɫ
	glShadeModel(GL_FLAT);	
	///������ȼ��
	glEnable(GL_DEPTH_TEST);	
	///�������޳���ȡ������Щ�������������Ⱦ
	glEnable(GL_CULL_FACE); 
	///������ʱ���Ϊ����
	glFrontFace(GL_CCW);    
	///������ɫ���
	glEnable(GL_BLEND);			
	///������Դ��ɫ��alpha��Ŀ����ɫ�����н��л��
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);		
	///�������գ��ر�������ȫ�ǻ谵��
	glEnable(GL_COLOR_MATERIAL);		
}

/**
* @brief ˢ��
* @TODO   �����
*/
void refresh(int c)
{
	if (man.is_moving())
	{
		if (man.ltangle < -60)
		{
			left_forward = false;
		}
		else if (man.ltangle > 60)
		{
			left_forward = true;
		}
		if (man.rtangle < -60) 
		{
			right_forward = false;
		}
		else if (man.rtangle > 60) 
		{
			right_forward = true;
		}
		if (left_forward)
		{
			man.ltangle--;
			man.laangle++;
		}
		else 
		{
			man.ltangle++;
			man.laangle--;
		}
		if (right_forward) 
		{
			man.rtangle--;
			man.raangle++;
		}
		else 
		{
			man.rtangle++;
			man.raangle--;
		}
	}
	else
	{
		man.raangle = 0;
		man.laangle = 0;
		man.rtangle = 0;
		man.ltangle = 0;
	}
	///ÿDELAY�������һ��refresh���������Ϊ0
	glutTimerFunc(DELAY, refresh, 0);	
	///��ǵ�ǰ������Ҫ�ػ�
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	scr_w = w;
	scr_h = h;
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75.0, (GLfloat)scr_w / scr_h, near_sight, far_sight);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// �����лص�����.......
void passiveMotion(int x, int y)
{
	camera.unname(x, y, scr_w, man);
}


// ���������
void mouseButton(int button, int state, int x, int y) 
{
	camera.mouse_Button(button, state, x, y, scr_h);
	TexCube *newCube = new TexCube(man.x + 1, man.y, man.z + 1, 1.0f, Stone);
	newCube->createCube();
}

// ����ƶ��ص�����
void mouseMotion(int x, int y) 
{
	trackball_ptov(x, y, scr_w, scr_h, curPos);
	trackMouse();
	glutPostRedisplay();
}

// ���лص�����
/*
void idle() 
{
	// �����귢���ƶ���������Զ�ת��
	if (redrawContinue) glutPostRedisplay();
}*/

// ��������
void control(unsigned char key, int x, int y) 
{
	Collision check;
	cout << "X:" << man.x << "  Z:" << man.z << endl;
	switch (key) 
	{
	case 'p':
		cout << man.vangle << endl;
		break;
	case 32:
		man.jump();
		break;
	case 'a':
		man.left(chunk_test);
		break;
	case 'd':
		man.right(chunk_test);
		break;
	case 'w':
		man.forward(chunk_test);
		break;
	case 's':
		man.back(chunk_test);
		break;
	case 'h':
		camera.change_view();
		break;
	case 27:
		exit(0);
	default:
		break;
	}

}

// �����ɿ�
void controlup(unsigned char key, int x, int y) 
{
	switch (key) 
	{
	case 'w':
		man.move = false;
		break;
	case 's':
		man.move = false;
		break;
	case 'a':
		man.move = false;
		break;
	case 'd':
		man.move = false;
		break;
	}
}

/**
* @brief ����(��ͼ)��ʼ��������������ͼ
*/
void initCube()
{
	///����2D����Ͳ��ʳ�ʼ��
	glEnable(GL_TEXTURE_2D); 
	///������ȼ��
	glEnable(GL_DEPTH_TEST);	
	///����������ã�����GL_NEAREST�ٶȽϿ죬����GL_REPEATʹ�����ظ�
	glTexParameterf(GL_NEAREST, GL_TEXTURE_WRAP_S, GL_REPEAT); 
	Cube::initCubeTexture();
	chunk_test.creat_chunk(cube_mgr);
	//chunk_test.print_test();

	/*
	int num_cube = 30;

	for (int i = num_cube; i >= (-num_cube); i--)
	{
		for (int j = num_cube; j >= (-num_cube); j--) 
		{
			cube_mgr.insertCube(TexCube(i, 0, j, 1.0f, Soil));
		}
	}
	*/
	//////////////////////����//////////////////////////
	cube_mgr.insertCube(TexCube(0, 1, 0, 1.0f, Table));
	cube_mgr.buildPool(8, 1, 10);
	cube_mgr.buildPyramid(30, 1, 10);
	cube_mgr.buildDiamondBuilding(8, 1, 1);
	//����----
	for (int i = 1; i <= 6; i++) 
	{
		cube_mgr.buildTree(1, 1, 4 * i);
		cube_mgr.buildTree(19, 1, 4 * i);
	}
}

// ��������
void music() {
	//    MCI_OPEN_PARMS op;                                     //���ű�������
	//    op.dwCallback = NULL;
	//    op.lpstrAlias = NULL;
	//    op.lpstrDeviceType = "MPEGAudio";
	//    op.lpstrElementName = "music.mp3";
	//    op.wDeviceID = NULL;
	//    UINT rs;
	//    rs = mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT, (DWORD) & op);
	//    if (rs == 0) {
	//        MCI_PLAY_PARMS pp;
	//        pp.dwCallback = NULL;
	//        pp.dwFrom = 0;
	//        //mciSendCommand(op.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)&pp);
	//        mciSendCommand(op.wDeviceID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD) & pp);
	//
	//    }
}

/**
* @brief ��ʼ�������������������
*/
void initOther()
{
	refresh(0);
	for (int i = 0; i < 10; i++)
	{
		crawler_arr.push_back(Crawler(8, 1, -10 - i));
	}

}

/**
* @brief main����
* @param argc:��������  *argv[]��������
* @return �ǺǺǺǺǺ�
*/
int main(int argc, char *argv[]) 
{
	//start ��ʼ��������
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WindowWidth, WindowHeight);
	GLint screenWidth = glutGet(GLUT_SCREEN_WIDTH);
	GLint screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowPosition((screenWidth - WindowWidth) / 2, (screenHeight - WindowHeight) / 2);
	glutCreateWindow("�ҵ�����");
	//end	
	cout << "��˵���û�����ı�ġ�����" << endl;
	init();
	//lastTime = clock();    //����ʱ�״��趨��ǰʱ��
	man.setLocation(6, 1, 6);
	//ShowCursor(false);
	initCube();
	initOther();
	glutDisplayFunc(display);
	//���ڴ�С�ı�ʱ���ı���Ϸ�������
	glutReshapeFunc(reshape);
	//������ƶ�ʱ������û��������ʱ�Ļص�����
	glutPassiveMotionFunc(passiveMotion);
	//������Ļص�����
	glutMouseFunc(mouseButton);
	//������ƶ�ʱ����������ʱ�Ļص�����
	glutMotionFunc(mouseMotion);
	//���̰�������ʱ�Ļص�����
	glutKeyboardUpFunc(controlup);
	//���̻ص�����
	glutKeyboardFunc(control);

	glutMainLoop();

	system("pause");
	return 0;
}

