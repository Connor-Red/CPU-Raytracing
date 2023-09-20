#include "utility.h"

#include "color.h"
#include "ray.h"
#include "vec3.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"
#include "hittable.h"
#include "material.h"
#include "interval.h"

#include <iostream>


int main() {
    // World 
    hittable_list world;

    auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
    auto material_center = make_shared<lambertian>(color(0.7, 0.3, 0.3));
    auto material_left   = make_shared<dielectric>(1.5);
    auto material_right   = make_shared<metal>(color(0.8, 0.8, 0.8), 0.3);

    world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.0),   0.5, material_center));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -0.9),   0.5, material_left));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -0.9),   -0.4, material_left));
    world.add(make_shared<sphere>(point3( 1.1,    0.0, -1.0),   0.5, material_right));

    // Camera

    camera cam;

    // Render

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width  = 400;
    cam.samples_per_pixel = 50;
    cam.max_depth = 50;

    cam.render(world);
}