#pragma once
#include<vector>
#include"Point.h"
/**
* @brief ��ײ��������
*/

class Collision
{
public:
	Collision();
	~Collision();

	/**
	* @param a,bΪ��������ԽǶ���
	* @brief ��ײ���,��AABB�㷨
	*/
	bool coll_dete(Point a, Point b);

	/**
	* @brief ����ת������opengl�е������Ӧ��ĳһchunk�е�����
	*/

private:


};

