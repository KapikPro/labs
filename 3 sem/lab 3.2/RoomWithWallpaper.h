#include "Room.h"

class RoomWithWallpaper : public Room
{
public:
	RoomWithWallpaper(double length, double width, double height, int windows_count = 0)
		: Room(length, width, height, windows_count)
	{ }
	double walls_area()
	{
		return 2 * (get_width() + get_length()) * get_height();
	}
	
	double get_wallpaper_area()
	{
		double walls_area = 2 * (get_width() + get_length()) * get_height();
		double windows_area = get_windows_count() * get_window_area();

		return walls_area - windows_area;
	}
};