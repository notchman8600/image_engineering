#include"pch.h"

#include"Image.h"
#include"Constant.h"
#include"imgProcLibIO.h"
#define _CRT_SECURE_NO_WARNINGS

namespace ImgProcLib {

	void save_image_data(Image& img)
		/* image2[ ][ ], __x_size2, __y_size2 �̃f�[�^���C���ꂼ�� pgm �摜�C*/
		/* ����f���C�c��f���Ƃ��ăt�@�C���ɕۑ�����D                  */
	{
		char file_name[MAX_FILENAME]; /* �t�@�C�����p�̕����z�� */
		FILE* fp; /* �t�@�C���|�C���^ */
		int x, y = 0; /* ���[�v�ϐ� */
				  /* �o�̓t�@�C���̃I�[�v�� */
		printf("-----------------------------------------------------\n");
		printf("  ���m�N���K���摜�ipgm�`���j�o�̓��[�`��\n");
		printf("-----------------------------------------------------\n");
		printf("�o�̓t�@�C���� (*.pgm) : ");
		scanf("%s", file_name);
		fp = fopen(file_name, "wb");
		/* �t�@�C�����ʎq "P5" ��擪�ɏo�͂��� */
		fputs("P5\n", fp);
		/* # �Ŏn�܂�R�����g�s�i�ȗ��\�j */
		fputs("# Created by Image Processing\n", fp);
		/* �摜�̉����C�c���̏o�� */
		fprintf(fp, "%d %d\n", img.x_size, img.y_size);
		/* �ő�K���l�̏o�� */
		fprintf(fp, "%d\n", MAX_BRIGHTNESS);
		/* �摜�f�[�^�̏o�� */
		for (y = 0; y < img.y_size; y++) {
			for (x = 0; x < img.x_size; x++) {
				fputc(img[y][x], fp);
			}
		}
		printf("�f�[�^�͐������o�͂���܂����D\n");
		printf("-----------------------------------------------------\n");
		fclose(fp);

	}

	void save_image_data(Image& img, std::string filename)
		/* image2[ ][ ], __x_size2, __y_size2 �̃f�[�^���C���ꂼ�� pgm �摜�C*/
		/* ����f���C�c��f���Ƃ��ăt�@�C���ɕۑ�����D                  */
	{
		FILE* fp; /* �t�@�C���|�C���^ */
		int x, y; /* ���[�v�ϐ� */
				  /* �o�̓t�@�C���̃I�[�v�� */
		printf("-----------------------------------------------------\n");
		printf("  ���m�N���K���摜�ipgm�`���j�o�̓��[�`��\n");
		printf("-----------------------------------------------------\n");
		printf("�o�̓t�@�C���� (*.pgm) : ");

		fp = fopen(filename.c_str(), "wb");
		/* �t�@�C�����ʎq "P5" ��擪�ɏo�͂��� */
		fputs("P5\n", fp);
		/* # �Ŏn�܂�R�����g�s�i�ȗ��\�j */
		fputs("# Created by Image Processing\n", fp);
		/* �摜�̉����C�c���̏o�� */
		fprintf(fp, "%d %d\n", img.x_size, img.y_size);
		/* �ő�K���l�̏o�� */
		fprintf(fp, "%d\n", MAX_BRIGHTNESS);
		/* �摜�f�[�^�̏o�� */
		for (y = 0; y < img.y_size; y++) {
			for (x = 0; x < img.x_size; x++) {
				fputc(img[y][x], fp);
			}
		}
		printf("�f�[�^�͐������o�͂���܂����D\n");
		printf("-----------------------------------------------------\n");
		fclose(fp);
	}


	//Todo �x���Ȃ錴�������˂�
	Image imageRead(std::string filename)
		/* pgm �摜�C����f���C�c��f���̃f�[�^���t�@�C������ǂݍ��݁C*/
		/* image1[ ][ ]�C__x_size1�C__y_size1 �ɂ��ꂼ��������D         */
	{
		Image result;
		result.load_image_data(filename);
		return result;
	}


}