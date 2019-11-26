#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "inc/rectangle.h"



//创建一个rectangle类对象
P_RECTANGLE_T rectangle_create(short int x,short int y,unsigned short width,unsigned short height)
{
    P_RECTANGLE_T p_rectangle = NULL;

    p_rectangle = (P_RECTANGLE_T)malloc(sizeof(RECTANGLE_T));

    if(NULL != p_rectangle)
    {
        p_rectangle->p_coordinate = NULL;
        p_rectangle->p_coordinate = coordinate_create(x,y);

        if(NULL != p_rectangle->p_coordinate)
        {
            p_rectangle->width = width;
            p_rectangle->height = height;
        }
        else
        {
            printf(" p_rectangle->p_coordinate create error! \n");
        }
        
    }
    else
    {
        printf("rectangle create error! \n");
    }
    

    return p_rectangle;
}

//销毁一个rectangle类对象
void rectangle_destroy(P_RECTANGLE_T p_rectangle)
{
    if(NULL != p_rectangle->p_coordinate)
    {
        free(p_rectangle->p_coordinate);
        p_rectangle->p_coordinate = NULL;
    }

    if(NULL != p_rectangle)
    {
        free(p_rectangle);
        p_rectangle = NULL;
    }
}





//测试函数，在main中调用，用于测试以上接口
void rectangle_test_function(void)
{
    P_RECTANGLE_T p_rectangle_1 = NULL;
    P_RECTANGLE_T p_rectangle_2 = NULL;

    p_rectangle_1 = (P_RECTANGLE_T)rectangle_create(0,0,100,150);
    p_rectangle_2 = (P_RECTANGLE_T)rectangle_create(200,200,500,500);

    if((NULL != p_rectangle_1) && (NULL != p_rectangle_2))
    {
        printf("p_rectangle_1,x = %d,y = %d,width = %d,height = %d \n",\
                coordinate_get_x(p_rectangle_1->p_coordinate),coordinate_get_y(p_rectangle_1->p_coordinate),\
                p_rectangle_1->width,p_rectangle_1->height);

        printf("p_rectangle_2,x = %d,y = %d,width = %d,height = %d \n",\
                coordinate_get_x(p_rectangle_2->p_coordinate),coordinate_get_y(p_rectangle_2->p_coordinate),\
                p_rectangle_2->width,p_rectangle_2->height);

        coordinate_moveby(p_rectangle_1->p_coordinate, 20, 20);
        coordinate_moveby(p_rectangle_2->p_coordinate, 50, 50);     //

        printf("after moveby,p_rectangle_1,x = %d,y = %d,width = %d,height = %d \n",\
                coordinate_get_x(p_rectangle_1->p_coordinate),coordinate_get_y(p_rectangle_1->p_coordinate),\
                p_rectangle_1->width,p_rectangle_1->height);

        printf("after moveby,p_rectangle_2,x = %d,y = %d,width = %d,height = %d \n",\
                coordinate_get_x(p_rectangle_2->p_coordinate),coordinate_get_y(p_rectangle_2->p_coordinate),\
                p_rectangle_2->width,p_rectangle_2->height);
    }
    else
    {

    }

    rectangle_destroy(p_rectangle_1);
    rectangle_destroy(p_rectangle_2);
}


