/* 画像を反転させるプログラム inverse.c */
#include<stdio.h>
#include<stdlib.h>
#include"mypgm.h"

void make_inverse_image( )
/* 原画像 image1 を反転させて image2 に代入する */
{
    int x, y;    /* 制御変数 */

    printf("反転画像を作成します．\n");
    x_size2 = x_size1;  /* 横画素数 */
    y_size2 = y_size1;  /* 縦画素数 */
    for ( y = 0; y < y_size2; y ++ ){
        for ( x = 0; x < x_size2; x ++ ){
            image2[y][x] = (unsigned char)
                           (MAX_BRIGHTNESS - image1[y][x]);
        }
    }
}

main( )
{
    load_image_data( );    /* 画像データを image1 に読み込む */
    make_inverse_image( ); /* image1 を反転させ image2 へ */
    save_image_data( );    /* image2 を保存する */
    return 0;
}
