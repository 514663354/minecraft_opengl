#pragma once
#include"Point.h"
#include"Chunk.h"

/**
* @brief �����࣬���Դ�����chunk���ɵĵ�ͼ
*/
class Word
{
public:
	Word();
	/**
	* @param center:�������ĵ�Ĭ��Ϊopenglԭ��  
	* num_chunk�����ص����������1��chunkΪ1�㣬9��Ϊ2�㣬25Ϊ3��....��
	*/
	Word(Point center,size_t num_chunk);

	/**
	* @brief ��������
	*/
	void display_word();
	/**
	* @param a:��������ϵ�µ�ĳһ��
	* @brief ȡ����������ϵ��ĳһ��ķ������
	* @return ��ȡ�ɹ����ض�Ӧ��ţ����򷵻�-1
	*/
	int get_block(Point a);
	/**
	* @param x,y,z:��������ϵ�µ�ĳһ���x,y,z����
	* @brief ȡ����������ϵ��ĳһ��ķ������
	* @return ��ȡ�ɹ����ض�Ӧ��ţ����򷵻�-1
	*/
	int get_block(int x,int y,int z);


	~Word();

private:


};
