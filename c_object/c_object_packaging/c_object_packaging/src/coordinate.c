#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "inc/coordinate.h"



//创建一个shape对象
P_COORDINATE_T shape_create(short int x,short int y)
{
    if((x == 0) || (y == 0))
    {
        printf("shape creat error! x or y can not be zero \n");
        return NULL;
    }

    P_COORDINATE_T p_coordiante = NULL;

    p_coordiante = (P_COORDINATE_T)malloc(sizeof(COORDINATE_T));

    if(NULL != p_coordiante)
    {
        p_coordiante->x = x;
        p_coordiante->y = y;

        return p_coordiante;
    }
    else
    {
        printf("shape malloc error! \n");
    }
    
    return NULL;
}

//销毁一个shape对象
void shape_destroy(P_COORDINATE_T p_coordiante)
{
    if(NULL != p_coordiante)
    {
        free(p_coordiante);
        p_coordiante = NULL;
    }
}

//修改shape的属性值
void shape_moveby(P_COORDINATE_T p_coordiante,short int dx,short int dy)
{
    if(NULL != p_coordiante)
    {
        p_coordiante->x += dx;
        p_coordiante->y += dy;
    }
}

//获取shape的属性值x
short int shape_get_x(P_COORDINATE_T p_coordiante)
{
    if(NULL != p_coordiante)
    {
        return p_coordiante->x;
    }
    else
    {
        return -1;
    }
}

//获取shape的属性值y
short int shape_get_y(P_COORDINATE_T p_coordiante)
{
    if(NULL != p_coordiante)
    {
        return p_coordiante->y;
    }
    else
    {
        return -1;
    }
}






//测试函数，在main中调用，用户测试以上的接口
void coordinate_test_function(void)
{
    P_COORDINATE_T p_coordiante_1 = NULL;
    P_COORDINATE_T p_coordiante_2 = NULL;

    p_coordiante_1 = (P_COORDINATE_T)shape_create(100,200);
    if(NULL == p_coordiante_1)
    {
        printf("p_coordiante_1 create error! \n");
    }

    p_coordiante_2 = (P_COORDINATE_T)shape_create(10,20);
    if(NULL == p_coordiante_2)
    {
        printf("p_coordiante_2 create error! \n");
    }

    printf("p_coordiante_1 x = %d, y = %d \n",shape_get_x(p_coordiante_1), shape_get_y(p_coordiante_1));
    printf("p_coordiante_2 x = %d, y = %d \n",shape_get_x(p_coordiante_2), shape_get_y(p_coordiante_2));

    shape_moveby(p_coordiante_1,50,50);
    shape_moveby(p_coordiante_2,50,50);

    printf("after moveby p_coordiante_1 x = %d, y = %d \n",shape_get_x(p_coordiante_1), shape_get_y(p_coordiante_1));
    printf("after moveby p_coordiante_2 x = %d, y = %d \n",shape_get_x(p_coordiante_2), shape_get_y(p_coordiante_2));

    shape_destroy(p_coordiante_1);
    shape_destroy(p_coordiante_2);
}

