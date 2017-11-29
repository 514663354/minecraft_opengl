#pragma once
#include<iostream>
#include<vector>
#include"CubeManager.h"

/**
* @file Chunk.h
* @author zf
* @date 2017/11/26
* @brief
* ��ͼ���
* 1.�����ú� 16���� 16���� 256 �ĳ�������������ʾһ������
* 2.�ɽ���ͼд���ļ�
* 3.����vector������������������
* 4.�������е��������޷������;Ϳ����ˣ�����ʾ����һ������
*/

class Chunk
{
public:
	Chunk();
	~Chunk();
	void print_test();

	/**
	* @brief ����һ������
	* @note ��Ĭ�Ϲ���һ��16*16*3��Ĳ�����
	*/
	bool creat_chunk(CubeManager &cube_mgr);

	/**
	* @param x:�����һλ��y:�ڶ�λ��z:����λ,new_block:�·���ı��
	* @return false:�޸Ķ�Ӧ����ʧ�� ture:�޸Ķ�Ӧ���ݳɹ�
	* @brief �޸�chunk��ĳһ�ķ������ຯ��
	*/
	bool set_data(size_t x, size_t y, size_t z, size_t new_block);

	/**
	* @param x:�����һλ��y:�ڶ�λ��z:����λ
	* @return -1:���������Խ�� ����:���ض�Ӧ�ķ�����
	* @brief ��ȡchunk��ĳһ��ķ������ຯ��
	*/
	int get_data(size_t x, size_t y, size_t z) const;

private:
	///һ��chunk�ĳ�
	const size_t chunk_x = 50;
	///һ��chunk�ĸ�
	const size_t chunk_y = 256;
	///һ��chunk����(����Ļ����ϵ)
	const size_t chunk_z = 50;
	///���ݴ�������
	std::vector<std::vector<std::vector<size_t>>> chunk_data;
};
