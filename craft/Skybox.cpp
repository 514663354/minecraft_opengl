#include "SkyBox.h"
#include<gl\glut.h>
#include<iostream>



CSkyBox::CSkyBox()
{

}

/** ��պг�ʼ�� */
bool CSkyBox::Init()
{
	return true;
}

/** ������պ� */
void  CSkyBox::CreateSkyBox(float x, float y, float z,
	float box_width, float box_height,
	float box_length)
{
	/** ��ó����й���״̬ */
	GLboolean lp;
	glGetBooleanv(GL_LIGHTING, &lp);

	/** ������պг� �� �� */
	float width = MAP * box_width / 8;
	float height = MAP * box_height / 8;
	float length = MAP * box_length / 8;

	/** ������պ�����λ�� */
	// @TODO������
	x = x + MAP / 8 - width / 2;
	y = y + MAP / 24 - height / 2;
	z = z + MAP / 8 - length / 2;


	glDisable(GL_LIGHTING);            /**< �رչ��� */

									   /** ��ʼ���� */
	glPushMatrix();
	glTranslatef(-x, -y, -z);

	/** ���Ʊ��� */
	glBindTexture(GL_TEXTURE_2D, m_texture.texSkybox_up);

	glBegin(GL_QUADS);

	/** ָ����������Ͷ������� */
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);

	glEnd();

	/** ����ǰ�� */
	glBindTexture(GL_TEXTURE_2D, m_texture.texSkybox_up);
	glBegin(GL_QUADS);

	/** ָ����������Ͷ������� */
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z + length);

	glEnd();

	/** ���Ƶ��� */
	glBindTexture(GL_TEXTURE_2D, m_texture.texSkybox_up);

	glBegin(GL_QUADS);

	/** ָ����������Ͷ������� */
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);

	glEnd();

	/** ���ƶ��� */
	glBindTexture(GL_TEXTURE_2D, m_texture.texSkybox_up);

	glBegin(GL_QUADS);

	/** ָ����������Ͷ������� */
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);

	glEnd();

	/** �������� */
	glBindTexture(GL_TEXTURE_2D, m_texture.texSkybox_up);

	glBegin(GL_QUADS);

	/** ָ����������Ͷ������� */
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);

	glEnd();

	/** �������� */
	glBindTexture(GL_TEXTURE_2D, m_texture.texSkybox_up);

	glBegin(GL_QUADS);

	/** ָ����������Ͷ������� */
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glEnd();

	glPopMatrix();                 /** ���ƽ��� */

	if (lp)                         /** �ָ�����״̬ */
		glEnable(GL_LIGHTING);

}