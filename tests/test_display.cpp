#include <fstream>


int main()
{
	std::ofstream ofs("test_display.png", std::ios::out | std::ios::binary);
	ofs << "P6\n"
	<< 400 << " " << 300
	<< "\n255\n";
	unsigned char r=255, g=255, b=255;
	for (unsigned j = 0; j < 300; ++j)
	{
		for (unsigned i = 0; i < 400; ++i)
		{
			if (i<200 && j>150){
				r=0;
				g=0;}
			else{
				r=255;
				g=255;}
			ofs << r << g << b;
		}
	}
	ofs.close();
}
