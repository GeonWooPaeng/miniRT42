/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:27:54 by gpaeng            #+#    #+#             */
/*   Updated: 2021/01/29 16:47:22 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	ft_camera_set(t_camera *cam, double aspect_ratio)
{
	cam->view_height = 2.0;
	cam->view_width = aspect_ratio * cam->view_height;
	cam->focal_length = 1.0;
	ft_vec3_set_xyz(&cam->origin, 0.0, 0.0, 0.0);
	ft_vec3_set_xyz(&cam->horizontal, cam->view_width, 0.0, 0.0);
	ft_vec3_set_xyz(&cam->vertical, 0.0, cam->view_height, 0.0);
	cam->lower_left_corner.x = cam->origin.x - (cam->horizontal.x / 2) - (cam->vertical.x / 2) - 0;
	cam->lower_left_corner.y = cam->origin.y - (cam->horizontal.y / 2) - (cam->vertical.y / 2) - 0;
	cam->lower_left_corner.z = cam->origin.z - (cam->horizontal.z / 2) - (cam->vertical.z / 2) - cam->focal_length;
}

t_ray	*ft_camera_cal_ray(t_ray *tar, t_camera *cam, double u, double v)
{
	t_vec3 cal;

	cal.x = cam->lower_left_corner.x 
				+ u * cam->horizontal.x
				+ v * cam->vertical.x
				- cam->origin.x;
	cal.y = cam->lower_left_corner.y
				+ u * cam->horizontal.y
				+ v * cam->vertical.y
				- cam->origin.y;
	cal.z = cam->lower_left_corner.z
				+ u * cam->horizontal.z
				+ v * cam->vertical.z
				- cam->origin.z;
	return (ft_ray_set(tar, &(cam->origin), &cal));
}