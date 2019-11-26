#ifndef __COORDINATE_H_
#define __COORDINATE_H_



//创建一个位置类对象，属性为坐标x，y
typedef struct coordinate
{
    short int x;
    short int y;
}COORDINATE_T,*P_COORDINATE_T;


extern P_COORDINATE_T coordinate_create(short int x,short int y);
extern void coordinate_destroy(P_COORDINATE_T p_coordinate);
extern void coordinate_moveby(P_COORDINATE_T p_coordinate,short int dx,short int dy);
extern short int coordinate_get_x(P_COORDINATE_T p_coordinate);
extern short int coordinate_get_y(P_COORDINATE_T p_coordinate);


extern void coordinate_test_function(void);





#endif // !__COORDINATE_H_



