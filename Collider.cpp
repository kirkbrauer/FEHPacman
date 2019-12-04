#include "Collider.h"

// Default Constructor
Collider::Collider() {}

// Main Constructor
Collider::Collider(unsigned int *m, unsigned int bs, int width, int height) {
  map = m;
  block_size = bs;
  size = Size { width, height };
}

// Check if at an intersection
bool Collider::at_intersection(int x, int y) {
  // Intersections only occur at whole multiples of the base block size
  return x % block_size == 0 && y % block_size == 0;
}

// Functions to check directions
bool Collider::can_go_north(int x, int y) {
  // Check within the map array to see if the block above is occupied
  // Also verify that we are inside the map bounds
  return y > 0 && map[(x/block_size) + (y/block_size-1) * size.width];
}

bool Collider::can_go_south(int x, int y) {
  // Check within the map array to see if the block below is occupied
  // Also verify that we are inside the map bounds
  return y < size.height*block_size && map[(x/block_size) + ((y/block_size)+1) * size.width];
}

bool Collider::can_go_east(int x, int y) {
  // Check within the map array to see if the block to the right is occupied
  // Also verify that we are inside the map bounds
  return x < size.width*block_size && map[(x/block_size+1) + (y/block_size) * size.width];
}

bool Collider::can_go_west(int x, int y) {
  // Check within the map array to see if the block to the left is occupied
  // Also verify that we are inside the map bounds
  return x > 0 && map[((x/block_size)-1) + (y/block_size) * size.width];
}