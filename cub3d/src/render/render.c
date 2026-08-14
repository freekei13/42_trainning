#include "render.h"

void    my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    draw_squar(void *img, int size, int color)
{
    int y;
    int x;

    y = 0;
    while (y < size)
    {
        x = 0;
        while (x < size)
        {
            if (y == 0 || y == size - 1)
                my_mlx_pixel_put(img, x, y, color);
            else if (x == 0 || x == size - 1)
                my_mlx_pixel_put(img, x, y, color);
            x++;
        }
        y++;
    }
}

void    map_render(t_data *data)
{
    int y;
    int x;

    mlx_clear_window(data->mlx, data->mlx_win);
    y = 0;
    while (data->map.map[y])
    {
        x = 0;
        while (data->map.map[y][x])
        {
            if (data->map.map[y][x] == '1')
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img,
                    x * 64, y * 64);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_p.img,
        data->player.pos_x * 64, data->player.pos_y * 64);
}

void    map_d_render(t_data *data)
{
    int x;
    int y;

    ft_memset(data->screen.addr, 0, data->screen.line_length * 1080);
    y = 0;
    while (y < 1080)
    {
        x = 0;
        while (x < 1920)
        {
            if (x < 1920 / 2)
                my_mlx_pixel_put(&data->screen, x, y, 0x00FF0000);
            else
                my_mlx_pixel_put(&data->screen, x, y, 0x13031990);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->screen.img, 0, 0);
}