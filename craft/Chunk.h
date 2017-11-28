#pragma once

#include<iostream>
#include<vector>
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
using namespace std;

class Chunk
{
public:
	Chunk();
	~Chunk();
	void print_test()
	{
		for (size_t i = 0; i < chunk_x; i++)
		{
			for (size_t j = 0; j < chunk_y; j++)
			{
				for (size_t k = 0; k < chunk_z; k++)
				{
					std::cout << chunk_data[i][j][k];
				}
			}
		}
	}
	/**
	* @brief ����һ������
	*/
	bool creat_chunk();


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
	int get_data(size_t x, size_t y, size_t z);
private:
	///һ��chunk�ĳ�
	const size_t chunk_x = 16;
	///һ��chunk�Ŀ�
	const size_t chunk_y = 16;
	///һ��chunk�ĸ�
	const size_t chunk_z = 256;
	///���ݴ�������
	vector<vector<vector<size_t>>> chunk_data;



};
