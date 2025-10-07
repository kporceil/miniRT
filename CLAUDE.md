# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

miniRT is a ray tracing renderer implementing concepts from "The Ray Tracer Challenge". It renders 3D scenes with spheres and planes, supporting Phong lighting, shadows, reflections, refraction, and procedural patterns. Output is generated as PPM images.

The project is written in C using a custom libft library and follows 42 school coding standards (norminette).

## Build Commands

The Makefile supports multiple build modes via the `MODE` variable:

```bash
# Build modes
make              # Default build
make debug        # Debug symbols (-g3)
make asan         # Address sanitizer
make lsan         # Leak sanitizer
make msan         # Memory sanitizer
make gprof        # Profiling
make opti         # Optimized build (-Ofast with vectorization)

# Testing
make test         # Build and run test suite (uses cmocka)
make TEST=yes     # Build test binary only

# Cleanup
make clean        # Remove build artifacts
make fclean       # Remove build artifacts and binary
make re           # Rebuild from scratch

# Other
make norm         # Run norminette on source files
make json         # Generate compile_commands.json
```

## Architecture

### Core Components

The renderer is organized around these key abstractions:

**Tuples** (`tuples.h`): Foundation type representing both points (w=1) and vectors (w=0) in 3D space. Used for positions, directions, and all geometric operations.

**Matrices** (`matrix.h`): 4x4 transformation matrices for translation, rotation, scaling, shearing. Shapes and cameras use transformation matrices that are inverted once during setup for efficient ray-space transformations.

**Rays** (`ray.h`): Defined by origin point and direction vector. Core of the rendering algorithm - rays are cast from camera through each pixel to test intersections.

**Shapes** (`shape.h`): Polymorphic shape system using type enum (SPHERE, PLANE). Each shape has:
- Transformation matrix and its inverse (precomputed)
- Material properties
- Unique ID for tracking during refraction

**Materials** (`material.h`): Surface properties including:
- Pattern (procedural texture)
- Phong components (ambient, diffuse, specular, shininess)
- Reflective coefficient
- Transparency and refractive index

**Intersections**: Ray-shape intersections stored as sorted arrays. The `t_inter` structure contains the shape pointer and intersection distance. The `inter_hit()` function finds the closest positive intersection.

### Rendering Pipeline

1. **Camera Setup** (`camera.h`): Camera has position, orientation (via view transformation matrix), field of view, and resolution. The `ray_for_pixel()` function computes rays through the camera's inverted transformation.

2. **World Intersection** (`world.h`): The world contains arrays of shapes and lights. `world_intersect()` tests a ray against all objects and returns a sorted list of intersections.

3. **Precomputation** (`ray.h` - `t_precomp`): For each intersection, precompute geometric data needed for shading:
   - Hit point and object normal
   - Eye vector and reflection vector
   - Over-point (slightly offset for shadow acne prevention)
   - Under-point (for refraction)
   - Inside flag (ray origin inside object)
   - Refractive indices (n1, n2) for Snell's law

4. **Shading** (`light.h`): Phong lighting model combines:
   - Ambient: Base illumination
   - Diffuse: Lambertian reflection
   - Specular: Glossy highlights
   - Shadow rays test occlusion to each light
   - Recursive reflection and refraction (limited by MAX_RECU constant)

5. **Refraction Tracking** (`refract.h`): When computing refractive indices for transparent objects, maintains a list of currently-entered objects. As the ray crosses boundaries, objects are added/removed to track nested materials.

### Ray-Shape Intersection

The `ray_intersect()` function in `srcs/ray/intersect.c` dispatches to shape-specific intersection routines:
- Transforms ray into object space using precomputed inverse matrix
- Calls `ray_sphere_intersect()` or `ray_plane_intersect()`
- Returns intersections in world space

This design allows easy addition of new shapes (cylinder, cube) by adding enum values and intersection functions.

### Performance Optimizations

Critical path functions are marked with `__attribute__((hot))`:
- Matrix operations (`matrix_mult`, `matrix_tuple_mult`)
- Ray transformations (`ray_transform`)
- Intersection routines (`ray_sphere_intersect`, `ray_plane_intersect`)
- Matrix inversion helpers (determinant, cofactor, submatrix)

The opti build mode enables aggressive optimizations including fast-math, loop unrolling, and native CPU instructions.

### Pattern System

Procedural patterns (`patterns.h`) support transformations independent of object transformations. Pattern evaluation:
1. Transform world point to object space
2. Transform object-space point to pattern space
3. Evaluate pattern function (striped, gradient, ring, checker)

Patterns are integrated into materials and applied during lighting calculations.

## Development Workflow

### Adding New Shapes

1. Add shape type to `e_tshape` enum in `shape.h`
2. Implement shape constructor function (e.g., `t_shape cylinder(size_t id)`)
3. Write intersection function `void ray_cylinder_intersect(t_shape *s, t_ray r, t_intersections *inter)`
4. Add dispatch case in `ray_intersect()` in `srcs/ray/intersect.c`
5. Implement normal calculation in `normal_at()` in `srcs/light/normal.c`
6. Add test cases in `srcs/test/[shape_name]/` directory

### Testing Strategy

The test suite follows The Ray Tracer Challenge's test scenarios. Tests are organized by component:
- `test/tuples/` - Vector math operations
- `test/matrix/` - Transformations and inversion
- `test/ray/` - Intersection and transformation
- `test/light/` - Phong lighting and normals
- `test/world/` - Scene rendering
- `test/patterns/` - Procedural textures
- `test/refraction/` - Transparency and refractive indices

Run `make test` to execute all tests. Failed test count is printed at the end.

### Main Programs

- `srcs/tmp_main.c`: Scene setup for manual testing and render output
- `srcs/test_main.c`: Orchestrates all unit tests

The tmp_main.c file demonstrates typical usage: create world, add shapes with transformations and materials, configure camera, render to canvas, export PPM.

## Code Conventions

- 42 school header format on all files
- Norminette compliance (use `make norm` to check)
- Struct typedefs with `t_` prefix
- Enum typedefs with `e_` prefix
- All angles in radians
- Matrix transformations applied right-to-left: `matrix_mult(translation, scaling)` means scale first, then translate
- Double precision floating point for all geometry
- Epsilon comparisons not shown in headers but used in implementations

## Current Development

The repository is on the `features/refraction` branch implementing transparent materials. Recent commits added:
- Refractive color computation
- Under-point calculation (refraction ray offset)
- Refractive index tracking through nested objects

The next steps would typically include:
- Schlick approximation for Fresnel effect
- Total internal reflection handling
- Additional shape types (cylinder, cone, cube)
- Multi-threading for rendering
