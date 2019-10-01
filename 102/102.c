#include <stdio.h>

enum {DIR_LEFT, DIR_RIGHT, DIR_NONE};

struct point {
	int x, y;
};

struct point origin = {0, 0};

int cross(struct point a, struct point b, struct point c) {
	return (b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y);
}

int direction(struct point a, struct point b, struct point c) {
	if (cross(a, b, c) > 0)
		return DIR_LEFT;
	if (cross(a, b, c) < 0)
		return DIR_RIGHT;
	return DIR_NONE;
}

int is_same_direction(int dir1, int dir2) {
	return dir1 == dir2 || dir1 == DIR_NONE || dir2 == DIR_NONE;
}

int main() {
	struct point points[3];
	int dir1, dir2, dir3;
	int same_dir;
	int count;

	count = 0;
	while (!feof(stdin)) {
		scanf("%d,%d,", &points[0].x, &points[0].y);
		scanf("%d,%d,", &points[1].x, &points[1].y);
		scanf("%d,%d\n", &points[2].x, &points[2].y);

		dir1 = direction(points[0], points[1], origin);
		dir2 = direction(points[1], points[2], origin);
		dir3 = direction(points[2], points[0], origin);

		same_dir = is_same_direction(dir1, dir2) && 
		           is_same_direction(dir2, dir3) && 
				   is_same_direction(dir3, dir1);

		if (same_dir) {
			printf("%d,%d,", points[0].x, points[0].y);
			printf("%d,%d,", points[1].x, points[1].y);
			printf("%d,%d\n", points[2].x, points[2].y);
			count++;
		}
	}

	return 0;
}
