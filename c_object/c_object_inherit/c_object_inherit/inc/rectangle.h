#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_


#include "coordinate.h"    //包含基类的接口



//创建一个rectangle类，继承coordinate类
typedef struct rectangle
{
    P_COORDINATE_T p_coordinate; //父类，必须放在首位

    unsigned short width;
    unsigned short height;

}RECTANGLE_T,*P_RECTANGLE_T;


extern P_RECTANGLE_T rectangle_create(short int x,short int y,unsigned short width,unsigned short height);
extern void rectangle_destroy(P_RECTANGLE_T p_rectangle);
extern void rectangle_test_function(void);


#endif // !__RECTANGLE_H_
